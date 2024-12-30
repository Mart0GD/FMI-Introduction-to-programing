#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)
/*
3. ��������� � ��� ������� ����� � a[i,j] ��� a[i,j] � ��������� ������� � i-��� ��� � ���������� ������� � j-��� ����� �� A ��� ��������� �� ���� � ���������� �� ������. �� �� ������ ��������, ����� ���������� ���� ���������� ������� ����� � ������ ������� A � ���������� n x m.
*/

void freeMatrix3(int** matrix, const rows) {
	for (int i = 0; i < rows; i++){
		free(matrix[i]);
	}

	free(matrix);
}

int** createMatrix3(const unsigned rows, const unsigned cols) {

	int** matrix = (int**)malloc(sizeof(int*) * rows);
	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++){
		matrix[i] = (int*)malloc(sizeof(int) * cols);
		if (!matrix[i]) return NULL;
	}

	return matrix;
}

void fillMatrix3(int** matrix,const unsigned rows, const unsigned cols) {
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
}

int isMinInRow(const int element, const int* row, const int cols) {
	for (int i = 0; i < cols; i++){
		if (element > row[i]) // no information for equalities 
			return 0;
	}
	return 1;
}

int isMaxInCol(const int** matrix, const int element, const int colIndex, const unsigned rows) {
	for (int y = 0; y < rows; y++){
		if (matrix[y][colIndex] > element){
			return 0;
		}
	}

	return 1;
}

int checkForSaddlePoint(int** matrix, const unsigned rows, const unsigned cols) {

	for (int y = 0; y < rows; y++){
		for (int x = 0; x < cols; x++){
			if (isMinInRow(matrix[y][x], matrix[y], cols) && isMaxInCol(matrix, matrix[y][x], x, rows))
				return 1;
		}
	}

	return 0;
}

int main_07_03() {
	unsigned rows, cols;

	printf("Insert matrix dimensions -->");
	int res = scanf("%u %u", &rows, &cols);
	if (res != 2){
		puts("Invalid inpu!");
		return -1;
	}

	int** matrix = createMatrix3(rows, cols);
	fillMatrix3(matrix, rows, cols);

	int hasSaddlePoint = checkForSaddlePoint(matrix, rows, cols);

	hasSaddlePoint
		? puts("The matrix has saddle point.")
		: puts("The matrix has no saddle points");

	freeMatrix3(matrix, rows);
	return 0;
}