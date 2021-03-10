/*
 * Scrivere un programma che chiede all’utente di inserire una matrice di interi
 * di dimensione 3X3.
 * 
 * ○ Il programma stampa a video il valore 1 se la matrice contiene tutti gli
 *   interi a partire da 0 fino al numero di celle matrice -1, 0 in caso
 *   contrario.
 *   Ad esempio con la matrice:
 *        1 0 2
 *        3 4 6
 *        5 7 8
 *   il programma stamperà a video il valore 1.
 */
#include <stdio.h>
#define D 3

void main ()
{
    int matrix [D] [D], flag = 0;
    // matrix = matrice
    // flag   = var flag per trovare risultato

    /****** Inserimento matrice e Controllo valore dei valori ******/
    for (int i = 0; i < D; i++)
        for (int j = 0; j < D; j++)
        {
            printf ("Inserire il valore nella posizione %dx%d (RxC): ", i + 1, j + 1);
            scanf ("%d", &matrix [i] [j]);
            if (matrix [i] [j] >= D*D)
                flag ++;
        }
    
    /****** Stampa risultati ******/
    if (!flag)
        printf("\n1\n\n");
    else
        printf("\n0\n\n");
}