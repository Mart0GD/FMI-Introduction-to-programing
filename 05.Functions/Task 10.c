#include<stdio.h>

/*
Напишете програма, която прочита букви (команди) докато не прочете буквата 'E' и тогава прекратява действието си. Програмата ще се налага да поддържа следните команди:

P -> изисква допълнителен вход цяло число n и пресмята пермутацията на n.
V -> изисква допълнителен вход 2 цели числа n и k и пресмята тяхната вариация.
C -> изисква допълнителен вход 2 цели числа n и k и пресмята тяхната комбинация.
E -> край на програмата.
друг вход -> принтира съобщение за невалиден вход и изисква нов вход "Invalid command input!"
*/

int CalculatePermutation(int n) {
	
	int sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
	}

	return sum;
}

int CalculateVariation(int n, int k) {

	int sum = 1;
	for (int i = 0; i < k; i++)
	{
		sum *= (n - i);
	}

	return sum;
}

int CalculateCombination(int n, int k) {
	if (n == 0)
	{
		puts("No combination possible!");
	}

	return CalculateVariation(n, k) / CalculatePermutation(n);
}

int main_10()
{
	char command;
	scanf_s("%c", &command);

	int n, k;
	while (command != 'E')
	{
		if (command == '\n') 
		{
			scanf_s("%c", &command);
			continue; 
		}

		switch (command)
		{
			case 'P':
				puts("Please input n:");
				scanf_s("%d", &n);

				printf("Permutation -> %d\n", CalculatePermutation(n));
			break;

			case 'V':
				puts("Please input n and k:");
				scanf_s("%d %d", &n, &k);

				printf("Variation -> %d\n", CalculateVariation(n, k));
			break;

			case 'C':
				puts("Please input n and k:");
				scanf_s("%d %d", &n, &k);

				printf("Combination -> %d\n", CalculateCombination(n, k));
			break;

			default:
				puts("Invalid command!");
			break;
		}

		scanf_s("%c", &command);
	}
	return 0;
}