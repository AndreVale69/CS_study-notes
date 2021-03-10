/*
 * Scrivere un sottoprogramma C che riceve come parametri due matrici quadrate
 * 4x4 di numeri interi, chiamate m1 e m2.
 * Il sottoprogramma calcola e restituisce al chiamante il numero di volte che
 * il valore m1 [i][j] = m2 [i][j] 
 * 
 * Esempio: Date in ingresso le due matrici il sottoprogramma restituirà il
 *          valore 4.
 * 
 *            9 4 9 2      1 2 3 4
 *            3 4 6 8      3 4 1 1
 *            5 2 3 4      1 1 7 4
 *            3 4 5 2      3 6 7 8
 */
#include <stdio.h>
#define N 4

int sottoprogramma (int m1 [N] [N], int m2[N] [N]);

void main ()
{
    int m1 [N] [N], m2 [N] [N], ris;
    // m1  = prima matrice
    // m2  = seconda matrice
    // ris = risultato delle occorrenze

    // Inserimento valore 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &m1 [i] [j]);
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &m2 [i] [j]);
        }

    // Invocazione sottoprogramma e salvataggio risultato
    ris = sottoprogramma (m1, m2);

    // Stampa del risultato
    printf ("Il risultato e': %d\n", ris);
}

int sottoprogramma (int m1 [N] [N], int m2[N] [N])
{
    int count = 0;
    // count = contatore di occorrenze

    // Controllo numero di occorrenze
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m1 [i] [j] == m2 [i] [j])
                count ++;
    
    // Return del risultato
    return count;
}