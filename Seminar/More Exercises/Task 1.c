#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
�������� �������� �������:

� �������, ����� ��������� ���� ��������� ����� �� ���� ���� ����� � ��������� (���� �� ������� ������-������� � �������-������). � ���� ������ �� ����������� ������ ����. ������ �� ������ ���������� �� ������� 3 (������� ����� 11), 5 (� ������� ����� 101), 27 (11011), ������ ������� 10 (1010) � 53 (110101) �� �� ����������.

� �������, ����� �������� ���� �������� ����� �� ���� ����� � �������� �� ���� ������, �� ����� ��������� �� ����� �� � ���������.

������������ ������ ��������, ����� ������� �� ����������� ������ �� �����, ������ ������������ ���������� ����� � ������� ���������� ��. ���� ���� ������� ������� ������� �� �� ������ � ���� ���� ������������� ����� � ������� ��������� �������� �� ������.

*/

int isBinaryPalindrome(int number) {
	int size = log2(number) + 1;

	int* binaryRep = (int*)malloc(sizeof(int) * size);
	if (!binaryRep) return 0;

	for (int i = 0; i < size; i++){
		binaryRep[i] = (number >> i) & 1;
	}

	int steps = size / 2;
	for (size_t i = 0; i < steps; i++){
		if (binaryRep[i] != binaryRep[size - 1 - i]) {
			free(binaryRep);
			return 0;
		}
	}

	free(binaryRep);
	return 1;
}

int deleteNonBinaryPalindromes(int* arr, int* size) {

	for (int i = 0; i < *(size); i++){

		if (!isBinaryPalindrome(arr[i])){
			for (int j = i; j < *(size) - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			(*size)--;
			i--;
		}
	}
	return 0;
}

int main_E_01() {

	int size = 0;
	scanf_s("%d", &size);

	int* arr = (int*)malloc(size * sizeof(int));
	if (!arr) return -1;
	
	for (int i = 0; i < size; i++){
		scanf_s("%d", &arr[i]);
	}

	deleteNonBinaryPalindromes(arr, &size);

	for (size_t i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}