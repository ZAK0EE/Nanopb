from Request_Services import *
import time

Request_Set_Pin(GPIOA,PIN0)
time.sleep(5)

ReadValue = Request_Read_Pin(GPIOA, PIN0)

if ReadValue == STATE_HIGH:
    Request_Set_Pin(GPIOA, PIN1)
