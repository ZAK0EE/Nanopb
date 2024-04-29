import message_pb2
import serial


# Create an instance of the Example message and set its value
example_message = message_pb2.Example()
print(example_message.value)
example_message.value = 0x11223344

serialized_data = example_message.SerializeToString()


# Function to send serialized data over UART (pseudo-code)
def send_over_uart(data):
    # Initialize serial connection
    print(f"data length {data.__len__()}")
    ser = serial.Serial('COM10', 9600)  # Adjust port and baudrate as needed
    # Write data to UART
    ser.write(b'\n') # delimiter for the end of the message
    ser.write(data)
    ser.write(b'\n') # delimiter for the end of the message
    # Close serial connection
    ser.close()

# Send the serialized data over UART
send_over_uart(serialized_data)
