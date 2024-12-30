//#include<stdio.h>
//#include<stdlib.h>
//
////Задача 3: Напишете функция, която приема матрица NxM и матрица MxK и умножава първата матрица по втората.
//
//void freeMatrix_3(int** matrix, const unsigned rows) {
//
//	for (int i = 0; i < rows; i++) {
//		free(matrix[i]);
//	}
//
//	free(matrix);
//}
//
//int** createMatrix(const unsigned rows, const unsigned cols) {
//
//	int** matrix = (int**)malloc(rows * sizeof(int*));
//	if (!matrix) return NULL;
//
//	for (int i = 0; i < rows; i++) {
//		matrix[i] = (int*)malloc(sizeof(int) * cols);
//		if (!matrix[i]) return NULL;
//	}
//
//	return matrix;
//}
//
//void readInput_3(int** firstMatrix, const unsigned rows, const unsigned cols) {
//	for (int i = 0; i < rows; i++) {
//		printf("Row %d.", i + 1);
//		for (int j = 0; j < cols; j++) {
//			scanf_s("%d", &firstMatrix[i][j]);
//		}
//	}
//}
//
//int** transponateRectangeleMatrix(const int** matrix, const unsigned rows, const unsigned cols) {
//
//	int** transponatedMatrix = createMatrix(cols, rows);
//	if (!transponatedMatrix) return NULL;
//
//	for (int y = 0; y < cols; y++)
//	{
//		for (int x = 0; x < rows; x++)
//		{
//			transponatedMatrix[y][x] = matrix[x][y];
//		}
//	}
//
//	return transponatedMatrix;
//}
//
//int** multiplyMatricies(const int** matrixOne, const int** matrixTwo, const unsigned n, const unsigned m, const unsigned k) {
//
//	int** product = createMatrix(n, k);
//	int** matrixTwoTransponated = transponateRectangeleMatrix(matrixTwo, m, k);
//
//	int sum = 0;
//	for (int y = 0; y < n; y++)
//	{
//		for (int x = 0; x < k; x++)
//		{
//			sum = 0;
//			for (int i = 0; i < m; i++)
//			{
//				sum += matrixOne[y][i] * matrixTwoTransponated[x][i];
//			}
//			product[y][x] = sum;
//		}
//	}
//
//	freeMatrix_3(matrixTwoTransponated, k);
//	return product;
//}
//
//void printMatrix_3(const int** matrix, const unsigned rows, const unsigned cols) {
//
//	for (int y = 0; y < rows; y++)
//	{
//		for (int x = 0; x < cols; x++)
//		{
//			printf("%d ", matrix[y][x]);
//		}
//		puts("");
//	}
//
//}
//
//int main_06_03() {
//
//	unsigned n, m, k;
//
//	printf("Insert matrices dimensions (NxM and MxK) --> ");
//	scanf_s("%u %u %u", &n, &m, &k);
//
//	int** firstMatrix = createMatrix(n, m);
//	int** secondMatrix = createMatrix(m, k);
//
//	puts("First matrix: ");
//	readInput_3(firstMatrix, n, m);
//
//	puts("Second matrix: ");
//	readInput_3(secondMatrix, m, k);
//
//	int** product = multiplyMatricies(firstMatrix, secondMatrix, n, m, k);
//
//	printMatrix_3(product, n, k);
//
//	freeMatrix_3(firstMatrix, m);
//	freeMatrix_3(secondMatrix, k);
//	freeMatrix_3(product, k);
//	return 0;
//}