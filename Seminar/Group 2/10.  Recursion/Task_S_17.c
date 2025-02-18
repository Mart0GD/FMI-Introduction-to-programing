#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "helper.h"

#define TOWER_SIZE 5
#define MAX_LETTERS 128
#pragma warning(disable: 4996)
/*
Да се напише рекурсивна функция, която решава задачата за ханойските кули.
*/

void move(int disk, char from, char to) {
	printf("Moved disk %d from %c --> %c\n", disk, from, to);
}

void solveHanoi(size_t disks, char from, char mid, char to) {
	if (disks == 0) return;

	solveHanoi(disks - 1, from, to, mid);
	move(disks, from, to);
	solveHanoi(disks - 1, mid, from, to);
}

int main_S_17() {
	int disks = 0;
	scanf("%d", &disks);

	solveHanoi(disks, 'a', 'b', 'c');
	puts(" ");
	
	return 0;
}