#include<stdio.h>
#include<stdlib.h>
#include "helpers.h"

#pragma warning(disable: 4996)
/*
6. Да се дефинират следните три функции:
а) char* replaceFirst(char* text, const char* findWhat, const char* replaceWith)
б) char* replaceLast(char* text, const char* findWhat, const char* replaceWith)
в) char* replaceAll(char* text, const char* findWhat, const char* replaceWith)
Първата заменя първото срещане на findWhat в низа text с низа replaceWith; врората заменя последното срещане на същия низ, а последната заменя всяко срещане.
*/

char* substring(const char* text, size_t startIndex, size_t endIndex) {
	if (startIndex > endIndex || !text) return NULL;

	char* substr = (char*)malloc(endIndex - startIndex + 1);
	if (!substr) return substr;

	int iter = 0;
	for (int i = startIndex; i < endIndex; i++){
		substr[iter++] = text[i];
	}
	substr[iter] = '\0';

	return substr;
}

char* replace(char* text, size_t index, char* what, char* with) {
	if (!text || !what || !with) return NULL;

	size_t textLen = strlen(text);
	size_t withLen = strlen(with);
	size_t whatLen = strlen(what);
	size_t diff = whatLen - withLen; 

	char* newText = (char*)malloc(textLen - diff + 1);
	if (!newText) return newText;

	char* temp = substring(text, 0, index);
	if (!temp) {
		free(newText);
		return NULL;
	}

	strcpy(newText, temp);
	free(temp);
	
	strcpy(newText + index, with);

	temp = substring(text, index + whatLen, textLen);
	if (!temp) {
		free(newText);
		return NULL;
	}

	strcpy(newText + index + withLen, temp);
	free(temp);

	newText[textLen - diff] = '\0';
	return newText;
}

char* replaceFirst(char* text, const char* what, const char* with) {
	if (!text || !what || !with) {
		puts("Null pointer detected!");
		return NULL;
	}

	char* pos = strstr(text, what);
	if (!pos) {
		printf("text doesn't contain %s\n", what);
		return NULL;
	}

	size_t index = pos - text;
	char* newText = replace(text, index, what, with);

	return newText;
}

char* replaceLast(char* text, const char* what, const char* with) {
	if (!text || !what || !with) {
		puts("Null pointer detected!");
		return NULL;
	}

	char* pos = NULL;
	size_t whatLen = strlen(what);
	size_t index = -1;
	while ((pos = strstr(text + (index + whatLen), what)) != NULL) {
		index = pos - text;
	}
	
	if (index == -1) {
		printf("text doesn't contain %s\n", what);
		return NULL;
	}

	char* newText = replace(text, index, what, with);
	if (!newText) return NULL;

	return newText;
}

char* replaceAll(char* text, const char* what, const char* with) {

	char* res = NULL;
	size_t withLen = strlen(with);
	size_t whatLen = strlen(what);
	size_t textLen = strlen(text);
	size_t estLen = 0;

	if (withLen < whatLen){
		estLen = textLen;
	}
	else {
		estLen = (textLen / whatLen + 1) * withLen;
	}

	res = malloc(estLen + 1);
	if (!res) return res;
	
	size_t pos = 0;
	char* origin = text;
	for (char* match; match = strstr(text, what); text = match + whatLen) {
		strncpy(res + pos, text, match - text);
		pos += match - text;
		strncpy(res + pos, with, withLen);
		pos += withLen;
	}

	strcpy(res + pos, text);
	text = origin;

	return res;
}

int main_08_06() {
	char* str = readText();

	char* newStr1 = replaceFirst(str, "him", "her");
	char* newStr2 = replaceLast(str, "hi", "gay");
	char* newStr3 = replaceAll(str, "gay", "i");

	free(str);
	if(newStr1) free(newStr1);
	if (newStr2) free(newStr2);
	if (newStr3) free(newStr3);
}