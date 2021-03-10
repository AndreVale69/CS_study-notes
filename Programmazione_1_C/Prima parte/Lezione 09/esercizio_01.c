/*
 * Scrivere un sottoprogramma che dati due interi, verifica se il primo e'
 * multiplo del secondo e restituisce 1 o 0 al chiamante.
 */
#include <stdio.h>

int multiplo (int n1, int n2);

void main ()
{
    int n1, n2, ret;
    // n1  = primo numero
    // n2  = secondo numero (da verificare se multiplo del primo)
    // ret = var che salva il risultato della funzione

    printf ("Inserire il primo numero  : ");
    scanf ("%d", &n1);
    // Inserimento primo numero
    printf ("Inserire il secondo numero: ");
    scanf ("%d", &n2);
    // Inserimento secondo numero

    // Se il secondo numero e' diverso da zero
    if (n2 != 0)
        // Invoco la funzione e passo i due numeri
        ret = multiplo (n1, n2);
    else
        // Altrimenti restituisco direttamente uno (0 e' multiplo di tutti)
        ret = 1;

    // Stampa risultato
    printf ("Il risultato: %d\n", ret);
}

// Funzione che calcola il multiplo
int multiplo (int n1, int n2)
{
    int ris, molt = 1;
    // Dichiaro var locali:
    // ris  = var risultato per verificare il ris della moltiplicazione
    // molt = var moltiplicando

    // Continuo finche' il risultato non e' uguale o maggiore al secondo numero
    do
    {
        ris = molt * n1;
        molt ++;
    } while (ris < n2);

    // Se risultato uguale al secondo numero
    if (ris == n2)
        // Vuol dire che c'e' un multiplo
        return 1;
    else
        // Altrimenti zero
        return 0;
}