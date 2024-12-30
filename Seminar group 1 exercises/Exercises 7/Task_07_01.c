#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
1. Напишете програма, която да работи с матрици от числа с плаваща точка и има функции, с които:
 - Въвежда матрица от стандартния вход
 - Извежда матрица на екрана
 - Събира две матрици
 - Изважда две матрици
 - Умножава две матрици
 - Транспонира матрица
*/

void freeMatrix(float** matrix, const unsigned rows) {
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void fillMatrix(float** matrix, const unsigned rows, const unsigned cols) {
	puts("Insert matrix values: ");
	for (int y = 0; y < rows; y++) {
		printf("Insert row %d -->", y + 1);
		for (int x = 0; x < cols; x++) {
			scanf("%f", &matrix[y][x]);
		}
	}
}

void printMatrix(const float** matrix, const unsigned rows, const unsigned cols) {
	for (int y = 0; y < rows; y++){
		for (int x = 0; x < cols; x++){
			printf("%.2f ", matrix[y][x]);
		}
		puts("");
	}
}

float** createMatrix(const unsigned rows, const unsigned cols) {
	float** matrix = (float**)malloc(sizeof(float*) * rows);

	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++) {
		matrix[i] = (float*)malloc(sizeof(float) * cols);
		if (!matrix[i]) return NULL;
	}

	return matrix;
}

float** sumMatricies(const float** matrixA, const float** matrixB, const unsigned rows, const unsigned cols) {
	float** sum = createMatrix(rows, cols);
	if (!sum) return NULL;

	for (int y = 0; y < rows; y++){
		for (int x = 0; x < cols; x++){
			sum[y][x] = matrixA[y][x] + matrixB[y][x];
		}
	}

	return sum;
}

float** subtractMatricies(const float** matrixA, const float** matrixB, const unsigned rows, const unsigned cols) {
	float** difference = createMatrix(rows, cols);
	if (!difference) return NULL;

	for (int y = 0; y < rows; y++){
		for (int x = 0; x < cols; x++){
			difference[y][x] = matrixA[y][x] - matrixB[y][x];
		}
	}

	return difference;
}

float** multiplyMatricies(const float** matrixA, const float** matrixB, const unsigned m, const unsigned n, const unsigned k){

	float** product = createMatrix(m,k);
	if (!product) return NULL;

	float sum = 0;
	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < k; x++)
		{
			sum = 0;
			for (int i = 0; i < n; i++){
				sum += matrixA[y][i] * matrixB[i][x];
			}
			product[y][x] = sum;
		}
	}
	
	return product;
}

float** transponateMatrix(const float** matrix, const unsigned rows, const unsigned cols) {

	float** transponatedMatrix = createMatrix(rows, cols);
	if (!transponatedMatrix) return NULL;

	for (int y = 0; y < cols; y++){
		for (int x = 0; x < rows; x++){
			transponatedMatrix[y][x] = matrix[x][y];
		}
	}

	return transponatedMatrix;
}

int main_07_01() {

	unsigned rows1, cols1;

	printf("Insert matrix one dimensions (MxN) --> ");
	int res = scanf("%u %u", &rows1, &cols1);
	if (res != 2) {
		puts("Invalid input!");
		return -1;
	}
	float** matrixOne = createMatrix(rows1, cols1);

	unsigned rows2, cols2;

	printf("Insert matrix two dimensions (MxN) --> ");
	res = scanf("%u %u", &rows2, &cols2);
	if (res != 2) {
		puts("Invalid input!");
		return -1;
	}

	float** matrixTwo = createMatrix(rows2, cols2);

	if (!matrixOne || !matrixTwo){
		puts("Invalid input!");
		return -1;
	}

	fillMatrix(matrixOne, rows1, cols1);
	fillMatrix(matrixTwo, rows2, cols2);

	float** sum = NULL;
	float** difference = NULL;
	float** product = NULL;

	if (rows1 != rows2 || cols1 != cols2){
		puts("Matricies must have the same dimensions to be summed or subtracted!");
	}
	else { 
		sum = sumMatricies(matrixOne, matrixTwo, rows1, cols1); 
		difference = subtractMatricies(matrixOne, matrixTwo, rows1, cols1);

		puts("Matricies sum: ");
		printMatrix(sum, rows1, cols1);

		puts("Matricies difference: ");
		printMatrix(difference, rows1, cols1);

		freeMatrix(sum, rows1);
		freeMatrix(difference, rows1);
	}

	if (cols1 != rows2){
		puts("Matricies cannot be multiplied! Matricies must be in format (MxN NxK)");
	}
	else{
		product = multiplyMatricies(matrixOne, matrixTwo, rows1, cols1, cols2);

		puts("Matricies product:");
		printMatrix(product, rows1, cols2);
		freeMatrix(product, cols2);
	}

	float** transponatedMatrixOne = transponateMatrix(matrixOne, rows1, cols1);
	float** transponatedMatrixTwo = transponateMatrix(matrixTwo, rows2, cols2);

	puts("Transponated matrix one:");
	printMatrix(transponatedMatrixOne, cols1, rows1);

	puts("Transponated matrix two:");
	printMatrix(transponatedMatrixTwo, cols2, rows2);

	freeMatrix(transponatedMatrixOne, cols1);
	freeMatrix(transponatedMatrixTwo, cols2);
	freeMatrix(matrixOne, rows1);
	freeMatrix(matrixTwo, rows2);
	return 0;
}