#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER 1024

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

static char* readText() {
	char* text = (char*)malloc(BUFFER);
	if (!text)
		return text;

	int buffer = BUFFER;
	int symb;
	int iter = 0;
	while ((symb = getc(stdin)) != EOF && symb != '\n') {
		if (iter < buffer)text[iter++] = symb;
		else {
			char* temp = (char*)realloc(text, (buffer * 2));
			if (!temp) return text;
			text = temp;
			buffer *= 2;
			text[iter++] = symb;
		}
	}
	char* temp = (char*)realloc(text, iter + 1);
	if (!temp) return text;

	text = temp;
	text[iter] = '\0';
	return text;
}


#endif