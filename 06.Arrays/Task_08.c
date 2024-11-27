#include<stdio.h>
#define ARR_LENGTH 128
/*
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив и намира началото и дължината на най-дългата растяща подредица.
*/

void FillArray_08(int arr[], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int GetMaxPositiveSequenceStartIndex(int arr[], int arrLength)
{
	int maxSequenceLength;
	int maxSequenceStartIndex; 

	int currentSequenceLength = 0;
	for (int i = 0; i < arrLength; i++)
	{
		currentSequenceLength = 1;
		for (int j = i + 1; j < arrLength; j++)
		{
			if (arr[j - 1] < arr[j])
				currentSequenceLength++;
			else
				break;
		}
	}
	return 0;
}

int main_08()
{
	int n;
	int arr[ARR_LENGTH];
	scanf_s("%d", &n);
	FillArray_08(arr, n);

	int maxSequenceIndex = GetMaxPositiveSequenceStartIndex(arr, n);
	return 0;
}