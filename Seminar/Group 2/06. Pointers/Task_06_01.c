//#include<stdio.h>
//#include<stdlib.h>
//
//#pragma warning(push)
//#pragma warning(disable: 4996)
////Напишете функция, която приема матрица NxN и транспонира матрицата.
//
//void freeMatrix(int** matrix, const unsigned matrixSize) {
//
//	for (int i = 0; i < matrixSize; i++){
//		free(matrix[i]);
//	}
//
//	free(matrix);
//}
//
//int** createSquareMatrix(const unsigned size) {
//
//	int** matrix = (int**)malloc(sizeof(int*) * size);
//	if (!matrix) return NULL;
//
//	for (int i = 0; i < size; i++)
//	{
//		matrix[i] = (int*)malloc(sizeof(int) * size);
//		if (!matrix[i]) return NULL;
//	}
//
//	return matrix;
//}
//
//void readInput(int** matrix, const unsigned matrixSize) {
//	for (int y = 0; y < matrixSize; y++){
//		for (int x = 0; x < matrixSize; x++){
//			scanf("%d", &matrix[y][x]);
//		}
//	}
//}
//
//int** transponateMatrix(const int** matrix, const unsigned matrixSize) {
//
//	int** transponatedMatrix = createSquareMatrix(matrixSize);
//
//	for (int y = 0; y < matrixSize; y++)
//	{
//		for (int x = 0; x < matrixSize; x++)
//		{
//			transponatedMatrix[x][y] = matrix[y][x];
//		}
//	}
//
//	return transponatedMatrix;
//}
//
//void printMatrix(int** matrix, const unsigned size) {
//
//	for (int y = 0; y < size; y++)
//	{
//		for (int x = 0; x < size; x++)
//		{
//			printf("%d ", matrix[y][x]);
//		}
//		puts("");
//	}
//
//}
//
//int main_06_01() {
//	unsigned matrixSize = 0;
//
//	printf("Insert matrix size: ");
//	scanf("%u", &matrixSize);
//
//	int** matrix = createSquareMatrix(matrixSize);
//
//	puts("Insert matrix rows");
//	readInput(matrix, matrixSize);
//	int** transponatedMatrix = transponateMatrix(matrix, matrixSize);
//
//
//	puts("transponated matrix: ");
//	printMatrix(transponatedMatrix, matrixSize);
//
//
//	freeMatrix(matrix, matrixSize);
//	freeMatrix(transponatedMatrix, matrixSize);
//	return 0;
////}