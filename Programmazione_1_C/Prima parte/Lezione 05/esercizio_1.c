/*
 * Scrivere un programma che calcoli il massimo comun divisore e il minimo 
 * comune multiplo di due numeri inseriti dall’utente. Entrambi i numeri 
 * inseriti devono essere maggiori di zero.
 */

#include <stdio.h>

int main ()
{
    /****** Dichiarazione variabili ******/
    int num1, num2, min, MCD = 1, mcm;
    // num1 = primo   numero
    // num2 = secondo numero
    // min  = minimo tra i due numeri
    // MCD  = massimo comun divisore
    // mcm  = minimo comune multiplo

    /****** Inserimento e controllo ******/
    do
    {
        printf ("Inserire il primo numero: ");
        scanf ("%d", &num1);
        // inserimento primo numero

        printf ("Inserire il secondo numero: ");
        scanf ("%d", &num2);
        // inserimento secondo numero
        
        if (num1 < 0 && num2 < 0)
        {
            printf ("Entrambi i numeri sono minori di 0.\n");
            printf ("Si prega di reinserire i numeri.\n\n");
        }
        else
        {
            if (num1 < 0)
            {
                printf ("Il primo numero inserito e' minore di 0.\n");
                printf ("Si prega di reinserire i numeri.\n\n");
            }
            else
            {
                if (num2 < 0)
                {
                    printf ("Il secondo numero inserito e' minore di 0.\n");
                    printf ("Si prega di reinserire i numeri.\n\n");
                }
                else
                {
                    min = num2;
                    if (num1 < num2)
                        min = num1;
                }
            }
        }

    } while ((num1 < 0) || (num2 < 0));

    if (num1 != 0 && num2 != 0)
    {

        /****** Algoritmo MCD ******/
        for (int i = 1; i < min; i++)
        {
            if ((num1 % i == 0) && (num2 % i == 0))
            {
                if (i > MCD)
                    MCD = i;
            }
        }
        printf ("Il massimo comun divisore e': %d\n", MCD);

        /****** Algoritmo mcm ******/
        if(num1<num2)
	        mcm = num2;
        else
            mcm = num1;
        while(mcm % num1 != 0 || mcm % num2 != 0)
	        mcm++;

        printf ("Il minimo comune multiplo e': %d\n", mcm);
    }
    else
    {
        printf ("Il massimo comun divisore e': 0\n");
        printf ("Il minimo comune multiplo e': 0\n");
    }
}