#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)
/*
4. Да се напише програма, която обхожда по диагонали успоредни на главния и в посока отгоре надолу елементите на матрица от цели числа с размерност n x m. Резултатът да се запише в едномерен масив.
Пример за матрицата:

1  2  3  4
5  6  7  8
9 10 11 12
трябва да се получи:

4 3 8 2 7 12 1 6 11 5 10 9
*/

void freeMatrix4(int** matrix, const unsigned rows) {
	for (int i = 0; i < rows; i++){
		free(matrix[i]);
	}

	free(matrix);
}

int** createMatrix4(const unsigned rows, const unsigned cols) {

	int** matrix = (int**)malloc(sizeof(int*) * rows);
	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++){
		matrix[i] = (int*)malloc(sizeof(int) * cols);
		if (!matrix[i]) return NULL;
	}
	return matrix;
}

void fillMatrix4(int** matrix, const unsigned rows, const unsigned cols) {
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
}

int* diagonalizeMatrix(const int** matrix, const unsigned rows, const unsigned cols) {
	const unsigned ELEMENTS = rows * cols;

	int* arr = (int*)malloc(sizeof(int) * ELEMENTS);
	if (!arr) return NULL;

	unsigned index = 0;
	unsigned y = 0, x = 2;
	unsigned tempY, tempX;
	for (int diagonal = 0; diagonal < rows + cols - 1; diagonal++){
		
		tempY = y;
		tempX = x;
		while (tempX < rows && tempY < cols){
			arr[index++] = matrix[tempY++][tempX++];
		}
		y = x > 0 ? 0 : y + 1;
		x = y > 0 ? 0 : x - 1;
	}

	return arr;
}

void printArr(const int* arr, const unsigned arrSize) {
	for (int i = 0; i < arrSize; i++){
		printf("%d", arr[i]);
	}
}

int main_07_04() {
	unsigned rows, cols;

	printf("Insert matrix dimensions --> ");
	scanf("%u %u", &rows, &cols);

	int** matrix = createMatrix4(rows, cols);

	puts("Fill matrix");
	fillMatrix4(matrix, rows, cols);

	int* diagonalizedMatrix = diagonalizeMatrix(matrix, rows, cols);

	printArr(diagonalizedMatrix, rows * cols);
	free(diagonalizedMatrix);
	freeMatrix4(matrix, rows);
	return 0;
}