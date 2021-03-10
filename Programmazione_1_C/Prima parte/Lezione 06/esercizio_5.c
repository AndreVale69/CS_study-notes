/*
 * Scrivere un programma C che: 
 * 
 * ○ Richiede all’utente di inserire 20 caratteri e li salva in un array.
 * ○ Produce due risultati:
 * 
 *      ● Una array costruito con i caratteri inseriti in cui ogni vocale
 *        (mauiscola o minuscola) è sostituita da un numero corrispondente
 *        (A=1, E=2, I=3, O=4, U=5).
 *      
 *      ● Un numero contenente la somma delle cifre (caratteri da 0 a 9)
 *        contenute nell'array prodotta.
 * 
 * L a b - P r o g r a m m a z i o n e - 1
 * 
 * L 1 b - P r 4 g r 1 m m 1 z 3 4 n 2 - 1
 * Somma = 17
 */

#include <stdio.h>
#define DIM 20

void main ()
{
    /****** Dichiarazione variabili ******/
    char array [DIM]; 
    int sum = 0;
    // array = nome dell'array
    // sum   = var somma

    /****** Richiesta inserimento caratteri ******/
    printf ("Inserire 20 caratteri.\n");
    printf ("NB: Se vengono inserite cifre, esse devono essere comprese tra 0 e 9.\n\n");

    for (int i = 0; i < DIM; i++)
    {
        if (i < 9)
            printf ("Inserire il %d° carattere  : ", i + 1);
        else
            printf ("Inserire il %d° carattere : ", i + 1);
        scanf (" %c", &array [i]);
        if (array [i] > 47 && array [i] < 58)
            sum += array [i] - 48;
    }

    /****** Algoritmo controllo vocali ******/
    for (int i = 0; i < DIM; i++)
    {
        if (array [i] == 'a' || array [i] == 'A')
        {
            array [i] = 1;
            sum += 1;
        }
        if (array [i] == 'e' || array [i] == 'E')
        {
            array [i] = 2;
            sum += 2;
        }
        if (array [i] == 'i' || array [i] == 'I')
        {
            array [i] = 3;
            sum += 3;
        }
        if (array [i] == 'o' || array [i] == 'O')
        {
            array [i] = 4;
            sum += 4;
        }
        if (array [i] == 'u' || array [i] == 'U')
        {
            array [i] = 5;
            sum += 5;
        }
    }

    /****** Algoritmo di stampa ******/
    for (int i = 0; i < DIM; i++)
    {
        if (array [i] == 0 || array [i] == 1 || array [i] == 2)
        {
            printf ("%d ", array [i]);
        }
        if (array [i] == 3 || array [i] == 4 || array [i] == 5)
        {
            printf ("%d ", array [i]);
        }
        if (array [i] == 6 || array [i] == 7 || array [i] == 8)
        {
            printf ("%d ", array [i]);
        }
        if (array [i] == 9)
        {
            printf ("%d ", array [i]);
        }
        else
            printf ("%c ", array [i]);
    }
    printf ("\n");
    printf ("La somma e': %d\n", sum);
}