// Scrivere un programma che dato un array di 
// caratteri lungo 10 (con i valori letti da standard 
// input) lo stampa, lo stampa invertito, sostituisce 
// ogni vocale minuscola con un ’*’.

#include <stdio.h>
#define DIM 10

void main ()
{
    char array [DIM], i;
    // array = nome array
    // i     = indice

    for (i = 0; i < DIM; i++)
    {
        printf ("Inserire un carattere: ");
        scanf (" %c", &array [i]);
    }
    // riempimento array da parte dell'utente

    for (i = 0; i < DIM; i++)
    {
        printf ("%c ", array [i]);
        if (i == 9)
            printf ("\n");
    }
    // stampa standard dell'array

    for (i = 0; i < DIM; i++)
    {
        printf ("%c ", array [DIM - 1 - i]);
        if (i == 9)
            printf ("\n");
    }
    // stampa invertita dell'array

    for (i = 0; i < DIM; i++)
    {
        if ((array [i] > 96) && (array [i] < 123))
            array [i] = '*';
        printf ("%c ", array [i]);
        if (i == 9)
            printf ("\n");
    }
    // sostituzione di * e stampa array
}