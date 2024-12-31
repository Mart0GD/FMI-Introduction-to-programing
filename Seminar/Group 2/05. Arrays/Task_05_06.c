#include<stdio.h>
#define MAX_ARR_LENGTH 128
/*
������ 6: ������� �� ����� k.
�� �� ������ �������, ����� ��������� ���� � ������� ����� ���������� ��������, ����� �������� ���� ����, ����� �� k. ��� ���, �� �� ������� ��������� �� ������ � ��������� ������� �� ���������. � �������� ������, �� �� ������ ��������� ���������.
����: 17 23 5 -14 0    -9, �����: yes
����: 17 23 5 8 0        31, �����: no
*/

void fillArray_05(int arr[], const int arrLength) {

	puts("Insert sequence members: ");
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void arrayContainsSum(const int arr[], const int sum, const int arrLength) {

	int currentSum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		currentSum = 0;
		for (int j = i; j < arrLength; j++)
		{
			currentSum += arr[j];
			if (currentSum == sum)
			{
				printf("Yes -> ");
				printf("start index -> %d, end index -> %d", i, j);
				return 1;
			}
		}
	}

	printf("No!");
}

int main_05_06()
{
	int arr[MAX_ARR_LENGTH];
	short arrLength = 0;

	puts("Insert sequence length: (MAX 128)");
	scanf_s("%hu", &arrLength);
	fillArray_05(arr, arrLength);

	int sum = 0;
	puts("Insert sum for search:");
	scanf_s("%d", &sum);

	arrayContainsSum(arr, sum, arrLength);

	return 0;
}