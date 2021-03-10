#!/bin/bash 

# indica al sistema operativo di utilizzare
# l’interprete Bash per eseguire lo script.

# Per poter essere eseguire uno script si devono avere i
# permessi di esecuzione (x) sul file:
# $ chmod u+x hello.sh
# $ ls –l
#  -rwx------ hello.sh
# $./hello.sh

# Script che copia tutti i files contenuti nella directory
# corrente in una nuova directory trash, e poi cancella la
# directory trash con tutto il suo contenuto.

#!/bin/bash 
mkdir trash
cp * traash
rm -rf trash
echo "Deleted all files!"

# Le variabili non devono essere dichiarate, per crearle
# basta assegnare loro un valore.

#!/bin/bash
str = "Hello world!"
echo $str

# Le virgolette doppie (partial quoting) permettono di risolvere le
# variabili al loro interno: ogni variabile nella stringa viene
# sostituita dal valore che essa assume in quel momento.

var = "stringa di test"
newvar = "il valore di var è $var."
echo $newvar
    il valore di var è stringa di test.

# Le virgolette singole (full quoting) non permettono la
# risoluzione delle variabili al loro interno.

var = "stringa di test"
newvar = 'il valore di var è $var.'
echo $newvar
    il valore di var è $var.

# Il carattere di escape \ conserva il valore del
# carattere letterale che segue:

ls *a
    *a indica tutte le sequenza di caratteri seguite da a
ls \*a
    \*a indica la sequenza di caratteri: *a

# Utile ad esempio per utilizzare delle virgolette
# all'interno di una stringa.

var = "stringa di \"test\""
echo $var
    stringa di "test"

# Il comando read consente di leggere l’input da
# tastiera e memorizzarlo in una variabile.

#!/bin/bash
echo "Inserire il nome del file da eliminare"
read file
rm -i $file

# Il comando read legge il nome del file da
# eliminare e lo memorizza nella varibile file.
# Il valore della variabile file viene usato
# dall’ultimo comando ($ per estrarre il valore).

#COMANDI INTERESSANTI

#    Non stampa a video l'input
read -s

#   Accetta soltanto N caratteri di input
read -nN

#   Visualizza il messaggio message
read -p "message"

#   Attendo l'input per T secondi.
read -tT

# Esempio

read -s -n1 -p "Yes (Y) or not (N)?" answer
#   Il valore digitato non viene visualizzato

# Il carattere $ può essere usato anche per
# sostituire dei comandi con il loro output.

list = $(ls)
echo $list
#    nel terminale stampa tutto quello che c'è nella cartella

ls $(pwd)
#   elenca i file nella directory corrente

#OPERATORI
# quelli classici di C
# MA ANCHE: ** --> elevazione a potenza

echo $((123+20))
    143
val = $[123+20];
echo $[10*$val]
    1430

# Il costrutto let può essere usato per associare un’espressione
# ad una variabile

let x = 10 + 2 * 7
echo $x
    24
    