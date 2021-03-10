/*
 * In un concorso di bruttezza, n giudici esprimono il loro giudizio su m
 * candidati. Il giudizio è un valore numerico tra 0 e 5 (più alto il voto più
 * brutto il candidato). I risultati sono organizzati in una matrice int matrix [N][M].
 * Si scriva un programma in linguaggio C per determinare il candidato più
 * brutto ed il giudice più cattivo (ovvero quello che attribuisce i più alti
 * voti di bruttezza).
 * Si supponga di non considerare il parimerito, quindi nessun punteggio dei
 * giudici o dei candidati sarà identico (al momento della somma).
 */

#include <stdio.h>
#define N 3 // Numero giudici
#define M 5 // Numero candidati

void main ()
{
    int matrix [N] [M];
    int arr_supp [N + M], som = 0, cattivo = 0, brutto = 0;
    int ind_bru, ind_cat;
    // matrix   = matrice originale con risultati
    // arr_supp = matrice con somme dei risultati di candidati e giudici
    // som      = var somma per effettuare somma all'interno dell'algoritmo calcolo
    // cattivo  = var per assegnare il piu' cattivo
    // brutto   = var per assegnare il piu' brutto
    // ind_bru  = indice utile per individuare il piu' brutto
    // ind_cat  = indice utile per individuare il piu' cattivo

    /****** Inserimento giudici e candidati ******/
    printf ("Al concorso hanno partecipato 5 candidati e hanno giudicato 3 giudici.\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf ("Inserire il %d° punteggio, per il %d° candidato, assegnato dal %d giudice: ", j + 1, j + 1, i + 1);
            scanf ("%d", &matrix [i] [j]);
        }
        printf ("\n");
    }

    /****** Calcolo punteggio giudici ******/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            som += matrix [i] [j];
        arr_supp [i] = som;
        som = 0;
    }

    /****** Calcolo punteggio candidati ******/
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            som += matrix [j] [i];
        arr_supp [N + i] = som;
        som = 0;
    }

    /****** Calcolo punteggio giudici ******/
    for (int i = 0; i < N; i++)
        if (cattivo < arr_supp [i])
        {
            cattivo = arr_supp [i];
            ind_cat = i + 1;
        }
    
    /****** Calcolo punteggio candidati ******/
    for (int i = N; i < N + M; i++)
    {
        if (brutto < arr_supp [i])
        {
            brutto = arr_supp [i];
            ind_bru = i - (N - 1);
        }
    }
    
    /****** Stampa risultati ******/
    for (int i = N; i < N + M; i++)
        printf ("Il %d° candidato ha ottenuto un punteggio totale di %d.\n", i - (N - 1), arr_supp [i]);
    printf ("\n");
    for (int i = 0; i < N; i++)
        printf ("Il %d° giudice ha dato un totale di %d punti.\n", i + 1, arr_supp [i]);
    printf ("\n");
    printf ("Il candidato numero %d e' il piu' brutto: %d.\n", ind_bru, brutto);
    printf ("Il giudice numero %d e' il piu' cattivo: %d.\n", ind_cat, cattivo);
}