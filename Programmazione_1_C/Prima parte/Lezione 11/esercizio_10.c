/*
 * Scrivere un programma che acquisisce un array di 10 numeri interi.
 * Il programma, terminata l’acquisizione, "muove" tutti i valori diversi da 0
 * alla sinistra dell’array, e tutti gli zeri a destra dell’array.
 * Al termine il programma visualizza l’array seguito dal numero di valori non
 * nulli in esso presenti.
 * Non è importante l’ordine degli elementi non nulli.
 * Esempio:
 * 
 * Ingresso: 1 0 2 0 0 3 4 0 3 2
 * Uscita  : 1 4 2 3 3 2 0 0 0 0 (o anche un diverso ordine dei primi 6 valori) 6
 */
#include <stdio.h>
#define N 10

void main ()
{
    int array [N], flag;

    /****** Inserimento valori ******/
    for (int i = 0; i < N; i++)
    {
        printf ("Il %d° valore: ", i + 1);
        scanf ("%d", &array [i]);
    }

    /****** Stampa array originale ******/
    printf ("\nL'array inserito:\n\n");
    for (int i = 0; i < N; i++)
        printf ("%d ", array [i]);
    printf ("\n");

    /****** Spostamento valori ******/
    for (int i = 0; i < N; i++)
    {
        if (array [i] == 0)
            for (int j = i, flag = 0; j < N && flag == 0; j++)
                if (array [j] != 0)
                {
                    array [i] = array [j];
                    array [j] = 0;
                    flag = 1;
                }
    }

    /****** Stampa array modificato ******/
    printf ("\nL'array modificato:\n\n");
    for (int i = 0; i < N; i++)
        printf ("%d ", array [i]);
    printf ("\n");
}