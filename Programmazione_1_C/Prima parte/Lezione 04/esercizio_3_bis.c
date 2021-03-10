// Scrivere un programma che inverta la posizione delle cifre di 
// un numero intero inserito dall’utente (4321 > 1234). Inoltre, il 
// programma avvisa se il numero inserito è palindromo (si legge
// allo stesso modo da sinistra a destra e viceversa, es: 121, 
// 32123, …).

#include<stdio.h> 

int main() {
	int n, num, rem, rev = 0; 
	// n   = numero richiesto all'utente
	// num = numero che serve per eseguire operazioni
	// rem = prende il resto
	// rev = permette di rovesciare il numero
	
	printf ("Inserire il numero: ");
	scanf("%d", &n);
	// richiesta di inserimento

	num = n;
	// assegno alla variabile num il valore
	// di n così da eseguire operazioni
	
	while (num > 0)
	// finchè num maggiore di 0, esegui
	{ 
		rem = num%10; 
		// 4321 / 10 = 432.1 e prende solo il resto (quindi 1)

		rev = rev*10+rem;
		// all'inizio fa 0*10 + 1 = 1
		// dopo la prima volta fa 1*10 + 2 = 12

		num = num/10;
		// modifica il numero e perdere il valore
		// dopo la virgola perché è un int = 432 (.1 lo perde)

	}

	if (rev == n)
		printf("Palindromo\n");
	else
		printf("Numero invertito: %d\n", rev);
	// se il numero presente in rev è uguale
	// al numero originale, è palindromo
}