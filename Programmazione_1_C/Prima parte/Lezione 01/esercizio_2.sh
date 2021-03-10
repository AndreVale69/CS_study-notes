# Creare uno script bash che:
# stampa la directory corrente (dove ci si trova)
# mostra i file contenuti nella directory corrente
# crea il file vuoto prova.txt
# crea la directory Script nella directory corrente
# muove prova.txt in nella directory Script
# mostra il contenuto della directory corrente
# mostra il contenuto della directory Script (testare qui lo
# script la prima volta)
# cancella la directory Script con il suo contenuto
# stampa il contenuto della directory corrente
# stampa «fine script»

#!/bin/bash
pwd

ls -l

touch prova.txt

mkdir Script

mv prova.txt Script/

ls -l

ls -l Script/

rm -r Script

ls -l

echo "Fine script"