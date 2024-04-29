#include <pb_encode.h>
#include <pb_decode.h>
#include "proto/message.pb.h"

#include "MCAL/GPIO/GPIO.h"
#include "HAL/ControlClock/CLK_Control.h"

#include "HAL/HUART/HUART.h"
#include "MCAL/RCC/RCC.h"

uint8_t rx_buffer[100] = {0};
int rxidx = 0;
uint8_t UART_ReceivedByte;

HUSART_UserReq_t HUART_RxReq;

int mystate = 0;

void OutputPins_handler()
{
     pb_istream_t instream;
    instream = pb_istream_from_buffer(rx_buffer, rxidx);

    /* Now we are ready to decode the message. */
    bool status = false;

    status = pb_decode(&instream, Example_fields, &outmessage); 
}
void on_UART_Receive(void)
{


  if(HUART_RxReq.Ptr_buffer[0] == '\n')
  {

   /* Allocate space for the decoded message. */
    Example outmessage = Example_init_zero;
    
    /* Create a stream that reads from the buffer. */
    pb_istream_t instream;
    instream = pb_istream_from_buffer(rx_buffer, rxidx);

    /* Now we are ready to decode the message. */
    bool status = false;

    status = pb_decode(&instream, Example_fields, &outmessage);
    
    /* Check for errors... */
    if (!status)
    {
        //printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        
    }
    else
    {
      // my message is
      volatile int x;
      x++;
    }
    rxidx = 0; // reset the buffer

  }
  else
  {
    rx_buffer[rxidx++] = HUART_RxReq.Ptr_buffer[0];
  }

}

int main(void)
{
    /* Enable clock for GPIOA */
    Set_Clock_ON(GPIOA);
    Set_Clock_ON(GPIOB);
    Set_Clock_ON(USART1);
    /* Initialize hardware UART */
    HUART_Init();
    
     HUART_RxReq = (HUSART_UserReq_t)
    {
        .USART_ID = USART1_ID,
        .Ptr_buffer= &UART_ReceivedByte,
        .Buff_Len = 1,
        .Buff_cb = on_UART_Receive,
    };
    
    HUART_ReceiveBuffAsync(&HUART_RxReq);


  // Main loop
  while (1)
  {
    // Main application code
  }


    // Example inmessage = {32};
    // uint8_t buffer[10] = {0};
    // pb_ostream_t outstream = pb_ostream_from_buffer(buffer, sizeof(buffer));
    // pb_encode(&outstream, Example_fields, &inmessage);

    
  
    
    /* Print the data contained in the message. */
    //printf("Your lucky number was %d!\n", (int)outmessage.value);
     
}

void assert_failed(uint8_t* file, uint32_t line)
{
    while (1);
    
}
