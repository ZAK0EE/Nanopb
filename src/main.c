/********************************************************************************************************/
/************************************************Includes************************************************/
/********************************************************************************************************/

#include <pb_encode.h>
#include <pb_decode.h>
#include "proto/message.pb.h"

#include "MCAL/GPIO/GPIO.h"
#include "HAL/ControlClock/CLK_Control.h"

#include "HAL/HUART/HUART.h"
#include "MCAL/RCC/RCC.h"


/********************************************************************************************************/
/************************************************Defines*************************************************/
/********************************************************************************************************/
#define PROTOBUFF_HEADER_LEN 10



/********************************************************************************************************/
/************************************************Types***************************************************/
/********************************************************************************************************/

typedef enum
{
  HEADER_RECEIVE_STATE,
  MSG_RECEIVE_STATE,
}ProtoBuf_Receive_State_t;

/********************************************************************************************************/
/*****************************************Static Functions Prototype*************************************/
/********************************************************************************************************/
static void ResetPinHandler(void);
static void ReadPinHandler(void);
static void SetPinHandler(void);
static void TogglePinHandler(void);

/********************************************************************************************************/
/************************************************Variables***********************************************/
/********************************************************************************************************/

uint8_t rx_buffer[100] = {0};

HUSART_UserReq_t HUART_RxReq;

/* Global Received messages */
Msg_ResetPin  ResetPinMsg;
Msg_ReadPin   ReadPinMsg;
Msg_SetPin    SetPinMsg;
Msg_TogglePin TogglePinMsg;

/* Global transmit messages */
Msg_PinValue  PinValueMsg;


/* Received Messages handlers */
typedef enum
{
  MSG_RESETPIN_ID,
  MSG_READPIN_ID,
  MSG_SETPIN_ID,
  MSG_TOGGLEPIN_ID,
}MessageID_t;

void (*messageHandlers[])(void) = {ResetPinHandler, ReadPinHandler, SetPinHandler, TogglePinHandler};




/********************************************************************************************************/
/*********************************************APIs Implementation****************************************/
/********************************************************************************************************/
static void ResetPinHandler(void)
{
  GPIO_setPinValue(ResetPinMsg.Pin_Port, ResetPinMsg.Pin_Num, GPIO_PINSTATE_RESET);
}
static void ReadPinHandler(void)
{
  
}
static void SetPinHandler(void)
{
  GPIO_setPinValue(SetPinMsg.Pin_Port, SetPinMsg.Pin_Num, GPIO_PINSTATE_SET);

}
static void TogglePinHandler(void)
{
  GPIO_PinState_t PinState = GPIO_getPinValue(TogglePinMsg.Pin_Port, TogglePinMsg.Pin_Num);
  GPIO_setPinValue(TogglePinMsg.Pin_Port, TogglePinMsg.Pin_Num, !PinState);

}

void Proto_Sent(void)
{
  
}
void Proto_Receive(void)
{
   static uint8_t state = 0;

  static MessageID_t MessageID = 0;
  static uint32_t MessageLen = 0;
  switch (state)
  {
  case HEADER_RECEIVE_STATE:
  {
    /* Allocate space for the decoded message. */
    Msg_Header HeaderMsg = Msg_Header_init_zero;

    /* Create a stream that reads from the buffer. */
    pb_istream_t instream;
    instream = pb_istream_from_buffer(rx_buffer, PROTOBUFF_HEADER_LEN);

    /* Now we are ready to decode the message. */
    bool status = false;

    status = pb_decode(&instream, Msg_Header_fields, &HeaderMsg);

    /* Check for errors... */
    if (status)
    {
      /* Update the next message length and ID*/
      MessageID = HeaderMsg.msg_ID;
      MessageLen = HeaderMsg.msg_len;
      HUART_RxReq.Buff_Len = MessageLen;
      HUART_ReceiveBuffAsync(&HUART_RxReq);

      state++;
    }
    else
    {
    }

    break;
  }
  case MSG_RECEIVE_STATE:
  {
    /* Allocate space for the decoded message. */

    void * dest_struct = 0;
    const pb_msgdesc_t* msg_fields = 0;
    switch(MessageID)
    {
      case MSG_RESETPIN_ID:
        dest_struct = &ResetPinMsg;
        msg_fields = Msg_ResetPin_fields;
        break;
      case MSG_READPIN_ID:
        dest_struct = &ReadPinMsg;
        msg_fields = Msg_ReadPin_fields;      
      break;
      case MSG_SETPIN_ID:
        dest_struct = &SetPinMsg;
        msg_fields = Msg_SetPin_fields;      
      break;
      case MSG_TOGGLEPIN_ID:
        dest_struct = &TogglePinMsg;
        msg_fields = Msg_TogglePin_fields;      
      break;
    }

    if(dest_struct != 0)
    {
      /* Create a stream that reads from the buffer. */
      pb_istream_t instream;
      instream = pb_istream_from_buffer(rx_buffer, MessageLen);

      /* Now we are ready to decode the message. */
      bool status = false;

      status = pb_decode(&instream, msg_fields, dest_struct);

      /* Check for errors... */
      if (status)
      {
        /* Call message handler */
        messageHandlers[MessageID]();
        HUART_RxReq.Buff_Len = PROTOBUFF_HEADER_LEN;
        HUART_ReceiveBuffAsync(&HUART_RxReq);

      }   
    }
    state = 0;
  }
    break;
  }
}


void on_UART_Receive(void)
{
  Proto_Receive();
}


int main(void)
{
  /* Enable clock for GPIOA */
  Set_Clock_ON(GPIOA);
  Set_Clock_ON(GPIOB);
  Set_Clock_ON(USART1);

  /* Init Pins */
  /* Input pins*/
  GPIO_PinConfig_t pin;
  pin.PinMode = GPIO_MODE_INPUT_PULLUP;
  pin.PinSpeed = GPIO_SPEED_MEDIUM;
  pin.Port = GPIOB;
  for(int i  = 0; i < 8; i++)
  {
    pin.PinNumber = i;
    GPIO_initPin(&pin);
  }

  /* Output pins*/
  pin.PinMode = GPIO_MODE_OUTPUT_PUSHPULL_NOPULL;
  pin.PinSpeed = GPIO_SPEED_MEDIUM;
  pin.Port = GPIO_GPIOA;
  for(int i  = 0; i < 8; i++)
  {
    pin.PinNumber = i;
    GPIO_initPin(&pin);
  }  

  /* Initialize hardware UART */
  HUART_Init();

  HUART_RxReq = (HUSART_UserReq_t){
      .USART_ID = USART1_ID,
      .Ptr_buffer = rx_buffer,
      .Buff_Len = PROTOBUFF_HEADER_LEN,
      .Buff_cb = on_UART_Receive,
  };

  HUART_ReceiveBuffAsync(&HUART_RxReq);

  // Main loop
  while (1)
  {
    // Main application code
  }

  /* Print the data contained in the message. */
  // printf("Your lucky number was %d!\n", (int)outmessage.value);
}

void assert_failed(uint8_t *file, uint32_t line)
{
  while (1)
    ;
}
