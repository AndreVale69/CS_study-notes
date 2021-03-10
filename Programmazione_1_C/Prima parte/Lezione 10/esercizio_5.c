/*
 * Scrivere due sottoprogrammi "maxr" e "maxc" che prendono in ingresso una
 * matrice 3X3 di interi e restituiscono rispettivamente al chiamante l’indice
 * della riga/colonna in cui la somma di tutti gli elementi è massima.
 */
#include <stdio.h>
#define N 3

int maxr (int matrix [N] [N]);
int maxc (int matrix [N] [N]);

void main ()
{
    int matrix [N] [N], r_m, c_m;
    // matrix = matrice
    // r_m    = riga con somma massima
    // c_m    = colonna con somma massima

    // Inserimento valori
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &matrix [i] [j]);
        }
    
    // Invocazione funzione max riga e salvataggio risultato
    r_m = maxr (matrix);

    // Invocazione funzione max colonna e salvataggio risultato
    c_m = maxc (matrix);

    // Stampa dei risultati
    printf ("La riga con la somma più alta e': %d.\n", r_m);
    printf ("La colonna con la somma piu' alta e': %d.\n", c_m);
}

int maxr (int matrix [N] [N])
{
    int r_m, count, max = 0;
    // r_m   = indice da restituire
    // count = contatore progressivo
    // max   = valore da confrontare per stabilire il massimo

    // Algoritmo di somma e assegnazione massimo con relativo indice
    for (int i = 0; i < N; i++)
    {
        count = 0;
        for (int j = 0; j < N; j++)
            count += matrix [i] [j];

        if (count > max)
        {
            max = count;
            r_m = i;
        }
    }
    return r_m;
}

int maxc (int matrix [N] [N])
{
    int c_m, max = 0, count;
    // c_m   = indice da restituire
    // max   = valore da confrontare per stabilire il massimo
    // count = contatore progressivo

    // Stesso algoritmo di "maxr", cambia solo il secondo for.
    // Vengono scambiati gli indici
    for (int i = 0; i < N; i++)
    {
        count = 0;
        for (int j = 0; j < N; j++)
            count += matrix [j] [i];
        
        if (count > max)
        {
            max = count;
            c_m = i;
        }
    }
    return c_m;
}