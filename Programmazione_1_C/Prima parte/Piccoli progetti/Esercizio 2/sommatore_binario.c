/*
 * Scrivere un programma in C per calcolare la somma di due numeri binari.
 * I due valori dovranno essere inseriti dall'utente. Il programma dovra', 
 * innanzitutto, controllare se i due numeri inseriti siano effettivamente 
 * espressi in notazione binaria. Qualora i valori inseriti fossero errati 
 * dovrà essere visualizzato un messaggio di errore, al quale, seguirà la 
 * terminazione del programma.
 *
 * Es: v1 = 100101; v2 = 111;
 *     v1 = 110110; v2 = 1310; -> ERRORE!
 *
 * Si dovra', quindi, effettuare la somma dei due valori inseriti e stampare 
 * il risultato. La somma deve essere svolta bit a bit, dunque, non è ammessa 
 * la conversione del numero binario.
 *
 * Es:
 *           111  <- carry bit (riporto)
 *      ---------
 *         100101 +
 *            111 =
 *      ---------
 *         101100
 */

#include <stdio.h>

void main ()
{
    /****** Inizializzazione delle variabili ******/

    int v1, v2, temp_v1, temp_v2, m1, m2, errore = 0, ris_temp, carry = 0;
    // v1       = primo valore binario
    // v2       = secondo valore binario
    // temp_v1  = var temporanea per controllo del primo valore
    // temp_v2  = var temporanea per controllo del secondo valore
    // m1       = modulo della divisione per controllare il primo numero
    // m2       = modulo della divisione per controllare il secondo numero
    // errore   = flag di uscita dal ciclo
    // ris_temp = risultato temporaneo/var di lavoro
    // carry    = var di riporto

    int count_ciclo = 0, ris = 0;
    // count_ciclo = contatore esecuzione ciclo
    // ris         = risultato finale 


    /****** Inserimento valori ******/

    printf ("Inserire primo numero binario  : ");
    scanf ("%d", &v1);
    // inserimento primo valore

    temp_v1 = v1;
    // var temporanea prende il valore del primo numero binario inserito

    printf ("Inserire secondo numero binario: ");
    scanf ("%d", &v2);
    // inserimento secondo valore

    temp_v2 = v2;
    // var temporanea prende il valore del secondo numero binario inserito


    /****** Controllo cifre dei numeri ******/

    while ((temp_v1 != 0 || temp_v2 != 0) && errore == 0)
    {
        m1 = temp_v1 % 10;
        m2 = temp_v2 % 10;
        // entrambi le var prendono il modulo (resto) di ogni numero inserito

        if ((m1 != 0 && m1 != 1) || (m2 != 0 && m2 != 1))
            errore ++;
        /* se i moduli sono diversi da 0 e 1, allora il falg errore viene
           impostato ad 1, cioe' l'utente ha inserito un numero non i base 2 */
        
        temp_v1 /= 10;
        temp_v2 /= 10;
        /* alla fine di ogni ciclo le var di lavoro contenenti le cifre,
           vengono divise per 10 per poter esaminare le cifre successive. */
    }
    /* finché le var temporali sono diverse da 0 e la var flag errore e'
       diversa da 0, il ciclo viene eseguito. */

    if (errore == 1)
        printf ("Cifre inserite sbagliate. Terminazione del programma\n");
    // se var flag errore e' stata impostata ad uno, il programma termina
    else
    {

        /****** Algoritmo della somma binaria ******/
        
        while (v1 != 0 || v2 != 0)
        // finche' i due numeri sono maggiori di 0, il ciclo prosegue
        {
            m1 = v1 % 10;
            m2 = v2 % 10;
            /* di nuovo, le var modulo prendono il resto di ogni numero per
               sommare ogni cifra. */

            ris_temp = m1 + m2;
            /* nella var 'risultato temporaneo' salvo il risultato temporaneo
               della somma. */

            if (ris_temp == 0 && carry == 1)
            {
                ris_temp = 1;
                for (int i = 1; i <= count_ciclo; i++)
                {
                    ris_temp *= 10;
                }
                ris += ris_temp;
                carry = 0;
                /* se il risultato dei moduli e' zero e abbiamo
                   un riporto, allora inserisco l'uno nel risultato tramite
                   questo piccolo algoritmo. Infine, imposto il riporto
                   utilizzato a zero. */
            }
            else
            {
                if (ris_temp == 1 && carry == 0)
                {
                    for (int i = 1; i <= count_ciclo; i++)
                    {
                        ris_temp *= 10;
                    }
                    ris += ris_temp;
                    /* se il risultato e' uno, quindi studiamo il caso 1+0
                       oppure 0+1, ma senza riporto, inseriamo l'uno nel
                       risultato tramite il nostro algoritmo for e somma */
                }
                else
                {
                    if (ris_temp == 2 && carry == 0)
                    {
                        carry = 1;
                        /* infine, se il risultato temporaneo e' due e non e'
                           presente il riporto, aggiorniamo ad uno il riporto 
                        */
                    }
                    else
                    {
                        if (ris_temp == 2 && carry == 1)
                        {
                            ris_temp = 1;
                            for (int i = 1; i <= count_ciclo; i++)
                            {
                                ris_temp *= 10;
                            }
                            ris += ris_temp;
                            /* altrimenti, se abbiamo un risultato di due e un
                            riporto di uno, dobbiamo inserire l'uno all'interno
                            del risultato tramite il classico algoritmo con
                            l'eccezione di impostare il risultato temporaneo ad
                            uno per evitare errori */
                        }
                    }
                }
            }

            v1 /= 10;
            v2 /= 10;
            count_ciclo ++;
            /* a questo punto, dividiamo il numero per proseguire con la somma
               delle altre cifre e aumentiamo l'accumulatore che conta le
               esecuzioni del ciclo. */
        }

        /****** Stampa risultato ******/
        
        if (carry == 1)
        {
            ris_temp = 1;
            for (int i = 0; i < count_ciclo; i++)
            {
                ris_temp *= 10;
            }
            ris += ris_temp;
            printf ("Il risultato e': %d\n", ris);
            /* una volta ottenuto il risultato, se il riporto e' rimasto ad
               uno, vuol dire che ci troviamo di fronte ad un caso di
               overflow. */
        }
        else
            printf ("Il risultato e': %d\n", ris);
            /* altrimenti stampo direttamente il risultato */
    }
}