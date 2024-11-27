#include<stdio.h>
#define ARR_LENGTH 128
/*
Ќапишете програма, ко€то прочита от конзолата ц€ло неторицателно число n (<= 128), след което прочита n реални числа, запазва ги в масив, прочита реално число sum и намира всички двойки числа от масива, които са равни на sum.
*/

void fillArray_06(int arr[], int arrLength) 
{
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int main_06()
{
	unsigned short n = 0;
	int arr[ARR_LENGTH];
	scanf_s("%hu", &n);
	fillArray_06(arr, n);
	 
	double sum = 0;
	scanf_s("%lf", &sum);

	int counter = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] + arr[j] == sum)
			{
				printf("%d. Pair -> %d,%d\n", counter, arr[i], arr[j]);
				counter++;
			}
		}
	}

	return 0;
}