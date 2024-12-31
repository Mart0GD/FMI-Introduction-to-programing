#include<stdlib.h>
#include<stdlib.h>
#include "Functions.h"

/*
Задача 4: Да се напише функция, която приема два символни низа и връща дали вторият е подниз на първия.
Вход: "nightlife"   "night", Изход: yes
Вход: "storm"   "thunderstorm", Изход: no
*/


int isStrInfix(char* word, char* potentialInfix) {
	unsigned wordLen = strlen(word);
	unsigned infixLen = strlen(potentialInfix);

	if (wordLen < infixLen) return 0;

	char* wordCopy = strcpy(word, wordLen);
	char* infixCopy = strcpy(potentialInfix, infixLen);

	int isInfix = 1;
	int chaged = 1;
	while (wordLen >= infixLen){
		if (*infixCopy == '\0') return 1;

		if (*wordCopy == *infixCopy){
			infixCopy++; wordCopy++;
			infixLen--; wordLen--;
			chaged = 1;

			continue;
		}
		else if(chaged){
			infixCopy = strcpy(potentialInfix, infixLen);
			infixLen = strlen(potentialInfix);
			chaged = 0;
		}

		wordCopy++;wordLen--;
	}

	return isInfix;
}

int main_08_04() {

	printf("Insert a word: ");
	char* str = readText();

	printf("Insert potential subword: ");
	char* potentialInfix = readText();

	
	isStrInfix(str, potentialInfix)
		? printf("yes")
		: printf("no");

	return 0;
}