/*
 * Scrivere un programma che chiede all’utente di riempire una matrice quadrata
 * 5x5 di caratteri (qualsiasi valore char). Il programma individua il
 * carattere che compare più frequentemente e lo mostra a schermo (si ipotizzi
 * che sia sempre unico). Inoltre il programma visualizza il contenuto della
 * matrice, mostrando però un asterisco al posto dei caratteri uguali a quello
 * individuato.
 */
#include <stdio.h>
#define N 3

void main ()
{
    char matrix [N] [N], arr_supp [N*N], car_max;
    int k = 0, count = 0, max = 0;
    // matrix   = matrice originaria
    // arr_supp = array di controllo per facilitare la lettura del codice
    // car_max  = var per salvare il carattere con più occorrenze
    // k        = indice per arr_supp e flag nell'algoritmo di ricerca max
    // count    = contatore di occorrenze
    // max      = var massima per confrontare i valori a fine di ogni ciclo

    /****** Richiesta inserimento e copia in arr_supp ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire il valore char che si trovera' in posizione %d x %d (RxC): ", i + 1, j + 1);
            scanf (" %c", &matrix [i] [j]);
            arr_supp [k] = matrix [i] [j];
            k ++;
        }

    /****** Algoritmo di ricerca max e salvataggio carattere max ******/
    for (int i = 0; i < N*N; i++)
    {
        // Conta le occorrenze di ogni carattere
        for (int q = 0; q < N*N; q++)
            if (arr_supp [i] == arr_supp [q])
                count ++;
        // Se il carattere ha delle occorrenze > al max
        if (max < count)
        {
            // Assegnamento nuovo max e copia del carattere
            max = count;
            car_max = arr_supp [i];
        }
        // Azzeramento var
        count = 0;
        k = 0;
    }

    // Stampa carattere massimo
    printf ("Il carattere piu' frequente e': %c\n", car_max);
    printf ("\n");

    /****** Stampa matrice ed eventuale sostituzione con asterisco ******/
    for (int i = 0; i < N*N; i++)
        if (i % N != 0)
            if (arr_supp [i] == car_max)
                printf ("* ");
            else
                printf ("%c ", arr_supp [i]);
        else
        {
            if (arr_supp [i] == car_max)
                printf ("* ");
            else
            {
                printf ("\n");
                printf ("%c ", arr_supp [i]);
            }
        }
    printf ("\n");
    printf ("\n");
}