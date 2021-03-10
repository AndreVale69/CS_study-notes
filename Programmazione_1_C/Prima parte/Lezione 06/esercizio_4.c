/*
 * Scrivere un programma C che:
 * ○ Richiede all’utente di inserire 20 numeri interi a piacere e li salva in un
 *   array.
 * ○ Crea e stampa un array risultato in cui:
 *      ● Ogni elemento in posizione pari (n) è uguale alla somma degli
 *        elementi dell’array originale in posizione pari dall’inizio fino a n.
 * 
 *      ● Ogni elemento in posizione dispari (m) è uguale alla somma degli
 *        elementi dell’array originale in posizione dispari dall’inizio fino
 *        a m.
 */
#include <stdio.h>
#define DIM 20

void main ()
{
    /****** Dichiarazione variabili ******/
    int array [DIM], arr_ris [DIM], sum = 0;
    // array   = nome array da riempire da parte dell'utente
    // arr_ris = nome array da riempire con i risultati
    // sum     = nome della somma nelle varie posizioni

    /****** Inserimento valori ******/
    for (int i = 0; i < DIM; i++)
    {
        printf ("Inserire il %d° numero : ", i + 1);
        scanf ("%d", &array [i]);
        arr_ris [i] = array [i];
    }
    
    /****** Algoritmo somma posizioni pari e dispari ******/
    for (int i = 0; i < DIM; i++)
    {
        if (i % 2 == 0 && i > 1)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j % 2 == 0)
                    sum += array [j];                
            }
            arr_ris [i] = sum;            
            sum = 0;
        }
        else
        {
            if (i % 2 != 0 && i > 1)
            {
                for (int j = 0; j <= i; j++)
                {
                    if (j % 2 != 0)
                        sum += array [j];                
                }
                arr_ris [i] = sum;            
                sum = 0;
            }
            else
            {
                arr_ris [0] = array [0];
                arr_ris [1] = array [1];
            }
        }
    }
    for (int i = 0; i < DIM; i++)
    {
        printf ("%d ", arr_ris [i]);
    }
    printf ("\n");
}