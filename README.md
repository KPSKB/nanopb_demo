# pcb-design-project

## Description

This project provides a simple example using nanopb with STM32. 

The requirements were as follows:

- Create UART communication on an STM32 Nucleo eval board.
- Implement two UART commands (STM32 eval board <-> PC) using protobuffers (e.g., LED on/off).
- Use the nanopb library for protobuffer implementation.
- Test the STM32 protobuffer with a PC serial terminal or Python script.
- Perform a flood test: using a PC script, send messages to the STM32 as quickly as possible via UART, ensuring it does not freeze, and if an incorrect message format is sent, there should be no issue with sending the next message.
  
## Project Structure

- **./STM32_protobuf**: This directory contains the STM32CubeIDE project files.
- **./STM32_protobuf/STM32_protobuf/Release/**: This directory contains the binary file.
- **./test/script/**: This directory contains the Python test script.
- **./test/c_app/**: This directory contains a console application to pre-test protobuf source files.
- **./proto_nanopb**: This directory contains the proto file and the generated protobuf source files.

## Prerequisites

- **STM32CubeIDE**: Make sure you have STM32CubeIDE installed to open and modify the STM32CubeIDE project.
- **Python**: Ensure you have Python installed to run the Python test script.
- **Python Packages**: Install the required Python packages using the following commands:
    ```
    pip install protobuf
    pip install pyserial
    ```

## Getting Started

1. **Clone the Repository**: Clone this repository to your local machine using the following command:
    ```
    git clone https://github.com/KPSKB/pcb-design-project.git
    ```

2. **STM32CubeIDE Project**:
    - Open STM32CubeIDE.
    - Navigate to File -> Open Project from File System and select the `./STM32_protobuf/` directory.
	- Make sure to select the appropriate target MCU for your board when creating the project.
	- Build and Flash the Project.

3. **Python Test Script**:
    - Navigate to the `./test/script/` directory.
    - Run the Python test script using the following command:
        ```
        python proto.py
        ```
	- The Python script will guide you through the process and provide instructions as needed.
	
4. **LED States**:
    - Green LED: This can be changed using the proto messages.
    - Yellow LED: Signals that data processing is ongoing.
    - Red LED: Signals possible data loss or error in protobuf decoding.
	
## Test Results

UART communication and LED control using protobuffers are working correctly. Incorrectly formatted messages did not cause any issues. The system remained stable under heavy message loads.

 
