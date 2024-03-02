import STM32_led_pb2 as pb
import serial
import serial.tools.list_ports
import time


# Function for change the state of the led "manually" (with command line)
def switchLedState(ser):

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
            return
        else:
            print("Invalid command!")
            print("Choose from the following commands: 0/1/c : on/off/abort")


# Flood test, blinking LED with a frequency of 1 HZ
def floodTest(ser):

    period_time_ms = 1000

    for i in range(20):

        start_time_ms = time.time() * 1000
        current_time_ms = start_time_ms

        print("ON", end =" ", flush=True)

        # Sending "ON" messages as fast as possible for half period
        while(current_time_ms - start_time_ms < period_time_ms/2):
            ser.write(serialized_on)
            current_time_ms = time.time() * 1000

        print("OFF", end =" ", flush=True)

        # Sending "OFF" messages as fast as possible for half period
        while(current_time_ms - start_time_ms < period_time_ms):
            ser.write(serialized_off)   
            current_time_ms = time.time() * 1000



#*************************************************************************************************************
# SCRIPT STARTS HERE
#*************************************************************************************************************

device_found = False
device_port = None
ports = None


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


# Get list of comports
ports = serial.tools.list_ports.comports()

# Print out available COM ports 
for port, desc, hwid in sorted(ports):
    print("{}: {} [{}]".format(port, desc, hwid))

# Let the user decide, which COM port shall be used
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

switchLedState(ser)
floodTest(ser)

# TEST ENDS HERE


# Close COM port
print("Close port and exit")
ser.close()