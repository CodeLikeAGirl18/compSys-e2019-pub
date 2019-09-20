# Exercises for 16/9-2019

Author: Michael Kirkedal Thomsen <kirkedal@acm.org>


### More compilation quirks
`a_sum.c` is a simple function calculating five times the sum of a `0` terminated list of `long`s using pointer arithmetic. Using `gcc` this is translated into the assembler code in `a_sum.s`. Locate the non-control statements (lines 4, 5, 7, 8 and 9) of `a_sum.c` in `a_sum.s`. For each what differs from the expected translation and try to consider why? Remember that input registers are `%rdi`, `%rsi`, etc. and output is `%rax` only.

Remember that:
  - function parameter registers are `%rdi`, `%rsi`, and so on (BOH p. 216).
  - return value register is `%rax` (BOH p. 216).
  - in x86prime, %r11 is the return address register.

Note: for now, please ignore lines 3-4 and 15-16 of `a_sum.prime`, as these instructions relate to the stack pointer, which we will save for later.

#### Solution
  * Line 4 -> line 9: `movl $0, %eax` using the 32-bit version instead of 64-bit due to a more compact encoding.
  * Line 5 -> line 8: Swapped with previous line. The is expected to have a better pipelined/ooo execution, but they don't know that yet.
  * Line 7 -> line 12+13: Uses `leaq` for arithmetic as you can multiply with 5 in one instruction; `addq` cannot and `imulq` uses up to 4 clock-cycles.
  * Line 8 -> line 14: Adds 8 instead of 1. Remember we use pointer arithmetic and a long is 8 bytes.
  * Line 9 -> line 15: Loads as expected.