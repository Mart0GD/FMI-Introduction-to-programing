#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#pragma warning(disable: 4996)

/*
Напишете програма, която прочита "компресиран" низ и извежда декомпресираната му версия. Ако низът не е записан коректно трябва да съобщите това.

Компресираният низ съдържа 4 вида конструкции:
- Символи (всякакви символи, различни от двойна кавичка, скоби, цифри и наклонена черта ‘\’)
- Екранирани символи - наклонена черта, следвана от произволен символ. Така в компресираният низ може да се сложат специални символи. Например: o\ks->oks.
- Групи, които започват с число последвано от скоби, съдържащи компресиран низ. Декомпресират се като се декомпресира низа в скобите и се повтори толкова пъти колкото е числото.
- Стрингове - последователност от произволни символи, оградени с двойни кавички - пренася се в декомпресираната версия непроменена, но без кавичките. В тази последователност се допускат екранирани кавички.

Примери:
AABC -> AABC
А\\BC -> A\BC
R2(AB)3(Z) -> RABABZZZ
A"3(Zs)"3(Zs)-> A3(Zs)ZsZsZs
R2(A\2B)3(Z) -> RA2BA2BZZZ
AB12(X)2(B3(A)) -> ABXXXXXXXXXXXXBAAABAAA
AB12(X)2(B3(A"2'1")) -> ABXXXXXXXXXXXXBA2'1A2'1A2'1BA2'1A2'1A2'1
A"\"BC" -> A\"BC
*/

int isNumber(const char chr) {
	return chr >= '0' && chr <= '9';
}

char* extractLoopableString(char* text) {
	char* str = (char*)malloc(strlen(text) + 1);
	if (!str) return NULL;

	int iter = 0;
	int nested = 0;
	while (*text) {
		if (*text == ')' && nested == 0) break;
		if (*text == '(') nested++;
		else if (nested && *text == ')') nested--;

		str[iter++] = *(text++);
	}

	char* temp = (char*)realloc(str, iter + 1);
	if (!temp) return str;
	str = temp;
	str[iter] = '\0';

	return str;
}

char* extractDirectString(char* text) {
	char* str = (char*)malloc(strlen(text) + 1);
	if (!str) return NULL;

	int iter = 0;
	int nested = 0;
	while (*text && *text != '"') {
		if (*text == '\\') { str[iter++] = *(text++); }
		str[iter++] = *(text++);
	}

	char* temp = (char*)realloc(str, iter + 1);
	if (!temp) return str;
	str = temp;
	str[iter] = '\0';

	return str;
}

void reallocate(char** text, size_t* buffer){
	char* temp = (char*)realloc(*text, *buffer * 2);
	if (!temp) return *text;
	*text = temp;
	*buffer *= 2;
}

char* decompress(char* text) {
	int buffer = 128;
	char* decompressedText = (char*)malloc(buffer);
	if (!decompressedText) return decompressedText;

	int iter = 0;
	while (*text){

		if (*text == '\\') {
			text++;
			decompressedText[iter++] = *(text++);
		}
		else if (isNumber(*text)) {
			int number = 0;
			while (isNumber(*text)) {
				number *= 10;
				number += *text - '0';
				text++;
			}

			char* loopabeleString = extractLoopableString(++text);
			char* newstr = decompress(loopabeleString);
			for (size_t i = 0; i < number; i++) {
				if (iter + strlen(newstr) >= buffer) reallocate(&decompressedText, &buffer);

				strcpy(decompressedText + iter, newstr);
				iter += strlen(newstr);
			}
			text += strlen(loopabeleString) + 1;
			free(loopabeleString);
			free(newstr);
		}
		else if (*text == '"') {
			char* directPlacementString = extractDirectString(++text);

			if (iter + strlen(directPlacementString) >= buffer) reallocate(&decompressedText, &buffer);
			strcpy(decompressedText + iter, directPlacementString);

			iter += strlen(directPlacementString);
			text += strlen(directPlacementString) + 1;
		}
		else decompressedText[iter++] = *(text++);

		if (iter + 1 == buffer) reallocate(&decompressedText, &buffer);
	}

	char* temp = (char*)realloc(decompressedText, iter + 1);
	if (!temp) return decompressedText;
	decompressedText[iter] = '\0';

	return decompressedText;
}

int main() {

	char* text = readText();

	char* decompressed = decompress(text);
	printf("decompressed --> %s", decompressed);

	free(text);
	free(decompressed);
	return 0;
}