#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#pragma warning(disable: 4996)

/*
Ала-Бала е игра, която се играе на правоъгълно поле от цели числа (както положителни, така и отрицателни). Играчът започва от горния ляв ъгъл - поле с координати (0, 0) и енергия, колкото е стойността в това поле. На всеки ход той има право да се премести в някое съседно поле, като енергията му се променя със стойността на полето в което се премества и след това допълнително се намалява с поредния номер на хода му (след първото преместване се намалява с едно, след следващото с две и така нататък). Целта на играча е да достигне последното поле - долния десен ъгъл, с максимална енергия. Ако в даден момент енергията му стане нула или отрицателна, то той губи играта.

Напишете програма, която играе Ала-Бала. За целта въведете от клавиатурата размерите на матрицата на игралното поле, следвани от стойностите на всяка клетка. След това трябва да изведете максималната енергия, с която играчът може да достигне последното поле или подходящо съобщение, ако това не е възможно или възникне друг проблем. Опишете в коментар подхода си и обосновете оптималността на получения резултат.
*/

#define DIRECTIONS 2

// Greedy approach
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

void clearStdin() {
	char c = ' ';
	while ((c = getc(stdin)) != EOF && c && '\n');
}

void clearMatrix(int** matrix, size_t rows) {

	for (int i = 0; i < rows; i++){
		free(matrix[i]);
	}
	free(matrix);
	matrix = NULL;
}

size_t readDimension() {
	size_t input = 0;

	int res = 0;
	do
	{
		res = scanf("%zu", &input);
		if (res != 1) {
			clearStdin();
		}
	} while (res != 1);

	return input;
}

int readNumber() {
	int input = 0;

	int res = 0;
	do
	{
		res = scanf("%d", &input);
		if (res != 1) {
			clearStdin();
		}
	} while (res != 1);

	return input;
}

int** createField(size_t rows, size_t cols) {
	int** matrix = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; ++i) {
		matrix[i] = (int*)malloc(cols * sizeof(int));
		if (matrix[i] == NULL) {
			clearMatrix(&matrix, i);
			return NULL;
		}
	}

	return matrix;
}

void initField(int** field, size_t rows, size_t cols) {
	puts("Insert field values: ");
	for (int y = 0; y < rows; y++){
		for (int x = 0; x < cols; x++){
			field[y][x] = readNumber();
		}
	}
}

int inBounds(size_t rows, size_t cols, int x, int y) {
	return
		(x >= 0 && x < cols) &&
		(y >= 0 && y < rows);
}

int traverse(int** field, unsigned int rows, unsigned int cols, int x, int y, int energy, int* maxEnergy, int turn) {
	if (!inBounds(rows, cols, x, y)) return INT_MIN;
	else if (energy <= 0) return INT_MIN;

	if (x != 0 || y != 0) energy += field[y][x] - turn;
	if (x == cols - 1 && y == rows - 1) return energy;

	int right = traverse(field, rows, cols, x + 1, y, energy, maxEnergy, turn + 1);
	int down = traverse(field, rows, cols, x, y + 1, energy, maxEnergy, turn + 1);

	int max = right > down ? right : down;
	*maxEnergy = *maxEnergy >  max ? *maxEnergy : max;
	return max;
}

void hasPath(int** field, size_t rows, size_t cols) {
	int maxEnergy = INT_MIN;

	int hasPath = traverse(field, rows, cols, 0, 0, field[0][0], &maxEnergy, 0);

	if (maxEnergy) printf("There is a path and the most energy the player can have is --> %d", maxEnergy);
	else printf("No path can be found!");
}

int main_E_3() {
	size_t rows, cols;
	printf("Insert field dimensions: ");
	rows = readDimension();
	cols = readDimension();

	int** field = NULL;
	field = createField(rows, cols);
	if (!field) {
		puts("Problem allocating memory!");
		return -1;
	}
	initField(field, rows, cols);

	hasPath(field, rows, cols);


}