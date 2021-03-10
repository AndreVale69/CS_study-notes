/*
 * Scrivere un sottoprogramma C che riceve come parametri due matrici quadrate
 * 4x4 di numeri interi, chiamate "m1" e "m2". Il sottoprogramma calcola e
 * restituisce al chiamante il numero di volte che il valore m1[i][j]>m2[i][j].
 */
#include <stdio.h>
#define N 4

int sottoprogramma (int m1 [N] [N], int m2 [N] [N]);

void main ()
{
    int m1 [N] [N], m2 [N] [N], ris;
    // m1  = prima matrice
    // m2  = seconda matrice
    // ris = risultato

    /****** Inserimento prima matrice ******/
    printf ("\nInserire la prima matrice\n\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire valore %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &m1 [i] [j]);
        }
    
    /****** Inserimento seconda matrice******/
    printf ("\nInserire la seconda matrice\n\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire valore %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &m2 [i] [j]);
        }

    /****** Invocazione funzione e Salvataggio risultato ******/
    ris = sottoprogramma (m1, m2);

    /****** Stampa risultato ******/
    printf ("La prima matrice ha %d valori maggiori rispetto alla seconda matrice\n", ris);
}

int sottoprogramma (int m1 [N] [N], int m2 [N] [N])
{
    int ris = 0;
    // ris = risultato

    /****** Verifica e Conteggio risultato ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m1 [i] [j] > m2 [i] [j])
                ris ++;
    // Return del risultato
    return ris;
}