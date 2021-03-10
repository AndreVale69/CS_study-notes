/*
 * Scrivere un programma C che acquisisce un array a1 di 10 interi.
 * Il programma crea e visualizza un nuovo array a2 contenente in ciascuna
 * posizione i: 
 * 
 * ● La somma dei soli valori pari di a1 fino alla posizione i inclusa,
 *   se i è pari.
 * ● Il prodotto dei valori di a1 dispari nelle posizioni tra i e N-1,
 *   se i è dispari.
 * 
 * Per esempio se l’utente inserisce l’array:
 * 1  2  4  2  8  6  7  8  8  1
 * Il programma creerà e visualizzerà l’array:
 * 0  7  6  7  16   7   22   1  38  1
 */
#include <stdio.h>
#define N 10

void main ()
{
    int a1 [N], a2 [N], ris_temp1, ris_temp2;
    // a1        = array originale
    // a2        = array modificata
    // ris_temp1 = risultato temporaneo per la somma
    // ris_temp2 = risultato temporaneo per la moltiplicazione

    /****** Inserimento valori prima array ******/
    for (int i = 0; i < N; i++)
    {
        printf ("Inserire il %d° valore: ", i + 1);
        scanf ("%d", &a1 [i]);
    }
    
    /****** Controllo condizioni e Riempimento seconda array ******/
    for (int i = 0; i < N; i++)
    {
        /* Utilizzo due var perche' la var somma si pue' inizializzare a zero,
           mentre la var moltiplicazione no (un numero moltiplicato per zero,
           fa sempre zero) */
        ris_temp1 = 0;
        ris_temp2 = 1;

        if (i % 2 == 0)
        {
            for (int j = 0; j <= i; j++)
                if (a1 [j] % 2 == 0)
                    ris_temp1 += a1 [j];
            a2 [i] = ris_temp1;
        }
        else
            if (N % 2 == 0)
            {
                for (int j = i; j < N; j++)
                    if (a1 [j] % 2 != 0 || a1 [j] == 0)
                        ris_temp2 *= a1 [j];
                a2 [i] = ris_temp2;
            }
            else
            {
                for (int j = i; j < N - 1; j++)
                    if (a1 [j] % 2 != 0 || a1 [j] == 0)
                        ris_temp2 *= a1 [j];
                a2 [i] = ris_temp2;
            }
    }

    /****** Stampa del risultato ******/
    printf ("\n");
    for (int i = 0; i < N; i++)
        printf ("%d ", a2 [i]);
    printf ("\n");
}