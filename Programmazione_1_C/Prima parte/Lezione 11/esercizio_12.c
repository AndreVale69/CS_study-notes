/*
 * Si vuole realizzare un programma che permetta di giocare al gioco del 15.
 * In tale gioco, una scacchiera 4x4 contiene 15 pezzi (numerati da 1 a 15)
 * ed una casella vuota (rappresentata da uno 0).
 * Il giocatore ad ogni mossa può spostare uno dei pezzi adiacenti alla casella
 * vuota nella casella vuota stessa. Le mosse sono specificate indicando il
 * numero del pezzo da spostare e il gioco continua fino a quando tutti i numeri
 * non compaiono nell’ordine numerico corretto (crescente, con la casella vuota
 * nell’angolo in basso a destra).
 * Nel seguente esempio:
 *                          8  5  2  4
 *                         11  1  0  7
 *                         12 10  3 15
 *                          9 13 14  6
 * 
 * Le mosse possibili sono: 2, 1, 7, 3.
 * Se il giocatore sceglie la mossa 3, le mosse possibili diventano: 3, 10, 15, 14.
 * Nella risoluzione dell’esercizio l’inserimento può essere forzato in fase di
 * inizializzazione della matrice
 * (ad esempio, 
 * int gioco [N][N] = 
 * {
 *      {8,5,2,4},
 *      {11,1,0,7},
 *      {12,10,3,15},
 *      {9,13,14,6}
 * };)
 * Si implementino le seguenti funzioni: 
 * 
 * a) int valida (int gioco [N][N], int mossa); che riceve la scacchiera e una
 *    mossa e restituisce 1 se la mossa è valida, 0 altrimenti.
 * 
 * b) void muovi (int gioco [N][N], int mossa); che riceve la scacchiera e una
 *    mossa e aggiorna la scacchiera in base alla mossa effettuata.
 * 
 * c) int risolto (int gioco [N][N]); che riceve la scacchiera e restituisce 1
 *    se il gioco è stato risolto, 0 altrimenti.
 * 
 * d) void stampa (int gioco [N][N]); che riceve la scacchiera e la stampa a video.
 */
#include <stdio.h>
#define N 4

int valida (int gioco [N][N], int mossa);
void muovi (int gioco [N][N], int mossa);
int risolto (int gioco [N][N]);
void stampa (int gioco [N][N]);

void main ()
{
    int gioco [N] [N], mossa, ris, ris_mos, count = 0;
    // gioco   = matrice contenente la scacchiera
    // mossa   = valore corrispondente al numero in una cella della scacchiera
    // ris     = risultato della vittoria o meno
    // ris_mos = risultato validita' mossa inserita dall'utente
    // count   = contatore tentativi utente

    /****** Inserimento scacchiera ******/
    printf ("\nInserimento scacchiera\n\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserisci valore nella posizione %dx%d (RxC): ", i+1, j+1);
            scanf ("%d", &gioco [i] [j]);
        }

    /****** Invocazione funzione della stampa della scacchiera ******/
    stampa (gioco);

    /****** Algoritmo di richiamo di funzioni (cuore del gioco) ******/
    do
    {
        // Inserimento mossa
        printf ("Inserire la %d° mossa: ", count + 1);
        scanf ("%d", &mossa);

        /****** Invocazione funzione della validita' della mossa ******/
        ris_mos = valida (gioco, mossa);

        /****** Invocazione funzione per muovere valore o stampa errore ******/
        if (ris_mos == 1)
            muovi (gioco, mossa);
        else
            printf ("Mossa errata!\n");

        /****** Invocazione funzione controllo vincita ******/
        ris = risolto (gioco);
        // Stampa temporaneo Game Over
        if (ris == 0)
            printf ("\nIl gioco ancora non e' stato risolto\n\n");

        /****** Invocazione funzione della stampa della scacchiera ******/
        stampa (gioco);

        // Contatore cicli/mosse
        count ++;
    } while (ris == 0);
    
    /****** Stampa risultato ******/
    printf ("\nIl gioco e' stato risolto in %d mosse!\n", count);
}

int valida (int gioco [N][N], int mossa)
{
    /****** Algoritmo controllo mosse ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (gioco [i] [j] == 0)
            {
                if (mossa == gioco [i] [j])
                    return 0;

                if ((i > 0 && i < N-1) && (j > 0 && j < N-1))
                    if ((mossa == gioco [i+1] [j] || mossa == gioco [i-1] [j]) || (mossa == gioco [i] [j+1] || mossa == gioco [i] [j-1]))
                        return 1;
                    else
                        return 0;

                if (i == 0 && j == 0)
                    if (mossa == gioco [i+1] [j] || mossa == gioco [i] [j+1])
                        return 1;
                    else
                        return 0;

                if (i == 0 && (j > 0 && j < N-1))
                    if (mossa == gioco [i+1] [j] || mossa == gioco [i] [j+1] || mossa == gioco [i] [j-1])
                        return 1;
                    else
                        return 0;

                if (i == 0 && j == N-1)
                    if (mossa == gioco [i+1] [j] || mossa == gioco [i] [j-1])
                        return 1;
                    else
                        return 0;
                
                if (i == N-1 && j == 0)
                    if (mossa == gioco [i-1] [j] || mossa == gioco [i] [j+1])
                        return 1;
                    else
                        return 0;

                if (i == N-1 && j == N-1)
                    if (mossa == gioco [i-1] [j] || mossa == gioco [i] [j-1])
                        return 1;
                    else
                        return 0;

                if (i == N-1 && (j > 0 && j < N-1))
                    if (mossa == gioco [i-1] [j] || mossa == gioco [i] [j+1] || mossa == gioco [i] [j-1])
                        return 1;
                    else
                        return 0;

                if ((i > 0 && i < N-1) && j == 0)
                    if (mossa == gioco [i-1] [j] || mossa == gioco [i+1] [j] || mossa == gioco [i] [j+1])
                        return 1;
                    else
                        return 0;

                if ((i > 0 && i < N-1) && j == N-1)
                    if (mossa == gioco [i-1] [j] || mossa == gioco [i+1] [j] || mossa == gioco [i] [j-1])
                        return 1;
                    else
                        return 0;
            }    
}

void muovi (int gioco [N][N], int mossa)
{
    int ind_i, ind_j;
    // ind_i = indice riga del nuovo zero
    // ind_j = indice colonna del nuovo zero

    /****** Individuare il valore dell'utente e salvare indici ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (gioco [i] [j] == mossa)
            {
                gioco [i] [j] = 0;
                ind_i = i;
                ind_j = j;
            }
    
    /****** Individuare vecchio zero e sostituirlo con il nuovo valore ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (gioco [i] [j] == 0 && (ind_i != i || ind_j != j))
                gioco [i] [j] = mossa;
}

int risolto (int gioco [N][N])
{
    int count = 0;
    // count = contatore

    /****** Conteggio della condizione di vittoria ******/
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N-1; j++)
            if (gioco [i] [j] < gioco [i] [j+1])
                count ++;
    
    /****** Controllo posizione zero e conteggio ******/
    if (count == (((N*N) - N) - 1))
        if (gioco [N-1] [N-1] == 0)
            return 1;
        else
            return 0;
    else
        return 0;
    /* Se il conteggio e' uguale a 11 (nel caso di N = 4), vuol dire che tutti
       i valori sono in ordine crescente. L'unico fuori posto e' lo zero.
       Quindi, se lo zero si trova nella posizione giusta, ovvero in basso a
       destra, la partita e' vinta. */
}

void stampa (int gioco [N][N])
{
    /****** Stampa della scacchiera ******/
    printf ("\nLa scacchiera e' la seguente\n\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf (" %d ", gioco [i] [j]);
        printf ("\n");
    }
}