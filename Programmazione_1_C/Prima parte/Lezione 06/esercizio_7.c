/*
 * Chiedere all’utente una sequenza di numeri interi che termina con
 * l’inserimento dello 0 (e in ogni caso lunga al massimo 100 elementi).
 * Creare un array che contenga tutti e soli valori distinti della sequenza
 * (ovvero omettendo i duplicati con uno zero).
 * Visualizzare l’array e il numero di elementi unici inseriti.
 * 
 * Variante: creare un array che contenga tutti e soli i valori che nella prima
 *           sequenza non ammettono  duplicati.
 */
#include <stdio.h>
#define MAX 100

void main ()
{
    /****** Dichiarazione variabili ******/
    int array [MAX], i = 0, flag = 0, flag2 = 0, ele_un;
    // array  = nome array con numeri
    // i      = contatore di cicli ed indice array
    // flag   = primo flag per controllare se ci fosse uno zero inserito
    // flag2  = secondo flag per contare i doppioni
    // ele_un = var di elementi unici

    /****** Inserimento valori nell'array e confronto dei doppioni ******/
    do
    {
        if (i < 9)
            printf ("Inserire il %d° valore  : ", i + 1);
        else
            printf ("Inserire il %d° valore : ", i + 1);
        scanf ("%d", &array [i]);
        
        if (array [i] != 0)
        {
            for (int j = 0; j < i; j++)
            {
                if (array [i] == array [j])
                {
                    array [i] = 0;
                    flag2 ++;
                }
            }
            i ++;
        }
        else
            flag = 1;
    } while (i < MAX && flag == 0);
    
    ele_un = (i + 1) - flag2;

    /****** Stampa dei risultati ******/
    for (int l = 0; l < i; l++)
    {
        printf ("%d ", array [l]);
    }
    printf ("\n");
    printf ("Il numero di elementi unici sono: %d\n", ele_un);
}