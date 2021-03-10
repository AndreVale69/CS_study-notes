/*
 * Scrivere un programma che dato un array di interi (lungo 10) con i valori
 * inseriti da tastiera determina quanti massimi locali ci sono nell’array
 * stampando il risultato.
 * 
 * ○ Dato l’array  intA[10]; A[i] è detto massimo locale se uno dei seguenti
 * casi è verificato:
 *      1. i = 0 e A [0] > A [1]
 *      2. i = 9 e A [8] < A [9] 
 *      3. 0 < i < 9 e A [i - 1] < A [i] < A [i + 1]
 */

#include <stdio.h>
#define DIM 10

void main ()
{
    /****** Dichiarazione variabili ******/
    int array [DIM], max = 0;
    // array = nome array
    // max   = var che conta quanti max locali ci sono

    /****** Algoritmo max locali ******/
    for (int i = 0; i < DIM; i++)
    {
        printf ("Inserire il %d° valore: ", i + 1);
        scanf ("%d", &array [i]);
    }
    if (array [0] > array [1])
        max ++;
    if (array [8] < array [9])
        max ++;
    for (int i = 1; i < DIM - 1; i++)
    {
        if (array [i - 1] < array [i] && array [i] < array [i + 1])
            max ++;
    }
    printf ("Ci sono %d massimi locali.\n", max);
}