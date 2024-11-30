#include<stdio.h>
#include<limits.h>
/*
Задача 2: Конкатенация на две естествени числа n и k наричаме числото n ◦ k, което се получава като към цифрите на n "се долепят" цифрите на k.
Да се напише функция, която приема две цели положителни числа n и k и връща тяхната конкатенация.
Вход: 22 1995, Изход: 221995
*/

int reverse(int number) {
	int reversed = 0;

	while (number != 0)
	{
		reversed *= 10;
		reversed += number % 10;
		number /= 10;
	}

	return reversed;
}

int concat(int a, int b) {

	b = reverse(b);
	while (b != 0){
		a *= 10;
		a += b % 10;
		b /= 10;
	}

	return a;
}

int main_04_02() {
	int n, k;
	scanf_s("%d %d", &n, &k);

	int number = concat(n, k);
	printf("%d", number);
	return 0;
}