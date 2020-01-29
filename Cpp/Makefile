# ------------------------------------------------
# Makefile for Opencv projects
# ------------------------------------------------
# TODO(elsuizo: 2016-12-03) add debugg options
# project name (generate executable with this name)
TARGET   = out

COMPILER=g++ -std=c++11
# compiling flags here
CFLAGS   = -std=c99 -Wall -I.

# Opencv flags
CPPFLAGS = $(shell pkg-config --cflags opencv4)
LDLIBS = $(shell pkg-config --libs opencv4)

# linking flags here
LINKER   = g++ -o
LFLAGS   = -Wall -I. -lm

# Directories
SRCDIR   = src
INCDIR   = inc
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(COMPILER) $(CPPFLAGS) $(LDLIBS) $(OBJECTS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(COMPILER) $(CPPFLAGS) $(LDLIBS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
