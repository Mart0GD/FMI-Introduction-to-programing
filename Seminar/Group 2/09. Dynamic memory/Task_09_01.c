#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
Задача 1: Да се напише функция insertAt(index, element), която
добавя елемент на дадена позиция в динамичен масив. Масивът да се преоразмери с точна големина!

8 12 92 32 4,
insertAt(4, 123);
8 12 92 32 123 4
*/

void readArr(const int* arr, const unsigned size) {
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
}

void insertAt(int** arr, const int el, const unsigned index, unsigned* size) {
	++(*size);
	*arr = (int*)realloc(*arr, sizeof(int) * (*size));
	if (!*arr) {
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	for (int i = *size - 1; i > (int)index; i--) {
		(*arr)[i] = (*arr)[i - 1];
	}
	(*arr)[index] = el;
}

int main_09_01() {

	unsigned size;

	printf("Insert size --> ");
	scanf("%u", &size);

	int* arr = (int*)malloc(sizeof(int) * size);
	readArr(arr, size);

	int newElement = 0;
	unsigned index = 0;
	printf("insert element and index to insert at: ");
	scanf("%d %u", &newElement, &index);

	insertAt(&arr, newElement, index, &size);

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}