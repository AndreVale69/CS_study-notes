/*
 * Si scriva un programma che copi tutti i valori di una matrice int M [D1][D2]
 * in un array di dimensione D1*D2 eliminando nel processo di copia tutti i
 * duplicati negativi.
 */
#include <stdio.h>
#define D1 3
#define D2 4
// Definizione della doppia dimensione

void main ()
{
    int M [D1][D2] = 
    {
        {1, 2, 3, 4},
        {8, -10, 4, 8},
        {-10, 2, 3, 4}
    };
    int arr_supp [D1*D2], arr [D1*D2] = {0}, k = 0;
    // M        = definizion array
    // arr_supp = array di supporto per evitare 4 cicli for
    // arr      = array risultato
    // k        = indice e var di supporto

    for (int i = 0; i < D1; i++)
        for (int j = 0; j < D2; j++)
        {
            arr_supp [k] = M [i] [j];
            k ++;
            // Copiare matrice in un array di supporto
        }
    
    /****** ALGORITMO DI CONTROLLO E COPIA ******/
    for (int i = 0, k = 0; i < D1*D2; i++)
    {
        if (arr_supp [i] < 0)
            for (int j = 0; j < i; j++)
                if (arr_supp [i] == arr_supp [j])
                    k = 1;
        // Se il valore e' negativo, devo controllare, altrimenti salto la cella
        
        if (!k)
            arr [i] = arr_supp [i];
        // Copio il valore se non ho trovato doppioni negativi

        k = 0;
    }

    for (int i = 0; i < D1*D2; i++)
        printf ("%d ", arr [i]);
    // Stampo il risultato
}