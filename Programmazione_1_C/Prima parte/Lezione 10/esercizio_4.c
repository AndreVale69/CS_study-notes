/*
 * Scrivere sottoprogramma "conta" che preso come parametro un array di
 * caratteri e la sua dimensione, conta quante vocali minuscole sono presenti
 * nell’array e restituisce il valore al chiamante.
 * Il "main" chiede in ingresso all’utente un array di 10 caratteri, richiamando
 * il sottoprogramma conta stampa il numero di vocali nell’array.
 */
#include <stdio.h>
#define N 10

char conta (char array [N]);

void main ()
{
    char array [N];
    int voc_min;
    // array   = array originale
    // voc_min = var risultato delle vocali

    // Inserimento valori all'interno di un array
    for (int i = 0; i < N; i++)
    {
        printf ("Inserire il %d° carattere: ", i + 1);
        scanf (" %c", &array [i]);
    }
    
    // Invocazione funzione e salvataggio risultato
    voc_min = conta (array);

    // Stampa risultato
    printf ("Le vocali nell'array sono: %d.\n", voc_min);
}

char conta (char array [N])
{
    int voc_min = 0;
    // voc_min = contatore di vocali

    for (int i = 0; i < N; i++)
        if (array [i] == 97 || array [i] == 101 || array [i] == 105 || array [i] == 111 || array [i] == 117)
            voc_min ++;
    // CODICE ASCII:
    // a = 97, e = 101, i = 105, o = 111, u = 117
    return voc_min;
}