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
TOG_LED.lss \

FLASH_IMAGE += \
TOG_LED.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TOG_LED.elf secondary-outputs

# Tool invocations
TOG_LED.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TOG_LED.map -mmcu=atmega32 -o "TOG_LED.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TOG_LED.lss: TOG_LED.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TOG_LED.elf  >"TOG_LED.lss"
	@echo 'Finished building: $@'
	@echo ' '

TOG_LED.hex: TOG_LED.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TOG_LED.elf  "TOG_LED.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TOG_LED.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TOG_LED.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TOG_LED.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
