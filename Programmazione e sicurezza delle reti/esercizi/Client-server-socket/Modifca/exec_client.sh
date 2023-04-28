#!/bin/bash

# gcc network.c clientUDP.c -o clientUDP -lpthread
# gcc network.c clientUDP_inc.c -o clientUDP -lpthread
gcc network.c clientTCP.c -o clientTCP -lpthread
# ./clientUDP
./clientTCP
