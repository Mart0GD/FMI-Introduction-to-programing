#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

/*
Да се напише рекурсивна функция, която приема естествено число n>0 и извежда всички булеви вектори с дължина 2*n, такива че сумата на елементите им в първата и втората половина съвпада.
*/

int IsSymetrical(int* bitArr, int size) {
	int sum1 = 0;
	int sum2 = 0;
	int mid = size / 2;
	for (int i = 0; i < mid; i++){
		sum1 += bitArr[i];
		sum2 += bitArr[i + mid];
	}
	
	return sum1 == sum2;
}

find(int* bitArr, int n, int index) {
	if (n == index) {
		if (IsSymetrical(bitArr, n)) {
			for (int i = 0; i < n; i++){
				printf("%d ", bitArr[i]);
			}
			puts(" ");
		}
		return;
	}

	bitArr[index] = 0;
	find(bitArr, n, index + 1);

	bitArr[index] = 1;
	find(bitArr, n, index + 1);
}

void findVectors(int n) {
	int* bitArr = (int*)calloc(n, sizeof(int));
	if (!bitArr) return;

	find(bitArr, n, 0);
}

int main_Combinations() {
	int n = 0;
	scanf("%d", &n);

	findVectors(n * 2);
}