#include<stdio.h>

/*
Задача 2. Като се използва подходът "разделяй и владей" да се дефинира рекурсивна функция, която намира сумата на елементите на редица от числа.
*/

int sumNumbers(const int numbers[], size_t left, size_t right) {
	if (left > right) return 0;
	if (left == right) return numbers[left];

	int middle = (left + right) / 2;
	int leftSum = sumNumbers(numbers, left, middle);
	int rightSum = sumNumbers(numbers, middle + 1, right);

	return leftSum + rightSum;
}

int sumNumbersWrapper(const int* numbers, size_t size) {
	return sumNumbers(numbers, 0, size - 1);
}


int main_09_03() {

	int numbers[9] = { 3, 87, 23, 112, 87, 21, 7, 89, 10 };
	int sum = sumNumbersWrapper(numbers, 9);
	printf("%d", sum);

	return 0;
}