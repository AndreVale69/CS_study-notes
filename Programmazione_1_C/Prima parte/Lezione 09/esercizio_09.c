/*
 * Scrivere un programma che data una matrice quadrata di dimensione 5 verifica
 * che in ogni riga ed in ogni colonna ci siano sempre tutti e soli i valori da
 * 1 a 5, estremi inclusi, e restituisce 1 se la proprietà sussiste,
 * 0 altrimenti.
 */
#include <stdio.h>
#define N 5

void main ()
{
    int matrix [N] [N], count = 0;
    // matrix = matrice
    // count  = contatore di val superiori a 5 o minori di 1 (esclusi)

    /****** Inserimento valori matrice e Controllo proprieta' ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &matrix [i] [j]);
            if (matrix [i] [j] < 1 || matrix [i] [j] > 5)
                count ++;
        }
    
    /****** Stampa risultato ******/
    if (count == 0)
        printf ("La proprieta' sussiste: 1.\n");
    else
        printf ("La proprieta' non sussiste: 0.\n");
}