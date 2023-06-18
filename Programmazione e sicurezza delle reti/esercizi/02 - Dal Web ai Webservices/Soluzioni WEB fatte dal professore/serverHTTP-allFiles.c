#include "network.h"

int main(){
    char *HTMLInitResponse = "HTTP/1.1 200 OK\r\n\r\n";
    char *HTMLDefResponse = "HTTP/1.1 200 OK\r\n\r\n<html><head><title>Home page</title></head><body>Hello World, this is a very simple home page.</body></html>\r\n";
    char *HTMLBadResponse = "HTTP/1.1 404 Page not found\r\n\r\n<html><head><title>Error 404 Page not found</title></head><body>Error 404 Page not found!</body></html>\r\n";
    char *HTMLWIPResponse = "HTTP/1.1 200 OK\r\n\r\n<html><head><title>Work in progress</title></head><body>You need CGI!</body></html>\r\n";
    socketif_t sockfd;
    FILE* connfd; 
    FILE* sorgente;
    int res, i;
    long length=0;
    char request[MTU], method[10], filename[MTU], c;
    
    sockfd = createTCPServer(80);
    if (sockfd < 0){
        printf("[SERVER] Errore: %i\n", sockfd);
        return -1;
    }
    
    while(true) {
        connfd = acceptConnectionFD(sockfd);
        
        fgets(request, sizeof(request), connfd);
        printf("%s", request);
        strcpy(method,strtok(request," "));
        strcpy(filename, strtok(NULL, " "));
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
        
        // home page
        if(filename[0]=='/' && strlen(filename)==1)   {
            fputs(HTMLDefResponse, connfd);
        }
        // static html page
        else if(strstr(filename,".html")!=NULL) {
            strcpy(filename, filename+1);
            // Apro il file sorgente in lettura
            sorgente = fopen(filename, "r");
            if (sorgente == NULL)
            {
                fputs(HTMLBadResponse, connfd);
                fclose(connfd);
                continue;
            }

            fputs(HTMLInitResponse, connfd);
            
            // Leggo il primo byte dalla sorgente
            c = fgetc(sorgente);
            while (c != EOF)
            {
                // Scrivo il byte nella connessione
                fputc(c, connfd);
                fflush(connfd);
                c = fgetc(sorgente);
            }
            
            fputs("\r\n", connfd);            
        
            printf("[SERVER] File inviato\n");
        
            fclose(sorgente);
        }
        // something smarter
        else    {        
            fputs(HTMLWIPResponse, connfd);
        }
        
        fclose(connfd);
                
        printf("\n\n[SERVER] sessione HTTP completata\n\n");
    }
    
    closeConnection(sockfd);
    return 0;
}

