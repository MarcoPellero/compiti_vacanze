#include <stdio.h>
#include <stdlib.h>

/* "Programmazione imperativa, l’approccio Top-Down. Da pagina 4 a 43 del libro di testo)"
*/

int es62(int n) {
	/* Scrivere una funzione che dato un numero intero verifica se è primo.
	*/

	if (n == 2 || n == 3)
		return 1;
	else if (n == 1 || !(n % 2) || !(n  % 3))
		return 0;
	
	for (int i = 5; i*i <= n; i += 6)
		if (!(n % i) || !(n % (i+2)))
			return 0;
	
	return 1;
}

void es63(int width, int height) {
	/* crivere una procedura che data la base e l'altezza del rettangolo stampa a video
	 * un rettangolo formato da asterischi.
	*/

	// edge case: linea orizzontale o verticale
	if (width < 2) {
		for (int i = 0; i < height && width; i++)
			printf("*\n");
		return;
	} else if (height < 2) {
		for (int i = 0; i < width && height; i++)
			printf("*");
			
		if (height)
			printf("\n");
		return;
	}

	for (int i = 0; i < width; i++)
		printf("*");
	printf("\n");

	for (int i = 0; i < height; i++) {
		printf("*");

		for (int j = 0; j < height-2; j++)
			printf(" ");

		printf("*\n");
	}

	for (int i = 0; i < width; i++)
		printf("*");
	printf("\n");
}

int es64(int n) {
	/* Scrivere una funzione che dato in ingresso un numero N chiede N numeri e
	 * verifica se sono tutti pari.
	*/

	int even = 1;

	// anche se ne arriva uno dispari continua
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		even = even && (tmp ^ 1);
	}

	return even;
}

int es65(int n) {
	/* Scrivere una funzione che dato un numero in ingresso comunica se il numero è
	 * pari.
	*/

	return n ^ 1;
}

int es66(int base, int exp) {
	/* Scrivere la funzione potenza che dati in ingresso la base b e l'esponente e calcola
	 * la potenza b alla e. (esempio b=5, e=3 => 5 alla terza uguale 125)
	*/

	// metodo naive: O(min(base, exp))
	// binary exponentiation: O(log exp)

	int ans = 1;
	while (exp > 0) {
		if (exp & 1)
			ans *= base;
		
		base *= base;
		exp >>= 1;
	}

	return ans;
}

int main() {}