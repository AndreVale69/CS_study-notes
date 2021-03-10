// Scrivere un programma che ricevuto in ingresso un 
// numero intero positivo a (se così non è, lo richiede), 
// visualizza un quadrato di lato a usando il carattere ‘X’ 
// sulla diagonale principale e il carattere ’*’ altrove.

#include <stdio.h>

void main ()
{
    int a;
    // a = numero intero

    do
    {
        printf ("Inserire numero positivo: ");
        scanf ("%d", &a);
        if (a < 1)
            printf ("Il numero e' negativo o = 0, reinserire numero\n");
    } while (a < 1);
    // inserimento numero + controllo di positività

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (i == j)
                printf ("X");
            else
                printf ("*");
        }
        printf ("\n");        
    }
    // algoritmo di stampa
    
}