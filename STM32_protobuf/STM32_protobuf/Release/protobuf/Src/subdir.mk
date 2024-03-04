################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../protobuf/Src/STM32_led.pb.c \
../protobuf/Src/pb_common.c \
../protobuf/Src/pb_decode.c 

OBJS += \
./protobuf/Src/STM32_led.pb.o \
./protobuf/Src/pb_common.o \
./protobuf/Src/pb_decode.o 

C_DEPS += \
./protobuf/Src/STM32_led.pb.d \
./protobuf/Src/pb_common.d \
./protobuf/Src/pb_decode.d 


# Each subdirectory must supply rules for building sources it contributes
protobuf/Src/%.o protobuf/Src/%.su protobuf/Src/%.cyclo: ../protobuf/Src/%.c protobuf/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DPROTOBUF_LED_TIME_CRITICAL -DSTM32H7A3xxQ -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Soma/OneDrive/Villamosmernok/Projektek/PCB_design_project/pcb-design-project/STM32_protobuf/STM32_protobuf/protobuf/Inc" -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-protobuf-2f-Src

clean-protobuf-2f-Src:
	-$(RM) ./protobuf/Src/STM32_led.pb.cyclo ./protobuf/Src/STM32_led.pb.d ./protobuf/Src/STM32_led.pb.o ./protobuf/Src/STM32_led.pb.su ./protobuf/Src/pb_common.cyclo ./protobuf/Src/pb_common.d ./protobuf/Src/pb_common.o ./protobuf/Src/pb_common.su ./protobuf/Src/pb_decode.cyclo ./protobuf/Src/pb_decode.d ./protobuf/Src/pb_decode.o ./protobuf/Src/pb_decode.su

.PHONY: clean-protobuf-2f-Src

