#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable: 4996)
/*
������ 15. ������ � ���������� ����� N (1 < N < 20). ������ �������� ������ �� ������ N ���� �����. ���� ���� ������ �� ������ ����������� �������� �� ������, ����� �� �������� ���� ����� ����� ��� ������� ����� �� ����� ���� �� ������� '+', '-' ��� '*'. �� ������ �� ����������� ������� ��� �� �������� �����. ������������ �� ���� ����� ������ ������������ ������������� �������.

������:
����:                    �����:
3                    -17
-2 3 -5                (���-������� �������� �� �������� �� ������ -2 + 3 * -5)

����:                    �����:
4                    -8
1 5 0 4                (���-������� �������� �� �������� �� ������ 1 - 5 + 0 - 4)
*/

void getMinValue(int* numbers, int n, int* minSum, int currentValue, int index, int lastOperand) {
	if (index == n){
		*minSum = *minSum > currentValue ? currentValue : *minSum;
		return;
	}

	int next = numbers[index];

	getMinValue(numbers, n, minSum, currentValue + next, index + 1, next);

	getMinValue(numbers, n, minSum, currentValue - next, index + 1, -next);

	getMinValue(numbers, n, minSum, currentValue - lastOperand + (lastOperand * next), index + 1, lastOperand * next);
}

int main() {
	int n = 0;
	scanf("%d", &n);

	int* numbers = (int*)malloc(n * sizeof(int));
	if (!numbers) return -1;

	printf("Insert numbers --> ");
	for (int i = 0; i < n; i++){
		scanf("%d", &numbers[i]);
	}

	int minSum = INT_MAX;
	getMinValue(numbers, n, &minSum, numbers[0], 1, numbers[0]);
	printf("%d", minSum);

	return 0;
}