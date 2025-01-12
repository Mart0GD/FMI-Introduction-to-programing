#include<stdio.h>
#include<math.h>
#define ARR_LENGTH 128
/*
P9
Напишете програма, която прочита от конзолата цяло неторицателно число n (<= 128), след което прочита n цели числа, запазва ги в масив и намира най-късото възможно допълване до палиндром.
*/
// 14 21 71 1
void FillArray_09(int arr[], int arrLength) 
{
	for (int i = 0; i < arrLength; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}

int Reverse(int number)
{
	int reversed = 0;

	while (number != 0)
	{
		reversed *= 10;
		reversed += number % 10;
		number /= 10;
	}

	return reversed;
}

int ConcatNumbersInArray(const int arr[], int arrLength)
{
	int number = 0;
	for (int i = 0; i < arrLength; i++)
	{
		number *= 10;
		number += arr[i];
	}

	return number;
}

int IsPalindrome(int number) { return number == Reverse(number); }

int main_09()
{
	unsigned short n;
	int arr[ARR_LENGTH];

	scanf_s("%hu", &n);
	FillArray_09(arr, n);

	int originalNumber = ConcatNumbersInArray(arr, n);
	if (IsPalindrome(originalNumber))
	{
		puts("No extension needed!");
	}

	int numberToAdd = 0;
	int currentNumber = originalNumber;
	for (int i = 1; i < n; i++)
	{
		currentNumber *= pow(10, i);

		numberToAdd = Reverse(ConcatNumbersInArray(arr, i));
		currentNumber += numberToAdd;

		if (IsPalindrome(currentNumber))
		{
			printf("Minimum extension -> %d", numberToAdd);
			break;
		}

		currentNumber = originalNumber;
	}

	
	return 0;
}