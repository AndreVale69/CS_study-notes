#include "network.h"

int main(){
    int res = 0;
    connection_t connID;
    char receive[MTU];
    FILE *fd;
    
    fd = createTCPConnectionFD("localhost", 35000);
    
    fputs("Hello from the client, how are you?\n", fd);
    fflush(fd);

    fgets(receive, sizeof(receive), fd);
    fflush(fd);
    printf("[client] %s\n", receive);
    
    fgets(receive, sizeof(receive), fd);
    fflush(fd);
    printf("[client] %s\n", receive);

    fclose(fd);
}

