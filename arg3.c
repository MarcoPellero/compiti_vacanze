#include <stdio.h>
#include <stdlib.h>

/* "La gestione delle Stringhe"
*/

int es51(char string[], int size) {
	/* Data una parola verificare se è palindroma
	*/

	int flag = 1;
	for (int i = 0; i < size/2 && flag; i++)
		flag = string[i] == string[size-i-1];
	
	return flag;
}

int es52(char string[], int size) {
	/* Data una frase contare il numero di lettere doppie
	*/

	// presumo che lettere doppie siano tipo aNNa (2 lettere uguali attaccate)
	int ans = 0;
	for (int i = 1; i < size; i++)
		if (string[i-1] == string[i] &&
		(i+1 == size || string[i] != string[i+1]))
			ans++;
	
	return ans++;
}

int es53(char string[], int size, char n) {
	/* Ricerca di un carattere inserito in input in una frase.
	*/

	// cercherò solo il primo indice dove appare
	for (int i = 0; i < size; i++)
		if (string[i] == n)
			return i;
	
	// se non esiste da -1
	return -1;
}

int es54(char a[], char b[], int size) {
	/* Scrivere un algoritmo che date due parole verifica se sono uguali. (controllare
	 * carattere per carattere)
	*/

	int flag = 1;
	for (int i = 0; i < size && flag; i++)
		flag = a[i] == b[i];
	
	return flag;
}

int es55(char string[], int size) {
	/* Scrivere un programma che inserita una frase produce un vettore contenente le
	 * vocali.
	*/

	char match[] = "aeiou";
	char matchSize = 5;

	char vocals[size];
	int occupied = 0;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < matchSize; j++)
			if (string[i] == match[j]) {
				vocals[occupied++] = string[i];
				break;
			}
	
	for (int i = 0; i < occupied; i++)
		printf("[%d] : %c\n", i, vocals[i]);
}

int es56(char string[], int size) {
	/* Scrivere un programma che inserita una parola verifica se la parola contiene
	 * almeno una doppia.
	*/

	// aNNa contiene 1 doppia; aNNNa no
	for (int i = 1; i < size; i++)
		if (string[i-1] == string[i] &&
		(i+1 == size || string[i] != string[i+1]))
		return 1;
	
	return 0;
}

int es57(char string[], int size) {
	/* Scrivere un programma che inserita una frase conta il numero di parole di cui è
	 * composta.
	*/

	// in una frase corretta, il numero di parole è uguale an numero di spazi + 1
	// ovviamente l'input potrebbe essere malformato, bisogna tenerne conto

	int ans = 0;
	int flag = 0;
	for (int i = 0; i < size; i++)
		if (string[i] != ' ')
			flag = 1;
		else if (flag) {
			flag = 0;
			ans++;
		}
	
	ans += flag; // contiamo anche l'ultima parola
	return ans;
}

int es58(char string[]) {
	/* Scrivere un programma che inserita una frase visualizza la lunghezza della
	 * frase(compresi gli spazi)
	*/

	int ans = 0;
	while (string[ans++] != '\0') {}

	return ans-1; // ans viene aumentato di 1 anche quando trova \0
}

int es59(char string[], int size) {
	/* Scrivere un algoritmo che inseriti N caratteri conta quante sono le vocali.
	*/

	char match[] = "aeiouw";
	char matchSize = 5;

	int ans = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < matchSize; j++)
			if (string[i] == match[j]) {
				ans++;
				break;
			}
	
	return ans;
}

int es60(char string[], char word[], int stringSize) {
	/* Scrivere un programma che inserita una frase separata da spazi e una parola,
	 * verifica se la parola è presente nella frase.
	*/

	int offset = 0;
	for (int i = 0; i < stringSize; i++)
		if (word[offset] == '\0')
			return 1;
		else if (!offset && i && word[i-1] == ' ')
			continue;
		else if (string[i] == word[offset])
			offset++;
		else
			offset = 0;
	
	return 0;
}

int es61(char string[], int size) {
	/* Dato un array di caratteri, sostituire al posto dell'iniziale del vostro nome il
	 * carattere ! Esempio(ne mio caso) : Merenda -> M!r!nda.
	*/

	char initial = 'm';

	for (int i = 0; i < size; i++)
		if (string[i] == initial || string[i] == (initial + 32))
			string[i] = '!';
}

int main() {}