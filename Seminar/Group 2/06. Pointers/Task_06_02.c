//#include<stdio.h>
//#include<stdlib.h>
///*
//Задача 2: Напишете функция, която приема матрица NxN и проверява дали релацията, която представлява матрицата, е релация на еквивалентност.
//*/
//
//int** createSquareMatrix_2(const unsigned size) {
//
//	int** matrix = (int**)malloc(sizeof(int*) * size);
//	for (int i = 0; i < size; i++){
//		matrix[i] = (int*)malloc(sizeof(int) * size);
//	}
//
//	return matrix;
//}
//
//void readInput_2(int** matrix, const unsigned matrixSize) {
//	for (int y = 0; y < matrixSize; y++) {
//		for (int x = 0; x < matrixSize; x++) {
//			scanf_s("%d", &matrix[y][x]);
//		}
//	}
//}
//
//int checkReflexivity(const int** matrix, const unsigned matrixSize) {
//
//	for (int i = 0; i < matrixSize - 1; i++)
//		if (matrix[i][i] != matrix[i + 1][i + 1]) { return 0; }
//
//	return 1;
//}
//
//int checkSymmetry(const int** matrix, const unsigned matrixSize) {
//
//	for (int y = 0; y < matrixSize; y++){
//		for (int x = 0; x < matrixSize; x++){
//			if (matrix[y][x] != matrix[x][y])
//				return 0;
//		}
//	}
//
//	return 1;
//}
//
//int checkTransitivity(const int** matrix, const unsigned matrixSize) {
//
//	for (int i = 0; i < matrixSize - 1; i++){
//		for (int j = 0; j < matrixSize - 1; j++){
//			for (int k = 0; k < matrixSize - 1; i++){
//				if (matrix[i][j] > 0 && matrix[j][k] > 0 && matrix[i][k] > 0)
//					continue;
//				return 0;
//			}
//		}
//	}
//
//	return 1;
//}
//
//int checkRelationOfEquivalence(const int** matrix, const unsigned matrixSize) {
//	return checkReflexivity(matrix, matrixSize) && checkSymmetry(matrix, matrixSize) && checkTransitivity(matrix, matrixSize);
//}
//
//int main_06_02() {
//
//	int matrixSize = 0;
//
//	printf("insert matrix size: ");
//	scanf_s("%d", &matrixSize);
//
//	int** matrix = createSquareMatrix_2(matrixSize);
//	readInput_2(matrix, matrixSize);
//
//	printf("Is matrix a relation of equivalence --> %d", checkRelationOfEquivalence(matrix, matrixSize));
//
//	return 0;
//}