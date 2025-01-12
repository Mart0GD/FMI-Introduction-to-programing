#include<stdio.h>
/*
�������� ��������, ����� ������� �� ��������� ���� ������������� ����� n (<= 128), ���� ����� ������� n ���� �����, ������� �� � ����� � ����� �� �������� �� ���������.
*/
void fillArray_01(int arr[], const int numbersToRead)
{
	for (int i = 0; i < numbersToRead; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void printArray(const int arr[], const int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		printf("%d -> %d\n", i + 1, arr[i]);
	}
}

int main_01()
{
	#define ARR_LENGTH 128

	unsigned short n;
	int arr[ARR_LENGTH] = { 0 };
	scanf_s("%hu", &n);

	fillArray_01(arr, n);
	printArray(arr, n);
	return 0;
}