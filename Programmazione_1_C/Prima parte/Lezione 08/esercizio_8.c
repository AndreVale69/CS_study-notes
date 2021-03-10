/*
 * Scrivere un programma che permette all’utente di inserire una matrice di
 * valori interi di dimensione NxN (con N pari a 5).
 * Il programma deve poi calcolare e stampare l’indice della colonna in cui la
 * massima differenza (in valore assoluto) ottenuta tra due suoi elementi, sia
 * massima. Nel caso ci sia piu' di una colonna con uguale differenza massima,
 * stamperà l'indice della prima colonna trovata.
 * Ad esempio, se la matrice inserita fosse:
 * 
 *  2  5 10 15 18
 * 11  7  7 20 15
 *  5  5  7 11 22
 *  6  1  3 16 19
 *  7  1  2 10 18
 * 
 * Il programma stampera' l’indice 3: tale colonna ha come massima differenza
 * 10 (diff. tra 20 e 10), ed e' maggiore della differenza massima delle altre
 * quattro colonne, rispettivamente 9, 6, 8 e 7.
 */
#include <stdio.h>
#define N 5

void main ()
{
    int matrix [N] [N], max = 0, min, diff, max_diff = 0, max_ind, i, j;
    // matrix   = matrice
    // max      = valore massimo della colonna
    // min      = valore minimo della colonna
    // diff     = differenza tra max e min (per rendere pie' clean il codice)
    // max_diff = massima differenza raggiunta tra tutte le colonne
    // max_ind  = indice relativo alla differenza massima
    // i        = indice riga/colonna
    // j        = indice colonna/riga

    /****** Riempimento della matrice ******/
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", i + 1, j + 1);
            scanf ("%d", &matrix [i] [j]);
        }
    
    // Inizializzazione del minimo
    min = matrix [0] [0];

    /****** Differenza massima e Relativo indice ******/
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            // Viene cercato il valore massimo
            if (matrix [j] [i] > max)
                max = matrix [j] [i];
            else
                // E minimo
                if (matrix [j] [i] < min)
                    min = matrix [j] [i];
        /* Calcolata differenza e poi confrontata con le differenze delle altre
           colonne. Se differenza assoluta, aggiornata la var e il relativo
           indice. */
        diff = max - min;
        if (diff > max_diff)
        {
            max_diff = diff;
            max_ind = i;
        }
        // Azzeramento delle variabili
        max = 0;
        min = matrix [0] [i + 1];
    }

    /****** Stampa dei risultati ******/
    printf ("L'indice colonna con max differenza: %d\n", max_ind);
    printf ("La differenza massima ottenuta e'  : %d\n", max_diff);
    
}