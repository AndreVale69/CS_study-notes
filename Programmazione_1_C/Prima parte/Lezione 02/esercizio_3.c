// Scrivere in linguaggio C un programma per calcolare il
// numero di bottigliette d’acqua che si possono comprare
// alla macchinetta.
// Il programma, dopo aver chiesto
// all’utente i soldi a disposizione, stampa a video il numero
// di bottigliette che possono essere acquistate e il resto da 
// ricevere dopo l’acquisto. Il prezzo di ciascuna bottiglietta è
// di 40 centesimi. Si supponga che la cifra a disposizione sia
// positiva e che la macchinetta abbia in giacenza un numero
// illimitato di bottigliette. Per erogare il resto, la 
// macchinetta utilizza pezzi da 20, 10, 5 e 1 centesimi: il
// programma dovrà calcolare il numero di monete di resto di 
// ciascun taglio, prediligendo l’utilizzo di monete di taglio
// maggiore (ad esempio, se il resto è di 0.37 €, il programma
// dovrà restituire: 1*20 cent, 1*10 cent, 1*5 cent, 2*1 cent).
// Suggerimento: moltiplicare il valore della cifra a 
// disposizione per 100 per ottenere il numero di centesimi ed
// eseguire il cast del valore ad int.

#include <stdio.h>
#define bottiglia 0.40

//void calcolatore (int soldi);

int main ()
{
    int conto_20c = 0, conto_10c = 0, conto_05c = 0, tot_b;
    // conto_20c = conteggio dei 20 cent
    // conto_10c = conteggio dei 10 cent
    // conto_05c = conteggio dei 05 cent
    // tot_b     = totale bottiglie
    // 

    float soldi, ris, tot_s, resto;
    // soldi     = soldi posseduti dall'utente
    // ris       = risultato
    // tot_s     = totale speso
    // resto     = resto da dare
    //


    //Inserimento utente
    printf ("Quanti soldi avete a disposizione? ");
    scanf ("%f", &soldi);
    

    //Calcolo per i confronti
    tot_b = soldi / bottiglia;
    tot_s = tot_b * bottiglia;
    resto = soldi - tot_s;
    

    //Stampa numero bottiglie
    printf ("Il numero delle bottigliette e': %d \n", tot_b);
    
    
    //Confronto 20 cent
    while (resto > 0.19)
    {
        conto_20c ++; //conta pezzi da 20 cent
        resto = resto - 0.20;
    }
    printf ("Servono %d pezzi da 20 cent\n", conto_20c);


    //Confronto 10 cent
    while (resto > 0.09)
    {
        conto_10c ++; //conta pezzi da 10 cent
        resto = resto - 0.10;
    }
    printf ("Servono %d pezzi da 10 cent\n", conto_10c);


    //Confronto 5 cent
    while (resto > 0.04)
    {
        conto_05c ++; //conta pezzi da 5 cent
        resto = resto - 0.05;
    }
    printf ("Servono %d pezzi da 5 cent\n", conto_05c);


    //Confronto 1 cent
    /*Ho deciso di fare così per problemi relativi alle approssimazioni*/

    if (resto == 0.04)
        printf ("Servono 4 pezzi da 1 cent\n");
    else
        if (resto == 0.03)
            printf ("Servono 3 pezzi da 1 cent\n");
        else
            if (resto == 0.02)
                printf ("Servono 2 pezzi da 1 cent\n");
            else
                if (resto == 0.01)
                    printf ("Serve 1 pezzo da 1 cent\n");
                else
                    printf ("Servono 0 pezzi da 1 cent\n");
}