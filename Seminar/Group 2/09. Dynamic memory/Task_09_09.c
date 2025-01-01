#include<stdio.h>
#include<stdlib.h>
#include "Functions2.h"

/*
Задача 9: Да се напише функция, която приема низ и връща нов низ, в който всяко число е увеличено с единица. Резултатният низ да е с точна дължина!
Вход: "It's 2024 and I am 19 years old."
Изход: "It's 2025 and I am 20 years old."

Вход: "After 99 comes 100."
Изход: "After 100 comes 101."
*/

int isCurrentCharANumber(const char chr) {
	return chr >= '0' && chr <= '9';
}

char* increaseNumber(char* number) {

	int intNumber = 0;
	while (*number != '\0'){
		intNumber *= 10;
		intNumber += *(number++) - '0';
	}

	intNumber++;
	int temp = intNumber;
	int len = 0;
	while (temp){
		temp /= 10;
		len++;
	}

	char* newChar = (char*)malloc(sizeof(char) * len);
	int currentDigit = 0;
	for (int i = len - 1; i >= 0; i--){
		currentDigit = intNumber % 10;
		intNumber /= 10;
		newChar[i] = currentDigit + '0';
	}
	newChar[len] = '\0';

	return newChar;
}

void replaceNumber(char** text, char* number, int startIndex, int endIndex) {
	int numLen = strlen(number);
	int whatLen = endIndex - startIndex;

	if (numLen > whatLen){

		int newLength = strlen(*text) + 1;
		 
		for (int i = newLength; i > startIndex; i--){
			(*text)[i] = (*text)[i - 1];
		}

		*text = realloc(*text, sizeof(char) * (newLength + 1));
		if (!text) return NULL;

		(*text)[newLength] = '\0';
		int iter = startIndex;
		while (iter < startIndex + numLen){
			(*text)[iter++] = *(number++);
		}
	}
	else {
		int iter = startIndex;
		while (iter < startIndex + numLen) {
			(*text)[iter++] = *(number++);
		}
	}
}

char* increaseNumbers(const char* text) {
	int textLen = strlen(text);
	char* newtext = strcpy(text, textLen);

	int iter = 0;

	int numberStarted = 0;
	int startIndex = 0;
	int endIndex = 0;
	while (*newtext != '\0'){

		if (!numberStarted && isCurrentCharANumber(*newtext)){
			numberStarted = 1;
			startIndex = iter;
		}
		else if (numberStarted && !isCurrentCharANumber(*newtext))
		{
			numberStarted = 0;
			endIndex = iter;

			newtext -= iter;
			char* newNumber = increaseNumber(strsubstr(newtext, startIndex, endIndex));
			replaceNumber(&newtext, newNumber, startIndex, endIndex);
			newtext += iter;
		}

		newtext++;iter++;
	}
	if (numberStarted){
		newtext -= iter;
		char* newNumber = increaseNumber(strsubstr(newtext, startIndex, iter));
		replaceNumber(&newtext, newNumber, startIndex, endIndex);
		newtext += iter;
	}

	return newtext - iter;
}

int main() {

	char* text = readText();
	char* newText = increaseNumbers(text);
	int newTextLen = strlen(newText);

	for (int i = 0; i < newTextLen; i++){
		printf("%c", newText[i]);
	}

	free(newText);
	free(text);
	return 0;
}