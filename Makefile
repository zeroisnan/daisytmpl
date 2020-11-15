# Project Name
TARGET = main

# Sources
C_INCLUDES = -Iinclude
CPP_SOURCES = $(wildcard src/*.cpp)

# Daisy libraries Location
LIBDAISY_DIR = lib/libdaisy
DAISYSP_DIR = lib/DaisySP

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

libs: $(LIBDAISY_DIR)/build/libdaisy.a $(DAISYSP_DIR)/build/libdaisysp.a
$(LIBDAISY_DIR)/build/libdaisy.a:
	(cd $(LIBDAISY_DIR); make)

$(DAISYSP_DIR)/build/libdaisysp.a:
	(cd $(DAISYSP_DIR); make)

# --------------------------------------
# clean the current project and the
# libraries
# --------------------------------------
deepclean: clean
	(cd $(LIBDAISY_DIR); make clean)
	(cd $(DAISYSP_DIR); make clean)

