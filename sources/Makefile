# Rappel : 
# $@ 	Le nom de la cible
# $< 	Le nom de la première dépendance
# $^ 	La liste des dépendances
# $? 	La liste des dépendances plus récentes que la cible
# $* 	Le nom du fichier sans suffixe


# Workspace definitions
export INCLUDE_DIRS=$(shell find . -name include | sed -e 's|\.|-I $(CURDIR)|g')
export OBJDIR=$(CURDIR)/../objects
export BINDIR=$(CURDIR)/../bin
export OUTPUTS_DIRS=$(OBJDIR) $(BINDIR)



# Preparing sub directory makefiles
TOPTARGETS := all

SUBDIRS := raspberry devices main

$(TOPTARGETS): $(SUBDIRS) $(BIN)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)


# Artifacts definition
BIN=rasp-onotes-lib

# Link options
CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic -std=c++0x
LDFLAGS=-lwiringPi

# Build all
all:	$(BIN)

# Building final binary
$(BIN):
	$(CXX) -o $(BINDIR)/$@ $^ $(CXXFLAGS) $(LDFLAGS)
	
	
clean:
	rm $(OBJDIR)/*.o $(BINDIR)/*
 
mrproper:
	rm -rf $(BINDIR) $(OBJDIR)
	
	
$(shell mkdir -p $(OUTPUTS_DIRS))	
	
	
	
	
	
	
	
	
	
	
	
	
