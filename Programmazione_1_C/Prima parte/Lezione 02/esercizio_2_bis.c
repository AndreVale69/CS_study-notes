// Scrivere un programma che, acquisito un valore
// intero da utente, stampi a video 0 se il valore è pari, 
// 1 se è dispari (solo con i costrutti visti a lezione).

#include <stdio.h>

int main ()
{
    int numero;
    // numero = numero richiesto

    printf ("Inserire un numero: ");
    scanf ("%d", &numero);
    // richiesta di inserimento

    if (numero == 0)
        printf ("Il numero e' zero\n");
    else
    {
        if (numero % 2 == 0)
            printf ("Il numero e' pari: 0\n");
        else
            printf ("Il numero e' dispari: 1\n");
    }
    // controllo pari / dispari

}