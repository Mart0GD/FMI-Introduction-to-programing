#include<stdlib.h>
#include "helper.h"
/*
Задача 6: Да се напише рекурсивна функция, която приема низ и връща дали низът е палиндром.
Вход: abcdcba, Изход: true
Вход: abbab, Изход: false
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