
MAKEFLAGS += --silent

HOME_DIR = $(HOME)
LOC_FILE = $(HOME_DIR)/.loc.json

define ReadLoc
$(shell node -p "require('$(LOC_FILE)').$(1)")
endef

# Project directories, where the local project files are stored
LIB_DIR = library
OBJ_DIR = obj
BIN_DIR = bin
CONFIG_DIR = config
SRC_DIR = src
INC_DIR = include

APP = [[name]]

# All compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I$(INC_DIR) -g
C = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -I$(INC_DIR) -g
LD = g++
LDFLAGS = -L/usr/local/lib -I$(INC_DIR)
LDLIBS = -lm

# All compilable files
CPP_SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.cpp")
C_SRC_FILES += $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_SRC_FILES)) $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_SRC_FILES))

.PHONY: build
build: cleanall $(OBJ_FILES)
	echo "linking objects..."
	$(LD) $(LDFLAGS) $(OBJ_FILES) -o $(BIN_DIR)/$(APP) $(LDLIBS)
	echo "done!"

# Initialize the project
.PHONY: init
init:
	echo "initializing project..."
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(CONFIG_DIR)
	mkdir -p $(LIB_DIR)
	echo "done!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(C) $(CFLAGS) -c $< -o $@

# Run the compiled binary
.PHONY: run
run:
	./$(BIN_DIR)/$(APP)

# Clean all object files
.PHONY: clean
clean:
	echo "cleaning all object files..."
	rm -rf $(OBJ_DIR)/*

# Clean all object files and the binary
.PHONY: cleanall
cleanall:
	echo "cleaning all object files and the binary..."
	rm -rf $(OBJ_DIR)/*
	rm -f $(BIN_DIR)/$(APP)

# if install or uninstall is called, check if the directories exist
ifneq ($(filter install uninstall, $(MAKECMDGOALS)),)
$(if $(call ReadLoc, bin),,$(error ensure there is a .loc.json file in the home directory. if not run `make loc`))
endif

# PATH directories, where system wide binaries are stored
PATH_BIN_DIR = $(call ReadLoc,bin)
P_PATH_LIB_DIR = $(call ReadLoc,library)/$(APP)
P_PATH_CONFIG_DIR = $(call ReadLoc,config)/$(APP)

# Move all binaries to respective directories
.PHONY: install
install: uninstall
	echo "installing library..."
	mkdir -p $(P_PATH_LIB_DIR)
	cp -r $(LIB_DIR)/* $(P_PATH_LIB_DIR) 2>/dev/null || :
	echo "installing binaries..."
	mkdir -p $(PATH_BIN_DIR)
	cp -r $(BIN_DIR)/* $(PATH_BIN_DIR) 2>/dev/null || :
	echo "installing config files..."
	mkdir -p $(P_PATH_CONFIG_DIR)
	cp -r $(CONFIG_DIR)/* $(P_PATH_CONFIG_DIR) 2>/dev/null || :
	echo "removing unnessesary path directories..."
	rmdir $(P_PATH_LIB_DIR) 2>/dev/null || :
	rmdir $(P_PATH_CONFIG_DIR) 2>/dev/null || :
	echo "done!"

# Remove all project files from respective sys-wide directories
.PHONY: uninstall
uninstall:
	echo "uninstalling library..."
	rm -rf $(P_PATH_LIB_DIR)
	echo "uninstalling config files..."
	rm -rf $(P_PATH_CONFIG_DIR)
	for file in $(BIN_DIR)/*; do \
		echo "uninstalling binary (if exists): $$file"; \
		rm -f $(PATH_BIN_DIR)/$$(basename $$file); \
	done
	echo "Done!"

.PHONY: help
help:
	@echo "Usage: make [target]"
	@echo ""
	@echo "Targets:"
	@echo "  build       - Compile the project"
	@echo "  clean       - Clean all object files"
	@echo "  cleanall    - Clean all object files and the binary"
	@echo "  init        - Initialize the project (creates local directories)"
	@echo "  install     - Install the project"
	@echo "  uninstall   - Uninstall the project"
	@echo "  help        - Display this help message"
