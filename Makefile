######################################
# target
######################################
TARGET = crc8_checker

C_SOURCES =  \
	crc8_checker.cpp

#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(C_SOURCES) Makefile
	g++ $(C_SOURCES) -o $@

$(BUILD_DIR):
	mkdir $@

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
