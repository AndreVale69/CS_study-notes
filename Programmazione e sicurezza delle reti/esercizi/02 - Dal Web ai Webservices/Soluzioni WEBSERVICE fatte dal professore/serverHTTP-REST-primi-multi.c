#include "network.h"

float calcolaSomma(float val1, float val2)  {
    return (val1 + val2);
}

int calcolaPrimi(int min, int max, int results[])    {
    int a, b, i, j, flag;
    int count = 0;
    
    // lower bound 
    a = min;
    
    // upper bound
    b = max;
 
    // Traverse each number in the interval
    // with the help of for loop
    for (i = a; i <= b; i++) {
        // Skip 0 and 1 as they are
        // neither prime nor composite
        if (i == 1 || i == 0)
            continue;
 
        // flag variable to tell
        // if i is prime or not
        flag = 1;
 
        for (j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
 
        // flag = 1 means i is prime
        // and flag = 0 means i is not prime
        if (flag == 1)
            results[count++] = i;
    }
 
    return count;
}

int main(int argc, char *argv[]){
    socketif_t sockfd;
    FILE* connfd;
    int res, i;
    long length=0;
    char request[MTU], url[MTU], method[10], c;
    int port;
    
    if(argc<2)  {
        printf("USAGE: %s port\n", argv[0]);
        return -1;
    }
    else    {
        port = atoi(argv[1]);
    }

    sockfd = createTCPServer(port);
    if (sockfd < 0){
        printf("[SERVER] Errore: %i\n", sockfd);
        return -1;
    }
    
    while(true) {
        connfd = acceptConnectionFD(sockfd);
        
        fgets(request, sizeof(request), connfd);
        strcpy(method,strtok(request, " "));
        strcpy(url,strtok(NULL, " "));
        while(request[0]!='\r') {
            fgets(request, sizeof(request), connfd);
            if(strstr(request, "Content-Length:")!=NULL)  {
                length = atol(request+15);
            }
        }
        
        if(strcmp(method, "POST")==0)  {
            for(i=0; i<length; i++)  {
                c = fgetc(connfd);
            }
        }
        
        if(strstr(url, "calcola-somma")!=NULL)  {
            printf("Chiamata a funzione sommatrice\n");
            
            char *function, *op1, *op2;
            float somma, val1, val2;
   
            // skeleton: decodifica (de-serializzazione) dei parametri
            function = strtok(url, "?&");
            op1 = strtok(NULL, "?&");
            op2 = strtok(NULL, "?&");
            strtok(op1,"=");
            val1 = atof(strtok(NULL,"="));
            strtok(op2,"=");
            val2 = atof(strtok(NULL,"="));
            
            // chiamata alla business logic
            somma = calcolaSomma(val1, val2);
            
            // skeleton: codifica (serializzazione) del risultato
            fprintf(connfd,"HTTP/1.1 200 OK\r\n\r\n{\r\n    \"somma\":%f\r\n}\r\n", somma);
        }
        else if(strstr(url, "calcola-primi")!=NULL)  {
            printf("Chiamata a funzione per il calcolo dei numeri primi\n");

            char *function, *op1, *op2;
            int cont, val1, val2, *vett;
   
            // skeleton: decodifica (de-serializzazione) dei parametri
            function = strtok(url, "?&");
            op1 = strtok(NULL, "?&");
            op2 = strtok(NULL, "?&");
            strtok(op1,"=");
            val1 = atoi(strtok(NULL,"="));
            strtok(op2,"=");
            val2 = atoi(strtok(NULL,"="));

            vett = malloc(((val2-val1+1)/2)*sizeof(int));

            // chiamata alla business logic
            cont = calcolaPrimi(val1, val2, vett);
            
            // skeleton: codifica (serializzazione) del risultato
            fprintf(connfd,"HTTP/1.1 200 OK\r\n\r\n{\"numeri\":[\r\n");

            for(int i=0; i<cont-1; i++)  {
                fprintf(connfd,"\t%d,\r\n", vett[i]);
            }
            fprintf(connfd,"\t%d\r\n", vett[cont-1]);
            fprintf(connfd,"]}\r\n");
        }
        else {
            printf("Chiamata a funzione inesistente\n");
            fprintf(connfd,"HTTP/1.1 400 BAD REQUEST\r\n\r\n{\r\n    Funzione non riconosciuta!\r\n}\r\n");
        }
        
        fclose(connfd);
                
        printf("\n\n[SERVER] sessione HTTP completata\n\n");
    }
    
    closeConnection(sockfd);
    return 0;
}



