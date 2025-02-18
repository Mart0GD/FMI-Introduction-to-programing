#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
Напишете следните функции:

• Функция, която проверява дали двоичният запис на едно цяло число е палиндром (чете се еднакво отляво-надясно и отдясно-наляво). В този случай не разглеждаме водещи нули. Пример за такива палиндроми са числата 3 (двоичен запис 11), 5 (с двоичен запис 101), 27 (11011), докато числата 10 (1010) и 53 (110101) не са палиндроми.

• Функция, която получава като аргумент масив от цели числа и премахва от него всички, за които двоичният им запис не е палиндром.

Реализирайте кратка програма, която въвежда от потребителя размер на масив, заделя необходимото количество памет и прочита елементите му. След това прилага горната функция за да остави в него само палиндромните числа и извежда получения резултат на екрана.

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