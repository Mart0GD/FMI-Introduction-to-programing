#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"
/*
Напишете програма, която преброява изреченията в текст. Изречение започва с главна буква и завършва с '.', '!', '?' или '...'. Трябва да има поне 3 букви в него ("А." не е изречение).
*/

int isSentenceEnd(const char chr) {
	return
		chr == '.' ||
		chr == '!' ||
		chr == '?' ||
		chr == '...';
}

size_t countSentences(const char* text) {
	size_t count = 0;

	int lettersCount = 0;
	int sentenceStarted = 0;
	while (*text){
		if (!sentenceStarted && *text >= 'A' && *text <= 'Z') {
			sentenceStarted = 1;
			lettersCount = 1;
		}
		else if (sentenceStarted && isSentenceEnd(*text)) {
			if (lettersCount >= 3) count++;

			sentenceStarted = 0;
			lettersCount = 0;
		}
		else lettersCount++;

		text++;
	}

	return count;
}

int main_08_08(){

	char* text = readText();
	size_t sentencesCount = countSentences(text);
	printf("count of sentences --> %d", sentencesCount);
	return 0;
}

