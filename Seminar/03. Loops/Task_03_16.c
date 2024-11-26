#include<stdio.h>

/*
Задача 16: Да се напише програма, която прочита от стандартния вход две естествени числа n и k, където k != 0, и проверява дали k е инфикс на n.
Вход: 5123345 123, Изход: true
Вход: 761 761, Изход: true
Вход: 555 5, Изход: true
Вход: 555 5555, Изход: false
Вход: 99445 0, Изход: false
*/

//sufix
int main()
{
	int n, k;
	scanf_s("%d %d", &n, &k);

	int isNSufixOfK = IsSufix(n, k);
	if (isNSufixOfK)
	{
		printf("%d is a sufix of -> %d\n", k, n);
	}
	
	int isNPrefixOfK = IsPrefix(n,k);
	if (isNPrefixOfK)
	{
		printf("%d is a prefix of -> %d\n", k, n);
	}

	int isNInfixOfK = IsInfix(n, k);
	if (isNInfixOfK)
	{
		printf("%d is infix of -> %d", n,k);
	}
	return 0;
}

int IsSufix(int number, int suifix) {
	if (number == 0 && suifix > 0 || suifix > number) { return 0; }
	if (number == 0){ return suifix % 10 == 0; }

	while (suifix > 0){
		if (number % 10 != suifix % 10){ return 0; }

		suifix /= 10;
		number /= 10;
	}

	return 1;
}

int IsPrefix(int number, int prefix) {
	return IsSufix(ReverseNumber(number), ReverseNumber(prefix));
}

int IsInfix(int number, int infix) {
	if (number == 0 && infix == 0) { return 1; }

	while (number > 0)
	{
		if (IsSufix(number, infix))
		{
			return 1;
		}
		number /= 10;
	}

}

int ReverseNumber(int number) {

	int reversed = 0;
	while (number != 0)
	{
		reversed *= 10;
		reversed += number % 10;
		number /= 10;
	}

	return reversed;
}