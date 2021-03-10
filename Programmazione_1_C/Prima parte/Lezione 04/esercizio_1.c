// Scrivere un programma che ricevuto in ingresso due 
// numeri interi positivi a e b (se così non è, li richiede), 
// visualizza un rettangolo di dimensione a*b usando il 
// carattere '*'

#include <stdio.h>

void main () 
{
    int a, b;
    // a  = righe
    // b  = colonne

    printf ("Inserire il numero delle righe   : ");
    scanf ("%d", &a);
    printf ("Inserire il numero delle colonne : ");
    scanf ("%d", &b);
    // inserimento delle righe e colonne

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf ("*");
        }
        printf ("\n");        
    }
    // scorrimento colonne e righe    
}