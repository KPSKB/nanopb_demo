import STM32_led_pb2 as pb
import serial
import serial.tools.list_ports

# Function for change the state of the led "manually" (with command line)
def switchLedState():

    print("Choose from the following commands: 0/1/c : on/off/abort")

    while(True):

        command = str(input("Next command: "))

        if command == str(0):
            ser.write(serialized_off)
            print( "LED off " + "(" + str(serialized_off) +")" )
        elif command == str(1):
            ser.write(serialized_on)
            print( "LED on " + "(" + str(serialized_on) +")" )
        elif command == str('c'):
            print("Close port and exit")
            return
        else:
            print("Invalid command!")
            print("Choose from the following commands: 0/1/c : on/off/abort")



# Encode message for turn LED ON
message_on = pb.ChangeLedStateMsg()
message_on.led_state = 1
serialized_on = message_on.SerializeToString()
print(serialized_on)

# Encode message for turn LED OFF
message_off = pb.ChangeLedStateMsg()
message_off.led_state = 0
serialized_off = message_off.SerializeToString()
print(serialized_off)


# Let the user choose the COM port of the device
device_found = False
device_port = 0
ports = serial.tools.list_ports.comports()

for port, desc, hwid in sorted(ports):
    print("{}: {} [{}]".format(port, desc, hwid))

if len(port) > 0:
    while(True):
        device_to_test = str(input("Which device shall be tested? (COMx or ctrl+c to abort script) "))
        for port, desc, hwid in sorted(ports):
            if port == device_to_test:
                device_found = True
                device_port = port
                print("Start test")
        if device_found:
            break
        else:
            print('Device not found, please check if your input format is correct. Correct format: "COMx" , where x is the number of the COM port.')

# Open the selected COM port
ser = serial.Serial(port, 115200)

# TEST STARTS HERE

switchLedState()

#TEST ENDS HERE

# Close COM port
ser.close()




