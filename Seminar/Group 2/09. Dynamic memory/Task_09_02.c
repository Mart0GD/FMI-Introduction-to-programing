#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
Задача 2: Да се напише функция removeAt(index), която
премахва елемент от дадена позиция в динамичен масив. Масивът да се преоразмери с точна големина!

8 12 92 32 4,
removeAt(1);
8 92 32 4
*/

void removeAt(int** arr, const unsigned index, int* size) {

	for (int i = index; i < *size - 1; i++) {
		(*arr)[i] = (*arr)[i + 1];
	}

	*arr = (int*)realloc(*arr, sizeof(int) * --(*size));
	if (!arr) {
		puts("Allocation failed!");
	}
}

int main_09_02() {

	int size = 0;
	scanf("%d", &size);

	int* arr = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	int index = 0;
	scanf("%d", &index);

	removeAt(&arr, index, &size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}