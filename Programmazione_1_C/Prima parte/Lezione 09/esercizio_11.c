/*
 * Scrivete un programma che legga un carattere, uno spazio, e quindi una
 * sequenza di caratteri minuscoli terminati da "." e che stampi quanto ha
 * letto dopo il primo spazio, ma sostituendo tutte le vocali minuscole con il
 * primo carattere letto (la stampa avverrà dopo ogni carattere letto).
 * Per farlo, definite una funzione "cambia" che, dati due caratteri,
 * restituisca il primo carattere se il secondo è una vocale minuscola,
 * altrimenti restituisca il secondo carattere.
 * CODICE ASCII:
 * a = 97, e = 101, i = 105, o = 111, u = 117
 */
#include <stdio.h>

char cambia (char car, char p_car);

char main ()
{
    char car, p_car;
    // car   = carattere utente
    // p_car = primo carattere da, eventualmente, sostituire

    printf ("Inserisci carattere: \n");
    printf ("RISULTATO: ' '\n");
    // Visto i problemi con l'inserimento dello spazio, ipotizzo un inserimento

    /****** Inserimento carattere e Stampa risultato******/
    // 46, nella tabella ascii, e' il "."
    for (int i = 1; car != 46; i++)
    {
        printf ("Inserisci carattere: ");
        scanf (" %c", &car);

        // Assegnazione primo carattere da sostituire
        if (i == 1)
            p_car = car;

        // Invocazione funzione e stampa del risultato
        car = cambia (car, p_car);
        printf ("RISULTATO: '%c'\n", car);
    }
}

char cambia (char car, char p_car)
{
    // Se carattere una vocale, return del primo carattere
    if (car == 97 || car == 101 || car == 105 || car == 111 || car == 117)
        return p_car;
    else
        return car;
}