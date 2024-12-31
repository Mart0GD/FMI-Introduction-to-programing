#include<stdio.h>

/*
Задача 3: Напишете функция, която приема цяло число и обръща най-десния бит в него, който е единица.
Вход: 12, Изход: 8 //  1100 -> 1000
Вход: 15, Изход: 14 // 1111 -> 1110
*/

int findMostRightIndexInBinaryRepresentation(int* number) {
	const int SIGNED_INT_SIZE = (sizeof(int) * 8);

	for (int i = 0; i < SIGNED_INT_SIZE; i++){
		if (*number >> i & 1)
			return i;
	}
}

void flipMostRightBit(int* number) {

	int mostRightBitIndex = findMostRightIndexInBinaryRepresentation(number);
	*number = *number ^ (1 << mostRightBitIndex);
}

int main_07_03() {
	int number = 0;
	scanf_s("%d", &number);

	flipMostRightBit(&number);
	printf("%d", number);
	return 0;
}