gcc=gcc -I../ -g -Werror -Wpedantic -Wall -pthread -o
csapp=../csapp.c ../csapp.h

all: fstatcheck cpfile

fstatcheck: fstatcheck.c
	$(gcc) fstatcheck fstatcheck.c $(csapp)

cpfile: cpfile.c
	$(gcc) cpfile cpfile.c $(csapp)

clean: 
	rm -f cpfile fstatcheck
