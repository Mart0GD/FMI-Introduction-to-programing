#include<stdio.h>
#include<stdlib.h>
#include "Functions2.h"

/*
Задача 7: Да се напише функция, която приема низ и "патърн" и връща нов низ, в който всяко число е цензурирано с подадения "патърн". Резултатният низ да е с точна дължина!
Вход: "test124again4pocket55p"     "NUM",
Изход: "test_NUM_again_NUM_pocket_NUM_p"
*/

int isCharNumber(const char chr) {
	return chr >= '0' && chr <= '9';
}

void replaceWithPattern(char** text , const unsigned whatStartIndex, const unsigned whatEndIndex, const char* with, int* curIter) {
	
	int textLen = strlen(*text);
	int whatLen = whatEndIndex - whatStartIndex;
	int withLen = strlen(with);

	int diff = whatLen - withLen > 0 ? whatLen - withLen : -(whatLen - withLen);
	
	if (whatLen < withLen){
		int newLen = textLen + diff;
		*text = (char*)realloc(*text, sizeof(char) * (newLen + 1));
		if (!(*text)) return NULL;
		(*text)[newLen] = '\0';

		for (int i = newLen; i > whatStartIndex; i--){
			(*text)[i] = (*text)[i - diff];
		}

		int iter = whatStartIndex;
		while (iter < whatStartIndex + withLen) {
			(*text)[iter++] = *(with++);
		}
	}
	else if (whatLen > withLen) {
		int newLen = textLen - diff;

		for (int i = whatStartIndex + withLen; i < textLen; i++){
			(*text)[i] = (*text)[i + diff];
		}

		*text = (char*)realloc(*text, sizeof(char) * (newLen + 1));
		if (!(*text)) return NULL;
		(*text)[newLen] = '\0';

		int iter = whatStartIndex;
		while (iter < whatStartIndex + withLen) {
			(*text)[iter++] = *(with++);
		}
		*curIter -= diff;
	}
	else {
		int iter = whatStartIndex;
		while (iter < whatStartIndex + withLen){
			(*text)[iter++] = *(with++);
		}
	}
}

char* censor(const char* text, const char* pattern) {
	char* censored = strcpy(text, strlen(text));

	int numberStarted = 0;
	int startIndex = 0;
	int endIndex = 0;
	int iter = 0;
	while (*censored != '\0'){

		if (!numberStarted && isCharNumber(*censored)){
			numberStarted = 1;
			startIndex = iter;
		}
		else if ((numberStarted && !isCharNumber(*censored))) {
			numberStarted = 0;
			endIndex = iter;

			censored -= iter;
			replaceWithPattern(&censored, startIndex, endIndex, pattern, &iter);
			censored += iter;
			endIndex = 0;
			continue;
		}

		iter++; censored++;
	}
	if (startIndex > 0 && endIndex == 0) {
		censored -= iter;
		replaceWithPattern(&censored, startIndex, iter, pattern, &iter);
		censored += iter;
	}

	return censored - iter;
}

void printText(const char* text) {
	while (*text != '\0'){
		printf("%c", *(text++));
	}
}

int main_09_07() {
	char* text = readText();
	char* pattern = readText();

	char* censored = censor(text, pattern);
	printText(censored);

	free(text);
	free(pattern);
	free(censored);
	return 0;
}