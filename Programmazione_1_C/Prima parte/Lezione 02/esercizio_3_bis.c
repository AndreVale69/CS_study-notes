// Scrivere un programma in C che chiede all’utente un 
// carattere dell’alfabeto minuscolo (assumere non ci 
// siano errori in inserimento). Il programma calcola e 
// visualizza il corrispondente carattere maiuscolo.

#include <stdio.h>

void main ()
{
    char carattere;
    // carattere = carattere minuscolo

    printf ("Inserire un carattere dell'alfabeto minuscolo: ");
    scanf (" %c", &carattere);
    // richiesta inserimento dall'utente

    carattere = carattere - 32;
    // -32 posizioni sulla tabella ASCII

    printf ("Il carattere in maiuscolo e': %c\n", carattere);
    // stampa carattere maiuscolo
}