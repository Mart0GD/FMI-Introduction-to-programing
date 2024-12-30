#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

void freeMatrix6(int** matrix, const unsigned rows) {
	for (int i = 0; i < rows; i++){
		free(matrix[i]);
	}

	free(matrix);
}

int** createMatrix6(const unsigned size) {

	int** matrix = (int**)malloc(sizeof(int*) * size);
	if (!matrix) return NULL;

	for (int i = 0; i < size; i++){
		matrix[i] = (int*)malloc(sizeof(int) * size);
		if (!matrix[i]) {
			freeMatrix(matrix, i);
			return NULL;
		}
	}

	for (int y = 0; y < size; y++){
		for (int x = 0; x < size; x++){
			scanf("%d", &matrix[y][x]);
			if (matrix[y][x] <= 0 || matrix[y][x] > size){
				puts("Invalid input!");
				freeMatrix6(matrix, size);
				return NULL;
			}
		}
	}

	return matrix;
}

int* getNumbers(const unsigned boardSize) {

	unsigned actualSize = boardSize * boardSize;

	int* arr = (int*)malloc(sizeof(int) * actualSize);
	if (!arr) return NULL;

	for (int i = 1; i <= actualSize; i++)
		arr[i - 1] = i;

	return arr;
}

int isSeen3(const int* arr, const int element, const unsigned arrSize) {

	for (int i = 0; i < arrSize; i++){
		if (arr[i] == element)
			return 1;
	}

	return 0;
}

int checkNumbersInRow(const int* arr, const unsigned arrSize) {

	int* seenNumbers = (int*)malloc(sizeof(int) * arrSize);
	if (!seenNumbers) return -1;

	for (int i = 0; i < arrSize; i++){
		if (isSeen3(seenNumbers, arr[i], arrSize)){
			free(seenNumbers);
			return 0;
		}

		seenNumbers[i] = arr[i];
	}

	free(seenNumbers);
	return 1;
}

int checkNumbersInCol(const int** board, const unsigned col, const unsigned boardSize) {

	int* seenNumbers = (int*)malloc(sizeof(int) * boardSize);
	if (!seenNumbers) return -1;

	for (int row = 0; row < boardSize; row++){
		if (isSeen3(seenNumbers, board[row][col], boardSize)){
			free(seenNumbers);
			return 0;
		}

		seenNumbers[row] = board[row][col];
	}

	return 1;
}

int isSudokuSolution(const int** board, const int* numbersInPlay, const unsigned boardSize) {

	for (int i = 0; i < boardSize; i++) {
		if (!checkNumbersInRow(board[i], boardSize)) {
			return 0;
		}
		if (!checkNumbersInCol(board, i, boardSize)) {
			return 0;
		}
	}
	
	return 1;
}

int main_07_10() {

	unsigned size;

	printf("Insert boardSize --> ");
	scanf("%u", &size);

	int* numberInPlay = getNumbers(size);

	int** board = createMatrix6(size * size);
	if (!board) return -1;

	int result = isSudokuSolution(board, numberInPlay, size * size);

	result
		? printf("The matrix is a solution")
		: printf("The matrix is not a solution");

	freeMatrix6(board, size);
	free(numberInPlay);
}
