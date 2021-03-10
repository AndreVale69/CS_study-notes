// Scrivere un programma C che richiede all’utente 
// 10 voti (compresi tra 18 e 30) e li memorizza 
// all’interno di un array, quindi stampa l’array, il 
// voto massimo, minimo e medio.

#include <stdio.h>
#define DIM 10

void main ()
{
    int array [DIM], i, max = 0, min, med = 0;
    // array = nome array
    // i     = indice
    // max   = variabile con il massimo
    // min   = variabile con il minimo
    // med   = variabile con la media

    for (i = 0; i < DIM; i++)
    {
        printf ("Inserire un valore: ");
        scanf ("%d", &array[i]);
        // riempimento array con valori da parte dell'utente

        if ((array[i] > 30) || (array[i] < 18))
        {
            printf ("Valore errato, prego reinserire il valore.\n\n");
            i --;
        }
        // controllo voto se minore 18 e maggiore 30
    }
    
    min = array [0];
    // assegno al minimo il primo valore dell'array

    for (i = 0; i < DIM; i++)
    {
        printf ("%d ", array[i]);
        if (i == 9)
            printf ("\n");
        // stampa array

        if (array [i] > max)
            max = array [i];
        // controllo del valore massimo ed eventuale assegnazione

        if (array [i] < min)
            min = array [i];
        // controllo del valore minimo ed eventuale assegnazione

        med += array [i];
        // somma di tutti i valori dell'array
    }
    med /= 10;
    printf ("La MEDIA dei voti e': %d\n", med);
    // esegue media e stampa media dell'array

    printf ("Il voto MASSIMO e': %d\n", max);
    // stampa voto massimo

    printf ("Il voto MINIMO e': %d\n", min);
    // stampa voto minimo
}