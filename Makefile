# TODO Look at wildcard syntax
# TODO move target directory to /firmware

# Tool Chain
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
# Used to print flash and ram usage
SIZE = arm-none-eabi-size



# Target
# Name of file when compiled
TARGET = firmware
OBJDIR = build/obj
BINDIR = build/bin


# MCU Architecture Flags
CPU = -mcpu=cortex-m4
FPU = -mfpu=fpv4-sp-d16
FLOAT_ABI = -mfloat-abi=hard


# Compiler Flags
# CFLAGS = Extra flags for C compiler
CFLAGS = \
	$(CPU) $(FPU) $(FLOAT_ABI) \
	-mthumb \
	-O0 \
	-g \
	-Wall \
	-ffunction-sections \
	-fdata-sections \
	$(INCLUDES) \
	-DSTM32G474xx

# Linker Flags
# LDFLAGS = Linker flags
LDFLAGS = \
	$(CPU) $(FPU) $(FLOAT_ABI) \
	-mthumb \
	-T linker/STM32G474RETX_FLASH.ld \
	-Wl,--gc-sections

# Source Files
SRCS = \
	src/main.c \
	src/drivers/rcc.c \
	src/drivers/gpio.c \
	cmsis/Device/system_stm32G4xx/system_stm32g4xx.c \
	startup/startup_stm32g474xx.s \
	include/nucleog474/nucleo_g474.c

# Include Paths
INCLUDES = \
	-Icmsis \
	-Icmsis/Include \
	-Icmsis/Device/system_stm32G4xx \
	-Isrc/drivers \
	-Iinclude/nucleog474


.PHONY: all clean flash debug

all: $(BINDIR)/$(TARGET).elf $(BINDIR)/$(TARGET).bin



# Create build directory if it doesn't exist
$(OBJDIR) $(BINDIR):
	mkdir -p $@


# Object File
OBJS = $(SRCS:%=$(OBJDIR)/%.o)

# Recipe

# Compile C files
$(OBJDIR)/%.c.o: %.c | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble startup files
$(OBJDIR)/%.s.o: %.s | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CPU) $(FPU) $(FLOAT_ABI) -mthumb \
	-c $< -o $@

# Link
$(BINDIR)/$(TARGET).elf: $(OBJS) | $(BINDIR)
	$(CC) $(OBJS) $(LDFLAGS) -o $@
	$(SIZE) $@


# Convert .elf to .bin
$(BINDIR)/$(TARGET).bin: $(BINDIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# Cleaning old files
clean:
	rm -rf build

# Flash using make flash
flash:
	"C:/ST/STM32CubeProg/bin/STM32_Programmer_CLI.exe" -c port=SWD -w $(BINDIR)/$(TARGET).bin 0x08000000 -rst


# Debug using make debug
debug:
	mintty -t "OpenOCD" /bin/bash -c "openocd -s /mingw64/share/openocd/scripts -f interface/stlink.cfg -f target/stm32g4x.cfg; exec bash"
#	mintty -t "GDB" /bin/bash -c "gdb-multiarch $(TARGET).elf; exec bash"
