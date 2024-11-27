#include<stdio.h>
#define ARR_LENGTH 128
/*
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив, и проверява дали съществува подредица, чиято сума е равна на 0.
*/

// 1 -1 2 31 21-52
void FillArray_07(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int CheckZeroSumSequence(int arr[], int arrLength)
{ 
	int currentSum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		currentSum = arr[i];
		for (int j = i + 1; j < arrLength; j++)
		{
			currentSum += arr[j];
			if (currentSum == 0)
			{
				return 1;
			}
		}
	}

	return 0;
}

int main_07()
{
	int n;
	int arr[ARR_LENGTH];
	scanf_s("%d", &n);

	FillArray_07(arr, n);
	printf("Does array have undersequence equal to zero - %d", CheckZeroSumSequence(arr, n));
}