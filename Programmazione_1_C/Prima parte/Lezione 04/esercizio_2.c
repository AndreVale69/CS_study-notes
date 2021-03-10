// Scrivere un programma che ricevuto in ingresso due 
// numeri interi positivi a e b (se così non è, li richiede), 
// visualizza un rettangolo di dimensione a*b usando il 
// carattere ‘*’ sui bordi e il carattere ‘X’ all’interno

#include <stdio.h>

void main ()
{
    int a, b;
    // a = righe
    // b = colonne

    printf ("Inserisci le righe   : ");
    scanf ("%d", &a);
    printf ("Inserisci le colonne : ");
    scanf ("%d", &b);
    // inserimento righe e colonne

    for (int i = 0; i < b; i++)
    {
        printf ("*");
    }
    // '*' solo nella prima riga
    printf ("\n");

    for (int i = 0; i < a - 1; i++)
    {
        printf ("*");
        for (int j = 0; j < b - 2; j++)
        {
            printf ("X");
        }
        printf ("*");
        printf ("\n");
    }
    // sia * che X nella parte centrale
    
    for (int i = 0; i < b; i++)
    {
        printf ("*");
    }
    // '*' solo ultima riga
    printf ("\n");
}