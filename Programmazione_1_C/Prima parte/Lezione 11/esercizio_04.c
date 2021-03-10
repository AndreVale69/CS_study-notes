/*
 * Si scriva un programma in linguaggio C che converta un numero binario in un
 * numero decimale. Il numero binario è rappresentato su N bit, e il valore di
 * N è inserito da tastiera. L’utente inserisce le cifre del numero binario un
 * bit alla volta, partendo dal bit meno significativo (ossia dal bit di peso 0).
 * Il programma visualizzerà il numero decimale corrispondente.
 */
#include <stdio.h>

void main ()
{
    int N, flag = 0, bit, ris_temp, ris = 0;
    // N        = numero di bit
    // flag     = var per uscire dal ciclo while
    // bit      = bit inserito dall'utente
    // ris_temp = numero elevato alla i potenza
    // ris      = risultato decimale

    /****** Inserimento numero bit ******/
    printf ("Inserire il numero dei bit del numero: ");
    scanf ("%d", &N);

    /****** Algoritmo di acquisizione bit e conversione in decimale ******/
    while (flag < N)
    {
        ris_temp = 1;
        
        // Finche' valore diverso da 0 e 1, si chiede il bit
        do
        {
            printf ("Inserire il %d° bit del numero (partendo da dx): ", flag + 1);
            scanf ("%d", &bit);
            if (bit < 0 || bit > 1)
                printf ("\nUn bit puo' assumere solo 0 e 1. Valore errato!\n\n");
        } while (bit < 0 || bit > 1);
        
        // Se il bit e' ad 1, eseguo la potenza del due e la relativa somma
        if (bit == 1)
        {
            for (int i = 0; i < flag; i++)
                ris_temp *= 2;
            ris += ris_temp;
        }
        flag ++;
    }

    /****** Stampa del risultato ******/
    printf ("Il numero decimale corrispondente e': %d.\n", ris);
}