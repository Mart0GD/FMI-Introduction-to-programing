#include<stdio.h>
#include<math.h>

/*
Напишете програма, която прочита цяло положително число от конзолата и връща дали то е просто и дали то е перфектно.

Просто число ще наричаме число, по-голямо от 1, което има само 2 делителя - 1 и себе си. (Примери за прости числа: 2, 3, 5, 7, 11)

Перфектно число ще наричаме число, което е равно на сумата на неговите делители, без него. (Пример: 6 = 1 + 2 + 3)
*/
int main_7()
{
	int number;
	scanf_s("%d", &number);

	int isPrime = 1;
	for (int i = 2; i < number / 2; i++)
	{
		if (number % i == 0)
		{
			isPrime = 0;
			break;
		}
	}
	
	int sum = 0;
	for (int i = 1; i < number; i++)
	{
		if (number % i == 0)
		{
			sum += i;
		}
	}

	int isPerfect = sum == number;
	printf("Prime: %d\n", isPrime);
	printf("Perfect: %d", isPerfect);

	return 0;
}