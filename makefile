CC=gcc

minesweeper: board.o main.o grid.o input.o
	$(CC) -o minesweeper board.o grid.o main.o input.o
	./minesweeper

board.o: board.c 
	$(CC) -c board.c

grid.o: grid.c
	$(CC) -c grid.c

input.o: input.c
	$(CC) -c input.c

main.o: main.c
	$(CC) -c main.c

clean:
	rm *.o minesweeper