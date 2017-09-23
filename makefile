CC = gcc
CFLAGS = -g -std=c99 -Wsequence-point -Wcast-qual -Wuninitialized
EXEC = minesweeper
OBJS = board.o main.o grid.o input.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(OBJS) $(EXEC)
