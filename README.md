# pcb-design-project

## Description

This project provides a simple example using nanopb with STM32.

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

 
