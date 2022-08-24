CC = gcc
CFLAGS = -Wall -c -g
SRC := ../src
INC:=../inc
BIN:=../bin
LIB:=../lib
DATA:=../data
OBJ:=../obj
IFLAGS:=-I$(INC)


all: $(BIN)/app.exe $(DATA)./input.txt $(DATA)./out.txt

$(OBJ)/test.o : $(SRC)/test.c $(INC)/remove_duplicates.h
	$(CC) $(CFLAGS) $(SRC)/test.c $(IFLAGS)
	mv test.o $(OBJ)/

$(BIN)/app.exe : $(OBJ)/test.o $(OBJ)/remove_duplicates.o
	$(CC) -Wall -o app.exe $(OBJ)/test.o $(OBJ)/remove_duplicates.o
	mv app.exe $(BIN)/




