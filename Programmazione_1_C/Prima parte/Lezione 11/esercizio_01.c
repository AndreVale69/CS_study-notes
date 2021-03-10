/*
 * Scrivere un programma C che:
 * 
 * ○ Richiede all’utente di inserire 20 caratteri e li salva in un array.
 * ○ Produce due risultati:
 *      
 *      ● Un array costruito con i caratteri inseriti in cui ogni vocale
 *        (maiuscola o minuscola) è sostituita da una cifra corrispondente
 *        (A=1, E=2, I=3, O=4, U=5).
 *      ● Un numero contenente la somma delle cifre (caratteri da 0 a 9)
 *        contenute nella stringa prodotta.
 */
#include <stdio.h>
#define N 10

void main ()
{
    char array [N], array_mod [N];
    int som = 0;
    // array     = array originale
    // array_mod = array modificato
    // som       = somma valori

    /****** Inserimento caratteri nell'array ******/
    for (int i = 0; i < N; i++)
    {
        printf ("Inserire il %d° carattere: ", i + 1);
        scanf (" %c", &array [i]);
        array_mod [i] = array [i];
    }
    
    /****** Controllo vocali, sostituzione e somma ******/
    for (int i = 0; i < N; i++)
    {
        if (array_mod [i] == 'a' || array_mod [i] == 'A')
        {
            array_mod [i] = '1';
            som += 1;
        }
        else
            if (array_mod [i] == 'e' || array_mod [i] == 'E')
            {
                array_mod [i] = '2';
                som += 2;
            }
            else
                if (array_mod [i] == 'i' || array_mod [i] == 'I')
                {
                    array_mod [i] = '3';
                    som += 3;
                }
                else
                    if (array_mod [i] == 'o' || array_mod [i] == 'O')
                    {
                        array_mod [i] = '4';
                        som += 4;
                    }
                    else
                        if (array_mod [i] == 'u' || array_mod [i] == 'U')
                            som += 5;
    }
    
    /****** Stampa array originale ******/
    printf ("\nL'array originale\n\n");
    for (int i = 0; i < N; i++)
    {
        printf ("%c ", array [i]);
    }
    printf ("\n");
    
    /****** Stampa array modificato ******/
    printf ("\nL'array modificato\n\n");
    for (int i = 0; i < N; i++)
    {
        if (array_mod [i] == 'u' || array_mod [i] == 'U')
            printf ("5 ");
        else
            printf ("%c ", array_mod [i]);
    }
    printf ("\n");

    /****** Stampa somma cifre ******/
    printf ("La somma delle cifre e': %d.\n", som);
}