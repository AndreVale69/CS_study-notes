# Creare uno script bash che richiede due numeri
# ed esegue la loro: somma, sottrazione,
# moltiplicazione e divisione (quoziente e resto),
# stampando poi i risultati ottenuti.

#!/bin/bash
echo -n "Digitare il primo numero: " 
read x
echo -n "Digitare il secondo numero: " 
read y
add=$(($x+$y))
sub=$(($x-$y))
mul=$(($x*$y))
div=$(($x/$y))
mod=$(($x%$y))
echo "Somma: $add"
echo "Differenza: $sub"
echo "Prodotto: $mul"
echo "Quozionte: $div"
echo "Resto: $mod"