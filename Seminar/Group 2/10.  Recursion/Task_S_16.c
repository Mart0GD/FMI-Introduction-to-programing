#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

/*
Да се напише рекурсивна функция, която приема естествено число n>0 и извежда всички булеви вектори с дължина 2*n, такива че сумата на елементите им в първата и втората половина съвпада.
*/

int isSymetrical(int* bitstring, int len) {
	int sum1 = 0; int sum2 = 0;
	int steps = len / 2;
	for (size_t i = 0; i < steps; i++){
		sum1 += bitstring[i];
		sum2 += bitstring[i + steps];
	}

	return sum1 == sum2;
}

void printAllVectors(int size, int* bitstring, int pos) {
	if (pos == size){
		if (isSymetrical(bitstring, size)) {
			for (int i = 0; i < size; i++){
				printf("%d ", bitstring[i]);
			}
			puts(" ");
		}
		return;
	}

	bitstring[pos] = 0;
	printAllVectors(size, bitstring, pos + 1);

	bitstring[pos] = 1;
	printAllVectors(size, bitstring, pos + 1);
}

void printSymetricalBoolVectors(int size) {
	int* bitstring = (int*)calloc(size, sizeof(int));
	if (!bitstring) return;

	printAllVectors(size, bitstring, 0);
	free(bitstring);
}

int main_S_16() {
	int n = 0;
	scanf("%d", &n);

	printSymetricalBoolVectors(n * 2);
	return 0;
}