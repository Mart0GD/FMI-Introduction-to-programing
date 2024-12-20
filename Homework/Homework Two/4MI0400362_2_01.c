#include<stdio.h>
#include<math.h>
#pragma warning(push)
#pragma warning(disable: 4996)

#define MEMORY_SIZE 1024
#define COMMANDS_CAP 1024

/*
+
Стойността на текущата клетка, която се сочи от указателя, се увеличава с 1.
-
Стойността на текущата клетка, която се сочи от указателя, се намалява с 1.
>
Увеличава с 1 стойността на указателя. Ако указателят сочи към 1024-тата клетка в паметта, то той трябва да се върне обратно в първата.
<
Намалява с 1 стойността на указателя. Ако указателят сочи към първата клетка от паметта, то той трябва да се прехвърли на последната.
.
Извежда на стандартния изход съдържанието на клетката, която се сочи от указателя, ако стойността ѝ е символ, който може да бъде изведен на екрана (printable character).
,
Прочита се unsigned char от стандартния вход. Стойността се съхранява  в текущата клетка.
[
Ако стойността на текущата клетка е 0, преминаваме към инструкцията след съответната затварящата скоба. В противен случай, изпълнението продължава нормално със следващата инструкция.
]
Ако стойността на текущата клетка е различна от 0, преминаваме към инструкцията след съответстващата отваряща скоба. В противен случай, изпълнението продължава нормално със следващата инструкция.
*/
//++++++++++[>++++++++>++++++++>++++>+++++++>+++++++<<<<<-]>+++++.>.>+++++.>+++.+++++.>.x

int readInput(unsigned char* memory) {

	char currentCommand = ' ';
	int scanResult = 0;
	int iter = 0;
	while (currentCommand != 'x' && iter <= COMMANDS_CAP)
	{
		scanResult = scanf("%c", &currentCommand);
		if (scanResult <= 0){
			puts("Invalid input, please input a valid character!");
			continue;
		}

		*(memory++) = currentCommand;
		iter++;
	}

	if (iter > 1024)
		return -1;
	
	return iter;
}

void interpretCommands(const unsigned char* commands, unsigned char* memory) {
		
	while (*commands != 'x')
	{
		switch (*commands)
		{
			case '+': 
				*memory += (int)*memory == pow(2, (sizeof(char) * 8) - 1) // превъртане 
					? 0
					: 1; 
				break;

			case '-':
				*memory -= (int)*memory == 0  // превъртане
					? 0 
					: 1;
				break;

			case '>':
				memory = (int)*memory == MEMORY_SIZE - 1
					? 0
					: memory + 1;
				break;

			case '<':
				memory = (int)*memory == 0 
					? MEMORY_SIZE - 1
					: memory - 1;
				break;

			case '.':
				if (!isPrintable(*memory)) { break; }
				printf("%c", *memory);
				break;

			case ',':
				if (scanf("%c", memory) != 1) {
					puts("Invalid Input, please try again");
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

	interpretCommands(commands, memory);
	return 0;
}