/*
 * Scrivere un sottoprogramma che ricevuto in ingresso un intero positivo:
 * conta il numero di cifre che compongono il numero in ingresso
 * e restituisce al main il numero dei suoi divisori
 */
#include <stdio.h>

int sottoprogramma (int n);

void main ()
{
    int n, ris;
    // n   = numero richiesto
    // ris = risultato
    
    // Inserimento numero
    printf ("Inserire un intero positivo: ");
    scanf ("%d", &n);

    // Invocazione sottoprogramma
    ris = sottoprogramma (n);

    // Stampa risultato
    printf ("Il numero dei divisori di %d e': %d\n", n, ris);
}

int sottoprogramma (int n)
{
    int num = n, i, count = 0;
    // num   = var per contare le cifre del numero
    // i     = indice per contare le cifre e stampare
    // count = contatore dei divisori

    // Contatore delle cifre e relativa stampa
    for (i = 0; num > 0; i++)
        num /= 10;
    printf ("Il numero inserito ha %d cifre\n", i);

    // Contatore dei divisori
    for (int j = 1; j <= n; j++)
        if (n % j == 0)
            count ++;
    
    // Return del risultato
    return count;
}