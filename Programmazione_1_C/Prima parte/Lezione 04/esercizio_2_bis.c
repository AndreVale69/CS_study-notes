// Scrivere un programma che acquisisca un indice X tra 0 e 9 
// (controllare validità del valore inserito) e una sequenza di 10 
// numeri interi. Il programma dovrà stampare la somma dei 
// numeri in posizioni minori di X e il prodotto dei numeri in 
// posizioni successive a X.

#include <stdio.h>

int main ()
{
    int ind, num, dim = 0, stamp_1 = 0, stamp_2 = 1;
    // ind = indice
    // num = numero della sequenza
    // dim = variabile di appoggio per somma e prodotto

    do
    {
        printf ("Inserire un indice: ");
        scanf ("%d", &ind);
        if ((ind < 0) || (ind > 9))
            printf ("Reinserire l'indice\n");
    } while ((ind < 0) || (ind > 9));
    // richiesta indice e controllo

    for (int i = 0; i < 10; i++)
    {
        printf ("Inserire numero: ");
        scanf ("%d", &num);
        if (i < ind)
            stamp_1 = stamp_1 + num;
        else
        {
            if (i > ind)
                stamp_2 = stamp_2 * num;
        }
    }
    // algoritmo senza utilizzare array, prodotto e somma al momento dell'inserimento

    printf ("La somma prima dell'indice e' di: %d\n", stamp_1);
    printf ("Il prodotto dopo l'indice e' di : %d\n", stamp_2);
    // stampa risultati
    
}