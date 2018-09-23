CC = g++
OBJ = ./build
SRC = ./src
BIN = ./bin
INC = ./include

PROG = $(BIN)/restaum

CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

OBJS = $(OBJ)/jogo.o $(OBJ)/dado.o $(OBJ)/jogador.o $(OBJ)/main.o

all: mkdirs $(PROG)	

mkdirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/jogo.o: $(SRC)/jogo.cpp $(INC)/jogo.h $(OBJ)/dado.o $(OBJ)/jogador.o
	#Divisao de arquivos do JOGO
	$(CC) $(CPPFLAGS) -c $(SRC)/jogo.cpp -o $(OBJ)/jogo.o 
	#Compulacao de arquivos .cpp e .o do JOGO

$(OBJ)/dado.o: $(SRC)/dado.cpp $(INC)/dado.h
	$(CC) $(CPPFLAGS) -c $(SRC)/dado.cpp -o $(OBJ)/dado.o

$(OBJ)/jogador.o: $(SRC)/jogador.cpp $(INC)/jogador.h $(OBJ)/dado.o 
	#Divisao de arquivos do JOGADOR
	$(CC) $(CPPFLAGS) -c $(SRC)/jogador.cpp -o $(OBJ)/jogador.o 
	#Compulacao de arquivos .cpp e .o do J;OGO

$(OBJ)/main.o: $(SRC)/main.cpp $(OBJ)/jogo.o $(OBJ)/dado.o $(OBJ)/jogador.o 
	#Divisao de arquivos do MAIN
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o 
	#Compulacao de arquivos .cpp e .o do MAIN


clean:
	rm -f $(PROG)/*
	rm -f $(OBJS)/*