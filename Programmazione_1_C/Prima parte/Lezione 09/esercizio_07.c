/*
 * Scrivere un programma che date tre matrici A, B, C delle stesse dimensioni,
 * e modifica C in modo che al termine dell'esecuzione si abbia C = A + B.
 * Le matrici non sono necessariamente quadrate, ma devono avere tutte la
 * stessa dimensione, in modo che sia possibile calcolarne la somma.
 * Definire le dimensioni delle matrici con una costante simbolica.
 */
#include <stdio.h>
#define N 4
// Definizione di una costante

void main ()
{
    int A [N] [N], B [N] [N], C [N] [N];
    // Dichiarazione di matrici quadrate (per semplicita')
    // A = prima matrice
    // B = seconda matrice
    // C = terza matrice (risulto dell'addizione)

    /****** Richiesta inserimento e Salvataggio somma ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire nella matrice A il valore in posizione %dx%d (RxC): ", i + 1, j + 1);
            scanf ("%d", &A [i] [j]);
            printf ("\n");
            printf ("Inserire nella matrice B il valore in posizione %dx%d (RxC): ", i + 1, j + 1);
            scanf ("%d", &B [i] [j]);
            printf ("\n");
            C [i] [j] = A [i] [j] + B [i] [j];
        }
    
    /****** Stampa risultato della somma tra matrici ******/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf ("%d ", C [i] [j]);
        printf ("\n");
    }
}