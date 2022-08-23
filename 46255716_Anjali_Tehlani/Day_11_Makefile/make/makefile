#INC = ../inc
#SRC = ../src
#OBJ = ../obj
#BIN = ../bin

#CFLAGS = -c -g -Wall
#LFLAGS = -o
#GCC = gcc
#IFLAGS = -I $(INC)
#CVFLAGS = -v --tool=memcheck --leak-check=full --show-reachable=yes --log-file=valclient

#all = $(BIN)/app.exe :
#$(OBJ)/%.o : $(SRC)test_app.c $(SRC)str02.c $(SRC)str03.c
#	$(GCC) $(CFLAGS) $(SRC)/test_app.c $(SRC)/str02.c $(SRC)/str03.c $(SRC)/str04.c $(SRC)/str05.c $(SRC)/str06.c
#	mv *.o ../$(OBJ)

#$(BIN)/app.exe : $(OBJ)/%.o

#clean:
#	rm -f $(OBJ)/*.o $(BIN)/app.exe


INC_DIR := ../inc
SRC_DIR := ../src
OBJ_DIR := ../obj
BIN_DIR := ../bin

EXE := $(BIN_DIR)/app.exe
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CIFLAGS := -I $(INC_DIR)
CFLAGS = -Wall -c -g
LDFLAGS = -Llib
LDLIBS := -lm
CVFLAGS = -v --tool=memcheck --leak-check=full --show-reachable=yes --log-file=valclient

all = $(EXE)

$(EXE) : $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CIFLAGS) $(CFLAGS) $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
#-include $(OBJ:.o=.d)
