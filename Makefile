CC=g++

FLAGS=-Wall

SRC=src
OBJ=obj
BIN=bin
BAUER_PATH = /usr/lib

NAME=fast-cp

INC=-I/opt/gtest/include -Iinc/util -Iinc/pkg -Iinc -Isrc/util -Isrc/pkg -Isrc 
FLAGS=-std=c++11 -pthread
OBJS=$(OBJ)/main.o $(OBJ)/arg_parser.o $(OBJ)/progress_bar.o $(OBJ)/flag_mapper.o $(OBJ)/flag_copy.o $(OBJ)/flag_option.o $(OBJ)/flag_arguments.o $(OBJ)/copy_options.o $(OBJ)/flag.o $(OBJ)/output.o $(OBJ)/recv_options.o $(OBJ)/flag_recv.o $(OBJ)/master.o $(OBJ)/slave.o $(OBJ)/replicate_option.o $(OBJ)/flag_replicate.o

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

$(OBJ)/progress_bar.o:
		$(CC) -o $(OBJ)/progress_bar.o -c $(SRC)/util/progress_bar.cpp $(INC) $(FLAGS)

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

$(OBJ)/recv_options.o:
		$(CC) -o $(OBJ)/recv_options.o -c $(SRC)/pkg/recv_options.cpp $(INC) $(FLAGS)

$(OBJ)/flag_recv.o:
		$(CC) -o $(OBJ)/flag_recv.o -c $(SRC)/pkg/flag_recv.cpp $(INC) $(FLAGS)

$(OBJ)/master.o:
		$(CC) -o $(OBJ)/master.o -c $(SRC)/pkg/master.cpp $(INC) $(FLAGS)

$(OBJ)/slave.o:
		$(CC) -o $(OBJ)/slave.o -c $(SRC)/pkg/slave.cpp $(INC) $(FLAGS)

$(OBJ)/replicate_option.o:
		$(CC) -o $(OBJ)/replicate_option.o -c $(SRC)/pkg/replicate_option.cpp $(INC) $(FLAGS)

$(OBJ)/flag_replicate.o:
		$(CC) -o $(OBJ)/flag_replicate.o -c $(SRC)/pkg/flag_replicate.cpp $(INC) $(FLAGS)

clean:
		rm -rf $(OBJ) $(BIN)/$(NAME)
