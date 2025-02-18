#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Да се напише рекурсивна функция, която извежда всички възможни стрингове с дължина k, които могат да се получат от дадено множество от n символа.
*/

void variate(const char* str, char* bitstring, int index, int k, int strLen) {
	if (k == 0){
		bitstring[index] = '\0';
		printf(bitstring);
		puts(" ");
		return;
	}

	for (int i = 0; i < strLen; i++){
		bitstring[index] = str[i];
		variate(str, bitstring, index + 1, k - 1, strLen);
	}
}

void printVariations(const char* str, int k) {
	char* bitstring = (char*)malloc((k + 1) * sizeof(char));
	if (!bitstring) return;

	variate(str, bitstring, 0, k, strlen(str));
}

int main_Variations() {

	char str[4] = {'a', 'b', 'c', '\0'};
	int k = 2;

	printVariations(str, k);
	return 0;
}