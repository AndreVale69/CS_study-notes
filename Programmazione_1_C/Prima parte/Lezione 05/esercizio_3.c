/*
 * Chiamiamo coppia di quadrati (CQ) una coppia <a,b> di numeri interi che sono
 * uno il quadrato dell’altro. Esempio <9,3> oppure <-3,9> (infatti 9=3*3).
 * Si codifichi un programma C che legge da tastiera una sequenza che termina
 * con 99 (di lunghezza a priori illimitata) di numeri interi e stampa a video
 * quante coppie di numeri consecutivi all’interno della sequenza rappresentano
 * una CQ. Ad esempio: 2 4 16 0 3 9 99 contiene 3 CQ: <2,4> <4,16> e <3,9>
 */
#include <stdio.h>

void main ()
{
    /****** Dichiarazione variabili ******/
    int num = 0, prev_num, flag = 0;
    // num         = numero inserito dall'utente
    // prev_num    = numero precedente
    // flag        = contatore di coppie di quadrati

    /****** Algoritmo per cacolare le coppie di quadrati ******/
    printf ("Inserire una cifra dopo l'altra (99 per terminare).\n");
    do
    {
        prev_num = num;
        printf ("Inserire numero: ");
        scanf ("%d", &num);
        if (num != 99)
            if ((num * num == prev_num) || (prev_num * prev_num == num))
                flag ++;
    } while (num != 99);
    printf ("Ci sono %d coppie di quadrati.\n", flag);
}