TESTS=test0 test1
EXAMPLES=divisible

CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic -std=gnu99

.PHONY: all test clean ../src.zip

all: $(TESTS) $(EXAMPLES)

transducers.o: transducers.c transducers.h
	$(CC) -c transducers.c $(CFLAGS)

%: %.c transducers.o
	$(CC) -o $@ $^ $(CFLAGS)

var_test:
	gcc var_test.c -o var_test
test: $(TESTS)
	@set e; for test in $(TESTS); do echo ./$$test; ./$$test; done

clean:
	rm -rf $(TESTS) $(EXAMPLES) *.o core

../src.zip:
	make clean
	cd .. && zip src.zip -r src
