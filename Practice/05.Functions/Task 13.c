#include<stdio.h>
#include<math.h>
/*
Напишете програма, която прочита от конзолата цяло число и връща числото, но с разменени местата на най-младшия и най-старшия бит. Създайте функция swapEndBits, която приема цяло число като аргумент и връща цяло число.
*/

int toggleBitOn(int number, int index) {
	return number | (1 << index);
}

int toggleBitOff(int number, int index) {
	return number & ~(1 << index);
}

int swapEndBits(int number) {
	int msbIndex = log2(number);
	int msb = (number >> msbIndex) & 1;

	int lsbIndex = 0;
	int lsb = number & 1;

	for (int i = msbIndex; i >= 0; i--)
	{
		printf("%d", number >> i & 1);
	}
	puts("");

	number = lsb == 1 ? toggleBitOn(number, msbIndex) : toggleBitOff(number, msbIndex);
	number = msb == 1 ? toggleBitOn(number, lsbIndex) : toggleBitOff(number, lsbIndex);
	
	for (int i = msbIndex; i >= 0; i--)
	{
		printf("%d", number >> i & 1);
	}
	puts("");

	return number;
}

int main_13() {
	int number = 0;
	scanf_s("%d", &number);

	printf("%d", swapEndBits(number));
	return 0;
}