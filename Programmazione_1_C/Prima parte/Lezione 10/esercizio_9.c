/*
 * Scrivere una funzione che data una matrice char M [p][q] copi tutti gli
 * elementi di M in un array lungo p*q nell’ordine
 */
#include <stdio.h>
#define p 4
#define q 5

void main ()
{
    char M [p] [q], M_copy [p*q];
    int flag = 0;
    // M      = matrice originale
    // M_copy = array con ordine richiesto
    // flag   = var indice per array M_copy

    /****** Inserimento caratteri ******/
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf ("Inserire il carattere in %dx%d (RxC): ", i+1, j+1);
            scanf (" %c", &M [i] [j]);
        }
        printf ("\n");
    }
    
    /****** Algoritmo inserimento nell'array ******/
    do
    {
        for (int i = 0; i < q; i++)
            for (int j = 0; j < p; j++)
            {
                if (i % 2 == 0 || i == 0)
                    M_copy [flag] = M [j] [i];
                else
                    M_copy [flag] = M [(p - 1) - j] [i];
                flag ++;
            }
    // Eseguito finche' l'indice rispetta i limiti
    } while (flag < p*q);

    /****** Stampa risultato ******/
    for (int  i = 0; i < p*q; i++)
        printf ("%c ", M_copy [i]);
    printf ("\n");
}