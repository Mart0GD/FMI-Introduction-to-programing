#include<stdio.h>
#include<stdlib.h>

/*
Да се напише рекурсивна функция, която генерира всички подмножества на подадено n-елементно множество.
*/

void print(int* elements, int* bitstring, int index, size_t size) {
	if (index == size) {
		printf("{ ");
		for (int i = 0; i < size; i++) {
			if (bitstring[i]) printf("%d ", elements[i]);
		}
		printf(" }\n");
		return;
	}
	
	bitstring[index] = 0;
	print(elements, bitstring, index + 1, size);

	bitstring[index] = 1;
	print(elements, bitstring, index + 1, size);
}

void printAllSubSequences(int* elements, size_t size) {
	int* bitstring = (int*)calloc(size, sizeof(int));
	if (!bitstring) return;

	print(elements, bitstring, 0, size);
}

int main_S_13() {

	int elements[] = {1, 2, 3};

	printAllSubSequences(elements, 3);

	return 0;
}