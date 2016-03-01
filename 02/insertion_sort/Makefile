.PHONY:clean
CC=gcc
CFLAGS=-Wall -g -DDEBUG
BIN=insertion_sort
OBJS=main.o insertion_sort.o test.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
