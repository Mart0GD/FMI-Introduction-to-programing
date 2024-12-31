#include<stdio.h>

/*
Задача 6: Въвежда се цяло число n, последвано от n на брой цифри.
Да се напише програма, която отпечатва числото, образувано от четните цифри, умножено по 2.
*/
int main_03_06()
{
	int n;
	scanf_s("%d", &n);

	int currentNumber = 0;
	int finalNumber = 0;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &currentNumber);

		if (currentNumber % 2 == 0)
		{
			finalNumber *= 10;
			finalNumber += currentNumber;
		}
	}

	printf("%d", finalNumber * 2);
	return 0;
}