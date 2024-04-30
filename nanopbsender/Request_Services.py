import message_pb2
import serial
import time

# Define COM number of serial port
COM_NUM = 'COM10'
SERIAL_BAUD_RATE = 115200

GPIOA = 0x0
GPIOB = 0x1

PIN0 = 0x0
PIN1 = 0x1
PIN2 = 0x2
PIN3 = 0x3
PIN4 = 0x4
PIN5 = 0x5
PIN6 = 0x6
PIN7 = 0x7

Service_Set_Pin = 0x2
Service_Reset_Pin = 0x0
Service_Read_Pin = 0x1
Service_Toggle_Pin = 0x3


# Function to send serialized data over UART (pseudo-code)
def send_over_uart(data):
    # Initialize serial connection
    print(f"data length {data.__len__()}")
    ser = serial.Serial(COM_NUM, SERIAL_BAUD_RATE)  # Adjust port and baudrate as needed
    # Write data to UART
    ser.write(data)
    # Close serial connection
    ser.close()

def receive_over_uart(size):
    # Initialize serial connection
    ser = serial.Serial(COM_NUM, SERIAL_BAUD_RATE)  # Adjust port and baudrate as needed
    # Read data from UART
    received_data = ser.read(size)  # Adjust the number of bytes to read as needed
    # Close serial connection
    ser.close()
    return received_data

def Request_Set_Pin(Port, PinNum):
    # Create an instance of the Example message and set its value
    Header_Msg = message_pb2.Msg_Header()
    SetPin_Msg = message_pb2.Msg_SetPin()

    SetPin_Msg.Pin_Port = Port
    SetPin_Msg.Pin_Num = PinNum
    serialized_SetPin = SetPin_Msg.SerializeToString()

    Header_Msg.msg_ID = Service_Set_Pin
    Header_Msg.msg_len = serialized_SetPin.__len__()
    serialized_header = Header_Msg.SerializeToString()

    print(f"Header_Msg.msg_ID:{Header_Msg.msg_ID}")
    print(f"Header_Msg.msg_len:{Header_Msg.msg_len}")
    print(f"SetPin_Msg.Pin_Port:{SetPin_Msg.Pin_Port}")
    print(f"SetPin_Msg.Pin_Num:{SetPin_Msg.Pin_Num}")

    send_over_uart(serialized_header)
    time.sleep(0.001)
    send_over_uart(serialized_SetPin)
    time.sleep(0.001)

def Request_Reset_Pin(Port, PinNum):
    # Create an instance of the Example message and set its value
    Header_Msg = message_pb2.Msg_Header()
    ResetPin_Msg = message_pb2.Msg_ResetPin()

    ResetPin_Msg.Pin_Port = Port
    ResetPin_Msg.Pin_Num = PinNum
    serialized_ResetPin = ResetPin_Msg.SerializeToString()

    Header_Msg.msg_ID = Service_Reset_Pin
    Header_Msg.msg_len = serialized_ResetPin.__len__()
    serialized_header = Header_Msg.SerializeToString()

    print(f"Header_Msg.msg_ID:{Header_Msg.msg_ID}")
    print(f"Header_Msg.msg_len:{Header_Msg.msg_len}")
    print(f"ResetPin_Msg.Pin_Port:{ResetPin_Msg.Pin_Port}")
    print(f"ResetPin_Msg.Pin_Num:{ResetPin_Msg.Pin_Num}")

    send_over_uart(serialized_header)
    time.sleep(0.001)
    send_over_uart(serialized_ResetPin)
    time.sleep(0.001)

def Request_Toggle_Pin(Port, PinNum):
    # Create an instance of the Example message and set its value
    Header_Msg = message_pb2.Msg_Header()
    Toggle_Msg = message_pb2.Msg_TogglePin()

    Toggle_Msg.Pin_Port = Port
    Toggle_Msg.Pin_Num = PinNum
    serialized_TogglePin = Toggle_Msg.SerializeToString()

    Header_Msg.msg_ID = Service_Toggle_Pin
    Header_Msg.msg_len = serialized_TogglePin.__len__()
    serialized_header = Header_Msg.SerializeToString()

    print(f"Header_Msg.msg_ID:{Header_Msg.msg_ID}")
    print(f"Header_Msg.msg_len:{Header_Msg.msg_len}")
    print(f"Toggle_Msg.Pin_Port:{Toggle_Msg.Pin_Port}")
    print(f"Toggle_Msg.Pin_Num:{Toggle_Msg.Pin_Num}")

    send_over_uart(serialized_header)
    time.sleep(0.001)
    send_over_uart(serialized_TogglePin)
    time.sleep(0.001)

def Request_Read_Pin(Port, PinNum):
    # Create an instance of the Example message and set its value
    Header_Msg = message_pb2.Msg_Header()
    ReadPin_Msg = message_pb2.Msg_ReadPin()

    ReadPin_Msg.Pin_Port = Port
    ReadPin_Msg.Pin_Num = PinNum
    serialized_ReadPin = ReadPin_Msg.SerializeToString()

    Header_Msg.msg_ID = Service_Reset_Pin
    Header_Msg.msg_len = serialized_ReadPin.__len__()
    serialized_header = Header_Msg.SerializeToString()

    print(f"Header_Msg.msg_ID:{Header_Msg.msg_ID}")
    print(f"Header_Msg.msg_len:{Header_Msg.msg_len}")
    print(f"ReadPin_Msg.Pin_Port:{ReadPin_Msg.Pin_Port}")
    print(f"ReadPin_Msg.Pin_Num:{ReadPin_Msg.Pin_Num}")

    send_over_uart(serialized_header)
    time.sleep(0.001)
    send_over_uart(serialized_ReadPin)
    time.sleep(0.001)


    

# Send the serialized data over UART
#send_over_uart(serialized_data)