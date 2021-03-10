/*
 * Scrivere una funzione "most" che dato un intero positivo "n" restituisca la
 * sua cifra più significativa (quella più a sinistra) nella rappresentazione
 * in base 10.
 * Ad esempio se "n" è 9234 allora "most" deve restituire 9.
 */
#include <stdio.h>
#define N 10

int most (int n);

void main ()
{
    int n;
    // n = numero richiesto

    // Richiesta inserimento numero
    printf ("Inserire un numero: ");
    scanf ("%d", &n);

    // Invocazione funzione e salvataggio risultato in n
    n = most (n);
    
    // Stampa del risultato
    printf ("La cifra piu' significativa e': %d.\n", n);
}

int most (int n)
{
    int n_cop = n, div = 1;
    // n_cop = numero copiato per operazioni
    // div   = divisore utile per ottenere cifra piu' significativa

    // Finche' numero positivo, conto le cifre
    do
    {
        n_cop /= N;
        div *= N;
    } while (n_cop > 0);

    // Divido il numero per ottenere cifra piu' significativa
    n = n / (div / N);
    // Return del risultato
    return n;
}