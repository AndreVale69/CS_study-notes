/*
 * Funzione 1.
 * Riceve come parametro d'ingresso una matrice quadrata NxN (con N definito
 * staticamente) di caratteri, ne individua il carattere che compare con
 * maggiore frequenza e lo restituisce.
 * In caso di molteplici caratteri, si utilizzi il primo trovato.
 * 
 * Funzione 2.
 * Riceve come parametri d'ingresso un carattere e una matrice quadrata NxN di
 * caratteri. Stampa sul terminale la medesima matrice sostituendo con uno
 * spazio tutti i caratteri uguali al carattere passato come parametro.
 * Infine, si scriva un main che ricerca il carattere che compare più
 * frequentemente in una matrice NxN definita dall'utente e stampa la matrice
 * mostrando uno spazio al posto dei caratteri uguali al carattere individuato.
 *
 * Es:
 * Input ->     a.cde
 *              fdffr
 *              tQfrd
 *              yyfwe
 *              f1bpf
 *
 * Output ->    a.cde
 *               d r
 *              tQ rd
 *              yy we
 *               1bp
 */
#include <stdio.h>
#define N 5

char funzione_1 (char matrix [N] [N]);
char funzione_2 (char matrix [N] [N], char car);

void main ()
{
    char matrix [N] [N], car;
    // matrix = matrice
    // car    = carattere con piu' occorrenze

    /****** Inserimento caratteri nella matrice ******/
    printf ("\nInserisci caratteri nella matrice %dx%d\n\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf ("Inserire carattere %dx%d (Riga x Colonna): ", i+1, j+1);
            scanf (" %c", &matrix [i] [j]);
        }
    printf ("\n");
    
    /****** Invocazione prima funzione e Salvataggio risultato in "car" ******/
    car = funzione_1 (matrix);

    /****** Invocazione seconda funzione e Stampa risultato con sostituzione ******/
    funzione_2 (matrix, car);
}

char funzione_1 (char matrix [N] [N])
{
    char arr_supp [N*N], car;
    int ind = 0, count, max, i, j;
    // arr_supp = array di supporto per evitare "sporcizia" nel codice
    // car      = carattere con piu' occorrenze e da restituire
    // ind      = indice per la copiatura e successivamente var flag
    // count    = contatore di occorrenze
    // max      = occorrenze massime, inizializzato all'entrata del for
    // i        = indice dichiarato qua per evitare rindondanza di scritte "int"
    // j        = indice dichiarato qua per evitare rindondanza di scritte "int"

    /****** Copiatura matrice in un array di supporto ******/
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            arr_supp [ind] = matrix [i] [j];
            ind ++;
        }
    /* Ho optato per un utilizzo di un array di supporto per evitare di
       utilizzare 4 for. Il motivo di cie' e' dovuta ad una maggior comprensione
       del codice. Infatti, e' preferibile utilizzare al massimo 3 for, gia' il
       4° diventerebbe di difficile comprensione al programmatore
       (non al creatore ovviamente). */    

    /****** Controllo rindondanza e Conteggio occorrenze ******/
    for (i = 0, max = 0; i < N*N; i++)
    {
        /* Effettuo un controllo per vedere se ci sono doppioni per evitare un
           conteggio doppio */
        for (j = 0, ind = 0; j < i; j++)
            if (arr_supp [j] == arr_supp [i])
                ind = 1;
        
        // Se non ci sono doppioni, inizio con il conteggio e verifico max
        if (!ind)
        {
            for (j = i, count = 0; j < N*N; j++)
                if (arr_supp [j] == arr_supp [i])
                    count ++;
            if (max < count)
            {
                max = count;
                car = arr_supp [i];
            }
        }
    }
    // Infine return del risultato, quindi "car"
    return car;
}

char funzione_2 (char matrix [N] [N], char car)
{
    /****** Stampa del risultato con sostituzione spazio ******/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (matrix [i] [j] == car)
                printf ("  ");
            else
                printf ("%c ", matrix [i] [j]);
        printf ("\n");
    }
}