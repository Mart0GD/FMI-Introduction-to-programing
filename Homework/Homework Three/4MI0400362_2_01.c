#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

#define MEMORY_MESSAGE "No available memory to allocate"
#define INVALID_INPUT_MESSAGE "Invalid input!"

void freeMatrix(int** matrix, const unsigned size) {
	for (int i = 0; i < size; i++)
		free(matrix[i]);
	free(matrix);
}

int** createMatrix(const unsigned rows, const unsigned cols) {
	
	int** matrix = (int**)malloc(sizeof(int*) * rows);
	if (!matrix) {
		puts(MEMORY_MESSAGE);
		return NULL;
	}

	for (int i = 0; i < rows; i++){
		matrix[i] = (int*)malloc(sizeof(int) * cols);
		if (!matrix[i]){
			puts(MEMORY_MESSAGE);
			freeMatrix(matrix, i);
			return NULL;
		}
	}

	return matrix;
}

void readInput(int** matrix, const unsigned rows, const unsigned cols) {
	for (int y = 0; y < rows; y++){
		printf("Row %d. --> ", y + 1);
		for (int x = 0; x < cols; x++){
			scanf("%X", &matrix[y][x]);
		}
	}
}

long long extractCurrentRowNumber(const int* row, const unsigned size) {

	long long number = 0;
	unsigned power = 10;
	int temp = 0;
	for (int i = 0; i < size; i++){
		temp = row[i];
		while ((temp /= 10))
			power *= power;

		number *= power;
		number += row[i];

		power = 10;
	}

	return number;
}

void deleteRow(int*** matrix, const unsigned index, unsigned* rows, const unsigned cols) {

	for (int i = index; i < *rows; i++){
		(*matrix)[i] = (*matrix)[i + 1];
	}

	*rows -= 1;
	*matrix = (int**)realloc(*matrix, sizeof(int*) * *rows);
	if (!*matrix) {
		puts(MEMORY_MESSAGE);
		exit(EXIT_FAILURE);
	}
}

void deleteEvenComposedRows(int*** matrix, unsigned* rows, const unsigned cols) {
	
	long long currentRow = 0;
	for (int i = 0; i < *rows; i++){
		currentRow = extractCurrentRowNumber((*matrix)[i], cols);
		if (currentRow % 2 == 0) {
			deleteRow(matrix, i, rows, cols);
			i--;
		}
	}
}

void getColumsSums(const int** matrix, int* columnsSums, const unsigned rows, const unsigned cols) {

	int currentSum;
	for (int x = 0; x < cols; x++){
		currentSum = 0;
		for (int y = 0; y < rows; y++){
			currentSum += matrix[y][x];
		}
		columnsSums[x] = currentSum;
	}
}

void swap(int** matrix, const unsigned col1, const unsigned col2, const unsigned rows) {
	int temp = 0;
	for (int i = 0; i < rows; i++){
		temp = matrix[i][col1];
		matrix[i][col1] = matrix[i][col2];
		matrix[i][col2] = temp;
	}
}

void sort(int** matrix, int* columnsSums, const unsigned rows, const unsigned cols) {

	int swapped = 0;
	int temp = 0;
	for (int i = 0; i < cols - 1; i++){
		swapped = 0;
		for (int j = 0; j < cols - 1 - i; j++){
			if (columnsSums[j] <= columnsSums[j + 1]) continue;

			temp = columnsSums[j];
			columnsSums[j] = columnsSums[j + 1];
			columnsSums[j + 1] = temp;

			swap(matrix, j, j + 1, rows);
			swapped = 1;
		}
		if (!swapped) break;
	}
}

void sortColumsAscn(int** matrix, const unsigned rows, const unsigned cols) {
	int* columnsSums = (int*)malloc(sizeof(int) * cols);
	if (!columnsSums) {
		puts(MEMORY_MESSAGE);
		exit(EXIT_FAILURE);
	}

	getColumsSums(matrix, columnsSums, rows, cols);
	sort(matrix, columnsSums, rows, cols);
	free(columnsSums);
}

void printMatrix(const int** matrix, const unsigned rows, const unsigned cols) {
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			printf("%X ", matrix[i][j]);
		}
		puts(" ");
	}
}

int main_01() {

	unsigned rows, cols;

	printf("Insert rows and colums of table --> ");
	int res = scanf("%u %u", &rows, &cols);
	if (res != 2) {
		puts(INVALID_INPUT_MESSAGE);
		return -1;
	}

	int** table = createMatrix(rows, cols);
	if (!table) { return -1; }

	puts("Insert matrix values in hexadecimal format: ");
	readInput(table, rows, cols);

	deleteEvenComposedRows(&table, &rows, cols);
	sortColumsAscn(table, rows, cols);
	printMatrix(table, rows, cols);

	freeMatrix(table, rows);
	return 0;
}
