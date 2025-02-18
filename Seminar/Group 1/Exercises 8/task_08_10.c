#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#pragma warning(disable: 4996)
/*
Напишете програма, която в прочетен низ намира най-дългия под-низ, който е палиндром
*/

int isPalindrome(const char* str) {
	size_t len = strlen(str);
	int isPalindrome = 1;
	int steps =  len / 2;

	for (int i = 0; i < steps; i++){
		if (str[i] != str[len - 1 - i]) return 0;
	}

	return 1;
}

char* findLongestPalindrome(const char* text) {
	size_t len = strlen(text);
	char* wordHolder = NULL;

	char* longestPalindrome = (char*)malloc(len + 1);
	if (!longestPalindrome) return NULL;
	longestPalindrome[0] = '\0';

	int iter;
	for (int i = 0; i < len; i++){
		if (longestPalindrome && strlen(longestPalindrome) >= len - i) break;

		wordHolder = (char*)malloc(len + 1);
		if (!wordHolder) return longestPalindrome;

		iter = 0;
		for (int j = i; j < len; j++){
			wordHolder[iter++] = text[j];
			wordHolder[iter] = '\0';

			if (j - i >= 2 && isPalindrome(wordHolder) && strlen(wordHolder) > strlen(longestPalindrome)) { strcpy(longestPalindrome, wordHolder); }
		}
		free(wordHolder);
	}

	return longestPalindrome;
}

int main_08_10() {

	char* text = readText();

	char* longestPalindrome = findLongestPalindrome(text);
	printf(longestPalindrome);


	free(text);
	free(longestPalindrome);
	return 0;
}