
#include "helper.h"
/*
Задача 8: Да се напише рекурсивна функция, която връща дължината на най- дългата последователност от еднакви символи в низ.
Вход: aaabbbbcdeddddedeee, Изход: 4
*/

int getLongestSubstring(char* str, int count, int longestCount) {
	if (!*str) return longestCount;
	if (*str != *(str - 1)) count = 1;
	else count++;

	return getLongestSubstring(str + 1, count, longestCount < count ? count : longestCount);

}

int getLongestSubstringWrapper(char* str) {
	return getLongestSubstring(str, 0, 0);
}

int main_S_08() {
	char* str = readText();

	int longestSubstring = getLongestSubstringWrapper(str);
	printf("%d", longestSubstring);
}