#include<stdio.h>
#include<Stdlib.h>
#include "helpers.h"

#pragma warning(disable: 4996)
#define BUFFER 1024


size_t findCommonPrefixLen(const char* str1, const char* str2) {

	size_t len = 0;
	while (*str1 != '\n' && str2 != '\n' && (*str1 == *str2)){
		str1++;str2++;
		len++;
	}

	return len;
}

/*1. Да се дефинира функция, която намира дължината на най-дългия общ префикс на два символни низа.*/
int main_01() {

	char* str1 = readText();
	char* str2 = readText();

	size_t longestCommonPrefixLen = findCommonPrefixLen(str1, str2);
	printf("%d", longestCommonPrefixLen);


	free(str1);
	free(str2);
	return 0;
}