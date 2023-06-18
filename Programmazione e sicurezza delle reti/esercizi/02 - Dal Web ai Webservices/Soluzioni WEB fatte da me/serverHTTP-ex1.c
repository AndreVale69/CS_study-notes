#include "network.h"

/**
 * @brief Modificare il file serverHTTP.c in modo che, invece di restituire sempre la solita pagina web di prova,
 * restituisca una delle pagine html usate nel capitolo attraverso l'uso del browser. Suggerimenti:
 * - Provare a fare la nuova richiesta col browser usando il serverHTTP.c in modo da vedere la richiesta HTTP per
 *   capire dove si trova la stringa con il nome del file nella richiesta che fa il browser (aiutarsi anche con Wireshark). 
 *   Cosa devo scrivere nella barra del browser?
 * 
 * - Capire come recuperare la stringa con il nome del file della richiesta HTTP (si veda esempio-parser.c);
 * 
 * - Per costruire la risposta riciclare parte del codice usato nell'esercizio del trasferimento di file.
 * 
 * Prova finale: cosa succede se chiedo al server di restituire i file \textsf{form-get.html} e \textsf{form-post.html}?
 * 
 * @return int 
 */

int main(){
    socketif_t sockfd;
    FILE* connfd;
    int i;
    long length=0;
    char request[MTU], method[10], c;
    char tmp[MTU];
    char *f_split, *page_req;
    char *buffer = 0;
    FILE *fptr1;
    
    sockfd = createTCPServer(8000);
    if (sockfd < 0){
        printf("[SERVER] Errore: %i\n", sockfd);
        return -1;
    }
    
    while(true) {
        connfd = acceptConnectionFD(sockfd);

        fgets(request, sizeof(request), connfd);
        printf("%s", request);
        // save temp the request
        strcpy(tmp, request);
        strcpy(method,strtok(request," "));
        while(request[0]!='\r') {
            fgets(request, sizeof(request), connfd);
            printf("%s", request);
            if(strstr(request, "Content-Length:")!=NULL)  {
                length = atol(request+15);
                //printf("length %ld\n", length);
            }
        }
        
        if(strcmp(method, "POST")==0)  {
            for(i=0; i<length; i++)  {
                c = fgetc(connfd);
                printf("%c", c);
            }
        }

        // take the page requested
        f_split = strtok(tmp, "/ ");
        page_req = strtok(NULL, "/ ");
        // debug: printf("The page requested: %s\n", page_req);
        
        // open page web requested to send the content
        fptr1 = fopen(page_req, "r");
        if (fptr1 == NULL)
        {
            // if the page doesn't exist, error 404
            printf("Cannot open file %s \n", page_req);
            fputs("HTTP/1.1 404 NOT FOUND\r\n\r\n<html><head><title>404 Not Found</title></head><body>404 Page Not Found.</body></html>\r\n", connfd);
        }
        else
        {
            // if the page exists, read contents from file.
            // so, go to the EOF
            fseek(fptr1, 0, SEEK_END);
            // take the length
            length = ftell(fptr1);
            // come back to the start of file
            fseek(fptr1, 0, SEEK_SET);
            // read and save contents of file
            buffer = malloc(length);
            if (buffer)
                fread(buffer, 1, length, fptr1);
            else
            {
                printf("Error malloc\n");
                exit(-1);
            }
            fclose(fptr1);
            // check errors and send to client
            if (buffer)
            {
                // send OK code
                fputs("HTTP/1.1 200 OK\r\n\r\n", connfd);
                // send web page
                fputs(buffer, connfd);
                fputs("\r\n", connfd);
            }
            else
            {
                printf("Error fread\n");
                exit(-1);
            }
            free(buffer);
        }

        // close File Descriptor
        fclose(connfd);
        printf("\n\n[SERVER] sessione HTTP completata\n\n");
    }
    
    closeConnection(sockfd);
    return 0;
}