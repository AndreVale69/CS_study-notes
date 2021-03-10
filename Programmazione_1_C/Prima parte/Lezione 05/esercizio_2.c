/*
 * Scrivere un programma che realizzi il gioco Mastermind. Il primo giocatore
 * inserisce 4 caratteri che corrispondono alle iniziali di 4 colori tra
 * (r= rosso; g = giallo; v = verde, b = blu, n= nero; si assuma che gli utenti
 * inseriscano sempre una lettera compresa in questo elenco).
 * 
 * Il secondo giocatore ha a disposizione 10 tentativi per indovinare la
 * combinazione, inserendo a sua volta quattro caratteri ad ogni tentativo.
 * Dopo ogni tentativo il programma visualizza il numero di colori corretti in
 * posizione corretta (non vengono segnalati i colori corretti in posizione
 * sbagliata). Terminati i tentativi, se il secondo giocatore non è riuscito a
 * indovinare la sequenza, vengono visualizzati i caratteri corretti. 
 */
#include <stdio.h>
#define DIM 4

void main ()
{
    /****** Dichiarazione variabili ******/
    char array [DIM], car_osp;
    // array   = nome dell'array con all'interno i caratteri
    // car_osp = carattere inserito ogni qual volta dall'utente per indovinare

    int flag = 0;
    // flag    = var per indicare i confronti esatti

    /****** Inserimento caratteri ******/
    printf ("Player 1.\n");
    for (int i = 0; i < DIM; i++)
    {
        printf ("Inserisci il %d° carattere: ", i + 1);
        scanf (" %c", &array [i]);
    }
    printf ("\n");
    
    /****** Algoritmo del gioco ******/
    printf ("Player 2.\n");
    for (int i = 0; i < 10; i++)
    {
        if (flag == 0)
        {
            for (int j = 0; j < DIM; j++)
            {
                printf ("Inserisci il %d° carattere: ", j + 1);
                scanf (" %c", &car_osp);
                if (car_osp == array [j])
                    flag ++;
            }
            if (flag != 4)
            {
                printf ("Colori indovinati: %d. Rimangono altri %d tentativi.\n", flag, 9 - i);
                flag = 0;
            }
        }
    }
    if (flag == 4)
    {
        printf ("Il giocatore ha vinto! Con la combinazione: ");
        for (int i = 0; i < DIM; i++)
        {
            printf ("%c ", array [i]);
        }
        printf ("\n");        
    }
    else
    {
        printf ("Il giocatore non ha vinto, la combinazione era: ");
        for (int i = 0; i < DIM; i++)
        {
            printf ("%c ", array [i]);
        }
        printf ("\n");
    }
}