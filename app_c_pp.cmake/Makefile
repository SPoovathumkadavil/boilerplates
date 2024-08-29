
MAKEFLAGS += --silent

APP = [[name]]

BUILD_DIR = build
LIB_DIR = library
CONF_DIR = config

.PHONY: build
build: clean
	echo "building release ..."
	cmake -S . -B build -D CMAKE_BUILD_TYPE=Release
	cmake --build build

.PHONY: dev
dev: clean
	echo "building dev"
	cmake --preset=dev
	cmake --build --preset=dev

.PHONY: test
test: dev
	echo "running test"
	ctest --preset=dev

.PHONY: clean
clean:
	echo "cleaning build dir ..."
	rm -rf $(BUILD_DIR)

.PHONY: list
list:
	echo "Available targets:"
	echo "  build - Build the release version"
	echo "  dev   - Build the development version"
	echo "  test  - Run tests"
	echo "  clean - Clean the build directory"
