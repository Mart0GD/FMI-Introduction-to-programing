#include<stdio.h>
#include<stdlib.h>
#pragma warning(push)
#pragma warning(disable: 4996)

/*
2. Два реда на една матрица си приличат, ако съвпадат множествата от числата, съставящи редовете. Да се напише програма, която установява дали съществуват два реда в матрица A с размерност n x m, които си приличат.
*/

void freeMatrix2(int** matrix, const unsigned rows) {
	for (int i = 0; i < rows; i++){
		free(matrix[i]);
	}

	free(matrix);
}

int** createMatrix2(rows, cols) {
	int** matrix = (int**)malloc(sizeof(int*) * rows);
	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++){
		matrix[i] = (int*)malloc(sizeof(int) * cols);
		if (!matrix) return NULL;
	}

	return matrix;
}

void fillMatrix2(int** matrix, const unsigned rows, const unsigned cols) {
	for (int y = 0; y < rows; y++){
		printf("Insert row %d. -->", y + 1);
		for (int x = 0; x < cols; x++){
			scanf("%d", &matrix[y][x]);
		}
	}
}

void sort(int* arr, const unsigned arrSize) {

	int swapped = 0;
	int temp = 0;
	for (int i = 0; i < arrSize - 1; i++){
		swapped = 0;
		for (int j = 0; j < arrSize - i - 1; j++){
			if (arr[j] < arr[j + 1]) continue;

			temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			swapped = 1;
		}

		if (!swapped) break;
	}

}

int CheckForSimilarities(const int* row1, const int* row2, const unsigned cols) {

	sort(row1, cols);
	sort(row2, cols);

	for (int i = 0; i < sizeof(row1) / sizeof(int); i++)
		if (row1[i] != row2[i])  return 0;

	return 1;
}

int checkForSimilarRowsInMatrix(int** matrix, const unsigned rows, const unsigned cols) {
	for (int y = 0; y < rows - 1; y++)
		if (CheckForSimilarities(matrix[y], matrix[y + 1], cols)) return 1;

	return 0;
}

int main_07_02() {
	unsigned rows, cols;

	printf("Insert matrix dimensions --> ");
	int res = scanf("%u %u", &rows, &cols);
	if (res != 2){
		puts("Invalid input!");
		return -1;
	}

	int** matrix = createMatrix2(rows, cols);
	fillMatrix2(matrix, rows, cols);

	int matrixContainSimilarRows = checkForSimilarRowsInMatrix(matrix, rows, cols);

	matrixContainSimilarRows
		? puts("Matrix conatins similar rows")
		: puts("Matrix does not contain similar rows");

	freeMatrix2(matrix, rows);
	return 0;
}