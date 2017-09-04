CC=gcc

minesweeper: board.o main.o grid.o input.o
	$(CC) -o minesweeper board.o grid.o main.o input.o
	./minesweeper

clean:
	rm *.o minesweeper
