/*
 * Scrivere un programma che chiede all’utente di inserire da tastiera una
 * matrice 3X3 con soli valori maggiori o uguali a zero.
 * 
 * ○ Il programma, dopo aver stampato la matrice a video, verifica se la matrice
 *   è pari o meno e stampa un opportuno messaggio a video.
 * 
 * ○ Una matrice si dice pari se è composta di soli valori pari.
 * 
 * ○ Ad esempio, se l’utente inserisce la seguente matrice
 *   4 0 2
 *   4 4 6
 *   6 4 8
 *   L’output sarà del tipo: Matrice pari? 1
 */
#include <stdio.h>
#define M 3

void main ()
{
    int matrix [M] [M], flag = 0;
    // matrix = matrice
    // flag   = var flag per individuare valori pari

    /****** Inserimento matrice e Controllo valori positivi ******/
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
        {
            printf ("Inserire un valore positivo o uguale a zero nella posizione %dx%d (RxC): ", i + 1, j + 1);
            scanf ("%d", &matrix [i] [j]);
            if (matrix [i] [j] < 0)
            {
                printf ("\nVALORE ERRATO!\n");
                j --;
            }
        }
    
    /****** Stampa della matrice e Controllo di tutti valori pari ******/
    printf ("\nLa matrice inserita e' la seguente:\n");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf ("%d ", matrix [i] [j]);
            if (matrix [i] [j] % 2 == 0 || matrix [i] [j] == 0)
                flag ++;
            // Ipotizzo che l'utente non inserisca tutti zeri nella matrice
        }
        printf ("\n");
    }

    /****** Stampa risultato, matrice pari oppure no ******/
    if (flag == M*M)
        printf ("La matrice e' pari.\n");
    else
        printf ("La matrice non e' pari.\n");
}