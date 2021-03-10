/*
 * Scrivere un sottoprogramma che ricevuto in ingresso un numero intero,
 * calcola e restituisce il numero intero ottenuto mettendo le cifre in ordine
 * opposto.
 * Per esempio, se il valore ricevuto in ingresso e 1245 il sottoprogramma
 * restituisce 5421. Se il valore ricevuto in ingresso e 190 il sottoprogramma
 * restituisce 91.
 */
#include <stdio.h>
#define D 10

int sottoprogramma (int n);

void main ()
{
    int n;
    // n = numero intero

    // Inserimento numero intero
    printf ("Inserire un numero intero: ");
    scanf ("%d", &n);

    // Invoco il sottoprogramma e salvo il risultato nel numero
    n = sottoprogramma (n);

    // Stampo il risultato
    printf ("Il numero al contrario e': %d\n", n);
}

int sottoprogramma (int n)
{
    int ris = 0, ris_2 = 0;
    // ris   = var che salva il modulo di n
    // ris_2 = var che contiene il numero al contrario

    // Algoritmo per ottenere il numero al contrario
    while (n > 0)
    {
        ris = n % D;
        ris_2 = ris_2 * D + ris;
        n /= D;
    }

    // Return del risultato
    return ris_2;
}