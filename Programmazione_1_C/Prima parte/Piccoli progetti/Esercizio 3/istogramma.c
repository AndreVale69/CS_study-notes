/* Scrivere un programma in C che chieda all'utente di inserire cinque valori
 * interi non negativi e ne disegna l'istogramma a barre verticali.
 *
 * Esempio:
 * Se l'utente inserisce i valori: 1 4 5 2 1, il programma visualizzerà il
 * seguente output:
 * 
 *      *
 *      * *
 *      * *
 *      * * *
 *    * * * * *
 *    1 4 5 2 1
 *
 * Qualora i valori inseriti fossero errati dovrà essere visualizzato un
 * messaggio di errore, al quale, seguirà la terminazione del programma.
 */

#include <stdio.h>
#define DIM 5

void main ()
{
    int array [DIM], j = 0, flag = 0, max = 0;
    // array = nome array con relativa dimensione
    // j     = indice di array per trovare eventuali valori negativi
    // flag  = var per uscire immediatamente dal ciclo
    // max   = valore massimo nell'array

    for (int i = 0; i < DIM; i++)
    {
        printf ("Inserire il %d° valore: ", i + 1);
        scanf ("%d", &array [i]);
        if (max < array [i])
            max = array [i];
    }
    printf ("\n");
    // Inserimento valori nell'array e assegnazione del valore massimo
    
    do
    {
        if (array [j] < 0)
            flag ++;
        j ++;
        /* Qui avrei potuto usare una sola variabile, cioe' appena avessi
         * trovato un valore negativo, avrei potuto assegnare il valore 6 alla
         * variabile j cosi' da uscire immediatamente. Questo approccio non mi
         * entusiasma poiche' la considero un'uscita forzata. Quindi, ho
         * utilizzato una variabile flag. (Programmazione strutturata)
         */
    } while (j < DIM && flag == 0);
    // Controllo valori negativi
    

    // Se ci sono stati errori, termino il programma altrimenti algoritmo
    if (flag == 0)
    {
        while (max != 0)
        {
            for (int i = 0; i < DIM; i++)
            {
                if (max <= array [i])
                    printf ("*");
                else
                    printf (" ");
                printf (" ");
                /* Se il valore massimo e' uguale o minore al valore dell'array
                 * stampo l'asterisco altrimenti lo spazio (in piu' aggiungo
                 * uno spazio per distanziare le colonne.
                 */
            }
            printf ("\n");
            max --;
            // Vado a capo e diminuisco la var max
        }
        // Finche' il valore massimo e' diverso da 0, continuo il ciclo

        for (int i = 0; i < DIM; i++)
            printf ("%d ", array [i]);
        printf ("\n");
        // Stampo i numeri dell'array sotto gli asterischi
    }
    else
        printf ("I valori inseriti sono negativi. Fine Programma.\n");
}