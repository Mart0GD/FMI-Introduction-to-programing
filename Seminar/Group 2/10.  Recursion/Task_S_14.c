#include "helper.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable: 4996)
/*
Да се напише рекурсивна функция, която извежда всички възможни стрингове с дължина k, които могат да се получат от дадено множество от n символа.
*/

void printRec(const char* str, char* bitstring, int index, int len, int k) {
	
	if (k == 0) {
		bitstring[index] = '\0';
		printf("%s\n", bitstring);
		return;
	}

	for (int i = 0; i < len; i++){
		bitstring[index] = str[i];
		printRec(str, bitstring, index + 1, len, k - 1);
	}
}

void printAllPossibleStrings(const char* str, int k) {
	char* string = (char*)malloc((k + 1) * sizeof(int));
	if (!string) return;

	printRec(str, string, 0, strlen(str), k);
}

int main_S_14() {

	int k = 0;
	scanf("%d", &k);
	getchar();

	char* string = readText();

	printAllPossibleStrings(string, k);
	return 0;
}