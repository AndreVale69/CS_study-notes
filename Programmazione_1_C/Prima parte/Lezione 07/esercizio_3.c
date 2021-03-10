/*
 * Scrivere un programma che memorizza tutte le righe di una matrice di interi
 * 4x6 in un unico array di interi lungo 24.
 */
#include <stdio.h>
#define r 4
#define c 6
#define DIM 24

void main ()
{
    /****** Dichirazione variabili ******/
    int matrice [r] [c], array [DIM], ind = 0;
    // matrice = nome della matrice con r righe e c colonne
    // array   = nome dell'array con dimensione DIM
    // ind     = indice utilizzato per l'array

    /****** Riempimento matrice e array ******/
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf ("Inserire il %d° valore nel %d° colonna: ", j + 1, i + 1);
            scanf ("%d", &matrice [i] [j]);
            array [ind] = matrice [i] [j];
            ind ++;
        }
    }
    
    /****** Stampa risultato ******/
    for (int i = 0; i < DIM; i++)
    {
        printf ("%d ", array [i]);
    }
    printf ("\n");    
}