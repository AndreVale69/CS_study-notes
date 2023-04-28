#!/bin/bash

gcc network.c serverHTTP.c -o serverHTTP -lpthread
./serverHTTP
