#include<stdio.h>

/*
�������� ��������, ����� ������� ���� ����� n � �������� ������� �� �������� �� n-��� ���� (�����������). �������� � ����������� ������� printFibonacciSequence, ����� ������ ���� ����� ���� �������� � �� ����� ����.
*/

void printFibonacciSequence(int n) {

	if (n <= 2)
	{
		for (int i = 0; i < n; i++)
		{
			printf("1 ");
		}
		return;
	}

	printf("1 1 ");
	int predecessor = 1;
	int prePredecessor = 1;

	int currentNumber = 0;
	for (int i = 2; i < n; i++)
	{
		currentNumber = predecessor + prePredecessor;
		printf("%d ", currentNumber);

		prePredecessor = predecessor;
		predecessor = currentNumber;
	}
	
	return 0;
}

int main() {
	int n = 0;
	scanf_s("%d", &n);

	printFibonacciSequence(n);
	return 0;
}