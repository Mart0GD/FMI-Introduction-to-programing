#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#pragma warning(push)
#pragma warning(disable: 4996)

#define MEMORY_SIZE 1024
#define COMMANDS_CAP 1024

int readInput(unsigned char* memory) {

	char currentCommand = ' ';
	int scanResult = 0;
	int iter = 0;
	while (currentCommand != 'x')
	{
		if (iter > COMMANDS_CAP - 1)
			return -1;

		scanResult = scanf("%c", &currentCommand);
		if (scanResult != 1){
			puts("Invalid input, please input a valid character!");
			continue;
		}

		*(memory++) = currentCommand;
		iter++;
	}

	return iter;
}

int readChar(unsigned char* memory) {
	while (getchar() != '\n');

	puts("Please insert char to save into memory: ");
	return scanf("%c", memory);
}

int interpretCommands(const unsigned char* commands, unsigned char* memory, char* text) {
		
	unsigned char* firstCellPrt = memory;
	unsigned char* lastCellPtr = memory + (MEMORY_SIZE - 1);
	int currentTextIndex = 0;

	while (*commands != 'x')
	{
		switch (*commands)
		{
			case '+': 
				*memory += 1;
				break;

			case '-':
				*memory -= 1;
				break;

			case '>':
				if (memory < lastCellPtr) memory++;
				else memory = firstCellPrt;

				break;

			case '<':
				if (memory > firstCellPrt) memory--;
				else memory = lastCellPtr;

				break;

			case '.':
				if (!isPrintable(*memory)) { break; }
				text[currentTextIndex++] = *memory;
				break;

			case ',': 
				if (readChar(memory) != 1) {
					puts("Invalid Input, please try again!");
					continue;
				}
				break;

			case '[':
				if ((int)*memory > 0) { break; }

				while (*commands != ']')
					commands++;
				break;

			case ']':
				if ((int)*memory == 0) { break; }

				while (*commands != '[')
					commands--;
				break;

			default:
				puts("Unkown symbol!");
				break;
		}

		commands++;
	}

	return currentTextIndex;
}

int isPrintable(const unsigned char charToValidate) {

	const int BOTTOM_CHAR_PRINTABLE_INDEX = 32;
	const int TOP_CHAR_PRINTABLE_INDEX = 126;

	return charToValidate >= BOTTOM_CHAR_PRINTABLE_INDEX && charToValidate <= TOP_CHAR_PRINTABLE_INDEX;
}

int validateNestedBraces(const unsigned char* commandsArr, const int arrSize) {

	int bracketsOpened = 0;
	int commandsValid = 1;
	while (*commandsArr != 'x')
	{
		if (*commandsArr == '[' && !bracketsOpened){
			bracketsOpened = 1;;
		}
		else if (*commandsArr == '[' && bracketsOpened){
			commandsValid = 0;
			break;
		}
		else if (*commandsArr == ']' && bracketsOpened){
			bracketsOpened = 0;
		}
		else if (*commandsArr == ']' && !bracketsOpened){
			commandsValid = 0;
			break;
		}

		commandsArr++;
	}

	return commandsValid;
}

void printText(const char* textArr, const unsigned arrLength) {

	for (int i = 0; i < arrLength; i++){
		printf("%c", textArr[i]);
	}
}

int main1() {

	unsigned char memory[MEMORY_SIZE] = {0};
	unsigned char commands[COMMANDS_CAP];

	int commandsCount = readInput(commands);
	if (commandsCount == -1){
		puts("No more than 1024 commands allowed!");
		return -1;
	}
	else if (!validateNestedBraces(commands, commandsCount))
	{
		puts("Invalid input!");
		return -1;
	}

	char text[MEMORY_SIZE];
	int textSize = interpretCommands(commands, memory, text);
	printText(text, textSize);

	return 0;
}