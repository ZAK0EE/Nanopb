from Request_Services import *
import time

Request_Set_Pin(GPIOA,PIN0)
time.sleep(5)

Request_Toggle_Pin(GPIOA,PIN1)
time.sleep(5)

Request_Reset_Pin(GPIOA,PIN0)
time.sleep(5)