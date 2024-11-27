#include<stdio.h>
#define ARR_LENGTH 128
/*
�������� ��������, ����� ������� �� ��������� ���� ������������� ����� n (<= 128), ���� ����� ������� n ���� �����, ������� �� � ����� � ��������� ���� ������� � ������ ��������� ������ "�����".

���� ������ �� �������� �����, ��� ���� 3 �������������� ����� �������/���������� �����.
*/

void fillArray_05(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int main_05()
{
	unsigned short n;
	unsigned int arr[ARR_LENGTH];
	scanf_s("%hu", &n);
	fillArray_05(arr, n);

	int isSequenceSaw = 1;
	int positiveProgress = 1;
	int negativeProgress = 1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[i - 1])
		{
			positiveProgress++;
			negativeProgress = 0;
		}
		else if (arr[i] < arr[i - 1])
		{
			negativeProgress++;
			positiveProgress = 0;
		}

		if (positiveProgress >= 3 || negativeProgress >= 3)
		{
			isSequenceSaw = 0;
			break;
		}
	}

	printf("The sequence is saw -> %d", isSequenceSaw);;
	return 0;
}