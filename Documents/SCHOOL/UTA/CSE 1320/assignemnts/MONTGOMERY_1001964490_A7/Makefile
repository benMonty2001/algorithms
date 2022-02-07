PROJECT_NAME := program

SRC_DIR := src
UTILS_DIR := $(SRC_DIR)/utils

UTIL_FILES := $(wildcard $(UTILS_DIR)/*.c) 
PROJECT_FILES := $(wildcard $(SRC_DIR)/*.c)

DEBUG_FLAGS := -g -Wall -O0 -DDEBUG=1 -lm
LINK := -lm

BUILD_DIR := build
RELEASE := $(BUILD_DIR)/$(PROJECT_NAME)
DEBUG_BUILD := $(BUILD_DIR)/$(PROJECT_NAME)_debug

release: $(PROJECT_FILES) $(UTIL_FILES)
	mkdir -p $(BUILD_DIR)
	gcc $^ -o $(RELEASE) $(LINK)

debug: $(PROJECT_FILES) $(UTIL_FILES)
	mkdir -p $(BUILD_DIR)
	gcc -p $(DEBUG_FLAGS) $^ -o $(DEBUG_BUILD) 

clean:
	rm -rf $(BUILD_DIR)