# Rappel : 
# $@ 	Le nom de la cible
# $< 	Le nom de la première dépendance
# $^ 	La liste des dépendances
# $? 	La liste des dépendances plus récentes que la cible
# $* 	Le nom du fichier sans suffixe


# Workspace definitions
SRCDIR=src
HEADDIR=include
OBJDIR=object
BINDIR=bin

OUTPUTS_DIRS=$(OBJDIR) $(BINDIR)


# Artifacts definition

SRC= $(wildcard $(SRCDIR)/*.c)
OBJ= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
BIN=rasp-onotes-lib

# Compilation and link options
CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic -std=c++0x
LDFLAGS=-lwiringPi

# Build all
all:  $(BIN)

# Building final binary
$(BIN): $(OBJ)
	$(CXX) -o $(BINDIR)/$@ $^ $(CXXFLAGS) $(LDFLAGS)
	
	
# Build objects files 
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CXX) -o $@ -c $< $(CFLAGS)
	
clean:
	rm $(OBJDIR)/*.o $(BINDIR)/*
 
mrproper:
	rm -rf $(BINDIR) $(OBJDIR)
	
	
$(shell mkdir -p $(OUTPUTS_DIRS))	
	
	
	
	
	
	
	
	
	
	
	
	
