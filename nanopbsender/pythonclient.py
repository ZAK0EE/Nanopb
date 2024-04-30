import message_pb2
import serial


# Create an instance of the Example message and set its value
headermsg = message_pb2.Msg_Header()
headermsg.msg_ID = 3
headermsg.msg_len = 0


examplemsg = message_pb2.Msg_TogglePin()
examplemsg.Pin_Port = 0 
examplemsg.Pin_Num = 0
serialized_msg = examplemsg.SerializeToString()

headermsg.msg_len = serialized_msg.__len__()
serialized_header = headermsg.SerializeToString()

# Function to send serialized data over UART (pseudo-code)
def send_over_uart(data):
    # Initialize serial connection
    #print(f"data length {data.__len__()}")
    ser = serial.Serial('COM10', 115200)  # Adjust port and baudrate as needed
    # Write data to UART
    ser.write(data)
    # Close serial connection
    ser.close()

# Send the serialized data over UART
send_over_uart(serialized_header)
send_over_uart(serialized_msg)

# Send the serialized data over UART
send_over_uart(serialized_header)
send_over_uart(serialized_msg)

