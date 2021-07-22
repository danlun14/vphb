OBJ_DIR := objectsrc
SRC_DIR := libsrc
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
all: main

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c -o $@  $<

main: main.c $(OBJ_DIR)/other.o $(OBJ_DIR)/myTerminal.o $(OBJ_DIR)/myReadKey.o 
	gcc main.c -o main $(OBJ_DIR)/other.o $(OBJ_DIR)/myTerminal.o $(OBJ_DIR)/myReadKey.o 