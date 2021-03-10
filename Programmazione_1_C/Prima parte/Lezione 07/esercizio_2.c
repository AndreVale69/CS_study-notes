/*
 * Scrivere un programma che data una matrice quadrata intera M [D] [D] calcoli
 * la sua trasposta intera N [D] [D].
 * NB: N è la trasposta di M se N [i] [j] = M [j] [i] per ogni j ∈ [0, D - 1] e
 *     i ∈ [0, D - 1]
 * M:                 N:
 *   1  3  2 -1         1  4  2  2
 *   4  1  5  5         3  1  1  4
 *   2  1  0  7         2  5  0  1
 *   2  4  1  5        -1  5  7  5
 */
#include <stdio.h>
#define D 4

void main ()
{
    /****** Dichiarazione variabili ******/
    int M [D] [D];
    // M = nome array

    /****** Riempimento array da parte dell'utente ******/
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < D; j++)
        {
            printf ("Inserire il %d° valore nella %d° riga: ", j + 1, i + 1);
            scanf ("%d", &M [i] [j]);
        }
    }
    
    /****** Stampa risultato senza usare array di sussidio ******/
    printf ("La sua trasposta sara': \n\n");
    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < D; j++)
        {
            printf (" %d ", M [j] [i]);
        }
        printf ("\n");
    }
}