/*
 * Si scriva un programma C che definisce una funzione
 *                  int next_prime(int last);
 * che restituisce il numero primo immediatamente successivo a last.
 * Si utilizzi inoltre la seguente funzione main() per testarne il funzionamento:
 * 
 * int main()
 * {
 *      int number;
 *      int c;
 *      int p = 2;
 *      
 *      printf ("Quanti numeri primi vuoi stampare? ");
 *      scanf("%d”, &number);
 * 
 *      for (c = 0; c < number; c++)
 *      {
 *          printf("%d\n", p);
 *          p = next_prime(p);
 *      }
 * }
 */
#include <stdio.h>

int next_prime (int last);

int main ()
{
    int number, c, p = 2;

    printf ("Quanti numeri primi vuoi stampare? ");
    scanf("%d", &number);

    for (c = 0; c < number; c++)
    {
        printf("%d\n", p);
        p = next_prime(p);
    }
}

// Definizione della funzione richiesta
int next_prime (int last)
{
    int count = 1;
    // count = contatore necessario per inidividuare num primo

    do
    {
        // Un numero primo non ha divisori (eccetto 1 e se' stesso)
        for (int i = 2; i < last; i++)
            if (last % i == 0)
                count ++;
        
        // Se non ci sono divisori, allora return del numero primo
        if (count == 0)
            return last;
        // Altrimenti aumento last e proseguiamo con la ricerca
        else
        {
            count = 0;
            last ++;
        }
    } while (1);
    /* Ciclo apparentemente infinito, viene interrotto automaticamente quando
       viene trovato un numero primo. Personalmente la trovo una scelta poco
       "etica". Difatti non credo si rispetti la Programmazione Strutturata.
       Io, personalmente, avrei optato per una var flag che avrebbe terminato
       il ciclo una volta posta ad uno. */
}