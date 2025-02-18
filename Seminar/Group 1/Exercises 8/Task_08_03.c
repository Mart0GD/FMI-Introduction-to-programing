#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#define WORDS_BUFFER 128
#define LETTERS_BUFFER 64
/*3.
Да се напише програма, която чете текст и извежда броя на еднобуквените, двубуквените и т.н. думи на текста. За разделители на думите служат знаците: ' ', ',', ';' и '.'. (интервал, запетая, точка и запетая и точка).
*/

void freeMatrix(char** matrix, size_t size) {
	for (size_t i = 0; i < size; i++){
		free(matrix[i]);
	}
	free(matrix);
}

int isSeparator(char chr) {
	return
		chr == ' ' ||
		chr == ',' ||
		chr == ';' ||
		chr == '.';
}

void getNextWord(char** text) {
	while (*(*text) && isSeparator(*(*text)))
		(*text)++;
}

char* extractWord(char** text) {
	char* word = (char*)malloc(LETTERS_BUFFER);
	if (!word) return NULL;

	int len = 0;
	while (*(*text) && !isSeparator(*(*text))){
		word[len++] = *((*text)++);
	}

	char* temp = (char*)realloc(word, len + 1);
	if(!temp) return word;
	word = temp;
	word[len] = '\0';

	return word;
}

void sortWords(char** words, size_t size) {

	char* temp = NULL;
	int swapped = 0;
	for (size_t i = 0; i < size; i++){
		swapped = 0;
		for (int j = 0; j < size - 1 - i; j++){
			if (strlen(words[j]) <= strlen(words[j + 1])) continue;

			temp = words[j];
			words[j] = words[j + 1];
			words[j + 1] = temp;
		}
	}
}

void printWordsCount(char* text) {
	char** words = (char**)malloc(sizeof(char*) * WORDS_BUFFER);
	if (!words) return;

	for (size_t i = 0; i < WORDS_BUFFER; i++) {
		words[i] = (char*)malloc(LETTERS_BUFFER);
		if (!words[i]) {
			freeMatrix(words, i);
		}
	}

	size_t wordsCount = 0;
	while ((getNextWord(&text), *text)) {
		words[wordsCount++] = extractWord(&text);
	}

	sortWords(words, wordsCount);

	int currentLen = 0;
	int currentWordsCount = 0;
	for (size_t i = 0; i < wordsCount; i++)
	{
		currentLen = strlen(words[i]);
		currentWordsCount = 1;
		printf("%d letters --> ", currentLen);
		while (strlen(words[i + 1]) == currentLen){
			currentWordsCount++;
			i++;
		}
		printf("%d\n", currentWordsCount);
	}

	freeMatrix(words, WORDS_BUFFER);
}

int main_08_03() {

	char* text = readText();
	printWordsCount(text);

	return 0;
}