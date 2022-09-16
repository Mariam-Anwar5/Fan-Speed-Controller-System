################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PWM_driver.c \
../adc.c \
../gpio.c \
../lcd.c \
../lm35_sensor.c \
../motor_driver.c \
../project3.c 

OBJS += \
./PWM_driver.o \
./adc.o \
./gpio.o \
./lcd.o \
./lm35_sensor.o \
./motor_driver.o \
./project3.o 

C_DEPS += \
./PWM_driver.d \
./adc.d \
./gpio.d \
./lcd.d \
./lm35_sensor.d \
./motor_driver.d \
./project3.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


