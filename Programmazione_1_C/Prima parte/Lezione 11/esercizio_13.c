/*
 * Si scriva una funzione "partiziona" che riceve un array di interi di
 * dimensione 10 e lo modifica in modo che tutti i numeri dispari precedano i
 * numeri pari. Si scriva quindi una funzione "main" che testa la funzione
 * chiedendo all’utente i valori per riempire un array, passa tale array alla
 * funzione partizione e lo stampa dopo la sua esecuzione.
 * Verrà penalizzata la soluzione che utilizza un array di supporto per
 * raggiungere la soluzione.
 * 
 * Esempio:
 * $ ./a.out
 *  Inserire 10 valori interi: 59 26 53 22 31 41 80 87 78 37
 *  Ecco i valori raggruppati: 53 59 41 31 87 37 22 26 80 78
 */
#include <stdio.h>
#define N 10

int partiziona (int array [N]);

void main ()
{
    int array [N];
    // array = array originale

    // Inserimento valori da parte dell'utente
    printf ("Inserire %d valori interi: ", N);
    for (int i = 0; i < N; i++)
            scanf ("%d", &array [i]);
    
    // Invocazione funzione per modifica dell'array
    partiziona (array);

    // Stampa dei risultati (array modificato)
    printf ("Ecco i valori raggruppati: ");
    for (int i = 0; i < N; i++)
        printf ("%d ", array [i]);
    printf ("\n");
}

int partiziona (int array [N])
{
    int flag = 0, temp;
    // flag = var per uscire dal ciclo
    // temp = var temporanea per prendere valore
    
    // Cerca numero dispari e lo cambia con un numero pari precedente
    for (int i = 0; i < N; i++)
    {
        if (array [i] % 2 != 0)
            for (int j = 0; j < i && flag == 0; j++)
                if (array [j] % 2 == 0)
                {
                    temp = array [j];
                    array [j] = array [i];
                    array [i] = temp;
                    flag = 1;
                }
        flag = 0;
    }
}