#include<stdio.h>

/*
Напишете програма, която прочита от конзолата две цели числа x и y и намира най-големия общ делител (НОД) на тези числа, използвайки Евклидовия алгоритъм. Създайте и използвайте функция gcd, която приема две цели числа като аргументи и връща НОД.
*/

int gcd(int a, int b) {
	if (a > b){ // znam che go zadraska na zadachata, no inache delim po malko na po golqmo (pitah i mariq i neito reshenie pak gi raszmenq)
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0){
		puts("Division by zero!");
		return 1;
	}

	int k = 0;
	while (b != 0)
	{
		k = a % b;

		a = b;
		b = k;
	}

	return a;
}

int main_12()
{
	int a, b;
	scanf_s("%d %d", &a, &b);

	printf("The gcd is -> %d", gcd(a, b));
	return 0;
}