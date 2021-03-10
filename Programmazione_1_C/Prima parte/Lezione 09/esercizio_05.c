/*
 * Scrivete una funzione avente due parametri interi b ed e
 * che calcoli la potenza b^e
 */
#include <stdio.h>

int potenza (int b, int e);

void main ()
{
    int b, e, ris;
    // b   = base
    // e   = esponente
    // ris = risultato

    // Inserimento della base di un numero
    printf ("Inserire la base (b) del numero: ");
    scanf ("%d", &b);

    // Inserimento dell'esponente di un numero
    printf ("Inserire l'esponente (e) del numero: ");
    scanf ("%d", &e);

    // Invocazione del sottoprogramma e salvataggio risultato in ris
    ris = potenza (b, e);

    // Stampa del risultato
    printf ("Il risultato della potenza e': %d\n", ris); 
}

int potenza (int b, int e)
{
    int ris = b;
    // ris = risultato che parte da b

    // Calcolo della potenza
    for (int i = 1; i < e; i++)
        ris *= b;

    // Ritorno del risultato
    return ris;
}