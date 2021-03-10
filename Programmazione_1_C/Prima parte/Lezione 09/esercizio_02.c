/*
 * Si realizzi un programma nel linguaggio C che, dati due interi n e m da
 * standard input, facendo uso di una funzione di nome multipli, calcoli il
 * numero degli interi appartenenti all’intervallo [1, n] che sono multipli
 * di m. Il programma principale, al termine della chiamata alla funzione
 * multipli, dovrà stampare il numero degli elementi appartenenti all’insieme
 * e poi terminare.
 */
#include <stdio.h>

int multipli (int n, int m);

void main ()
{
    int n, m, ris;
    // n   = primo numero inserito (limite da raggiungere)
    // m   = secondo numero inserito (multiplo)
    // ris = var dove salvare risultato

    // Finche' il numero e' minore di 1, chiedo reinserimento
    do
    {
        printf ("Inserire il primo numero  : ");
        scanf ("%d", &n);
        if (n < 1)
            printf ("Il valore inserito non puo' essere minore di 1.\n");
    } while (n < 1);

    // Inserimento multiplo
    printf ("Inserire il secondo numero: ");
    scanf ("%d", &m);
    
    // Se secondo numero uguale a zero, tutti elementi sono multipli di m
    if (m != 0)
        ris = multipli (n, m);
    else
        ris = n;

    // Stampa risultato
    printf ("Il numero di elementi appartenenti all'insieme: %d\n", ris);
}

// Dichiarazione funzione
int multipli (int n, int m)
{
    int molt, ris, count = 0, number = m;
    // molt   = moltiplicatore
    // ris    = risultato temporaneo da confrontare con number
    // count  = contatore di multipli
    // number = var che aumenta per confrontare tutti i valori. Inizializzata
    //          uguale ad m poiche' i multipli non possono essere minori di m
    //          (escluso lo 0)

    while (number <= n)
    {
        // Cerco i multipli
        molt = 1;
        do
        {
            ris = molt * m;
            molt ++;
        } while (ris < number);

        // Se ho trovato un multiplo, aumento il contatore
        if (ris == number)
            count ++;
        number ++;
    }
    
    // Return del risultato
    return count;
}