/*
 * Si scriva un programma in linguaggio C per calcolare il valore massimo e
 * minimo di un insieme di "n" numeri inseriti da tastiera.
 * Il programma deve leggere il valore di "n", ed in seguito deve leggere una
 * sequenza di "n" numeri. A questo punto il programma deve stampare il massimo
 * ed il minimo tra i numeri inseriti.
 */
#include <stdio.h>

void main ()
{
    int num, num_prog, flag = 0, max = 0, min;
    // num      = numero di numeri da inserire
    // num_prog = numero progressivo della sequenza
    // flag     = numero di conteggio del ciclo
    // max      = numero massimo della sequenza
    // min      = numero minimo della sequenza

    /****** Inserimento numero di numeri da inserire ******/
    printf ("Inserire il numero di numeri da inserire: ");
    scanf ("%d", &num);
    printf ("\n");

    /****** Inserimento sequenza valori e Controllo min e max ******/
    while (flag < num)
    {
        printf ("Inserire il %d° valore della sequenza: ", flag + 1);
        scanf ("%d", &num_prog);
        
        if (flag == 0)
            min = num_prog;
        
        if (num_prog > max)
            max = num_prog;
        
        if (num_prog < min)
            min = num_prog;
        
        flag ++;
    }
    
    /****** Stampa del massimo e del minimo ******/
    printf ("\nIl numero massimo della sequenza e': %d\n", max);
    if (flag == 0)
        printf ("Il numero minimo della sequenza e': 0\n");
    else
        printf ("Il numero minimo della sequenza e': %d\n", min);
}