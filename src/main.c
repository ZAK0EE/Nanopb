#include "proto/pb_encode.h"
#include "proto/pb_decode.h"
#include "proto/message.pb.h"

#include "MCAL/GPIO/GPIO.h"
#include "HAL/ControlClock/CLK_Control.h"

#include "HAL/HUART/HUART.h"
#include "MCAL/RCC/RCC.h"
uint8_t rx_buffer[100];


HUSART_UserReq_t HUART_RxReq;

void on_UART_Receive(void)
{

    if(HUART_RxReq.Buff_Len == 1)
    {
        HUART_RxReq.Buff_Len = rx_buffer[0];
    }
    else
    {
        /* Allocate space for the decoded message. */
        Example outmessage = Example_init_zero;
        
        /* Create a stream that reads from the buffer. */
        pb_istream_t instream = pb_istream_from_buffer(rx_buffer, HUART_RxReq.Buff_Len);
        
        /* Now we are ready to decode the message. */
        bool status = pb_decode(&instream, Example_fields, &outmessage);
        
        volatile int x = 0;
        x++;
        /* Check for errors... */
        if (!status)
        {
            //printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
            return;
        }
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
        .Ptr_buffer= &rx_buffer,
        .Buff_Len = 6,
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
