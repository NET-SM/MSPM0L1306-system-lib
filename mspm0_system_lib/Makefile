CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

TARGET = firmware
LINKER_DIR = linker
BUILD_DIR = build

CFLAGS =  \
	-mcpu=cortex-m0plus \
	-mthumb \
	-O0 \
	-g \
	-Wall \
	-Iinclude
	
LDFLAGS =  \
	-T $(LINKER_DIR)/mspm0l1306.ld \
	-nostdlib

# Svi izvorni fajlovi
SRCS_ROOT = startup.c main.c
SRCS_SRC    = $(wildcard src/*.c)
SRCS_ALL      = $(SRCS_ROOT) $(SRCS_SRC)

# Kreiraj listu object fajlova u build/
OBJS = $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS_ALL:.c=.o)))

all: $(BUILD_DIR)/$(TARGET).elf \
	  $(BUILD_DIR)/$(TARGET).bin \
	  $(BUILD_DIR)/$(TARGET).hex

# Kreiraj build folder
$(BUILD_DIR):
	mkdir -p $@

# Linkovanje
$(BUILD_DIR)/$(TARGET).elf: $(OBJS) | $(BUILD_DIR)
	$(CC) $(LDFLAGS) $^ -o $@

# Kompajliranje (fajlovi u root folderu)
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Kompajliranje (fajlovi u src folderu)
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Generiranje .bin fajla
$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O binary $< $@

#Generiranje .hex fajla
$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) -O ihex $< $@
	
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean