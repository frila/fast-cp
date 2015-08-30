CC=g++

FLAGS=-Wall

SRC=src
OBJ=obj
BIN=bin
BAUER_PATH = /usr/lib

NAME=fast-cp

INC=-I/opt/gtest/include -Iinc/util -Iinc -Isrc/util -Isrc -I$(DEPINC) -L$(DEPLIB) -L$(BAUERLIB)

FLAGS=-std=c++11 -pthread
OBJS=$(OBJ)/main.o $(OBJ)/arg_parser.o

build: clean dep $(OBJS)
		$(CC) -o $(BIN)/$(NAME) $(OBJS) $(INC) $(FLAGS)

dep:
		mkdir -p obj
		mkdir -p bin

#### building 

$(OBJ)/main.o:
		$(CC) -o $(OBJ)/main.o -c $(SRC)/main.cpp $(INC) $(FLAGS)

$(OBJ)/arg_parser.o:
		$(CC) -o $(OBJ)/arg_parser.o -c $(SRC)/util/arg_parser.cpp $(INC) $(FLAGS)

clean:
		rm -rf $(OBJ) $(BIN)/$(NAME)
