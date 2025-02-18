#include<stdio.h>
#include<stdlib.h>
#include "helper.h"

#pragma warning(disable: 4996)
#define MAX_LETERS 128
/*
Да се напише рекурсивна функция, която приема естествено число n>0, последвано от n на брой низа (думи), и отпечатва всички техни пермутации.
*/

void freeMatrixx(char** matrix, size_t size) {
	for (int i = 0; i < size; i++){
		free(matrix[i]);
	}

	free(matrix);
	matrix = NULL;
}

char** initMat(size_t rows, size_t cols) {
	char** matrix = (char*)malloc(sizeof(char*) * rows);
	if (!matrix) return -1;

	for (int i = 0; i < rows; i++) {
		matrix[i] = (char*)malloc(cols);
		if (!matrix[i]) {
			freeMatrixx(matrix, i);
			return -1;
		}
	}

	return matrix;
}

void swap(char** matrix, int index1, int index2) {
	char* temp = matrix[index1];
	matrix[index1] = matrix[index2];
	matrix[index2] = temp;
}

void printPermutation(const char** matrix, size_t rows) {
	for (int i = 0; i < rows; i++) {
		printf("%s ", matrix[i]);
	}
	puts(" ");
}

void printAll(const char** matrix, int index, int size) {
	if (index == size) {
		printPermutation(matrix, size);
		return;
	}

	for (int i = index; i < size; i++){
		swap(matrix, index, i);
		printAll(matrix, index + 1, size);
		swap(matrix, i, index);
	}
}

void printPermutations(const char** matrix, int size) {
	printAll(matrix, 0, size);
}

int main_S_15() {

	unsigned n = 0;
	scanf("%u", &n);
	getchar();

	char** words = initMat(n, MAX_LETERS);

	for (int i = 0; i < n; i++){
		words[i] = readText();
	}

	printPermutations(words, n);

	return 0;
}