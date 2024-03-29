# Project Name
TARGET = main

# this is the target pulling libs and project together
.PHONY: first
first: libs all

# include files
C_INCLUDES = -Iinclude -I$(DAISYSP_DIR)/
# C++ files from this project
CPP_SOURCES += $(wildcard src/*.cpp)
# C files - if any
# C_SOURCES += 

# Daisy libraries Location
LIBDAISY_DIR = lib/libdaisy
DAISYSP_DIR = lib/DaisySP

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

# this target will build the two libraries, when needed
.PHONY: libs
libs:
	(cd $(LIBDAISY_DIR); make)
	(cd $(DAISYSP_DIR); make)

# --------------------------------------
# clean the current project and the
# libraries
# --------------------------------------
deepclean: clean
	(cd $(LIBDAISY_DIR); make clean)
	(cd $(DAISYSP_DIR); make clean)

