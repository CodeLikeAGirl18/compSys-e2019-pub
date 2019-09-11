# OS X users should use additionally gcc-6, gcc will invoke the Clang compiler
CC=cc
CFLAGS=-std=c11 -Wall -Wextra -pedantic -g
PROGRAMS=pi pm pa
LIBS=myprint.c

.PHONY: clean all

all:
	make $(PROGRAMS)

pi: pointer_intro.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $<

pm: pointer_mem.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

pa: pointer_arr.c $(LIBS)
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f $(PROGRAMS)
# Needed to clean OS X debug information}
	rm -fr $(foreach prg,$(PROGRAMS),$(prg).dSYM)
