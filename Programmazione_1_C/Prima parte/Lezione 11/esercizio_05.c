/*
 * Si realizzi un programma in linguaggio C che legga un numero intero "N" e
 * visualizzi un quadrato di * (fino alla diagonale principale inclusa) e
 * + (sopra la diagonale principale) come segue (esempio con N= 5):
 *          * + + + +
 *          * * + + +
 *          * * * + +
 *          * * * * +
 *          * * * * *
 */
#include <stdio.h>

void main ()
{
    int N;
    // N = numero intero

    // Inserimento numero intero
    printf ("Inserire un numero intero: ");
    scanf ("%d", &N);

    // Algoritmo di stampa
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (j > i)
                printf ("+ ");
            else
                printf ("* ");
        printf ("\n");
    }
}