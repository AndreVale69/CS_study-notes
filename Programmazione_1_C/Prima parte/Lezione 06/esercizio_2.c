/*
 * Scrivere un programma C che memorizza in un array di lunghezza 15 tutti i
 * numeri primi minori di 50 e successivamente li stampa a video.
 * 
 *      ● Un numero x è primo se è diverso da 1 ed ha come unici divisori 1
 *        ed x.
 *      
 *      ● NB 0 non è primo in quanto ogni numero divide 0
 */

#include <stdio.h>
#define DIM 15

void main ()
{
    /****** Dichiarazione variabili ******/
    int array [DIM], cont = 2, flag = 0, j = 0;
    // array = nome array
    // cont  = numero da confrontare ogni volta
    // flag  = var per uscire dal controllo dei numeri primi
    // j     = indice per inserire i numeri primi nell'array

    /****** Algoritmo per numeri primi ******/
    for (int i = 2; i < 51; i++)
    {
        while (cont < i && flag == 0)
        {
            if (i % cont == 0)
                flag ++;
            cont ++;
        }
        if (flag == 0)
        {
            array [j] = i;
            printf ("%d ", array [j]);
            j ++;
        }
        else
            flag = 0;
        cont = 2;
    }
    printf("\n");
}