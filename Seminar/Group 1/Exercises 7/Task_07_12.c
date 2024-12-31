#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#pragma warning(push)
#pragma warning(disable: 4996)
#define NUMBER_OF_OPERATORS 4
/*
12. Дадена е редицата x0, x1, …, xn-1 от различни от 0 цели числа. Да се напише програма, която в израза
( .. ((x0 ? x1) ? x2) ? … ) ? xn-1 вместо всеки знак ? поставя една от четирите аритметични операции +, -, * или /, така че в резултат стойността на получения аритметичен израз да е равна на цялото число p. Програмата да намира всички решения. Предната задача ще ви е полезна.
*/

void freeMatrix8(int** matrix, const int rows) {
	for (int i = 0; i < rows; i++){
		free(matrix[i]);
	}

	free(matrix);
}

int* generateSequence(const unsigned size) {
	int* arr = (int*)malloc(sizeof(int) * size);
	if (!arr) return NULL;

	for (int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}

	return arr;
}

char** createMatrix8(const unsigned  rows, const unsigned cols) {
	char** matrix = (char**)malloc(sizeof(char*) * rows);
	if (!matrix) return NULL;

	for (int i = 0; i < rows; i++) {
		matrix[i] = (char*)malloc(sizeof(char) * (cols));
		if (!matrix[i]) freeMatrix8(matrix, i);
	}

	return matrix;
}

void printOutcome(const int* numbers, const char** outocomes, const unsigned outcomeIndex, const unsigned numbersLength) {
	for (int i = 0; i < numbersLength - 2; i++)
		printf("(");

	for (int i = 0; i < numbersLength - 1; i++) {
		if(i == 0 ) printf("%d%c", numbers[i], outocomes[outcomeIndex][i]);
		else printf("%d)%c", numbers[i], outocomes[outcomeIndex][i]);
	}
	printf("%d", numbers[numbersLength - 1]);
	puts("");
}

void calculateOperations(const int* numbers, const int desiredNumber, char** outcomes, int currentSum, int index, int outcomeIndex, const unsigned numbersLength) {
	if (index == numbersLength - 1){
		if (currentSum == desiredNumber) {
			printOutcome(numbers, outcomes, outcomeIndex, numbersLength);
			outcomeIndex++;
		}
		return;
	}

	// addition
	outcomes[outcomeIndex][index] = '+';
	calculateOperations(numbers, desiredNumber, outcomes, currentSum + numbers[index + 1], index + 1, outcomeIndex, numbersLength);

	// subtraction 
	outcomes[outcomeIndex][index] = '-';
	calculateOperations(numbers, desiredNumber, outcomes, currentSum - numbers[index + 1], index + 1, outcomeIndex , numbersLength);

	// multiplication
	outcomes[outcomeIndex][index] = '*';
	calculateOperations(numbers, desiredNumber, outcomes, currentSum * numbers[index + 1], index + 1, outcomeIndex, numbersLength);

	//divison
	outcomes[outcomeIndex][index] = '/';
	calculateOperations(numbers, desiredNumber, outcomes, currentSum / numbers[index + 1], index + 1, outcomeIndex, numbersLength);
}

int main_07_12() {

	unsigned sequenceLength;
	printf("Insert sequence length --> ");
	scanf("%u", &sequenceLength);

	puts("Insert sequence: ");
	int* sequence = generateSequence(sequenceLength);

	int res = 0;
	printf("Insert end result --> ");
	scanf("%d", &res);

	int allOutcomes = pow(NUMBER_OF_OPERATORS, sequenceLength - 1);
	char** outcomes = createMatrix8(allOutcomes, sequenceLength - 1);
	
	calculateOperations(sequence, res, outcomes, sequence[0], 0, 0, sequenceLength);

	freeMatrix8(outcomes, allOutcomes);
	free(sequence);
	return 0;
}