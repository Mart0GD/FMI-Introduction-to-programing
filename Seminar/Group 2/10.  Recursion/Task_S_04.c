#include<stdio.h>

#pragma warning(disable: 4996)

/*
������ 4 (������� �������): �� �� ������ ���������� �������, ����� ������ ���������� ����� �� ����� � ����� n � ����� ���� n �� ������� � ������.
����: 6 12 33 16 8     16, �����: true
����: 6 12 33 16 8     5, �����: false
*/

liniarSearch(const int arr[], int n, size_t len) {
	if (len == 0) return arr[len] == n;
	if (arr[len] == n) return 1;

	return liniarSearch(arr, n, len - 1);
}

int main_S_04() {
	int n;
	scanf("%d", &n);

	int numbers[8] = { 12, 1323, 43, 9, 2, 872, 23, 10 };

	int includes = liniarSearch(numbers, n, 8);
}