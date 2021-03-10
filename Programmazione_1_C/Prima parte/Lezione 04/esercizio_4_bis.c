// Scrivere un programma che, chiesti all'utente due numeri 
// interi positivi a e b comunica all'utente se si tratta di una 
// coppia di numeri affiatati oppure no. Definiamo due numeri 
// affiatati se sono diversi tra loro e la loro somma è pari al 
// prodotto delle cifre che li compongono. Ad esempio (14, 34) e 
// (63, 81) sono coppie di numeri affiatati perché
// 14 + 34 = 1 x 4 x 3 x 4 = 48
// 63 + 81 = 6 x 3 x 8 x 1 = 144

#include <stdio.h>

void main ()
{
    int a, b, sum, prod, prod_a = 1, prod_b = 1;
    // a      = primo numero inserito dall'utente
    // b      = secondo numero inserito dall'utente
    // sum    = somma dei due numeri
    // prod   = prodotto finale delle cifre dei due numeri
    // prod_a = prodotto cifre del primo numero
    // prod_b = prodotto cifre del secondo numero

    printf ("Inserire primo numero: ");
    scanf ("%d", &a);
    // inserimento primo numero

    printf ("Inserire secondo numero: ");
    scanf ("%d", &b);
    // inserimento secondo numero

    sum = a + b;
    // somma primo numero con secondo

    while (a != 0)
    {
        prod_a *= a % 10;
        a /= 10;
    }
    // finché a è maggiore zero esegui ciclo.
    // ogni volta prendi il resto della divisione
    // e moltiplicalo per il resto precedente.
    // all'inizio sarà 1 prod_a.
    // poi si divide a per 10 così da uscire dal ciclo dopo

    while (b != 0)
    {
        prod_b *= b % 10;
        b /= 10;
    }
    // stessa cosa della riga 33 to 37

    prod = prod_a * prod_b;
    // prodotto finale delle cifre dei due numeri

    if (sum == prod)
        printf ("I due numeri sono affiatati\n");
    else
        printf ("I due numeri non sono affiatati\n");
    // controllo affiatati o no
}