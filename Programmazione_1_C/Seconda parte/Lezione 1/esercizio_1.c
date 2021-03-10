/*
 * Si scriva un programma che:
 * 
 * - Genera un array monodimensionale di 100 elementi;
 * 
 * - Riempie l'array con numeri casuali da 0 a 100;
 * 
 * - Tramite la funzione "verifica()", verifica se esiste un elemento tale
 *   che esso e' maggiore o uguale della somma degli elementi a seguire e ne
 *   stampi a video il valore e la posizione.
 */

#include <stdio.h>
#include <time.h>
#define N 100 // Definisco la grandezza dell'array

int verifica(int array[N]); // Dichiaro funzione con parametro

int main()
{
    int array[N];      // Dichiarazione array
    srand(time(NULL)); // Invocazione funzione della generazione numeri

    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 101; // Genera numero casuale da 0 a 100
        printf("%d ", array[i]); // Stampo il numero casuale
    }
    printf("\n");

    verifica(array); // Invoco la funzione di verifica
}

int verifica(int array[N])
{
    int som, val, flag = 0;
    // som  = var di somma progressiva ad ogni ciclo per confrontare
    // val  = valore da confrontare con som
    // flag = var flag per capire se condizione si è manifestata o no

    for (int i = 0; i < N - 1; i++)
    {
        som = 0;        // Inizializzo ad ogni ciclo la somma
        val = array[i]; // Assegno il valore dell'array a val per confrontare
        for (int j = i + 1; j < N; j++)
            som += array[j]; // Somma progressiva
        if (val >= som)
        {
            // Se la condizione e' vera, stampo i valori e la posizione
            printf("Il valore e'   : %d\n", val);
            printf("La posizione e': %d\n", i);
            flag = 1;
        }
    }

    if (!flag)
        printf("Nessun valore corrisponde alla condizione data\n");
    // Se valore di flag uguale a zero
}