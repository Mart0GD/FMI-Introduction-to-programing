#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#pragma warning(push)
#pragma warning(disable: 4996)
/*
Задача 5: Да се напише функция, която филтрира всички прости числа от зададен динамичен масив. Масивът да се преоразмери с точна големина!
Вход: [3 5 8 7 11 24 42], Изход: [3 5 7 11]
*/

int isNumPrime(int number) {
	int sqrtNum = sqrt(number);
	for (int i = 2; i <= sqrtNum; i++)
		if (number % i == 0) return 0;

	return 1;
}

void deleteAt(int** arr, const unsigned index, int* size) {

	for (int i = index; i < *size - 1; i++) {
		(*arr)[i] = (*arr)[i + 1];
	}

	*arr = (int*)realloc(*arr, sizeof(int) * --(*size));
	if (!arr) {
		puts("Allocation failed!");
	}
}

void compreesPrimes(int** arr, unsigned int* size) {
	for (int i = 0; i < *size; i++) {
		if (isNumPrime((*arr)[i])) {
			deleteAt(arr, i, size);
			i--;
		}
	}
}

int* createArr(const unsigned size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	if (!arr) return NULL;

	printf("Insert arr --> ");
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	return arr;
}

int main_09_05() {
	int size = 0;
	printf("Insert arr size --> ");
	scanf("%d", &size);

	int* arr = createArr(size);
	compreesPrimes(&arr, &size);

	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}