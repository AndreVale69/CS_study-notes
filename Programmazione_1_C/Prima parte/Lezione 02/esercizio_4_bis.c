// Scrivere un programma in C che acquisisce un
// carattere da tastiera e lo visualizza. In seguito il
// programma chiede un altro carattere e lo visualizza

#include <stdio.h>
void main ()
{
    char c, enter;
    printf ("Inserire un carattere: ");
    scanf (" %c", &c);
    //scanf ("%c", &enter);
    printf ("Il carattere digitato: %c\n", c);
    printf ("Inserire un secondo carattere: ");
    scanf (" %c", &c);
    //scanf ("%c", &enter);
    printf ("Il carattere digitato: %c\n", c);
}