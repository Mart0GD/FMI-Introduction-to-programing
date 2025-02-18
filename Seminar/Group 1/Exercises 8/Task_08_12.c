#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#pragma warning(disable: 4996)
/*
Напишете функция, която получава като аргумент низ и обръща всички думи (и само тях) в него. Дума е последователност от латински букви. Ако започва с главна буква и не е само с главни букви, то обърнатата дума да започва с главна буква.
The quick brown Fox jumps OVER the lazy-dog!
Eht kciuq nworb Xof spmuj REVO eht yzal-god!

*/

int isWord(const char chr) {
	return (chr >= 'a' && chr <= 'z') 
		|| (chr >= 'A' && chr <= 'Z');
}

char* getNextWordWord(const char** text) {
	char* word = (char*)malloc(strlen(*text) + 1);
	if (!word) return word;

	int iter = 0;
	while (*(*text) && isWord(*(*text))){
		word[iter++] = *(*text);
		(*text)++;
	}
	word[iter] = '\0';

	return word;
}

void reverseWithCapital(char* word) {
	size_t len = strlen(word);

	int steps = len / 2;
	char temp = ' ';
	for (int i = 0; i < steps; i++){
		if (i == 0 && word[i] >= 'A' && word[i] <= 'Z' && word[len - i - 1] >= 'a' && word[len - i - 1] <= 'z') {
			temp = word[i] + 32;
			word[i] = word[len - i - 1] - 32;
			word[len - i - 1] = temp;
			continue;
		}
		temp = word[i];
		word[i] = word[len - i - 1];
		word[len - i - 1] = temp;
	}
}

char* reverseOnlyWords(const char* text) {
	char* reversed = (char*)malloc(strlen(text) + 1);
	if (!reversed) return reversed;

	char* word = NULL;
	int iter = 0;
	while (*text)	{
		if (!isWord(*text)) reversed[iter++] = *(text++);
		else {
			word = getNextWordWord(&text);
			reverseWithCapital(word);
			strcpy(reversed + iter, word);
			iter += strlen(word);

			free(word);
		}
	}

	char* temp = realloc(reversed, iter + 1);
	if (!temp) return reversed;
	reversed = temp;
	reversed[iter] = '\0';

	return reversed;
}

int main_08_12() {

	char* word = readText();
	if (!word) return -1;

	char* reversed = reverseOnlyWords(word);
	printf(reversed);


	return 0;
}