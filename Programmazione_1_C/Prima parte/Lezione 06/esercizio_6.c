/*
 * Scrivere un programma C che:
 *      ○ Richiede all’utente di inserire 20 caratteri che memorizza in un
 *        array, e altri due caratteri c e r.
 *      ○ Restituisce una array costruito a partire dall’array iniziale in cui
 *        ogni occorrenza di c è sostituita con r.
 */
#include <stdio.h>
#define DIM 20

void main ()
{
    /****** Dichiarazione variabili ******/
    char array [DIM], c, r;
    // array = nome array dove vengono salvati caratteri
    // c     = carattere da rimuovere
    // r     = carattere da inserire

    /****** Inserimento caratteri ******/
    for (int i = 0; i < DIM; i++)
    {
        if (i < 9)
            printf ("Inserire il %d° carattere  : ", i + 1);
        else
            printf ("Inserire il %d° carattere : ", i + 1);
        scanf (" %c", &array [i]);
    }

    /****** Inserimetno caratteri da sostituire/inserire ******/
    printf ("Inserire il carattere da cercare e sostituire: ");
    scanf (" %c", &c);
    printf ("Adesso inserire il carattere da inserire a posto del sostituto: ");
    scanf (" %c", &r);

    /****** Verifica, sostituzione eventuale e stampa di caratteri ******/
    for (int i = 0; i < DIM; i++)
    {
        if (array [i] == c)
            array [i] = r;
        printf ("%c ", array [i]);
    }
    printf ("\n");    
}