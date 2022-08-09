################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EEPROM_program.c \
../ExtEEPROM_program.c \
../Function.c \
../GPIO_program.c \
../I2C_program.c \
../I2Cfun_program.c \
../KEYPAD_program.c \
../LCD_program.c \
../LED_program.c \
../UART_program.c \
../main.c 

OBJS += \
./EEPROM_program.o \
./ExtEEPROM_program.o \
./Function.o \
./GPIO_program.o \
./I2C_program.o \
./I2Cfun_program.o \
./KEYPAD_program.o \
./LCD_program.o \
./LED_program.o \
./UART_program.o \
./main.o 

C_DEPS += \
./EEPROM_program.d \
./ExtEEPROM_program.d \
./Function.d \
./GPIO_program.d \
./I2C_program.d \
./I2Cfun_program.d \
./KEYPAD_program.d \
./LCD_program.d \
./LED_program.d \
./UART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


