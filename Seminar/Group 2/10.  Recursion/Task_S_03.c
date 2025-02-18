#include<limits.h>

/*
������ 3: �� �� ������ ���������� �������, ����� ������ ����� �� ����� � ����� ���- ������ �� �������.
����: 40 12 33 16 8, �����: 8
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