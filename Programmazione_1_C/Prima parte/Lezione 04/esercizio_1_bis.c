// Si definisce triangolare un numero costituito dalla somma dei 
// primi N numeri interi positivi per un certo N. Esempio: dato 
// N=4, il numero triangolare Q è 10 (Q=1+2+3+4). Scrivere un 
// programma che riceva dall’utente un numero intero positivo e 
// stampi a video se è
// ̀o meno triangolare (ossia se può essere 
// scritto come somma dei primi N interi consecutivi). 

#include <stdio.h>

void main ()
{
    int num, dim = 0, contatore = 1;
    // num       = numero intero da verificare
    // dim       = sarebbe la Q dell'esempio
    // contatore = aumenta ad ogni ciclo

    printf ("Inserire numero: ");
    scanf ("%d", &num);
    // richiesta inserimento numero

    do
    {
        printf ("%d", contatore);
        // stampa valore per fare la somma (1 + 2 + 3 etc.)
        
        dim = dim + contatore;
        contatore ++;
        // dim aumenta grazie al contatore il quale aumenta ad ogni ciclo di +1

        if (num > dim)
            printf (" + ");
        // se è l'ultimo numero, il + non viene stampato

    } while (num > dim);
    // algoritmo, finché il numero è minore di "Q", bisogna continuare

    printf (" = %d\n", dim);
    // stampa di uguale, fattore grafico
    
    if (num == dim)
        printf ("Il numero inserito e' un numero triangolare\n");
    else
        printf ("Il numero non e' un numero triangolare\n");
    // stampo risultato, dico se triangolare o no
    
}