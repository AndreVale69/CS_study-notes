/*
 * Scrivere un programma C che acquisisce un array a1 di 10 interi.
 * Il programma crea e visualizza un nuovo array a2 contenente in ciascuna
 * posizione i:
 * 
 * ● La somma dei numeri di a1 fino alla posizione i inclusa, se i è pari
 * 
 * ● Il prodotto dei valori di a1 nelle posizioni i e i-1, se i è dispari.
 * 
 * Per esempio se l’utente inserisce l’array: 1 2 4 2 8 6 6 8 8 1
 * Il programma creerà e visualizzerà l’array: 1 2 7 8 17 48 29 48 45 8
 */
#include <stdio.h>
#define N 10

void main ()
{
    int a1 [N], a2 [N], som, flag = 0;
    // a1   = array originale
    // a2   = array somma
    // som  = somma progressiva
    // flag = indice e var per terminare ciclo

    // Inserimento valori nell'array
    for (int i = 0; i < N; i++)
    {
        printf ("Inserire il %d° valore: ", i + 1);
        scanf ("%d", &a1 [i]);
    }

    // Algoritmo di somma e salvataggio risultato in array
    do
    {
        som = 0;
        for (int i = 0; i <= flag; i++)
            som += a1 [i];

        a2 [flag] = som;
        flag ++;
    } while (flag < N);
    
    // Stampa del risultato
    for (int i = 0; i < N; i++)
        printf ("Il %d° valore e': %d\n", i + 1, a2 [i]);
}