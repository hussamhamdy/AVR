################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EXTI_program.c \
../GPIO_program.c \
../LED_program.c \
../SWITCH_program.c \
../main.c 

OBJS += \
./EXTI_program.o \
./GPIO_program.o \
./LED_program.o \
./SWITCH_program.o \
./main.o 

C_DEPS += \
./EXTI_program.d \
./GPIO_program.d \
./LED_program.d \
./SWITCH_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


