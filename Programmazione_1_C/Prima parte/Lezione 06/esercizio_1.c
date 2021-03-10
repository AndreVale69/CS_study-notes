/*
 * Scrivere un programma C che memorizza in un array i primi 15 numeri di
 * Fibonacci e li stampa a video.
 * ●    I primi due numeri di Fibonacci, Fib(0) e Fib(1), sono definiti come:
 *          ○ Fib(0) = 1
 *          ○ Fib(1) = 1
 * ●    Il numero di Fibonacci di un valore n>= 2 è:
 *          ○ Fib(n) = Fib(n-2) + Fib(n-1)
 */

#include <stdio.h>
#define DIM 15

void main ()
{
    /****** Dichiarazione variabili ******/
    int array [DIM] = {1};

    /****** Algoritmo Fibonacci ******/
    for (int i = 2; i < DIM; i++)
    {
        array [i] = array [i - 2] + array [i - 1];
        printf ("%d ", array [i]);
    }
    printf ("\n");
}