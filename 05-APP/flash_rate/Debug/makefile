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
flash_rate.lss \

FLASH_IMAGE += \
flash_rate.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: flash_rate.elf secondary-outputs

# Tool invocations
flash_rate.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,flash_rate.map -mmcu=atmega32 -o "flash_rate.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

flash_rate.lss: flash_rate.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S flash_rate.elf  >"flash_rate.lss"
	@echo 'Finished building: $@'
	@echo ' '

flash_rate.hex: flash_rate.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex flash_rate.elf  "flash_rate.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: flash_rate.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 flash_rate.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) flash_rate.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
