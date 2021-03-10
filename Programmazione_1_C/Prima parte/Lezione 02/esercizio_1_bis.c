// Scrivere un programma in C che chiede all’utente
// una numero in virgola mobile. Il programma calcola
// e visualizza su due righe separate la parte intera e 
// quella decimale di tale numero.
// Ad esempio, nel caso in cui l’utente inserisce il
// numero 4.14, il programma visualizzerà:
// 4
// 0.14

#include <stdio.h>

int main ()
{
    float numero, part_dec;
    // numero     =    numero richiesto
    // part_dec   =    parte decimale

    int num_int;
    // num_int    =    parte intera

    printf ("Inserire numero in virgola mobile: ");
    scanf ("%f", &numero);
    // inserimento numero

    num_int = numero;
    // assegnazione per stampare parte intera

    printf ("La parte intera e'   : %d\n", num_int);
    // stampo parte intera

    part_dec = numero - num_int;
    printf ("La parte decimale e' : %f\n", part_dec);
}