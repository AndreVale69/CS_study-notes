/*
 * Scrivere un programma che chiede all’utente di inserire due sequenze di 5
 * numeri ciascuna (salvandole in 2 array). Il programma stampa a video se la
 * seconda sequenza è una permutazione della prima.
 */

#include <stdio.h>
#define DIM 5

void main ()
{
    /****** Dichiarazione variabili ******/
    int array1 [DIM], array2 [DIM], flag = 0;
    // array1 = primo array
    // array2 = secondo array
    // flag   = var per contare valori identici

    /****** Inserimento valori ******/
    for (int i = 0; i < DIM; i++)
    {
        printf ("Inserire il %d° numero della prima sequenza: ", i + 1);
        scanf ("%d", &array1 [i]);
        // Inserire valori NON nulli
    }
    
    for (int i = 0; i < DIM; i++)
    {
        printf ("Inserire il %d° numero della seconda sequenza: ", i + 1);
        scanf ("%d", &array2 [i]);
        // Inserire valori NON nulli
    }
    
    /****** Algoritmo di controllo ******/
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (array1 [i] == array2 [j])
                flag ++;
        }
    }
    
    /****** Stampa risultati ******/
    if (flag >= 5)
        printf ("La prima sequenza e' una permutazione della seconda.\n");
    else
        printf ("Non c'e' nessuna permutazione.\n");
}