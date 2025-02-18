#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable: 4996)

/*
Задача 10 (контролно): Пред нас са поставени m супер-туби с вода, като всяка е с неограничена вместимост. Даден ни е и контейнер с n литра вода. Да се напише функция, която по подадени n и m намира по колко различни начина можем да разпределим литрите вода в тубите. Начините да се извеждат на стандартния изход.
Вход:
2 8
Изход: 9
5, 3
3, 5
4, 4
6, 2
2, 6
7, 1
1, 7
0, 8
8, 0
*/

void printfSubSets(int m, int n, int* set, int index) {
	if (index == m - 1) {
		set[index] = n;
		for (int i = 0; i < m; i++){
			printf("%d ", set[i]);
		}
		puts(" ");
		return;
	}

	for (int i = n; i >= 0; i--){
		set[index] = i;
		printfSubSets(m, n - i, set, index + 1);
	}
}

void printAllDistributions(int m, int n) {
	int* set = (int*)calloc(m, sizeof(int));
	if(!set){
		printf("no memory can be allocated!");
		return;
	}

	printfSubSets(m, n, set, 0);
	free(set);
}

int main_S_10() {
	int m, n = 0;
	scanf("%d %d", &m, &n);

	printAllDistributions(m, n);
	return 0;
}