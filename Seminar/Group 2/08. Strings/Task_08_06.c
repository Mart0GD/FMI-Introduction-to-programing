#include<stdio.h>
#include<stdlib.h>
#include "Functions.h"

/*
Задача 6: Да се напише функция, която приема низ и връща броя на думите в него (думите са разделени с произволен брой интервали, табулации и препинателни знаци). Валидна дума съдържа единствено букви, цифри и долна черта.
Вход: "Me? Why always me?", Изход: 4
*/

int isCharValid(char  chr) {
	return
		chr >= '0' && chr <= '9' ||
		chr >= 'a' && chr <= 'z' ||
		chr >= 'A' && chr <= 'Z' ||
		chr == '_';
}

int wordsCount(char* sentence) {
	int words = 0;

	int wordStarted = 0;
	while (*sentence != '\0'){
		if (!wordStarted && isCharValid(*sentence)){
			wordStarted = 1;
		}
		else if (wordStarted && !isCharValid(*sentence)) {
			wordStarted = 0;
			words++;
		}

		sentence++;
	}

	return words;
}

int main_08_06() {

	char* sentence = readText();

	int count = wordsCount(sentence);
	printf("The count of all words is --> %d", count);
	return 0;
}