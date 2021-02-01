# Artifacts definition
SRCDIR=src
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


# Compilation and link options
CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic -std=c++0x $(INCLUDE_DIRS)
LDFLAGS=

# Build all
all:  $(OBJ)

# Build objects files 
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)
	

	
	
	
	
	
	
	
	
	
	
	
