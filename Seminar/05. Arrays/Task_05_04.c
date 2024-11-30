#include<stdio.h>
#define MAX_ARR_LENGTH 128
/*
������ 4: �� �������, �� ��������� �� ����� � �����, ��� ����� ����� � ��� � ������������ ��- ������ ��� ����� �� ����� �� ������ ��� ������������ ��- ����� ��� ����� �� ���.
�� ������ � ��������� ������� ����� ���� �� ���� �����.
�������� �������, ����� ������ ����� �� ���� ����� � �� ���������� ����, �� �� ��������� �������� �����.
����: 1 5 1 0 3, �����: 1 5 0 3 1
����: 10 -10 -22 11 18, �����: 10 -22 11 -10 18

Zab| -> tuk poglednah reshenieto, izobshto ne se bqh setil
*/

void fillArray_03(int arr[], const int arrLength) {

	puts("Insert sequence members: ");
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void printSequence(const int arr[], const int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		printf("%d ", arr[i]);
	}
}

void swap(int arr[], int num1Index, int num2Index) {
	int temp = arr[num1Index];

	arr[num1Index] = arr[num2Index];
	arr[num2Index] = temp;
}

void convertSequenceToSaw(int arr[], const int arrLength)
{
	
	for (int i = 1; i < arrLength - 1; i++)
	{
		if (arr[i - 1] < arr[i] && arr[i] < arr[i + 1] || arr[i - 1] > arr[i] && arr[i] > arr[i + 1])
		{
			swap(arr, i, i + 1);
		}
		
	}
}

int main_05_04()
{
	int arr[MAX_ARR_LENGTH];
	short arrLength = 0;

	puts("Insert sequence length: (MAX 128)");
	scanf_s("%hu", &arrLength);
	fillArray_03(arr, arrLength);

	convertSequenceToSaw(arr, arrLength);

	printSequence(arr, arrLength);
	return 0;
}