#include<stdio.h>
#include<limits.h>
#define ARR_LENGTH 128

fillArray_04(const arr[], const int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int isNumberInArray(const int arr[], const int number, const int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == number)
		{
			return 1;
		}
	}

	return 0;
}

void findUniqueNumbersInArray(int arr[], const int arrLength)
{
	int seenNumbers[ARR_LENGTH] = { 0 };

	for (int i = 0; i < arrLength; i++)
	{
		if (!isNumberInArray(arr, arr[i], arrLength))
		{
			seenNumbers[arr[i]];
		}
	}

}

/*
�������� ��������, ����� ������� �� ��������� ���� ������������� ����� n (<= 128), ���� ����� ������� n ���� �����, ������� �� � ����� � ����� ������� ������� � ���������, ����� �� ��������.
*/
int main_04()
{
	unsigned short n;
	int arr[ARR_LENGTH];
	scanf_s("%hu", &n);

	fillArray_04(arr, n);
	findUniqueNumbersInArray(arr, n);
}