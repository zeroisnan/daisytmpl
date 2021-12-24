# If RACK_DIR is not defined when calling the Makefile, default to four directories above
# this can be also modified here for good
RACK_DIR ?= $(abspath ../../../thirdparty/Rack-SDK)

# workspace root dir
WORKSPACE_DIR = $(abspath ../)

# path to the libraries
# enter an absolute path, or make the path absolute using $(abspath) such that
# the lower level VCV Rack makefile can calculate the buil path correctly - not
# doing so would result in object files getting created outside of build. Final
# output would still work, but it would leave behind leftovers to be cleaned
# manually 
DAISYSP_DIR  = $(abspath ../lib/DaisySP)
DAISYSP_INC = $(addprefix -iquote , $(shell find $(DAISYSP_DIR)/Source -type d))

# FLAGS will be passed to both the C and C++ compiler
FLAGS += $(DAISYSP_INC)
FLAGS += -I$(WORKSPACE_DIR)/include
CFLAGS +=
CXXFLAGS +=

# Careful about linking to shared libraries, since you can't assume much about the user's environment and library search path.
# Static libraries are fine, but they should be added to this plugin's build system.
LDFLAGS +=

# Add .cpp files to the build
SOURCES += $(wildcard src/*.cpp)
# all project C++ files except main
SOURCES += $(filter-out %main.cpp, $(wildcard $(WORKSPACE_DIR)/src/*.cpp))
SOURCES += $(wildcard $(DAISYSP_DIR)/Source/*/*.cpp)

# Add files to the ZIP package when running `make dist`
# The compiled plugin and "plugin.json" are automatically added.
DISTRIBUTABLES += res
DISTRIBUTABLES += $(wildcard LICENSE*)

# Include the Rack plugin Makefile framework
include $(RACK_DIR)/plugin.mk
