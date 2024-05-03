from Request_Services import *
import time


Request_Reset_Pin(GPIOA,PIN0)
Request_Reset_Pin(GPIOA,PIN1)

Request_Set_Pin(GPIOA,PIN0)
Request_Set_Pin(GPIOA,PIN1)

Request_Reset_Pin(GPIOA,PIN0)
Request_Reset_Pin(GPIOA,PIN1)

Request_Set_Pin(GPIOA,PIN0)
Request_Set_Pin(GPIOA,PIN1)


# Request_Set_Pin(GPIOA,PIN0)

print("the only read")
ReadValue = Request_Read_Pin(GPIOB, PIN0)

# if ReadValue == STATE_HIGH:
#     print("pin1 is set")
#     time.sleep(1)
#     Request_Set_Pin(GPIOA, PIN1)

print("PROGRAM IS FINISHED**********************************************************")
while(1):
    pass
