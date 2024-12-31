#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
11а. Напишете версия на програмата, която съдържа функция, която генерира тези n-мерни вектори като редове в матрица. Опитайте да генерирате същите вектори с елементи числата от 0 до K-1 при подаден параметър K.
*/

void freeMatrix7_a(int** matrix, const unsigned size) {

	for (int i = 0; i < size; i++) {
		free(matrix[i]);
	}

	free(matrix);
}

int** createMatrix7_a(const unsigned rows, const unsigned cols) {

	int** matrix = (int**)malloc(sizeof(int*) * rows);
	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)calloc(cols, sizeof(int));
		if (!matrix[i]) {
			freeMatrix7_a(matrix, i);
			return NULL;
		}
	}

	return matrix;
}

void printMatrix3_a(int** matrix, const unsigned rows, const unsigned cols) {
	for (int i = 0; i < rows; i++) {
		printf("( ");
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		puts(")");
	}
}

int main_07_11a() {

	unsigned dimension, k;

	puts("Insert dimension: ");
	scanf("%u", &dimension);

	puts("Insert k:");
	scanf("%u", &k);

	int vectors = pow(k, dimension);
	int** matrix = createMatrix7_a(vectors, dimension);

	for (int i = 0; i < vectors; i++){
		for (int j = 0; j < dimension; j++){
			matrix[i][j] = (i / (1 << j)) % k;
		}
	}

	printMatrix3_a(matrix, vectors, dimension);
	freeMatrix7_a(matrix, vectors);
	return 0;
}