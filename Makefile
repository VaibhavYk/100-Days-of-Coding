# Makefile for Network Utility Program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Windows-specific flags
WINDOWS_LIBS = -lws2_32 -liphlpapi

# Target executable names
TARGET_WINDOWS = network_utility.exe
TARGET_LINUX = network_utility

# Detect OS
ifeq ($(OS),Windows_NT)
    TARGET = $(TARGET_WINDOWS)
    LIBS = $(WINDOWS_LIBS)
    RM = del /Q
else
    TARGET = $(TARGET_LINUX)
    LIBS =
    RM = rm -f
endif

# Source file
SRC = network_utility.c

# Default target
all: $(TARGET)

# Build for Windows
windows:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET_WINDOWS) $(WINDOWS_LIBS)

# Build for Linux
linux:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET_LINUX)

# Generic build
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Clean build artifacts
clean:
	$(RM) $(TARGET_WINDOWS) $(TARGET_LINUX) 2>nul || true

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Network Utility Makefile"
	@echo "========================"
	@echo "Targets:"
	@echo "  all      - Build for current platform (default)"
	@echo "  windows  - Build for Windows"
	@echo "  linux    - Build for Linux"
	@echo "  clean    - Remove build artifacts"
	@echo "  run      - Build and run the program"
	@echo "  help     - Show this help message"
	@echo ""
	@echo "Usage:"
	@echo "  make          # Build for current platform"
	@echo "  make windows  # Build for Windows"
	@echo "  make linux    # Build for Linux"
	@echo "  make run      # Build and run"
	@echo "  make clean    # Clean up"

.PHONY: all windows linux clean run help
