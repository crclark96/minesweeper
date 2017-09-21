CC = gcc
CFLAGS = -g -std=c99 -Wsequence-point -Wcast-qual
EXEC = minesweeper
OBJS = board.o main.o grid.o input.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm $(OBJS) $(EXEC)
