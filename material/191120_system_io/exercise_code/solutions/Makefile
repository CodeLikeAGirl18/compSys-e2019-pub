gcc=gcc -I../../ -g -Werror -Wpedantic -Wall -pthread -o
csapp=../../csapp.c ../../csapp.h

all: fstatcheck cpfile cpfile_infile

fstatcheck: fstatcheck.c
	$(gcc) fstatcheck fstatcheck.c $(csapp)

cpfile: cpfile.c
	$(gcc) cpfile cpfile.c $(csapp)

cpfile_infile: cpfile_infile.c
	$(gcc) cpfile_infile cpfile_infile.c $(csapp)


clean: 
	rm -f cpfile fstatcheck cpfile_infile
