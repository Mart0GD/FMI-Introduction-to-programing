#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#pragma warning(disable: 4996)
/*
2. Да се дефинират следните функции за работа със символни низове:
а) int stringCompareNotSensitive(const char* first, const char* second), която сравнява лексикографски два символни низа, като не различава малки и главни латински букви. Функцията да връща 0, ако символните низове съвпадат без да се различават малки и главни букви, отрицателно цяло число, ако първият низ е по-малък от втория и положително цяло число, ако първият низ е по-голям от втория;
б) void trimLeft(char* text, const char* tokens), която изтрива от низа text всички символи – разделители пред първия символ, който не е разделител. Разделителите се задават чрез низа tokens;
в) void trimRight(char* text, const char* tokens), която изтрива от низа text всички символи – разделители след последния символ, който не е разделител. Разделителите се задават чрез низа tokens;
г) void trim(char* text, const char* tokens), която изтрива от низа text всички символи – разделители пред първия символ, който не е разделител и след последния символ, който не е разделител. Разделителите се задават чрез низа tokens;
д) void removeToken(char* text, const char* tokens), която изтрива всички символи – разделители от низа text. Разделителите се задават чрез низа tokens;
е) void toUpper(char* text), която заменя всички малки букви от низа text със съответните главни. Работим само с латински букви;
ж) void toLower(char* text), която заменя всички главни букви от низа text със съответните малки. Работим само с латински букви.
*/

int contains(char symb, const char* tokens) {
	while (*tokens){
		if (symb == *tokens) return 1;
		tokens++;
	}

	return 0;
}

int stringCompareNotSensitive(const char* str1, const char* str2) {

	if (!str1 || !str2) {
		puts("Null pointer detected!");
		exit(-1);
	}

	int diff = 'a' - 'A';
	char currentStr1Letter = ' ';
	char currentStr2Letter = ' ';
	while(*str1 && *str2) {
		currentStr1Letter = *str1 >= 'A' && *str1 <= 'Z' ? *str1 + diff : *str1;
		currentStr2Letter = *str2 >= 'A' && *str2 <= 'Z' ? *str2 + diff : *str2;

		if (currentStr1Letter != currentStr2Letter) break;
		str1++;str2++;
	}

	return currentStr1Letter - currentStr2Letter;
}

void trimLeft(char* text, const char* tokens) {

	size_t cnt = 0;
	for (int i = 0; contains(text[i], tokens); i++)
		cnt++;

	int len = strlen(text);
	for (int i = 0; i < len - cnt; i++) {
		text[i] = text[i + cnt];
	}
	text[len - cnt] = '\0';
}

void trimRight(char* text, const char* tokens) {
	if (!text) {
		puts("Null pointer");
		return;
	}

	int len = strlen(text);
	size_t cnt = 0;
	for (int i = len - 1; contains(text[i], tokens); i--)
		cnt++;
	text[len - cnt] = '\0';
}

void trim(char* text, const char* tokens) {
	trimLeft(text, tokens);
	trimRight(text, tokens);
}

void removeToken(char* text, const char* tokens) {
	size_t tokensLen = strlen(tokens);

	while (*text){
		trimLeft(text, tokens);
		text++;
	}
}

void toLower(char* str) {
	int diff = 'a' - 'A';

	while (*str) {
		if (*str >= 'A' && *str <= 'Z') *str += diff;
		str++;
	}
}

void toUpper(char* str) {
	int diff = 'a' - 'A';

	while (*str) {
		if (*str >= 'a' && *str <= 'z') *str -= diff;
		str++;
	}
}

int main_02() {
	char* str1 = readText();
	char* str2 = readText();
	char* str3 = readText();
	char* str4 = readText();

	char tokens[] = ", ";
	printf("string compared non sensitive --> %d", stringCompareNotSensitive(str1, str2));
	trimLeft(str1, tokens);
	trimRight(str2, tokens);
	trim(str3, tokens);
	removeToken(str4, tokens);


	free(str1);
	free(str2);
	free(str3);
	free(str4);
	return 0;
}