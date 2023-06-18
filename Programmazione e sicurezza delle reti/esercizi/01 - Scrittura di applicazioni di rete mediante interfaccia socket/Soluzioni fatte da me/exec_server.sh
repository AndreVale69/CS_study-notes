#!/bin/bash

# gcc network.c serverUDP.c -o serverUDP -lpthread
# gcc network.c serverUDP_inc.c -o serverUDP -lpthread
gcc network.c serverTCP.c -o serverTCP -lpthread
# ./serverUDP
./serverTCP
