# Exercises for 19/9-2018

Author: Michael Kirkedal Thomsen <kirkedal@acm.org>

These exercises will:
* Recap basic instructions
* Translation of C to assembler and x86prime
* Work with assembler in C

## Memory calculation and operation on register file
* BOH 3.1  (page 218)
* BOH 3.2  (page 221)
* BOH 3.3  (page 222)
* BOH 3.8  (page 230)

## Understanding translations
* BOH 3.5  (page 225)
* BOH 3.10 (page 232)
* BOH 3.11 (page 233)

### More compilation quirks
`a_sum.c` is a simple function calculating five times the sum of a `0` terminated list of `long`s using pointer arithmetic. Using `gcc` this is translated into the assembler code in `a_sum.s`. Locate the non-control statements (lines 4, 5, 7, 8 and 9) of `a_sum.c` in `a_sum.s`. For each what differs from the expected translation and try to consider why? Remember that input registers are `%rdi`, `%rsi`, etc. and output is `%rax` only.


