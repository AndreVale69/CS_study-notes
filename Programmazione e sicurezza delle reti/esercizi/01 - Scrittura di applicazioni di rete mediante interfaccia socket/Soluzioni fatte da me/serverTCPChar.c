#include "network.h"

int main(){
    char *sendd = "hi, im the server :)";
    char receive;
    int res;
    socketif_t server;
    connection_t connfd;
    FILE *fd;
    
    server = createTCPServer(35000);
    if (server < 0){
        printf("Error: %i\n", server);
        return -1;
    }
    
    while(true){
        fd = acceptConnectionFD(server);
        
        receive=fgetc(fd);
        fflush(fd);
        printf("[server] %c\n", receive);
        
        fputc('B', fd);
        fflush(fd);
    
        fclose(fd);
    }
    
    closeConnection(server);
    return 0;
}

