// Scrivere un programma C che classifica un
// carattere immesso da tastiera come:
// alfabetico (az oppure A-Z),
// cifra (0-9),
// speciale (tutti gli altri).
#include <stdio.h>
void main ()
{
    int num, flag;
    char car, ris, car_con_pic = 'a', car_con_mai = 'A'; /* car=carattere; ris=risposta; car_con_pic=carattere di confronto piccolo e mai grande*/
    do
    {
        printf ("Inserisci un carattere: ");
        scanf (" %c", &car);
        //Confronto Numeri
        if ((car > 47) && (car < 58))
            printf ("Il carattere immesso e' una cifra\n");
        else
            //Confronto Lettere Maiuscole
            if ((car > 64) && (car < 91))
                printf ("Il carattere immesso e' una lettera maiuscola\n");
            else
                //Confronto Lettere Minuscole
                if ((car > 96) && (car < 123))
                    printf ("Il carattere immesso e' una lettera minuscola\n");
                else
                    printf ("Il carattere immesso e' un carattere speciale\n");
        printf ("Vuoi continuare? YES[y] or NO[n]: ");
        scanf (" %c", &ris);
    } while (ris == 'y');
    
}