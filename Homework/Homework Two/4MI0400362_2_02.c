#include<stdio.h>
#include<math.h>

#pragma warning(push)
#pragma warning(disable: 4996)
#define MAX_MATRIX_ROWS 100
#define MAX_MATRIX_COLS 100

int readMatrix(int matrix[][MAX_MATRIX_ROWS], const unsigned rows, const unsigned cols)
{
	for (int y = 0; y < rows; y++)
	{
		printf("Row %d:\n", y + 1);
		for (int x = 0; x < cols; x++)
		{
			if (scanf("%d", &matrix[y][x]) != 1) {
				return -1;
			}
		}
	}

	return 1;
}

void printMatrix(const int matrix[][MAX_MATRIX_ROWS], const unsigned rows, const unsigned cols) {
	if (rows == 0) {
		puts("All rows were k similar. No matrix can be formed!");
		return;
	}

	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			printf("%d ", matrix[y][x]);
		}
		puts(" ");
	}
}

int hammingDistance(unsigned a, unsigned b) {

	unsigned distance = 0;
	int loopCap = log2(a > b ? a : b);
	for (int i = 0; i <= loopCap; i++)
	{
		distance += ((a >> i) & 1) != ((b >> i) & 1);
	}

	return distance;
}

void deleteRow(int matrix[][MAX_MATRIX_ROWS], const unsigned index, const unsigned rows, const unsigned cols) {
	if (index >= rows){
		puts("Invalid input, index out of range!");
		return;
	}

	for (int y = index + 1; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			matrix[y - 1][x] = matrix[y][x];
		}
	}
}

int isSeen(const int arr[], const int value, const unsigned arrSize)
{
	for (int i = 0; i < arrSize; i++){
		if (arr[i] == value)
			return 1;
	}
	return 0;
}

void sort(int arr[], const unsigned arrSize) {

	int swapped = 0;
	int temp = 0;
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}

		if (!swapped) break;
	}
}

int clearK(int matrix[][MAX_MATRIX_ROWS], unsigned* rowSize, unsigned colSize, const int k) {

	int currentKSum = 0;
	int indexesToDelete[MAX_MATRIX_ROWS];
	unsigned indexArrSize = 0;

	for (int y = 0; y < (*rowSize); y++)
	{
		for (int currentY = y + 1; currentY < *rowSize; currentY++)
		{
			currentKSum = 0;
			for (int x = 0; x < colSize; x++)
			{
				currentKSum += hammingDistance(matrix[y][x], matrix[currentY][x]);
			}

			if (currentKSum <= k)
			{
				if(!isSeen(indexesToDelete, y, indexArrSize)) indexesToDelete[indexArrSize++] = y;
				if(!isSeen(indexesToDelete, currentY, indexArrSize)) indexesToDelete[indexArrSize++] = currentY;
			}
		}
	}

	if (indexArrSize > 0)
	{
		sort(indexesToDelete, indexArrSize);
		for (int i = 0; i < indexArrSize; i++) {
			deleteRow(matrix, indexesToDelete[i] - i, *rowSize, colSize);
			*rowSize -= 1;
		}
	}
	
}

int main2() {
	unsigned matrixRows, matrixCols;

	printf("Insert matrix rows: ");
	if (scanf("%d", &matrixRows) != 1 || matrixRows > MAX_MATRIX_ROWS) {
		puts("Invalid row size!");
		return -1;
	}

	printf("Insert matrix colums: ");
	if (scanf("%d", &matrixCols) != 1 || matrixCols > MAX_MATRIX_COLS) {
		puts("Invalid column size!");
		return -1;
	}

	int matrix[MAX_MATRIX_COLS][MAX_MATRIX_ROWS];
	if (readMatrix(matrix, matrixRows, matrixCols) == -1) {
		puts("Inavlid input!");
		return -1;
	}

	printf("Please input the k difference (max 32): ");
	unsigned k = 0;
	if (scanf("%d", &k) != 1 || k > (matrixCols * (sizeof(unsigned) * 8))){
		puts("Invalid input!");
		return -1;
	}

	clearK(matrix, &matrixRows, matrixCols, k);
	puts("Final matrix: ");
	printMatrix(matrix, matrixRows, matrixCols);
	return 0;
}