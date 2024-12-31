#include<stdio.h>
#include<math.h>
#define SIGNED_INT_SIZE 32

/*
������ 4: �������� �������, ����� �� �������� ���� ����� n � k ����� �������, ����� � "����������" � ���������� k ���� �� n.
����: 15 2, �����: 3 // 1111
����: 189 3, �����: 5 // 10111101 -> 101
����: 189 4, �����: 13 // 1101
*/

int findEncodedNumber(int number, int codeLength) {

	int encodedNumberArr[SIGNED_INT_SIZE] = { 0 };
	int lastOneBit = log2(number);

	if (lastOneBit < codeLength){
		puts("Invalid input!");
		return -1;
	}

	int codeEnd = (lastOneBit - codeLength) + 1;
	int encodingIndex = 0;
	for (int i = lastOneBit; i >= codeEnd; i--)
	{
		encodedNumberArr[encodingIndex] = number >> i & 1;
		encodingIndex++;
	}

	int encodedNumber = 0;
	for (int i = 0; i < codeLength; i++)
	{
		encodedNumber += encodedNumberArr[i] * pow(2, i);
	}

	return encodedNumber;
}

int main_07_04()
{
	int number, codeLength;
	scanf_s("%d %d", &number, &codeLength);

	printf("%d", findEncodedNumber(number, codeLength));
	return 0;
}