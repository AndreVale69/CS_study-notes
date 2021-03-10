/*
 * Scrivere un programma che data una matrice int A [M][M] esegua la sommatoria
 * di tutti gli elementi che si trovano sopra la diagonale principale.
 */
#include <stdio.h>
#define M 5

void main ()
{
    int A [M] [M] =
    {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    }, som = 0;
    // A   = matrice
    // som = var somma

    /****** Inserimento valori nella matrice ******/
    for (int r = 0; r < M; r++)
        for (int c = 0; c < M; c++)
        {
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", r + 1, c + 1);
            scanf ("%d", &A [r] [c]);
        }

    /****** Somma dei valori sopra la diagonale ******/
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            if (j > i)
                som += A [i] [j];
   
   /****** Stampa ******/
   printf ("La somma di tutti gli elementi che si trovano sopra la diagonale e': %d\n", som);
}