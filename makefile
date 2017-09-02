CC=gcc

minesweeper: board.o main.o grid.o
	$(CC) -o minesweeper board.o grid.o main.o 
	./minesweeper

board.o: board.c
	$(CC) -c board.c

grid.o: grid.c
	$(CC) -c grid.c

main.o: main.c
	$(CC) -c main.c

clean:
	rm *.o minesweeper