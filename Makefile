# Rappel : 
# $@ 	Le nom de la cible
# $< 	Le nom de la première dépendance
# $^ 	La liste des dépendances
# $? 	La liste des dépendances plus récentes que la cible
# $* 	Le nom du fichier sans suffixe







PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
SRC= $(wildcard src/*.cpp)
OBJ= $(SRC:.cpp=.o)
EXEC=rasp-onotes-lib
BUILD_DIR=build

CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic -std=c++0x
LDFLAGS=-lwiringPi


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)


%.o: %.c
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
