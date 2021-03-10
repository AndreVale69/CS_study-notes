/*
 * Data una matrice quadrata int M [N] [N], copiare tutti i suoi elementi in un
 * vettore lungo N^2 secondo in un ordine particolare
 */
#include <stdio.h>
#define N 6
#define L (N * 4) - 4
/* Definisco prima la grandezza della matrice qudrata attraverso la
   dichiarazione di N = 6. Successivamente definisco la grandezza del vettore
   che dovra' "ospitare" i numeri della matrice quadrata. La definizione viene
   effettuata tramite un'equazione banale che permette di considerare solo le
   celle esterne (cornice).
 */

void main ()
{
    int M [N] [N] = 
    {
        {1, 2, 6, 7, 15, 16},
        {3, 5, 8, 14, 17, 26},
        {4, 9, 13, 18, 25, 27},
        {10, 12, 19, 24, 28, 33},
        {11, 20, 23, 29, 32, 34},
        {21, 22, 30, 31, 35, 36}
    };
    int vettore [L], k = 0;
    // M       = nome matrice quadrata (già definita)
    // vettore = nome del vettore
    // k       = nome indice per il vettore

    vettore [k] = M [k] [k];
    k ++;
    // Il primo valore della matrice viene inserito nel primo posto del vettore

    for (int i = 0; i < N && k < L; i++)

        for (int j = 1; j < N && k < L; j++)
        // Eseguo i due for per scorrere la matrice

            if (i == 0) // Se i e' zero posso eseguire questo algoritmo
                if (j % 2 != 0)
                {
                    vettore [k] = M [i] [j];
                    k ++;
                    vettore [k] = M [j] [i];
                    k ++;
                }
                else
                {
                    vettore [k] = M [j] [i];
                    k ++;
                    vettore [k] = M [i] [j];
                    k ++;
                }
            else // Altrimenti devo eseguirne un altro algoritmo
            {
                j = N - 1;
                // Imposto la var j al massimo (forzatura)

                if (i % 2 == 0)
                {
                    vettore [k] = M [i] [j];
                    k ++;
                    vettore [k] = M [j] [i];
                    k ++;
                }
                else
                {
                    vettore [k] = M [j] [i];
                    k ++;
                    vettore [k] = M [i] [j];
                    k ++;
                }
            }
    
    for (int i = 0; i < L; i++)
        printf ("%d ", vettore [i]);
    // Stampa
}