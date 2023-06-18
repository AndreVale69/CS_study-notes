#include "network.h"
  
int main()
{
    FILE *connessione, *destinazione;
    char filename[100], c;
  
    printf("[CLIENT] Nome del file da richiedere:\n");
    scanf("%s", filename);
  
    connessione = createTCPConnectionFD("localhost", 35000);
  
    for(int i=0; filename[i]!='\0'; i++)
        fputc(filename[i],connessione);
    fputc('\0',connessione);
  
    // Apro il file destinazione in scrittura
    destinazione = fopen(filename, "w");
    if (destinazione == NULL)
    {
        printf("[CLIENT] Errore apertura file %s\n", filename);
        return 1;
    }
    
    // Leggo il primo byte dalla sorgente
    c = fgetc(connessione);
    while (c != EOF)
    {
        // Scrivo il byte nella destinazione
        fputc(c, destinazione);
        c = fgetc(connessione);
    }
  
    printf("[CLIENT] Contenuto trasferito su %s\n", filename);
  
    fclose(destinazione);
    fclose(connessione);
    return 0;
}
