#include<stdio.h>
#define ARR_LENGTH 128
/*
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив и прочита цяло число rotations. Ако rotations е позитивно число, измества масива на дясно с rotations брой позиции. Ако rotations е негативно се извършва същото действие, но на ляво.
*/
void FillArray_10(int arr[], unsigned short arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

void RotateArrayRight(int arr[], int arrLength, int rotations)
{
	int helper = 0;
	for (int i = 0; i < rotations; i++)
	{
		helper = arr[arrLength - 1];
		for (int j = arrLength - 1; j > 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = helper;
	}

}

void RotateArrayLeft(int arr[], int arrLength, int rotations)
{
	int helper = 0;
	for (int i = 0; i < rotations; i++)
	{
		helper = arr[0];
		for (int j = 0; j < arrLength - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[arrLength - 1] = helper;
	}

}

int main_10() 
{
	unsigned short n;
	int arr[ARR_LENGTH];

	scanf_s("%hu", &n);
	FillArray_10(arr, n);

	int rotations = 0;
	scanf_s("%d", &rotations);

	rotations > 0 ? RotateArrayRight(arr, n, rotations) : RotateArrayLeft(arr, n, -rotations);

	return 0;
}