################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/animations.c 

CPP_SRCS += \
../Src/jLog.cpp \
../Src/main.cpp \
../Src/stm32f1xx_hal_msp.cpp \
../Src/stm32f1xx_it.cpp \
../Src/system_stm32f1xx.cpp \
../Src/ws2812.cpp 

OBJS += \
./Src/animations.o \
./Src/jLog.o \
./Src/main.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/system_stm32f1xx.o \
./Src/ws2812.o 

C_DEPS += \
./Src/animations.d 

CPP_DEPS += \
./Src/jLog.d \
./Src/main.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/system_stm32f1xx.d \
./Src/ws2812.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F103xE -I"/home/jeremy/stm-workspace/led/led/Inc" -I"/home/jeremy/stm-workspace/led/led/Drivers/STM32F1xx_HAL_Driver/Inc" -I"/home/jeremy/stm-workspace/led/led/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"/home/jeremy/stm-workspace/led/led/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"/home/jeremy/stm-workspace/led/led/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F103xE -I"/home/jeremy/stm-workspace/led/led/Inc" -I"/home/jeremy/stm-workspace/led/led/Drivers/STM32F1xx_HAL_Driver/Inc" -I"/home/jeremy/stm-workspace/led/led/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"/home/jeremy/stm-workspace/led/led/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"/home/jeremy/stm-workspace/led/led/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


