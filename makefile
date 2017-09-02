CC=gcc

minesweeper: board.o main.o
	$(CC) board.o main.o -o minesweeper
	./minesweeper

board.o: board.c
	$(CC) -c board.c

main.o: main.c
	$(CC) -c main.c

clean:
	rm *.o minesweeper