################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO_program.c \
../Hbridge_program.c \
../I2C_program.c \
../LED_program.c \
../STP_program.c \
../main.c 

OBJS += \
./GPIO_program.o \
./Hbridge_program.o \
./I2C_program.o \
./LED_program.o \
./STP_program.o \
./main.o 

C_DEPS += \
./GPIO_program.d \
./Hbridge_program.d \
./I2C_program.d \
./LED_program.d \
./STP_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


