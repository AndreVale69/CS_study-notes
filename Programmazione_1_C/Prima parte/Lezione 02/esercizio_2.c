// Scrivere un programma che chiede all’utente una velocità
// in km/h, la converte e visualizza a schermo in m/s e miglia
// per ora (1 km/h= 0.64 Mph)

#include <stdio.h>

void convertire_ms (int vel); // converte km/h in m/s
void convertire_mph (int vel); // converte km/h in mph

int main ()
{
    char risp; // risposta
    int vel; // velocità
    do
    {
        printf ("Inserire la velocità in km/h, verra' convertita in m/s e Mph: ");
        scanf ("%d", &vel);
        convertire_ms (vel); // funzione da km/h a m/s
        convertire_mph (vel); // funzione da km/h a mph
        printf ("Continuare? Yes[y] or No[n]: ");
        scanf (" %c", &risp); // risposta per il ciclo
    } while (risp == 'y');
    
}

void convertire_ms (int vel)
{
    float conv;
    conv = vel / 3.6;
    printf ("%d km/h viene convertito e diventa %f m/s\n", vel, conv);
}

void convertire_mph (int vel)
{
    float conv;
    conv = vel * 0.6213711922;
    printf ("%d km/h viene convertito e diventa %f Mph\n", vel, conv);
}