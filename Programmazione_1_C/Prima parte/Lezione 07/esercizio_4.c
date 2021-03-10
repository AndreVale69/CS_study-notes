/*
 * Scrivere un programma che calcoli quanti elementi in una matrice occorrono
 * almeno due volte.
 */

#include <stdio.h>
#define D1 4
#define D2 6

int main()
{
    int M [D1] [D2] = {
                        {01,02,03,04,05,06},
                        {02,03,09,03,03,12},
                        {13,14,15,16,17,18},
                        {19,20,21,22,23,24}
                      };
    int V [D1*D2];
    int i, j, k = 0, flag = 0, c1 = 0, ctot = 0;
    // M    = array principale
    // V    = array di supporto
    // i    = indice per scorrere array bidimensionale e monodimensionale
    // j    = indice per scorrere array bidimensionale
    // k    = indice per scorrere array monodimensionale
    // flag = var booleana per controllare se ci sono doppioni o no
    // c1   = contatore di occorrenze
    // ctot = contatore di numeri con più di 2 occorrenze

    for (i = 0; i < D1; i++)
        for (j = 0; j < D2; j++)
        {
            V [k] = M [i] [j];
            k ++;
        }
    // Viene passato l'intero array bidimensionale ad un array monodimensionale

    for (k = 0; k < D1*D2; k++) 
    // Indice assegnato all'array che verrà confrontato con l'array intero
    {
        for (i = 0, flag = 0; i < k; i++)
		    if (V [i] == V [k])
		        flag = 1;
        // Algoritmo per cercare doppioni prima della posizione k

	    if (!flag)
        // Se flag = 0 vuol dire che non ci sono doppioni
        {
	        for (i = k, c1 = 0; i < D1*D2; i++)
		        if (V [i] == V [k])
		            c1 ++;
                /*
                 * Iniziamo a controllare dalla posizione k in poi.
                 * Quando troviamo una corrispondenza aumentiamo il contatore
                 */
	        if (c1 >= 2)
	            ctot ++;
            // Se il contatore è aumentato, aumentiamo il contatore di numeri
        }
        // Se flag = 1 vuol dire che ha trovato doppioni e salta
    }
    printf("Ci sono %d valori ripetuti almeno 2 volte\n",ctot);
}
