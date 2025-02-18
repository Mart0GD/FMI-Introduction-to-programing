#include<stdlib.h>
#include "helper.h"
/*
������ 6: �� �� ������ ���������� �������, ����� ������ ��� � ����� ���� ����� � ���������.
����: abcdcba, �����: true
����: abbab, �����: false
*/

int isPalindromeRec(char* str, int left, int right) {
	if (left >= right) return 1;
	if (str[left] != str[right]) return 0;

	return isPalindromeRec(str, left + 1, right - 1);
}

int isPalindromeWrapper(char* str) {
	return isPalindromeRec(str, 0, strlen(str) - 1);
}

int main_S_06() {

	char* str = readText();

	int palindrome = isPalindromeWrapper(str);
	printf("%d", palindrome);
	return 0;
}