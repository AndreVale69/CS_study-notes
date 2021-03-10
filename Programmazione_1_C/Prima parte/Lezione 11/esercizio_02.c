/*
 * Si scriva un programma C che definisce la funzione
 * "int cifra_minima (int num)" la quale deve restituire la cifra più bassa
 * nella rappresentazione decimale di num. Tale programma dovrà inoltre
 * definire un "main" che:
 * 
 * 1. Chiede all’utente di inserire un numero non negativo;
 * 2. Chiama la funzione "cifra_minima" per calcolarne la cifra più bassa;
 * 3. Stampa tale cifra minima trovata.
 * 
 * Esempi:
 * $./a.out
 *  Inserisci un numero non negativo: 1232
 *  La cifra_minima di 1232 e’ 1 
 * $./a.out
 *  Inserisci un numero non negativo: 0
 *  La cifra_minima di 0 è 0
 * $./a.out
 *  Inserisci un numero non negativo: -5
 *  Inserisci un numero non negativo: 30756
 *  La cifra_minima di 30756 è 0
 */
#include <stdio.h>
#define N 10

int cifra_minima (int num);

void main ()
{
    int num, n_min;
    // num   = numero inserito dall'utente
    // n_min = cifra minima del numero (proveniente dalla funzione)

    /****** Inserimento numero e Controllo segno del numero ******/
    do
    {
        printf ("Inserisci un numero non negativo: ");
        scanf ("%d", &num);
    } while (num < 0);
    
    /****** Invocazione funzione e Salvataggio risultato ******/
    n_min = cifra_minima (num);

    /****** Stampa del risultato ******/
    printf ("La cifra_minima di %d e' %d\n", num, n_min);
}

int cifra_minima (int num)
{
    int cif, n_min = 9;
    // cif   = cifra presa da ogni divisione
    // n_min = cifra minima

    /****** Algoritmo minimo ******/
    do
    {
        cif = num % N;
        if (cif < n_min)
            n_min = cif;
        num = num / N;
    } while (num > 0);
    
    // Return del risultato
    return n_min;
}