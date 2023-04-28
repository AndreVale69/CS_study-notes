#include "network.h"

int main(){
    int res = 0;
    connection_t connID;
    char receive;
    FILE *fd;
    
    fd = createTCPConnectionFD("localhost", 35000);
    
    fputc('A', fd);
    fflush(fd);

    receive=fgetc(fd);
    fflush(fd);
    printf("[client] %c\n", receive);

    fclose(fd);
}

