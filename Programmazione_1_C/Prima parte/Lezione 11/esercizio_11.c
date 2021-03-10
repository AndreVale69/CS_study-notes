/*
 * Scrivere un programma che acquisisce una sequenza di 8 interi positivi e ne
 * disegna un istogramma ruotato di 90 gradi, utilizzando il carattere *.
 * 
 * Esempio:
 * 
 *      2 5 7 0 5 1 9 3
 * 
 *                  *
 *                  *
 *          *       *
 *          *       *
 *        * *   *   *
 *        * *   *   *
 *        * *   *   * *
 *      * * *   *   * *
 *      * * *   * * * *
 */
#include <stdio.h>
#define N 8

void main ()
{
    int array [N], max = 0;
    // array = array originale
    // max   = valore massimo

    /****** Inserimento valore e Assegnazione massimo ******/
    for (int i = 0; i < N; i++)
    {
        printf ("Inserisci il %d° valore: ", i + 1);
        scanf ("%d", &array [i]);
        if (max < array [i])
            max = array [i];
    }
    
    /****** Stampa prima linea di numeri ******/
    for (int i = 0; i < N; i++)
        printf (" %d ", array [i]);
    printf ("\n\n");

    /****** Stampa degli asterischi ******/
    for (int i = 0; i < N; i++, max --)
    {
        for (int j = 0; j < N; j++)
            if (array [j] == max || array [j] >= max)
                printf (" * ");
            else
                printf ("   ");
        printf ("\n");
    }
}