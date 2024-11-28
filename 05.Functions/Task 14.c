#include<stdio.h>
#include<math.h>
/*
Напишете програма, която прочита цяло положително число и принтира броя на различните му прости делители. Създайте и използвайте функция countDistinctPrimeDivisors, която приема цяло число като аргумент и връща броя на различните прости делители на това число.
*/

int isNumberPrime(int number) {

	int sqrtOfNumber = sqrt(number);
	for (int i = 2; i <= sqrtOfNumber; i++)
	{
		if (number % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int countOfPrimeDivisors(int number) {
	int n = number % 2 == 0 ? (number / 2) + 1 : number;

	int count = 0;
	for (int i = 2; i < n; i++){
		if (number % i == 0 && isNumberPrime(i))
			count++;
	}

	return count;
}

int main_14() {

	int number = 0;
	scanf_s("%d", &number);

	printf("Prime divisors -> %d", countOfPrimeDivisors(number));
	return 0;
}