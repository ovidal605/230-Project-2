SRC = adventure.c items.c rooms.c avatar.c input.c
OBJ = adventure.o items.o rooms.o avatar.o input.o
PROG = a.out

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)
