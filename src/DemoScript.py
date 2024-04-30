import sys
import os

# Add the directory containing the nanopbsender module to the Python path
current_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.dirname(current_dir)
sys.path.append(os.path.join(parent_dir, 'nanopbsender'))
from Request_Services import *
import time
import unittest

class TestScenarios(unittest.TestCase):
    def test_Senario1(self):
        Request_Set_Pin(GPIOA, PIN0)
        time.sleep(5)
        ReadValue = Request_Read_Pin(GPIOA, PIN0)
        self.assertEqual(ReadValue, STATE_HIGH)
    def test_Senario2(self):
        Request_Reset_Pin(GPIOA, PIN0)
        time.sleep(5)
        ReadValue = Request_Read_Pin(GPIOA, PIN0)
        self.assertEqual(ReadValue, STATE_LOW)
    def test_Senario3(self):
        Request_Toggle_Pin(GPIOA, PIN0)
        time.sleep(5)
        ReadValue1 = Request_Read_Pin(GPIOA, PIN0)
        Request_Toggle_Pin(GPIOA, PIN0)
        time.sleep(5)
        ReadValue2 = Request_Read_Pin(GPIOA, PIN0)
        self.assertNotEqual(ReadValue1, ReadValue2)  
    
if __name__ == '__main__':
    unittest.main()