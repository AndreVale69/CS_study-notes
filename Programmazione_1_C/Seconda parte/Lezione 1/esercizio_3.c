/*
 * Si scriva un programma che:
 * - costruisca un array monodimensionale di dimensione 100
 * - lo riempie con numeri casuali da 0 a 10
 * - tramite la funzione verifica_crescente(...), verifica se esistono
 *   all'interno dell'array tre elementi successivi ordinati in modo crescente
 * - tramite la funzione verifica_decrescente(...), verifica se esistono
 *   all'interno dell'array tre elementi successivi ordinati in modo decrescente
 * - tramite la funzione massimo_crescente(....), calcoli il numero massimo di
 *   elementi successivi all'interno dell'array che risultano essere ordinati
 *   in modo crescente, e li stampi a video
 */
#include <stdio.h>
#include <time.h>
#define N 100

int verifica_crescente(int array[N]);
int verifica_decrescente(int array[N]);
int massimo_crescente(int array[N]);
int contatore;
// contatore = var globale

void main()
{
    int array[N];
    // array = nome array

    srand(time(NULL));
    // Invocazione generazione numeri casuali

    /*** Assegnazione numeri casuali ***/
    for (int i = 0; i < N; i++)
        array[i] = rand() % 11;

    /*** Invocazione funzione per verificare valori crescenti ***/
    verifica_crescente(array);

    /*** Invocazione funzione per verificare valori decrescenti ***/
    verifica_decrescente(array);

    /*** Invocazione funzione per conteggio valori crescenti ***/
    massimo_crescente(array);
}

int verifica_crescente(int array[N])
{
    int flag = 0;
    // flag = var per evitare di stampare piu' valori crescenti

    for (int i = 0; i < N; i++)
        if (array[i] < array[i + 1] && array[i + 1] < array[i + 2]) // Se sequenza crescente
        {
            if (flag == 0) // Se ancora non ho stampato, lo faccio
            {
                printf("Valore crescente:\n");
                printf("La serie di numeri e': %d - %d - %d\n", array[i], array[i + 1], array[i + 2]);
                printf("E gli indici sono rispettivamente: %d, %d, %d\n", i, i + 1, i + 2);
                flag = 1;
            }
            contatore++; // Aumento conteggio
        }
}

int verifica_decrescente(int array[N])
{
    int flag = 0;
    // flag = var per terminare il ciclo appena si trova un valore

    for (int i = 0; i < N && flag == 0; i++)
        if (array[i] > array[i + 1] && array[i + 1] > array[i + 2]) // Se sequenza decrescente
        {
            flag = 1;
            printf("Valore decrescente:\n");
            printf("La serie di numeri e': %d - %d - %d\n", array[i], array[i + 1], array[i + 2]);
            printf("E gli indici sono rispettivamente: %d, %d, %d\n", i, i + 1, i + 2);
            // Stampo risultato ed imposto la var flag ad 1 per uscire dal ciclo for
        }
}

int massimo_crescente(int array[N])
{
    printf("Il numero di valori crescenti e': %d\n", contatore);
    // Stampo risultato della variabile contatore
}