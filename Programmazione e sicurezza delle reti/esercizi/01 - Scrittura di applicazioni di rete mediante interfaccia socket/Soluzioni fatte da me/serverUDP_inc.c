#include "network.h"

int main(void) {
    int request;
    int response;
    socketif_t socket;
    char hostAddress[MAXADDRESSLEN];
    int port;
    
    socket = createUDPInterface(35000);

    printf("[SERVER] Sono in attesa di richieste da qualche client\n");
    
    UDPReceive(socket, &request, sizeof(request), hostAddress, &port);
    
    printf("[SERVER] Ho ricevuto un messaggio da host/porta %s/%d\n", hostAddress, port);
    
    printf("[SERVER] Contenuto: %d\n", request);
    
    response = request + 1;
    
    UDPSend(socket, &response, sizeof(response), hostAddress, port);

    // EX.8
    /*
    int somma = 0;
    do
    {
        printf("[SERVER] Sono in attesa di valori da qualche client\n");
        UDPReceive(socket, &request, sizeof(request), hostAddress, &port);
        printf("[SERVER] Sommo il numero %d...\n", request);
        somma += request;
    } while (request != 0);
    UDPSend(socket, &somma, sizeof(somma), hostAddress, port);
    printf("[SERVER] Ho ricevuto il valore di terminazione da host/porta %s/%d\n", hostAddress, port);
    printf("[SERVER] Contenuto: %d\n", request);
    */

    // EX.10 - Possibile soluzione
    // Aggiorna i client che si collegano
    /*
    do
    {
        UDPReceive(socket, &request, sizeof(request), hostAddress, &port);
        UDPSend(socket, &somma, sizeof(somma), hostAddress, port);
    } while (true);
    */
}