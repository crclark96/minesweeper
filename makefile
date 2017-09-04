CC = gcc
EXEC = minesweeper
OBJS = board.o main.o grid.o input.o

$(EXEC): $(OBJS)
	$(CC) -o $@ $^

run: $(EXEC)
	./$(EXEC)

clean:
	rm $(OBJS) $(EXEC)
