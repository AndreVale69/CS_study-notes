/*
 * Scrivere un programma C che chiede all’utente un numero intero n.
 * 
 * Il programma inizializza il contenuto della matrice seguendo il seguente
 * schema:
 * 
 * n   n+1 n+2 n+3 n+4
 * n+1 n+1 n+2 n+3 n+4
 * n+2 n+2 n+2 n+3 n+4
 * n+3 n+3 n+3 n+3 n+4
 * n+4 n+4 n+4 n+4 n+4
 * 
 * Per esempio se n=5, il programma popolerà la matrice come segue:
 * 5 6 7 8 9
 * 6 6 7 8 9
 * 7 7 7 8 9
 * 8 8 8 8 9
 * 9 9 9 9 9
 */
#include <stdio.h>
#define M 5

void main ()
{
    int matrix [M] [M], n_int;
    // matrix = matrice in cui salvare i risultati
    // n_int = numero intero inserito dall'utente

    // Inserimento di n_int
    printf ("Inserire il numero intero: ");
    scanf ("%d", &n_int);

    /****** Algoritmo di somma e riempimento matrice ******/
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            if (j < i)
                matrix [i] [j] = n_int + i;
            else
                matrix [i] [j] = n_int + j;

    /****** Stampa matrice ******/
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf ("%d ", matrix [i] [j]);
        }
        printf ("\n");
    }
}