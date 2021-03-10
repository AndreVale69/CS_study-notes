/*
 * Scrivere un sottoprogramma "scomponi" che ricevuto in ingresso un numero
 * intero senz’altro strettamente positivo "n" lo scompone e restituisce al
 * chiamante i fattori. 
 * Memorizzare i valori in un array di dimensione massima 10.
 * Ad esempio, per n = 60 il programma trasmette i valori 2 2 3 5.
 */
#include <stdio.h>
#define D 10

int scomponi (int n, int array [D]);

void main ()
{
    int array [D] = {0}, n;
    // array = array in cui salvare i fattori
    // n     = numero inserito da utente

    do
    {
        // Inserimento valore
        printf ("Inserire un numero intero: ");
        scanf ("%d", &n);
    } while (n < 0);
    
    // Invocazione della funzione
    scomponi (n, array);

    // Stampa dei risultati
    for (int i = 0; i < D; i++)
        if (array [i] == -1) // fix -> array alla fine stampava -1
            printf ("0 ");
        else
            printf ("%d ", array [i]);

    printf ("\n");
}

int scomponi (int n, int array [D])
{
    int flag;
    // flag = var flag per smettere di incrementare j

    for (int i = 0; i < D && n > 0; i++)
    {
        for (int j = 2, flag = 0; flag == 0 && n > 0; j++)
        {
            if (j % 2 != 0 || j == 2)
            {
                if (n % j == 0)
                {
                    array [i] = j;
                    flag = 1;
                    n /= j;
                }
            }
        }
    }
    /*
     * Il ciclo piu' esterno serve per l'indice dell'array,
     * per salvare i fattori.
     * Il secondo ciclo serve per incrementare l'eventuale il numero primo
     * Primo if serve per controllare se j e' un numero primo
     * Secondo if serve per controllare se e' un fattore di n
     */
}
/****** NOTE ******/
/*
 * Il programma potrebbe risultare "lento" nell'esecuzione. Questa velocita'
 * dipende molto dal sottoprogramma. Difatti, nel main, e' presente una semplice
 * richiesta di un numero positivo. Il sottoprogramma, invece, prima di
 * restituire il risultato al main, dovrà controllare i vari numeri, salvarli
 * nell'array e passare l'intera array al main. A questo punto il main
 * stampera' il risultato.
 */