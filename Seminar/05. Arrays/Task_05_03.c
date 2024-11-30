#include<stdio.h>

int firstOrDefaultMissing(const int arr[], const int arrLength)
{
	for (int i = arr[0] + 1; i < arrLength; i++)
	{
		if (arr[i] != i)
			return i;
	}

	return -1;
}

int main_05_03()
{
	int arr[] = { 1,2,3,4,6,7,8,10 };
	
	int firstMissingNumberIndex = firstOrDefaultMissing(arr, sizeof(arr) / sizeof(int));
	printf("%d", firstMissingNumberIndex);
}