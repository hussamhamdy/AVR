################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../System/03-HAL/03-???SEVSEG/SEVSEG_program.c 

OBJS += \
./System/03-HAL/03-???SEVSEG/SEVSEG_program.o 

C_DEPS += \
./System/03-HAL/03-???SEVSEG/SEVSEG_program.d 


# Each subdirectory must supply rules for building sources it contributes
System/03-HAL/03-???SEVSEG/%.o: ../System/03-HAL/03-???SEVSEG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


