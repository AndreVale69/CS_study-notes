#include "network.h"

int main(){
    char *sendd = "hi, im the server :)";
    char receive[MTU];
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
        
        fgets(receive, sizeof(receive), fd);
        fflush(fd);
        printf("[server] %s\n", receive);
        
        fputs("Hi from the server\n", fd);
        fflush(fd);
        
        fputs("I am fine!\n", fd);
        fflush(fd);
    
        fclose(fd);
    }
    
    closeConnection(server);
    return 0;
}

