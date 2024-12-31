#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
9. ƒа се напише програма, ко€то сортира елементите на дадена матрица от числа с размерност n x m, така че елементите на всеки стълб и на всеки ред да образуват монотонно намал€ващи редици.
*/

void freeMatrix5(int** matrix, const unsigned rows) {
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

int** createMatrix5(const unsigned rows, const unsigned cols) {

	int** matrix = (int**)malloc(sizeof(int*) * rows);
	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++){
		matrix[i] = (int*)malloc(sizeof(int) * cols);

		if (!matrix[i]) {
			freeMatrix5(matrix, i);
			return NULL;
		}
	}

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			scanf("%d", &matrix[i][j]);
		}
	}

	return matrix;
}

void printMatrix2(int** matrix, const unsigned rows, const unsigned cols) {
	for (int y = 0; y < rows; y++){
		for (int x = 0; x < cols; x++){
			printf("%d ", matrix[y][x]);
		}
		puts("");
	}
}

int isDesc(const int* arr, const unsigned arrSize) {
	for (int i = 0; i < arrSize - 1; i++){
		if (arr[i] < arr[i + 1])
			return 0;
	}

	return 1;
}

int isMatrixSorted(const int** matrix, const unsigned rows, const unsigned cols) {
	
	int* colArr = (int*)malloc(sizeof(int) * rows);

	for (int row = 0; row < rows; row++){
		if (!isDesc(matrix[row], cols)) {
			free(colArr);
			return 0;
		}
	}

	for (int col = 0; col < cols; col++){
		for (int row = 0; row < rows; row++){
			colArr[row] = matrix[row][cols];
		}
		if (!isDesc(colArr, rows)) {
			free(colArr);
			return 0;
		}
	}

	free(colArr);
	return 1;
}

void swapRow(int* arr, const unsigned index) {
	int temp = arr[index];
	arr[index] = arr[index + 1];
	arr[index + 1] = temp;
}

void swapCol(int** matrix, const unsigned col, const unsigned row) {
	int temp = matrix[row][col];
	matrix[row][col] = matrix[row + 1][col];
	matrix[row + 1][col] = temp;
}

void sortRow(int* arr, const unsigned arrSize) {

	int swapped = 0;
	for (int i = 0; i < arrSize - 1; i++){
		swapped = 0;
		for (int j = 0; j < arrSize - 1 - i; j++){
			if (arr[j] > arr[j + 1]) continue;
			swapRow(arr, j);
			swapped = 1;
		}
		if (!swapped) break;
	}
}

void sortCol(int** matrix, const unsigned col, const unsigned rows) {
	int swapped = 0;
	for (int i = 0; i < rows; i++)
	{
		swapped = 0;
		for (int j = 0; j < rows - i - 1; j++)
		{
			if (matrix[j][col] > matrix[j + 1][col]) continue;

			swapCol(matrix, col, j);
			swapped = 1;
		}
		if (!swapped) break;
	}

	/*for (int i = 0; i < rows; i++)
	{
		printf("%d ", matrix[i][col]);
	}
	puts(" ");*/
}

void sortMatrixInRowsAndColsDesc(int** matrix, const unsigned rows, const unsigned cols) {

	while (!isMatrixSorted(matrix, rows, cols)){
		for (int row = 0; row < rows; row++){
			sortRow(matrix[row], cols);
		}

		for (int j = 0; j < cols; j++){
			sortCol(matrix, j, rows);
		}
	}
}

int main_07_09() {
	unsigned rows, cols;

	printf("Insert matrix dimensions --> ");
	scanf("%u %u", &rows, &cols);

	puts("Insert matrix: ");
	int** matrix = createMatrix5(rows, cols);
	
	sortMatrixInRowsAndColsDesc(matrix, rows, cols);

	puts("Sorted matrix");
	printMatrix2(matrix, rows, cols);

	freeMatrix5(matrix, rows);
	return 0;
}