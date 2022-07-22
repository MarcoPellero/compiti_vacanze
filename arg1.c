#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* "Le costanti, le variabili, espressioni, operandi e operatori, le istruzioni di
 * selezione, e di iterazione."
*/

void es1() {
	// Programma che stampa a video i primi 50 numeri

	for (int i = 1; i <= 50; i++)
		printf("%d\n", i);
}

void es2(int nums[], int size) {
	// Programma che inseriti N numeri visualizza solo i numeri positivi.

	for (int i = 0; i < size; i++)
		if (nums[i] > 0)
			printf("%d\n", nums[i]);
}

void es3(int nums[], int size) {
	// Programma che dati N numeri li stampi a video.

	for (int i = 0; i < size; i++)
		printf("%d\n", nums[i]);
}

void es4() {
	// Programma che stampa i numeri da 50 a 1.

	for (int i = 50; i; i--)
		printf("%d\n", i);
}

void es5() {
	// Programma che stampa i numeri pari tra 1 e 50.

	for (int i = 2; i <= 50; i += 2)
		printf("%d\n", i);
}

void es6() {
	// Programma che stampa i numeri dispari tra 1 e 50.

	for (int i = 1; i <= 50; i += 2)
		printf("%d\n", i);
}

int es7(int a, int b) {
	// Programma che esegue la moltiplicazione tra due numeri senza usare il "per".

	// O(a*b) ;)
	int result = 0;
	while (a--)
		for (int i = 0; i < b; i++)
			result++;
	
	return result;
}

int es8(int nums[], int size) {
	// Programma che inserti N numeri ne produce la somma e verifica se i numeri inseriti sono in ordine crescente.
	// ritorna -1 se non sono ordine, sennò la somma

	int sum = nums[0];
	for (int i = 1; i < size; i++) {
		if (nums[i] < nums[i-1])
			return -1;
		sum += nums[i];
	}
	
	return sum;
}

int es9(int nums[], int size) {
	// Programma che inseriti N numeri conta quanti sono quanti sono i numeri pari.

	int count = 0;
	for (int i = 0; i < size; i++)
		if (nums[i] ^ 1)
			count++;
	
	return count;
}

void es10(int nums[], int size) {
	// Scrivere un programma che inseriti N numeri visualizza il maggiore e il minore.

	int min = nums[0], max = min;
	for (int i = 1; i < size; i++)
		if (nums[i] > max)
			max = nums[i];
		else if (nums[i] < min)
			min = nums[i];
	
	printf("MIN: %d;\tMAX: %d\n", min, max);
}

void es11(int nums[], int size) {
	/* Dati N numeri, contare i numeri positivi e i numeri negativi. In seguito
	 * visualizzare la percentuale dei numeri positivi la percentuale dei numeri
	 * negativi rispetto al totale dei numeri.
	*/

	int pos = 0, neg = 0;
	for (int i = 0; i < size; i++)
		if (nums[i] > 0)
			pos++;
		else if (nums[i] < 0) // ignora 0
			neg++;
	
	printf("POSITIVI: %d (%f)\n", pos, (float)pos / size * 100);
	printf("NEGATIVI: %d (%f)\n", neg, (float)neg / size * 100);
}

int es12(int nums[]) {
	/* 12.Data una sequenza di numeri TERMINATA DAL NUMERO ZERO contare quanti
	 * numeri sono stati inseriti.
	*/

	for (int i = 0; 1; i++)
		if (!nums[i])
			return i+1;
}

int es13(int nums[]) {
	/* 13.Data una sequenza di numeri TERMINATA DAL NUMERO ZERO contare quanti
	 * sono i numeri dispari.
	*/

	int count = 0;
	for (int i = 0; 1; i++)
		if (!nums[i])
			return count;
		else if (nums[i] & 1)
			count++;
}

void es14(int n) {
	// Scrivere un programma che inserito un numero n VISUALIZZA e CONTA i divisori di n.

	// https://www.geeksforgeeks.org/find-all-divisors-of-a-natural-number-set-2/
	// O(sqrt(n)) tempo, O(1) spazio, NICE :)

	int i;
	for (i = 1; (i*i) < n; i++)
		if (!(n % i))
			printf("%d\n", i);
	
	if (i - (n/i) == 1)
		i--;
	
	for (; i > 0; i--)
		if (!(n % i))
			printf("%d\n", n/i);
}

void es15(int width, int height) {
	// Scrivere un programma che visualizza la tavola pitagorica

	for (int i = 1; i < height; i++) {
		for (int j = 1; j < width; j++)
			printf("%d\t", i*j);
		printf("\n");
	}
}

float es16(int temps[7][2]) {
	/* Scrivere un programma che ricevendo la temperatura massima e minima
	 * giornaliera di una settimana a Genova, calcola la media delle escursioni
	 * termiche.
	*/

	float mean = 0;
	for (int i = 0; i < 7; i++)
		mean += temps[i][1] - temps[i][0];
	
	return mean / 7;
}

void es17(int revenue[12]) {
	/* Costruire un programma che, ricevendo in input il fatturato mensile di
	 * un'azienda (un fatturato per ogni mese dell'anno), calcola il fatturato mensile
	 * medio e il mese con il fatturato massimo.
	*/

	int max = revenue[0];
	float mean = max;

	for (int i = 1; i < 12; i++) {
		mean += revenue[i];
		if (revenue[i] > max)
			max = revenue[i];
	}

	printf("Fatturato massimo: %d\n", max);
	printf("Fatturato medio: %f\n", mean);
}

void es18(int grades[][3], int size) {
	/* Realizzare un programma che riceve tre voti: scritto, orale e pratico di
	 * informatica di N allievi e visualizzi: la media di ogni allievo, la media della classe,
	 * il numero di insufficienti (<=5) e quello di medie ottime (>=8).
	*/

	float totalMean = 0;
	int fails = 0, optimals = 0;

	for (int i = 0; i < size; i++) {
		float mean = 0;

		for (int j = 0; j < 3; j++) {
			mean += grades[i][j];

			if (grades[i][j] <= 5)
				fails++;
			else if (grades[i][j] >= 8)
				optimals++;
		}

		totalMean += mean;
		mean /= 3;

		printf("Media studente [%d]: %f\n", i, mean);
	}

	totalMean /= (size * 3);
	printf("Media tra tutti gli studenti: %f\n", totalMean);
	printf("Insufficenze: %d;\tProdigi: %d\n", fails, optimals);
}

void es19(int wins, int draws, int losses) {
	/* Realizzare un programma che, ricevendo il numero di partite vinte, perse e
	 * pareggiate da una squadra, calcoli la percentuale delle vittorie, e visualizzi un
	 * messaggio di "consuntivo positivo" se il numero delle partite vinte è maggiore di
	 * quello delle partite perse.
	*/

	int total = wins + draws + losses;

	printf("Percentuale vittorie (%d su %d) : %f\n", wins, total, (float)wins / total * 100);
	if (wins > losses)
		printf("Piu' vittorie che perdite\n");
}

void es20(int grades[], int size) {
	/* Un insegnante decide di annullare il compito in classe se il numero delle
	 * insufficienze è maggiore dei 2/3 dei voti. Realizzare il programma che ricevendo
	 * in input il n° delle prove e i voti di ciascuna prova calcoli la percentuale delle
	 * sufficienze e visualizzi un opportuno messaggio se la prova è da annullare.
	*/

	int fails = 0;
	for (int i = 0; i < size; i++)
		if (grades[i] < 6)
			fails++;
	
	if (fails > (float)size * 0.666)
		printf("La prova e' da annullare :)\n");
}

int es21(int a, int b) {
	// Costruire un programma che riceva due numeri N1 e N2 e sommi quelli fra essi compresi (es N1=3, N2=7 S=+4+5+6+7)

	// https://study.com/academy/lesson/finding-the-sum-of-consecutive-numbers.html
	return (b-a)/2 * (a+b);
}

void es22(int s, int n) {
	/* Leggere due numeri S e N e visualizzare la serie di numeri che si ottiene
	 * sottraendo successivamente S fino a quando il risultato diventa <S. (es N=10,
	 * S=3 Calcolare 10-7-4).
	*/

	while (n >= s) {
		printf("%d-", n);
		n -= s;
	}
	printf("\n");
}

int es23HelperSort(const void *aPtr, const void *bPtr) {
	int *a = (int *)aPtr;
	int *b = (int *)bPtr;

	return (a[0] < b[0])	? -1
		: (b[0] < a[0])		?  1
		: (a[1] < b[1])		? -1
		: (b[1] < a[1])		?  1
		: 0;
}

void es23(int pairs[10][2]) {
	/* Scrivere un programma che memorizza 10 coppie di numeri e per ogni coppia
	 * visualizzi il massimo, il valore medio. Contare quante coppie hanno valori
	 * uguali.
	*/

	for (int i = 0; i < 10; i++) {
		int max = pairs[i][0];
		if (pairs[i][1] > max)
			max = pairs[i][1];
		
		printf("[%d] MAX: %d;\tMEDIO: %d\n", i, max, (pairs[i][0]+pairs[i][1]) / 2);
	}

	// sortando le coppie possiamo trovare le coppie uguali in O(nlogn + n) al posto di O(n^2)
	// uso il builtin sort perchè sono pigro :)
	qsort(pairs, 10, sizeof(*pairs), es23HelperSort);

	for (int i = 0; i < 10;) {
		int copies = 1; // pairs[i] "is a copy"

		int j;
		for (j = i+1; j < 10; j++) {
			if (pairs[i][0] == pairs[j][0] && pairs[i][1] == pairs[j][1])
				copies++;
			else
				break;
		}

		if (copies > 1)
			printf("%d copie della coppia [%d, %d]\n", copies, pairs[i][0], pairs[i][1]);
		i = j;
	}
}

void es24(int orders[][2], int size) {
	/* Scrivere un programma che inseriti N ordini (numero pezzi e prezzo unitario)
	 * calcola il prezzo totale dell'ordine e il prezzo medio dei prodotti.
	*/

	// [numero pezzi, prezzo unitario]

	int total = 0;
	float mean = 0;

	for (int i = 0; i < size; i++) {
		total += orders[i][0] * orders[i][1];
		if (orders[i][0])
			mean += orders[i][1];
	}

	mean /= size;
	printf("Prezzo totale: %d;\tPrezzo medio: %f\n", total, mean);
}

float es25(float temps[]) {
	/* Scrivere un programma che inseriti N ordini (numero pezzi e prezzo unitario)
	calcola il prezzo totale dell'ordine e il prezzo medio dei prodotti.
	*/

	float mean = 0;

	int i;
	for (i = 0; 1; i++)
		if (!temps[i])
			mean += temps[i];
	
	return mean / i;
}

int es26(int n) {
	/* Sommare i primi 50 numeri naturali e visualizzare il risultato.
	 * (n al posto di 50)
	*/

	// https://stackoverflow.com/questions/4911777/finding-first-n-primes
	// TLDR: possiamo stimare (stima per eccesso) l'Nth primo, poi lanciare una "trivella" di eratostene su esso per trovare l'Nth primo e tutti quelli prima

	int estimate = (n * log(n)) + (n + log(log(n))); // log() è logaritmo naturale

	// se fossi intelligente farei una "trivella" segmentata, che usa O(sqrt(n)) spazio
	int sieve[estimate+1];
	for (int i = 0; i < estimate; i++)
		sieve[i] = 1;

	sieve[0] = 0;
	sieve[1] = 0;

	int sum = 0;

	for (int i = 0; i <= estimate; i++) {
		if (!sieve[i])
			continue;
		
		sum += i;
		
		for (int j = (i*i); j <= estimate; j += i)
			sieve[i] = 0;
	}

	return sum;
}

void es27(int n, int k) {
	/* Dato un numero N, visualizzare K numeri naturali successivi a N. Facoltativo:
	 * controllare che N sia maggiore di zero.
	*/

	if (n < 0)
		n = 0;
	
	for (int i = n; i < n+k; i++)
		printf("%d\n", i);
}

int es28(int nums[], int size) {
	/* Dati N numeri, contare quante volte compare il numero 10. Facoltativo:
	 * controllare che N sia maggiore di zero.
	*/

	if (size <= 0)
		return 0;
	
	int count = 0;
	for (int i = 0; i < size; i++)
		if (nums[i] == 10)
			count++;
	
	return count;
}

void es29(int nums[]) {
	/* Data una sequenza di numeri terminata da zero, sommare separatamente i
	 * numeri pari e i dispari. Visualizzare i risultati.
	*/

	int odd = 0, even = 0;

	for (int i = 0; 1; i++)
		if (!nums[i])
			break;
		else if (nums[i] & 1)
			odd++;
		else
			even++;
	
	printf("Pari: %d;\tDispari: %d\n", even, odd);
}

void es30(int pairs[][2], int size) {
	/* Date in ingresso N coppie di numeri A e B, visualizzare il massimo per ogni
	 * coppia. Facoltativo: introdurre anche il controllo di correttezza sui dati in input
	 * che impone che i due numeri A e B siano distinti.
	*/

	for (int i = 0; i < size; i++)
		if (pairs[i][0] == pairs[i][1])
			printf("[%d] valori non distinti (%d)\n", i, pairs[i][0]);
		else
			printf("[%d] %d\n", i, (pairs[i][0] > pairs[i][1] ? pairs[i][0] : pairs[i][1]));
}

int es31(int a, int b) {
	/* Eseguire il prodotto di due numeri A e B per somme successive.
	*/

	printf("[31] non ho la benche minima idea di cosa la consegna voglia dire\n");
	return -1;
}

void es32(int nums[]) {
	/* Data una sequenza di numeri terminata da zero, visualizzare il cubo di ciascuno.
	*/

	for (int i = 0; 1; i++)
		if (!nums[i])
			return;
		else
			printf("[%d] %d^3 = %d\n", i, nums[i], (int)pow(nums[i], 3));
}

void es33(int n, int k) {
	/* Dato un numero N visualizzare i primi k numeri multipli di N
	*/

	for (int i = 2; i < (k+2); i++)
		printf("%d\n", n*i);
}

int main() {
}