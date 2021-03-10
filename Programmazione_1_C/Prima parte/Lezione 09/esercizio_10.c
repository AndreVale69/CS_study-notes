/*
 * Si scriva un programma che data una matrice quadrata riempita di soli 0 e 1,
 * stampa:
 * 
 * ● Il numero di sequenze di 1 contenute complessivamente nelle righe della
 *   matrice;
 * ● La lunghezza della sequenza di 1 più lunga;
 * ● La lunghezza della sequenza di 1 più corta.
 */
#include <stdio.h>
#define N 4

void main ()
{
    int matrix [N] [N], count_max = 0, seq_max = 0, count_min, seq_min = N;
    // matrix    = matrice
    // count_max = contatore di sequenze di sequenze di 1 e di 1 piu' lunga
    // seq_max   = risultato sequenza piu' lunga
    // count_min = contatore di sequenza di 1 piu' corta
    // seq_min   = risultato sequenza piu' corta

    /****** Inserimento valori e controllo di 0 e 1 ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &matrix [i] [j]);
            if (matrix [i] [j] < 0 || matrix [i] [j] > 1)
            {
                printf ("Il valore inserito e' errato!\n");
                j --;
            }
        }
    // Si ipotizzi che l'utente metta sia 0 che 1 all'interno della matrice
    
    /****** Contatore di sequenze di uno e Stampa risultato ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++)
            if (matrix [i] [j] == 1 && matrix [i] [j+1] == 1 && matrix [i] [j+2] != 1)
                count_max ++;
    printf ("Il numero di sequenze di 1 contenute sono: %d.\n", count_max);

    /****** Contatore di sequenze di uno e Stampa risultato ******/
    for (int i = 0; i < N; i++)
    {
        count_max = 1;
        count_min = 1;
        for (int j = 0; j < N - 1; j++)
        {
            if (matrix [i] [j] == 1 && matrix [i] [j + 1] == 1)
            {
                count_max ++;
                if (count_max > seq_max)
                    seq_max = count_max;
            }
            else
                count_max = 1;

            if (matrix [i] [j] == 1 && matrix [i] [j + 1] == 1)
            {
                count_min ++;
                if (count_min < seq_min && (matrix [i] [j + 2] == 0 || j + 1 == N - 1))
                    seq_min = count_min;
            }
            else
                count_min = 1;
        }
    }
    printf ("La lunghezza della sequenza di 1 piu' lunga e': %d.\n", seq_max);
    printf ("La lunghezza della sequenza di 1 più corta e': %d.\n", seq_min);
}