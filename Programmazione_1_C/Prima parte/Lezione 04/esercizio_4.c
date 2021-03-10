// Scrivere un programma che stampa a video la tavola 
// pitagorica (un quadrato con le tabelline dei numeri da 
// 1 a 10).

#include <stdio.h>
#define dim 11

int main ()
{
    for (int i = 1; i < dim; i++)
    {
        for (int j = 1; j < dim; j++)
        {
            printf ("%d ", i*j); // moltiplicazione diretta
        }
        printf ("\n");
    }
    // solo algoritmo senza uso di una terza variabile
}