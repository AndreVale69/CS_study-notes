/*
 * Scrivere un programma che data una matrice intera M [D1] [D2] ed un valore
 * intero x calcoli quante volte x si presenta in M.
 */
#include <stdio.h>
#define r 3
#define c 4

void main ()
{
    /****** Dichiarazioni variabili ******/
    int M [r] [c], x, count = 0;
    // M     = matrice con r righe e c colonne
    // x     = valore da cercare
    // count = var di conteggio

    /****** Riempimento matrice e inserimento x da parte dell'utente ******/
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf ("Inserire il il %d° valore nella %d° riga: ", j + 1, i + 1);
            scanf ("%d", &M [i] [j]);
        }
    }

    printf ("Inserire il valore da cercare: ");
    scanf ("%d", &x);

    /****** Confronto valori e stampa risultato ******/
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (M [i] [j] == x)
                count ++;
        }
    }
    printf ("Il valore %d si presenta %d volte all'interno della matrice %dx%d\n", x, count, r, c);
}