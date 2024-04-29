import message_pb2
import serial


# Create an instance of the Example message and set its value
example_message = message_pb2.Example()
example_message.value = 0x11223344

# Serialize the message to bytes
serialized_data = example_message.SerializeToString()

# Function to send serialized data over UART (pseudo-code)
def send_over_uart(data):
    # Initialize serial connection
    print(f"data length {serialized_data.__len__()}")
    ser = serial.Serial('COM10', 9600)  # Adjust port and baudrate as needed
    # Write data to UART
    ser.write(int(serialized_data.__len__()))
    ser.write(data)
    # Close serial connection
    ser.close()

# Send the serialized data over UART
send_over_uart(serialized_data)
