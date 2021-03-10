/*
 * ○ Scrivere un programma C composto da:
 * 
 * ● Una funzione "leggi" che richiede all’utente 10 numeri interi non negativi
 *   nell’intervallo [0,10] e li memorizza in un array.
 * 
 * ● Una funzione "media" che calcola la media dei voti inseriti.
 * 
 * ● Una funzione "moda" cha calcola la moda dei voti inseriti.
 *      ○ La moda è il valore che compare più frequentemente. In caso ci siano
 *        più numeri con la stessa frequenza ritornare uno qualsiasi di essi.
 *      ○ Usare un array aggiuntivo per memorizzare le frequenze.
 * 
 * ● Una funzione "mediana" che calcola la mediana dei voti inseriti:
 *      ○ Dato un array di "n" elementi ordinati, la mediana è il valore centrale:
 *          ○ Se "n" è dipari la mediana è il valore che occupa la posizione
 *            (n+1)/2.
 *          ○ Se "n" è pari la mediana è la media dei valori che occupano la
 *            posizione n/2 e (n/2)+1.
 *      ○ Tale funzione richiamerà una funzione "ordina" che ordina gli elementi
 *        dell’array e li memorizza in un altro array.
 * 
 * ● Una funzione "main" che richiama le altre funzioni e stampa i risultati
 *   ottenuti.
 * 
 * ○ Le funzioni parametriche nella dimensione dell’array
 */
#include <stdio.h>
#define N 10

int leggi (int array [N]);
float media (int array [N]);
int moda (int array [N], int frequenze [N]);
int mediana (int array [N], int ordinamento [N], int median [N]);
int ordina (int ordinamento [N], int array [N]);


void main ()
{
    int array [N], frequenze [N], freq, ordinamento [N], median [2];
    float medi;
    // array       = array dove vengono memorizzati i valori
    // frequenze   = array relative frequenze per ogni numero
    // ordinamento = array con valori ordinati
    // freq        = salvataggio del valore con piu' frequenza
    // median      = array per salvare mediana
    // medi        = media

    /****** Inserimento array ******/
    leggi (array);

    /****** Media ******/
    medi = media (array);

    /****** Valore con piu' frequenza ******/
    freq = moda (array, frequenze);

    /****** Mediana ******/
    mediana (array, ordinamento, median);

    /****** Stampa risultato ******/
    printf ("La media e': %.2f.\n", medi);
    printf ("Il valore con piu' frequenza e': %d.\n", freq);
    if (N % 2 == 0)
        for (int i = 0; i < 2; i++)
            printf ("La mediana (array pari) sono: %d.\n", median [i]);
    else
        printf ("La mediana (array dispari) e': %d.\n", median [0]);
}

int leggi (int array [N])
{
    int n;
    // n = numero inserito

    /****** Richiesta inserimento e Controllo condizioni ******/
    for (int i = 0; i < N; i++)
        do
        {
            printf ("Inserire valore non negativo [0,10]: ");
            scanf ("%d", &n);
            if (n < 0 || n > 10)
                printf ("Valore errato!\n");
            else
                array [i] = n;
        } while (n < 0 || n > 10);
}

float media (int array [N])
{
    float med, ris = 0;
    // med = valore da restituire (conterra' la media)
    // ris = somma di tutti i valori dell'array

    // Somma di tutti i valori
    for (int i = 0; i < N; i++)
        ris += array [i];

    // Divisione della somma per la quanita'
    med = ris / N;

    // Return del risultato
    return med;
}

int moda (int array [N], int frequenze [N])
{
    int freq, count = 0, max = 0;
    // freq  = numero con piu' frequenza nell'array
    // count = contatore di frequenza
    // max   = var massima

    // Contatore di frequenza e Salvataggio risultato (anche nell'array)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (array [i] == array [j])
                count ++;
        }
        // Nella posizione i c'e' la frequenza di ogni numero
        frequenze [i] = count;
        if (count > max)
        {
            max = count;
            freq = array [i];
        }
        count = 0;
    }
    // Return del risultato
    return freq;
}

int mediana (int array [N], int ordinamento [N], int median [N])
{
    /****** Ordinamento array ******/
    ordina (ordinamento, array);

    // Se numero valori pari, eseguiamo questo algoritmo di salvataggio
    if (N % 2 == 0)
    {
        median [0] = ordinamento [(N / 2) - 1];
        median [1] = ordinamento [N / 2];
    }
    else
        median [0] = ordinamento [((N + 1) / 2) - 1];
}

int ordina (int ordinamento [N], int array [N])
{
    int min, j = 0, ind_min;
    // min     = valore minimo
    // j       = indice progressivo
    // ind_min = indice corrispondente al valore minimo

    /****** Copia dell'array ******/
    for (int i = 0; i < N; i++)
        ordinamento [i] = array [i];

    do
    {
        min = ordinamento [j];
        for (int i = j; i < N; i++)
        {
            if (ordinamento [i] < min)
            {
                min = ordinamento [i];
                ind_min = i;
            }
        }
        ordinamento [ind_min] = ordinamento [j];
        ordinamento [j] = min;
        j ++;
    } while (j < N - 1);
    /*************************************************************************/
    /**************** SPIEGAZIONE ALGORITMO DI ORDINAMENTO ********************
     * Il minimo viene assegnato al valore dell'array con indice j (inizialm= *
     * =ente uguale a 0). Nel for si cerca il valore minimo. Il valore minimo *
     * viene salvato in min, il suo indice in ind_min. Alla fine del ciclo,   *
     * nell'array ordinamento viene salvato il valore attuale di j. Valore    *
     * salvato nella posizione del minimo. Nell'array ordinamento con indice  *
     * j, viene salvato il valore min e l'indice aumentera'.                  *
     * Al ciclo successivo, il controllo del valore minimo verra' effettuato  *
     * dal valore gia' controllato precedentemente in poi (quindi N - 1).     *
     * L'intero ciclo prosegue finche' j non e' maggiore di 8.                *
     *************************************************************************/
}