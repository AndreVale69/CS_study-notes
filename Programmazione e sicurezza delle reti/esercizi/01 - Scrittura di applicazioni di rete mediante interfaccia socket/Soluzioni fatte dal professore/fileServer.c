#include "network.h"
  
int main()
{
    char filename[MTU], c;
    socketif_t server;
    FILE *connessione, *sorgente;
    int i;
    
    server = createTCPServer(35000);
    if (server < 0){
        printf("[SERVER] Error: %i\n", server);
        return -1;
    }
    
    while(1){
        connessione = acceptConnectionFD(server);
        
        i = 0;
        filename[i] = fgetc(connessione);
        while(filename[i]!='\0') {
            i++;
            filename[i] = fgetc(connessione);
        }   
        
        printf("[SERVER] Nome del file richiesto: %s\n", filename);
        
        // Apro il file sorgente in lettura
        sorgente = fopen(filename, "r");
        if (sorgente == NULL)
        {
            printf("[SERVER] Errore apertura file %s \n", filename);
            fclose(connessione);
            continue;
        }

        // Leggo il primo byte dalla sorgente
        c = fgetc(sorgente);
        while (c != EOF)
        {
            // Scrivo il byte nella connessione
            fputc(c, connessione);
            // Scarica il flusso stream
            fflush(connessione);
            c = fgetc(sorgente);
        }
        
        printf("[SERVER] File inviato\n");
        
        fclose(sorgente);        
        fclose(connessione);
    }
    
    return 0;
}
