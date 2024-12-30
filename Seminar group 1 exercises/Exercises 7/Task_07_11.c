#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
11. Да се напише програма, която намира и извежда на екрана всички n-мерни вектори с компоненти 0 и 1. Например при n = 3, всички 3-мерни вектори с компоненти 0 и 1 са: (0, 0, 0), (0, 0, 1), (0, 1, 0), (0, 1, 1), (1, 0, 0), (1, 0, 1), (1, 1, 0), (1, 1, 1).
*/

void freeMatrix7(int** matrix, const unsigned size) {

	for (int i = 0; i < size; i++){
		free(matrix[i]);
	}

	free(matrix);
}

int** createMatrix7(const unsigned rows, const unsigned cols) {

	int** matrix = (int**)malloc(sizeof(int*) * rows);
	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++){
		matrix[i] = (int*)calloc(cols, sizeof(int));
		if (!matrix[i]){
			freeMatrix7(matrix, i);
			return NULL;
		}
	}

	return matrix;
}

void printMatrix3(int** matrix, const unsigned rows, const unsigned cols){
	for (int i = 0; i < rows; i++) {
		printf("( ");
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		puts(")");
	}
}

int main_07_11() {

	unsigned dimension;
	scanf("%u", &dimension);

	int vectors = 1 << dimension;
	int** matrix = createMatrix7(vectors, dimension);

	for (int i = 0; i < vectors; i++){
		for (int j = 0; j < dimension; j++){

			if (i & (1 << j)){
				matrix[i][j] = 1;
			}
		}
	}
	
	printMatrix3(matrix, vectors, dimension);
	freeMatrix7(matrix, vectors);
	return 0;
}