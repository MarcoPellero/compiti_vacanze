#include <stdio.h>
#include <stdlib.h>

/* "i vettori, aspetti implementativi dei vettori, ordinamento per selezione, a bolle, il
 * problema della ricerca.(Da pagina 46 a 91 del libro di testo)."
*/

int es34(int nums[], int size, int k) {
	/* Scrivere un algoritmo che inseriti N numeri in un array verifica se tutti gli
	 * elementi sono maggiori di un elemento k inserito da tastiera.
	*/

	// 0: Falso, 1: Vero

	for (int i = 0; i < size; i++)
		if (nums[i] <= k)
			return 0;
	
	return 1;
}

int es35(int nums[], int size, int x) {
	/* Dato un vettore di N elementi e un elemento X verificare se l'elemento X è
	presente nel vettore.
	*/

	// 0: Falso, 1: Vero
	// presumo l'array sia disordinato

	for (int i = 0; i < size; i++)
		if (nums[i] == x)
			return 1;
	
	return 0;
}

void es36(int nums[]) {
	/* Scrivere un programma che riempie un vettore di interi con i primi 10 numeri
	 * pari.
	*/

	for (int i = 1; i <= 10; i++)
		nums[i-1] = 2*i;
}

int es37(int nums[], int size, int k) {
	/* Scrivere un algoritmo che inseriti N numeri in un array verifica che almeno un
	 * elemento sia maggiore di un valore k inserito da tastiera.
	*/

	// 0: Falso, 1: Vero
	// presumo l'array sia disordinato

	for (int i = 0; i < size; i++)
		if (nums[i] > k)
			return 1;
	
	return 0;
}

int es38(int nums[], int size) {
	/* Verificare che gli elementi all'interno di un array di posizione pari siano pari.
	*/

	// 0: Falso, 1: Vero

	for (int i = 0; i < size; i += 2)
		if (nums[i] & 1)
			return 0;
	
	return 1;
}

#define es39HelperSwap(a, b, type) do { type tmp = a; a = b; b = tmp; } while (0)

void es39HelperSelectionSort(int nums[], int size) {
	for (int i = 0; i < size; i++) {
		int smallIndex = i;

		for (int j = i+1; j < size; j++)
			if (nums[smallIndex] > j)
				smallIndex = j;
		
		if (smallIndex == i) continue;

		es39HelperSwap(nums[smallIndex], nums[i], int);
	}
}

void es39HelperBubbleSort(int nums[], int size) {
	int sorted = 0;

	while (!sorted) {
		sorted = 1;

		for (int i = 1; i < size; i++)
			if (nums[i-1] > nums[i]) {
				sorted = 0;
				es39HelperSwap(nums[i-1], nums[i], int);
			}
	}
}

int es39HelperSearch(int nums[], int size, int x) {
	// array disordinato

	for (int i = 0; i < size; i++)
		if (nums[i] == x)
			return i;
	
	return -1;
}

void es39HelperOutput(int nums[], int size) {
	for (int i = 0; i < size; i++)
		printf("[%d] : %d\n", i, nums[i]);
}

void es39() {
	/* Implementare il seguente menu:
		a. Inserimento valori
		b. Ordinamento per selezione
		c. Ordinamento a bolle
		d. Ricerca di un elemento
		e. Visualizzazione elementi
	*/

	int chunkSize = 256 * sizeof(int);
	int totalSize = chunkSize;
	int used = 0;

	int *nums = malloc(totalSize);
	int *reallocTmp;

	while (1) {
		printf("[%d]: Inserimento valore\n", 0);
		printf("[%d]: Ordinamento tramite selection sort\n", 1);
		printf("[%d]: Ordinamento tramite bubble sort\n", 2);
		printf("[%d]: Ricerca di un elemento\n", 3);
		printf("[%d]: Visualizzazione array\n", 4);
		printf("Inserisci qualsiasi altro numero per uscire\n");

		int cmd;
		scanf("%d", &cmd);

		switch (cmd) {
			case 0:
				if (used == totalSize) {
					totalSize += chunkSize;
					reallocTmp = realloc(nums, totalSize);
					if (reallocTmp)
						nums = reallocTmp;
					else {
						printf("ERRORE NELLA RIALLOCAZIONE DI MEMORIA\n");
						exit(EXIT_FAILURE);
					}
				}
				scanf("%d", &nums[used++]);
			case 1:
				es39HelperSelectionSort(nums, used);
			case 2:
				es39HelperBubbleSort(nums, used);
			case 3:
				printf("Valore da cercare: ");
				int x;
				scanf("%d", &x);

				int index = es39HelperSearch(nums, used, x);
				if (index == -1)
					printf("L'elemento non e' presente nell'array\n");
				else
					printf("L'elemento si trova all'indice [%d]\n", index);
			case 4:
				es39HelperOutput(nums, used);
			default:
				free(nums);
				return;
		}
	}
}

int * es40(int nums[], int size) {
	/* Scrivere un algoritmo che inseriti N numeri, produce un secondo vettore che
	 * contiene i valori maggiori della media.
	*/

	static int *arr;

	int newSize = 0;
	float mean = 0;

	for (int i = 0; i < size; i++)
		mean += nums[i];

	mean /= size;

	for (int i = 0; i < size; i++)
		if (nums[i] > mean)
			newSize++;
	
	arr = realloc(arr, newSize * sizeof(int));
	if (!arr) {
		printf("ERRORE NELLA RIALLOCAZIONE DI MEMORIA\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0, j = 0; j < size; j++)
		if (nums[i] > mean)
			arr[i++] = nums[j];
	
	return arr; // dare in output un array che cambia grandezza e contenuto spesso non e' la migliore delle idee diciamo
}

void es41(int nums[], int size) {
	/* Dato un vettore di N elementi sostituire tutti gli elementi pari con il loro
	 * opposto.(es 2->-2, 4->-4....) e visualizzare il numero di sostituzioni fatte.
	*/

	for (int i = 0; i < size; i++)
		if (nums[i] ^ 1)
			nums[i] = -nums[i];
}

void es42(int nums[], int size) {
	/* Dato un vettore di N elementi numerici visualizzare il doppio di ogni elemento
	 * dispari.
	*/

	for (int i = 0; i < size; i++)
		if (nums[i] & 1)
			printf("[%d]: %d\n", i, nums[i] * 2);
}

float es43(float nums[], int size) {
	/* In un vettore sono memorizzate le temperature giornaliere massime registrare
	 * in una località montana nei mesi invernali. Calcolare l'escursione termica del
	 * periodo considerato.
	*/

	float min = nums[0], max = min;

	for (int i = 1; i < size; i++)
		if (nums[i] > max)
			max = nums[i];
		else if (nums[i] < min)
			min = nums[i];
	
	return max - min;
}

void es44(int nums[], int size) {
	/* In un vettore sono memorizzati i movimenti di denaro su un conto corrente. I
	 * valori positivi indicano i versamenti di denaro, mentre i valori negativi indicano
	 * i prelievi. Contare i numeri di prelievi e versamenti e indicare se i prelievi
	 * superano o meno i versamenti. Verificare inoltre se il conto corrente risulta in
	 * rosso.
	*/

	int positive = 0, negative = 0, sum = 0;
	for (int i = 0; i < size; i++) {
		sum += nums[i];

		if (nums[i] > 0)
			positive++;
		else if (nums[i] < 0)
			negative++;
	}
	
	if (positive > negative)
		printf("Piu' versamenti che prelievi\n");
	else if (negative > positive)
		printf("Piu' prelievi che versamenti\n");
	else
		printf("Tanti versamenti quanti prelievi\n");
	
	printf("Soldi rimasti sul conto: %d\n", sum);
}

int es45(int nums[], int size) {
	/* Dopo aver caricato un vettore di N componenti numeriche, sommare solo le
	* componenti di indice dispari.
	*/

	int sum = 0;
	for (int i = 1; i < size; i += 2)
		sum += nums[i];
	
	return sum;
}

void es46(int nums[], int size) {
	/* Dopo aver caricato un vettore di M elementi, calcolare il valore e la posizione del
	 * massimo e il valore e la posizione del minimo.
	*/

	int max = 0, min = 0;
	for (int i = 1; i < size; i++) {
		if (nums[i] > nums[max])
			max = i;
		if (nums[i] < nums[min])
			min = i;
	}

	printf("Massimo: indice %d e valore %d\n", max, nums[max]);
	printf("Minimo: indice %d e valore %d\n", min, nums[min]);
}

void es47(int nums[], int size) {
	/* Dopo aver caricato un vettore di N componenti numeriche, visualizzarli in
	 * ordine inverso.
	*/

	for (int i = size-1; i >= 0; i--)
		printf("[%d] : %d\n", i, nums[i]);
}

void es48(int nums[], int size) {
	/* Dato un vettore di N elementi, costruire un altro vettore che contiene solo i
	 * numeri pari.
	*/

	int evenNums[size];
	int occupied = 0;

	for (int i = 0; i < size; i++)
		if (nums[i] ^ 1)
			evenNums[occupied++] = nums[i];
	
	for (int i = 0; i < occupied; i++)
		printf("[%d] : %d\n", i, evenNums[i]);
}

void es49(int a[], int b[], int size) {
	/* Dati due array A e B di N interi scrivere un programma per costruire un vettore
	 * C ( di dimensione 2N) che contenga nelle prime N posizioni gli elementi del
	 * vettore A e nelle restanti posizioni N gli elementi di B.
	*/

	int c[size*2];

	for (int i = 0; i < size; i++) {
		c[i] = a[i];
		c[size+i] = b[i];
	}

	for (int i = 0; i < size*2; i++)
		printf("[%d] : %d\n", i, c[i]);
}

void es50(int nums[], int size, int k) {
	/* Scrivere un programma che sostituisce tutti i valori maggiori di un certo valore
	 * K con l'opposto. Esempio vett= { 5,4,7,8,2,10}. K=6. Il vettore diventa
	 * vett={5,4,-7,-8,2,-10}
	*/
	
	for (int i = 0; i < size; i++)
		if (nums[i] > k)
			nums[i] = -nums[i];
}

int main() {}