#include<stdio.h>
#include<math.h>
/*
Напишете програма, която прочита цяло число и принтира в конзолата резултата от функция, която приема число като аргумент, сменя стойностите на всеки 2 последователни бита на подаденото число и връща резултата.
*/

int ToogleOff(int number, int index) {
	return number & ~(1 << index);
}

int togleOn(int number, int index) {
	return number | (1 << index);
}

int swapNeighbourBitsValues(int number){

	int previousBit = number & 1;
	int msob = log2(number) + 1;


	for (int i = msob; i >= 0; i--)
	{
		int bit = number >> i & 1;
		printf("%d", bit);
	}
	puts("");

	for (int i = 1; i < msob; i++)
	{
		if (previousBit == 0)
		{
			previousBit = number >> i & 1;
			number = ToogleOff(number, i);
			continue;
		}
		else {
			previousBit = number >> i & 1;
			number = togleOn(number, i);
		}

	}

	for (int i = msob; i >= 0; i--)
	{
		int bit = number >> i & 1;
		printf("%d", bit);
	}
	return number;
}

int main_09()
{
	int number = 0;
	scanf_s("%d", &number);

	number = swapNeighbourBitsValues(number);
	return 0;
}