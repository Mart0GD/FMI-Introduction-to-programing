#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#pragma warning(push)
#pragma warning(disable: 4996)
//* �) �� �� ������ ��������, ����� ������ �������������� �� ��������� ������� �� ��� N.

void freeDet(int** det, const unsigned size) {
	for (int i = 0; i < size; i++){
		free(det[i]);
	}

	free(det);
}

int** createDeterminant(const unsigned size) {

	int** det = (int**)malloc(sizeof(int*) * size);
	if (!det) return NULL;

	for (int i = 0; i < size; i++){
		det[i] = (int*)malloc(sizeof(int) * size);
		if (!det[i]) {
			freeDet(det, i);
		}
	}
	return det;
}

int** copyDeterminant(const int** det, const unsigned size, const unsigned rowSkip, const unsigned colSkip) {

	int** newDet = createDeterminant(size - 1);

	unsigned newX = 0, newY = 0;
	for (int y = 0; y < size; y++){
		newX = 0;
		for (int x = 0; x < size; x++){
			if (y != rowSkip && x != colSkip){
				newDet[newY][newX++] = det[y][x];
			}
		}
		newY += y == rowSkip ? 0 : 1;
	}
	return newDet;
}

void fillDeterminant(int** det, const unsigned size) {

	for (int y = 0; y < size; y++){
		for (int x = 0; x < size; x++){
			scanf("%d", &det[y][x]);
		}
	}
}

int solveDeterminant(int** det, unsigned size) {
	if (size == 1) return det[0][0];
	if (size == 2) {
		int res = det[0][0] * det[1][1] - (det[0][1] * det[1][0]);
		return res;
	}

	int sum = 0;
	int** newDet = NULL;
	for (int i = 0; i < size; i++)
	{
		newDet = copyDeterminant(det, size, 0, i);
		sum += pow(-1, 2 + i) * det[0][i] * solveDeterminant(newDet, size - 1);
		freeDet(newDet)
	}
	
	return sum;
}

int main() {

	unsigned size;
	int res = scanf("%u", &size);
	if (res != 1) {
		puts("Invalid input!");
		return -1;
	}

	int** determinant = createDeterminant(size);
	fillDeterminant(determinant, size);

	int result = 0;
	if (size == 1) {
		result = determinant[0][0];
	}
	else {
		result = solveDeterminant(determinant, size);
	}

	printf("the result is %d", result);
	freeDet(determinant);
	return 0;
}