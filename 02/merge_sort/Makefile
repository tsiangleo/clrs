.PHONY:clean
CC=gcc
CFLAGS=-Wall -g -DDEBUG
BIN=merge_sort
OBJS=main.o merge_sort.o test.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o $(BIN)
