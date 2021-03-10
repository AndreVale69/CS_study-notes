/*
 * Scrivere un programma in linguaggio C che riceve in ingresso una sequenza di
 * "N" numeri interi. Il valore "N" è inserito dall’utente e al massimo vale 10.
 * I numeri sono memorizzati in un array. Terminato l’inserimento della
 * sequenza di numeri, il programma deve visualizzare una riga di asterischi per
 * ogni numero inserito. Il numero di asterischi nella riga e' pari al valore
 * del numero inserito.
 * 
 * ○ Ad esempio, dato il vettore 9 4 6 il programma deve visualizzare:
 *      Elemento 1: 9 *********
 *      Elemento 2: 4 ****
 *      Elemento 3: 6 ******
 */
#include <stdio.h>
#define D 10

void main ()
{
    int N [D], num;
    // N   = matrice con i valori della sequenza
    // num = numero di numeri della sequenza

    // Inserimento numero di numeri della sequenza con controllo
    do
    {
        printf ("Inserire il numero di numeri della sequenza: ");
        scanf ("%d", &num);
    } while (num < 0 || num > 10);

    // Inserimento della sequenza
    for (int i = 0; i < num; i++)
    {
        printf ("Inserire il %d° valore: ", i + 1);
        scanf ("%d", &N [i]);
    }
    
    // Stampa con asterischi
    for (int i = 0; i < num; i++)
    {
        printf ("Elemento %d: %d ", i + 1, N [i]);
        for (int j = 0; j < N [i]; j++)
            printf ("*");
        printf ("\n");
    }
}