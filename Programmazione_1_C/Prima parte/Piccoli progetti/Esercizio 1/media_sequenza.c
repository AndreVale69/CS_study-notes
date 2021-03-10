/*
TESTO ESERCIZIO:
Scrivere un programma C per calcolare la media, il massimo 
ed il minimo di una sequenza di voti inseriti dall'utente. 
I valori ammessi devono essere maggiori o uguali a 18 
e minori o uguali a 30. L'inserimento dei voti prosegue fino 
a quando l'utente non inserisce un numero non valido 
(cioè minore di 18 o maggiore di 30).
Subito dopo l'immissione del valore di fine inserimento vengono 
visualizzati media, massimo, minimo ed il numero di voti inseriti.
Qualora il primo valore inserito fosse di fine inserimento 
dovrà essere visualizzato un messaggio di errore.
*/
#include <stdio.h>

int main ()
{
    int voto, max = 0, min = 30, contatore = 0;
    // voto      = voto inserito dall'utente
    // max       = massimo voto inserito
    // min       = minimo voto inserito.
    /* contatore = contiene il numero di volte che viene eseguito il ciclo while */

    float med = 0;
    // med       = media dei voti

    printf ("Inserire il voto (per terminare inserire un numero > 30 o < 18): ");
    scanf ("%d", &voto);
    // Richiesta inserimento voto

    if ((voto > 17) && (voto < 31))
    /* Controllo se l'utente ha inserito un valore errato. In tal caso, stampo errore */
    {
        while ((voto > 17) && (voto < 31))
        {
            if (voto > max)
                max = voto;
            /* Voto è maggiore di max? Allora assegno a max il valore di voto */

            if (voto < min) 
                min = voto;
            /* Se voto è minore di min, assegno valore a min.
               La prima volta nel ciclo, voto sarà sicuramente minore
               di 30. Al massimo sarà uguale ed a noi andrà bene.
               Ecco perché ho inizializzato min a 30 al momento della dichiarazione */
            
            med += voto;
            /* Variabile med incrementa ad ogni ciclo (esegue la somma di tutti i voti) */

            contatore ++;
            // Aumento il contatore del ciclo

            printf ("Inserire il voto (per terminare inserire un numero > 30 o < 18): ");
            scanf ("%d", &voto);
            // Richiedo di inserire il voto per proseguire o terminare
        }
        printf ("Il valore minimo e' : %d\n", min);
        // Stampo valore minimo

        printf ("Il valore massimo e': %d\n", max);
        // Stampo valore massimo

        med /= contatore;
        printf ("La media dei voti e': %.2f\n", med);
        /* Eseguo prima la divisione tra la somma dei voti e il quantità dei voti. 
           Dopodiché stampo il risultato con solo due numeri dopo la virgola. */
    }
    else
        printf ("Errore, il valore inserito non e' valido\n");
    /* Nel testo non viene specificato se dopo il messaggio di errore,
       bisogna far decidere all'utente se 'riavviare' il programma oppure no.
       Io ho ipotizzato che dopo il messaggio di errore,
       il programma finisca senza dare l'opportunità di essere 'riavviato'
       (avrei utilizzato un do...while(); per 'riavviare' il programma). */
}