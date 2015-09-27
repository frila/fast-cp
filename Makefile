CC=g++

FLAGS=-Wall

SRC=src
OBJ=obj
BIN=bin
BAUER_PATH = /usr/lib

NAME=fast-cp

INC=-I/opt/gtest/include -Iinc/util -Iinc/pkg -Iinc -Isrc/util -Isrc/pkg -Isrc 
FLAGS=-std=c++11 -pthread

OBJS=$(OBJ)/main.o $(OBJ)/arg_parser.o $(OBJ)/flag_mapper.o $(OBJ)/flag_copy.o $(OBJ)/flag_option.o $(OBJ)/flag_arguments.o $(OBJ)/copy_options.o $(OBJ)/flag.o $(OBJ)/output.o

build: clean dep $(OBJS)
		$(CC) -o $(BIN)/$(NAME) $(FLAGS) $(OBJS) $(INC) -lbauer
dep:
		mkdir -p obj
		mkdir -p bin

#### building 
$(OBJ)/main.o:
		$(CC) -o $(OBJ)/main.o -c $(SRC)/main.cpp $(INC) $(FLAGS)

$(OBJ)/arg_parser.o:
		$(CC) -o $(OBJ)/arg_parser.o -c $(SRC)/util/arg_parser.cpp $(INC) $(FLAGS)

$(OBJ)/flag.o:
		$(CC) -o $(OBJ)/flag.o -c $(SRC)/pkg/flag.cpp $(INC) $(FLAGS)

$(OBJ)/flag_mapper.o:
		$(CC) $(FLAGS) -o $(OBJ)/flag_mapper.o -c $(SRC)/pkg/flag_mapper.cpp $(INC) 
		
$(OBJ)/flag_copy.o:
		$(CC) -o $(OBJ)/flag_copy.o -c $(SRC)/pkg/flag_copy.cpp $(INC) $(FLAGS)

$(OBJ)/flag_option.o:
		$(CC) -o $(OBJ)/flag_option.o -c $(SRC)/pkg/flag_option.cpp $(INC) $(FLAGS)

$(OBJ)/flag_arguments.o:
		$(CC) -o $(OBJ)/flag_arguments.o -c $(SRC)/pkg/flag_arguments.cpp $(INC) $(FLAGS)

$(OBJ)/copy_options.o:
		$(CC) -o $(OBJ)/copy_options.o -c $(SRC)/pkg/copy_options.cpp $(INC) $(FLAGS)

$(OBJ)/output.o:
		$(CC) -o $(OBJ)/output.o -c $(SRC)/util/output.cpp $(INC) $(FLAGS)

clean:
		rm -rf $(OBJ) $(BIN)/$(NAME)
