#include<stdio.h>
#include<stdlib.h>

#pragma warning(push)
#pragma warning(disable: 4996)

/*
14. Дадена е матрица, сортирана по редове и стълбове (всеки ред е сортиран във възходящ ред и всеки стълб е сортиран във възходящ ред). Да се напише функция, която проверява дали даден елемент се среща в матрицата (Двумерно двоично търсене).
*/

void freeMatrix9(int** matrix, const unsigned rows) {

	for (int i = 0; i < rows; i++){
		free(matrix[i]);
	}

	free(matrix);
}

int** createMatrix9(const unsigned rows, const unsigned cols) {

	int** matrix = (int**)malloc(sizeof(int*)* rows);

	for (int i = 0; i < rows; i++){
		matrix[i] = (int*)malloc(sizeof(int) * cols);
		if (!matrix[i]) {
			freeMatrix9(matrix, i);
			return NULL;
		}
	}

	for (int y = 0; y < rows; y++){
		for (int x = 0; x < cols; x++){
			scanf("%d", &matrix[y][x]);
		}
	}

	return matrix;
}

int conatins(const int** matrix, const int desiredNumber, const unsigned rows, const unsigned cols) {

	for (int y = 0; y < rows; y++) {
		for (int x = cols - 1; x >= 0 ; x--){
			if (y >= rows || x < 0) return 0;

			if (matrix[y][x] > desiredNumber) continue;
			if (matrix[y][x] == desiredNumber) return 1;

			y++;x++;
		}
	}

	return 0;
}

int main_07_14() {

	unsigned rows, cols;
	printf("Insert matrix dimensions --> ");
	scanf("%u %u", &rows, &cols);

	puts("Insert sorted matrix: ");
	int** matrix = createMatrix9(rows, cols);

	int numberToFind = 0;
	printf("Number to find -->");
	scanf("%d", &numberToFind);

	int res = conatins(matrix, numberToFind, rows, cols);

	res
		? printf("Matrix conatins %d", numberToFind)
		: printf("Matrix does not conatins %d", numberToFind);

	freeMatrix9(matrix, rows);
	return 0;
}
