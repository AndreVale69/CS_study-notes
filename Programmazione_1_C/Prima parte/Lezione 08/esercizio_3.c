/*
 * Scrivere un programma che data una matrice int A [M][M] verifichi se per
 * ogni elemento x della diagonale principale esiste un elemento y della 
 * diagonale secondaria tale che y>x.
 */
#include <stdio.h>
#define M 5

void main ()
{
    int A [M] [M], i = 0;
    // A = matrice
    // i = indice

    /****** Inserimento valori nella matrice ******/
    for (int r = 0; r < M; r++)
        for (int c = 0; c < M; c++)
        {
            printf ("Inserisci il valore nella posizione %dx%d (RxC): ", r + 1, c + 1);
            scanf ("%d", &A [r] [c]);
        }

    /****** Algoritmo di scorrimento della matrice ******/
    do
    {
        if (i < 5)
            if (A [i] [i] < A [i] [M - i - 1])
                printf ("Il valore %d rispetta la condizione\n", A [i] [M - i - 1]);
        else
            if (i == 5 && A [i] [i] < A [i] [M - i])
                printf ("Il valore %d rispetta la condizione\n", A [i] [M - i]);
        i ++;
    } while (i <= M);
    // Eseguito finche' i e' minore o uguale a M
}