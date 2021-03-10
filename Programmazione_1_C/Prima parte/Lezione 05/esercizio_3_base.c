/* Scrivere un programma che dato un array di interi
 * A ed un intero x determina quante occorrenze di x
 * sono in A.
 *
 * Ad esempio se A e':
 * 1, -3, 1, 4, -3, -4, 2, -3
 *
 * 1. se x == 1  il programma stampa 2
 * 2. se x == -3 il programma stampa 3
 * 3. se x == 5  il programma stampa 0
 */

#include <stdio.h>
#define DIM 8

void main ()
{
    int A [DIM], x, flag = 0;

    printf ("Inserire numero da cercare successivamente nell'array: ");
    scanf ("%d", &x);
    // Inserimento numero da confrontare

    for (int i = 0; i < DIM; i++)
    {
        printf ("Inserire un numero: ");
        scanf ("%d", &A [i]);
        // Riempimento dell'array
        
        if (A [i] == x)
            flag ++;
        /* Se il numero e' uguale al numero da confrontare,
           aumento il contatore */
    }
    printf ("Il numero %d compare %d all'interno dell'array.\n", x, flag);
    // Stampo il risultato
}