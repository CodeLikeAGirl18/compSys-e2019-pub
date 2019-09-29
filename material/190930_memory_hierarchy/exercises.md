# Exercises for 30/09-2019

Based on exercises by: Michael Kirkedal Thomsen <kirkedal@acm.org>
Minor changes: Finn Schiermer Andersen <schier@diku.dk>

## Finish leftover exercises from last week

I you have unfinished business from last week, finish it first.


## Summing an array

Consider the two programs from the lecture

```C
long sum_array_rows(long a[M][N])
{
    int i, j, sum = 0;

    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            sum += a[i][j];
    return sum;
}
```

```C
long sum_array_cols(long a[M][N])
{
    int i, j, sum = 0;

    for (j = 0; j < N; j++)
	    for (i = 0; i < M; i++)
            sum += a[i][j];
    return sum;
}
```

The programs are included in the `exercise_code` directory.

### Locality

First, recap the two types of locality that we would like to achieve to in order to get good performance. Why does `sum_array_rows` have better locality than `sum_array_cols`? Which types of locality does the programs have?

### Performance

Try to run the programs on increasing sizes until you can see a difference. You can use `time(1)` to get a quick measurement of the execution time.

Map the execution time for increasing sizes of input. Compare the two programs. What is the asymptotic behaviour? Calculate the execution time per element. 

How does it compare to the operations per element that we discussed at the lecture? You need to examine the assembler code to know the exact number for this.

Hint, I can suggest that you setup a simple test-bench (e.g. using a script) that makes the above calculations, but don't spend too much time on it.

## Summing a 3D array

Consider the following program taken from the slides (note, the indices on the slides are messed up, so this is more correct).

```
long sum_array_3d(long a[L][M][N])
{
  long sum = 0;
  int i, j, k;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < L; k++) {
        sum += a[k][i][j];
      }
    }
  }
  return sum;
}
```

### Locality
Sketch what the structure of a 3D array will be like in the 1D memory of the computer. What should be the order of the indices be to achieve spacial locality?

### Performance

Write the above into a C program that you can run. You can base it on the previous examples.

Test with different ordering of the indices to very verify your previous result.

Take care to prevent the compiler from completely optimizing away your computation.

