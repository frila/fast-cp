CC=g++

FLAGS=-Wall

SRC=src
OBJ=obj
BIN=bin
BAUER_PATH = /usr/lib

NAME=fast-cp

INC=-I/opt/gtest/include -I../inc -Isrc -I$(DEPINC) -L$(DEPLIB) -L$(BAUERLIB)

FLAGS=-std=c++11 -pthread
OBJS=$(OBJ)/main.o

build: dep $(OBJS)
		$(CC) -o $(BIN)/$(NAME) $(OBJS) $(INC) $(FLAGS)

dep:
		mkdir -p obj
		mkdir -p bin

#### building test source
$(OBJ)/main.o:
		$(CC) -o $(OBJ)/main.o -c $(SRC)/main.cpp $(INC) $(FLAGS)

clean:
		rm -rf $(OBJ) $(BIN)/$(NAME)
