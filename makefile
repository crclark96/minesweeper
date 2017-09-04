CC = gcc
CFLAGS = -g
EXEC = minesweeper
OBJS = board.o main.o grid.o input.o

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm $(OBJS) $(EXEC)
