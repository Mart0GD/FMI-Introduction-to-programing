#include<limits.h>

/*
Задача 3: Да се напише рекурсивна функция, която приема масив от числа и връща най- малкия му елемент.
Вход: 40 12 33 16 8, Изход: 8
*/

int minRecTail(const int arr[], size_t len, int min) {
	if (len == 0) return arr[len] < min ? arr[len] : min;

	return minRecTail(arr, len - 1, min > arr[len] ? arr[len] : min);
}

int minRec(const int arr[], size_t len) {
	return minRecTail(arr, len - 1,INT_MAX);
}

int main_S_03() {
	int numbers[6] = { 666, 54, 87, 3, 23, 76 };

	int min = minRec(numbers, 6);

	return 0;
}