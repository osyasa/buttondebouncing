################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/EXT_DRIVERS/button_driver.c \
../Drivers/EXT_DRIVERS/counter.c \
../Drivers/EXT_DRIVERS/led_driver.c 

OBJS += \
./Drivers/EXT_DRIVERS/button_driver.o \
./Drivers/EXT_DRIVERS/counter.o \
./Drivers/EXT_DRIVERS/led_driver.o 

C_DEPS += \
./Drivers/EXT_DRIVERS/button_driver.d \
./Drivers/EXT_DRIVERS/counter.d \
./Drivers/EXT_DRIVERS/led_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/EXT_DRIVERS/%.o Drivers/EXT_DRIVERS/%.su: ../Drivers/EXT_DRIVERS/%.c Drivers/EXT_DRIVERS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L152xC -c -I../Core/Inc -I../Drivers/EXT_DRIVERS -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-EXT_DRIVERS

clean-Drivers-2f-EXT_DRIVERS:
	-$(RM) ./Drivers/EXT_DRIVERS/button_driver.d ./Drivers/EXT_DRIVERS/button_driver.o ./Drivers/EXT_DRIVERS/button_driver.su ./Drivers/EXT_DRIVERS/counter.d ./Drivers/EXT_DRIVERS/counter.o ./Drivers/EXT_DRIVERS/counter.su ./Drivers/EXT_DRIVERS/led_driver.d ./Drivers/EXT_DRIVERS/led_driver.o ./Drivers/EXT_DRIVERS/led_driver.su

.PHONY: clean-Drivers-2f-EXT_DRIVERS

