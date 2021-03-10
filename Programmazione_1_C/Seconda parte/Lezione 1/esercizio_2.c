/*
 * Prodotto tra matrici quadrate
 * 
 * Data una matrice A di dimensione n x n, ed una matrice B di dimensione n x n:
 * - il risultato del prodotto matriciale A x B e' una nuova matrice di
 *   dimensioni n x n.
 * 
 * Si scriva un programma che:
 * - Costruisce due matrici di dimensione 10 x 10
 * - Le riempie con numeri casuali da 0 a 50
 * - Calcola il prodotto matriciale
 * - Stampa il risultato
 */
#include <stdio.h>
#include <time.h>
#define N 10

int main()
{
    int A[N][N], B[N][N], C[N][N];
    // A = prima matrice
    // B = seconda matrice
    // C = terza matrice

    srand(time(NULL)); // Invocazione numeri casuali

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            A[i][j] = rand() % 51; // Assegnazione numeri casuali nelle matrici
            B[i][j] = rand() % 51;
        }

    /*** Stampa della prima matrice ***/
    printf("\nPRIMA MATRICE\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (A[i][j] - 9 > 0)
                printf("[%d]  ", A[i][j]); // Se num con due cifre
            else
                printf("[ %d]  ", A[i][j]); // Se num con una cifra, metto spazio
        printf("\n");
    }

    /*** Stampa della seconda matrice ***/
    printf("\nSECONDA MATRICE\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (B[i][j] - 9 > 0)
                printf("[%d]  ", B[i][j]);
            else
                printf("[ %d]  ", B[i][j]);
        printf("\n");
    }

    /*** Stampa della terza matrice ***/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] * B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}