from Request_Services import *
import time

#Request_Reset_Pin(GPIOA,PIN0)
Request_Set_Pin(GPIOA,PIN0)

time.sleep(1)

ReadValue = Request_Read_Pin(GPIOA, PIN0)

if ReadValue == STATE_HIGH:
    print("pin1 is set")
    time.sleep(1)
    Request_Set_Pin(GPIOA, PIN1)

print("PROGRAM IS FINISHED**********************************************************")
while(1):
    pass
