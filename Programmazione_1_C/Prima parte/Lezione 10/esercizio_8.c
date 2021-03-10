/*
 * Scrivere un programma C che acquisisce un array di 10 interi.
 * Il programma individua e visualizza tutte le sotto-sequenze di lunghezza
 * massima (cioè non contenute in una sotto-sequenza più lunga) e maggiore di 1
 * costituite da soli numeri pari.
 * Per esempio se l’utente inserisce l’array: 1 2 4 3 2 6 6 7 8 1,
 * il programma visualizzerà le due sotto-sequenze: 2 4 e 2 6 6.
 */
#include <stdio.h>
#define N 10

void main ()
{
    int array [N];
    // array = array con valori

    // Richiesta inserimento dei valori
    for (int i = 0; i < N; i++)
    {
        printf ("Inserire il %d° valore: ", i + 1);
        scanf ("%d", &array [i]);
    }
    
    // Algoritmo di controllo
    for (int i = 0; i < N - 1; i++)
        if (array [i] % 2 == 0 && (array [i+1] % 2 == 0 || array [i-1] % 2 == 0))
            printf (" %d ", array [i]);
        else
            printf ("  ");
    // Il programma in questo modo stampera' i valori che sono di una sequenza
    // Altrimenti stampera' uno spazio per dividere i valori
}