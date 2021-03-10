// Scrivere un programma che riceve in ingresso un angolo in 
// gradi e lo converte in radianti (rad= gradi * π / 180°)

#include <stdio.h>

float radianti (int ang);

int main ()
{
    int ang; //ang=angolo
    float rad; //rad=radianti
    char risp; //risp=risposta
    do
    {
        printf ("Inserire un angolo in gradi: ");
        scanf ("%d", &ang);
        rad = radianti (ang);
        printf ("L'angolo convertito in radianti e' = %f\n", rad);
        printf ("Vuoi continuare? Yes[y] oppure digita qualsiasi altro pulsante: ");
        scanf (" %c", &risp);
    } while (risp == 'y');
}

float radianti (int ang)
{   
    float rad;
    rad = ang * 3.14 / 180;
    return rad;
}