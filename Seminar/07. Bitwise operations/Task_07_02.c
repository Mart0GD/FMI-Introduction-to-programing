#include<stdio.h>
#include<math.h>

/*
Задача 2: Напишете функция, която приема цяло число и връща броя на единиците в двоичния му запис.
Вход: 189, Изход: 6
*/

int countBinaryOnes(int number) {
	
	int lastOneBitIndex = log2(number);
	int onesCount = 0;
	for (int i = 0; i <= lastOneBitIndex; i++)
	{
		onesCount += number >> i & 1;
	}

	return onesCount;
}

int main_07_02()
{
	int number = 0;
	scanf_s("%d", &number);

	int binaryOnesCount = countBinaryOnes(number);
	printf("Ones -> %d", binaryOnesCount);
	return 0;
}