################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
GRAD_PRO_I2C.lss \

FLASH_IMAGE += \
GRAD_PRO_I2C.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: GRAD_PRO_I2C.elf secondary-outputs

# Tool invocations
GRAD_PRO_I2C.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,GRAD_PRO_I2C.map -mmcu=atmega32 -o "GRAD_PRO_I2C.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

GRAD_PRO_I2C.lss: GRAD_PRO_I2C.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S GRAD_PRO_I2C.elf  >"GRAD_PRO_I2C.lss"
	@echo 'Finished building: $@'
	@echo ' '

GRAD_PRO_I2C.hex: GRAD_PRO_I2C.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex GRAD_PRO_I2C.elf  "GRAD_PRO_I2C.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: GRAD_PRO_I2C.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t GRAD_PRO_I2C.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) GRAD_PRO_I2C.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
