CC=gcc

minesweeper: board.o
	$(CC) board.o -o minesweeper
	./minesweeper

board.o: board.c
	$(CC) -c board.c

clean:
	rm *.o minesweeper