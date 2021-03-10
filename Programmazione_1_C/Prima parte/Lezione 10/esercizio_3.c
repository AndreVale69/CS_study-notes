/*
 * Scrivere un programma C composto da:
 * 
 * ● Una funzione "leggi" che richiede all’utente di inserire da standard input
 *   una matrice 4x5.
 * 
 * ● Una funzione "trasposta" che riceve come parametro una matrice a 4x5 e una
 *   matrice b 5x4. La funzione calcola la trasposta di a e la memorizza in b.
 *      ○ Una matrice a con i righe e j colonne può essere trasposta in una
 *        matrice b con j righe e i colonne, dove ogni elemento b(j,i) = a(i,j).
 */
#include <stdio.h>
#define R 4
#define C 5

int leggi (int matrix_a [R] [C]);
int trasposta (int matrix_a [R] [C], int matrix_b [C] [R]);

void main ()
{
    int matrix_a [R] [C], matrix_b [C] [R];
    // matrix_a = matrice originale
    // matrix_b = matrice trasposta

    /****** Inserimento valori matrice originale ******/
    leggi (matrix_a);

    /****** Operazione di crazione matrice trasposta ******/
    trasposta (matrix_a, matrix_b);

    /****** Stampa matrice originale ******/
    printf ("\nLa Matrice inserita e' la seguente\n\n");
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            printf ("%d ", matrix_a [i] [j]);
        printf ("\n");
    }
    
    /****** Stampa matrice trasposta ******/
    printf ("\nLa Matrice trasposta e' la seguente\n\n");
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < R; j++)
            printf ("%d ", matrix_b [i] [j]);
        printf ("\n");
    }
}

int leggi (int matrix_a [R] [C])
{
    // Inserimento valori nella matrice originale
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &matrix_a [i] [j]);
        }
}

int trasposta (int matrix_a [R] [C], int matrix_b [C] [R])
{
    // Creazione matrice trasposta
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            matrix_b [j] [i] = matrix_a [i] [j];
}