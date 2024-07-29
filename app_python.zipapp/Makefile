
Makeflags += --silent

# project dirs
SRC_DIR = src
BIN_DIR = bin
DEP_DIR = dependencies
CONF_DIR = config

APP = app

# system-wide dirs
HOME_DIR = $(HOME)
PATH_BIN_DIR = $(HOME_DIR)/dev/.bin
PATH_DEP_DIR = $(HOME_DIR)/dev/.dependencies/$(APP)
PATH_CONF_DIR = $(HOME_DIR)/dev/.config/$(APP)

PYTHON = python3
PYFLAGS = -p "/opt/homebrew/bin/python3"

.PHONY: build
build: clean
	echo "building $(APP)..."
	mkdir -p $(BIN_DIR)
	$(PYTHON) -m zipapp $(PYFLAGS) $(SRC_DIR) -o $(BIN_DIR)/$(APP)
	chmod +x $(BIN_DIR)/$(APP)
	echo "done."

.PHONY: init
init:
	echo "initializing project..."
	mkdir -p $(BIN_DIR)
	mkdir -p $(DEP_DIR)
	mkdir -p $(CONF_DIR)
	echo "done."

.PHONY: clean
clean:
	echo "cleaning local bin directory..."
	rm -rf $(BIN_DIR)
	echo "done."

.PHONY: install
install: uninstall
	echo "cnstalling $(APP)..."
	mkdir -p $(PATH_BIN_DIR)
	mkdir -p $(PATH_DEP_DIR)
	mkdir -p $(PATH_CONF_DIR)'
	echo "copying files..."
	cp -r $(BIN_DIR)/$(APP) $(PATH_BIN_DIR) 2>/dev/null || :
	cp -r $(DEP_DIR)/* $(PATH_DEP_DIR) 2>/dev/null || :
	cp -r $(CONF_DIR)/* $(PATH_CONF_DIR) 2>/dev/null || :
	rmdir $(PATH_DEP_DIR) 2>/dev/null || :
	rmdir $(PATH_CONF_DIR) 2>/dev/null || :
	echo "done."

.PHONY: uninstall
uninstall:
	echo "uninstalling $(APP)..."
	rm $(PATH_BIN_DIR)/$(APP)
	rm -rf $(PATH_DEP_DIR)
	rm -rf $(PATH_CONF_DIR)
	echo "done."
