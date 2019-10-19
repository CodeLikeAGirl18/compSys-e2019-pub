CFLAGS=-Wall -Wextra -pedantic -g
CC=gcc

test_list: test_list.o list.o
	$(CC) test_list.o list.o -o test_list $(CFLAGS)

test_list.o: test_list.c
	$(CC) -c test_list.c $(CFLAGS)

test.o: list.c
	$(CC) -c list.c $(CFLAGS)
