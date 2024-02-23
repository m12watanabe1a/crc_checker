######################################
# target
######################################
TARGET = crc8_checker

C_SOURCES =  \
	crc8_checker.cpp


ifdef USE_TABLE
C_DEFS = -DUSE_TABLE
endif

#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(C_SOURCES) Makefile | $(BUILD_DIR)
	g++ $(C_SOURCES) $(C_DEFS) -o $@

$(BUILD_DIR):
	mkdir $@

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
