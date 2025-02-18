#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#pragma warning(disable: 4996)

/*
5. Да се дефинира функция char* reverseWordsOnly(const char*), която получава като параметър символен низ и връща символен низ, получен от дадения, но отделните думи (и само те) са обърнати. Думите са произволни редици от символи. За разделители служат ' ', ', ', ';' и '.'
*/

int isValid(const char chr) {
	return
		chr != ' ' &&
		chr != ',' &&
		chr != ';' &&
		chr != '.';
}

char* getWord(char** sentence) {
	char* word = (char*)malloc(strlen(*sentence) + 1);
	if (!word) return NULL;

	int iter = 0;
	while (*(*sentence) && isValid(*(*sentence))){
		word[iter++] = *(*sentence);
		(*sentence)++;
	}

	char* temp = (char*)realloc(word, iter + 1);
	if (!temp) return word;

	word = temp;
	word[iter] = '\0';

	return word;
}

void reverse(char* word) {
	size_t len = strlen(word);
	int moves = len / 2;

	char temp = ' ';
	for (int i = 0; i < moves; i++){
		temp = word[i];
		word[i] = word[len - 1 - i];
		word[len - 1 - i] = temp;
	}
}

char* reverseWordsOnly(const char* sentence) {
	char* reversed = malloc(strlen(sentence) + 1);

	int iter = 0;
	char* word = NULL;
	while (*sentence){
		if (!isValid(*sentence)) reversed[iter++] = *(sentence++);
		else {
			word = getWord(&sentence);
			reverse(word);

			strcpy(reversed + iter, word);
			iter += strlen(word);
			free(word);
		}
	}
	reversed[iter] = '\0';

	return reversed;
}

int main_08_05() {

	char* sentence = readText();

	char* reversed = reverseWordsOnly(sentence);
	if(reversed) printf(reversed);

	free(reversed);
	free(sentence);
	return 0;
}