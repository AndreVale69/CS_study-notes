/*
 * Scrivere un programma per la verifica dei codici ISBN-10. Un codice ISBN-10
 * è una sequenza numerica di 10 cifre (da 0 a 9) e, per verificarne la
 * validità:
 * 
 * (i) si moltiplica ogni cifra per un peso in base alla posizione della cifra
 * stessa: la prima cifra per 10, la seconda per 9, la terza per 8 e così via;
 * 
 * (ii) si sommano i risultati;
 * 
 * (iii) la somma deve essere un multiplo intero di 11.
 * 
 * Ad esempio:
 * ○ ISBN: 0078818095
 * 0*10 + 0*9 + 7*8 + 8*7 + 8*6 + 1*5 + 8*4 + 0*3 + 9*2 + 5*1 = 220
 * 220 è un multiplo di 11, di conseguenza il codice ISBN è valido.
 * Nella risoluzione dell’esercizio si implementi la seguente funzione:
 * int valido (int isbn[]) che riceve in ingresso un codice ISBN e restituisce
 * 1 se èvalido, 0 altrimenti.
 */
#include <stdio.h>
#define N 10

int valido (int isbn [N]);

void main ()
{
    int isbn [N], ris;
    // isbn = array contenente le cifre isbn
    // ris  = risultato da stampare

    /****** Inserimento array ******/
    printf ("\nInserire un ISBN valido:\n");
    for (int i = 0; i < N; i++)
            scanf ("%d", &isbn [i]);
    
    /****** Invocazione funzione e Salvataggio risultato ******/
    ris = valido (isbn);

    /****** Stampa risultato ******/
    if (ris == 1)
        printf ("\nISBN corretto!\n");
    else
        printf ("\nISBN errato!\n");
}

int valido (int isbn [N])
{
    int ris = 1, molt, som = 0;
    // ris  = risultato da ritornare
    // molt = var che salva ogni moltiplicazione
    // som  = somma ogni moltiplicazione

    /****** Controllo correttezza cifre ******/
    for (int i = 0; i < N && ris == 1; i++)
        if (isbn [i] < 0 || isbn [i] > 9)
            ris = 0;

    /****** Se le cifre sono corrette, eseguo il controllo dettagliato ******/
    if (ris == 1)
    {
        // Moltiplicazione e somma
        for (int i = N; i > 0; i--)
            for (int j = 0; j < N; j++)
            {
                molt = i * isbn [j];
                som += molt;
            }
        // In base al multiplo, decido che risultato ritornare
        if (som % 11 == 0)
            return 1;
        else
            return 0;
    }
    else
        return ris;
}