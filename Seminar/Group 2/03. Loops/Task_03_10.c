#include<stdio.h>

int main_03_10()
{
	int number = 0;
	scanf_s("%d", &number);

	if (number < 3) {
		puts("dumbell not possoble!");
	}

	int steps = (number * 3) - 2;
	for (int y = 1; y <= number; y++)
	{
		if (y == 1 || y == number)
		{
			for (int i = 1; i <= number; i++)
			{
				printf(". ");
			}

			for (int j = 1; j <= number - 2; j++)
			{
				printf("  ");
			}

			for (int z = 1; z <= number; z++)
			{
				printf(". ");
			}

		}
		else if ((number % 2 == 0 && (y == number / 2 || y == number / 2 + 1)) || (number % 2 != 0 && y == number / 2 + 1))
		{
			for (int i = 1; i <= number; i++)
			{
				if (i == 1 || i == number)
				{
					printf(". ");
				}
				else
				{
					printf("  ");
				}
			}

			for (int j = 1; j <= number - 2; j++)
			{
				printf(". ");
			}

			for (int z = 1; z <= number; z++)
			{
				if (z == 1 || z == number)
				{
					printf(". ");
				}
				else
				{
					printf("  ");
				}
			}
		}
		else
		{
			for (int i = 1; i <= number; i++)
			{
				if (i == 1 || i == number)
				{
					printf(". ");
				}
				else
				{
					printf("  ");
				}
			}

			for (int j = 1; j <= number - 2; j++)
			{
				printf("  ");
			}

			for (int z = 1; z <= number; z++)
			{
				if (z == 1 || z == number)
				{
					printf(". ");
				}
				else
				{
					printf("  ");
				}
			}
		}

		puts("");
	}
	
	return 0;
}