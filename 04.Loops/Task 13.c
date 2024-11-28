#include<stdio.h>

/*
Ќапишете програма, ко€то прочита от конзолата ц€ло положително число a и принтира/рисува на конзолата квадрат с големина на страните a.
*/
int main_13()
{
	unsigned int n;
	scanf_s("%u", &n);

	if (n == 0)
	{
		puts("Not possible!");
		return 1;
	}
	else if (n == 1)
	{
		puts("#");
		return 0;
	}

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (x == 0 || x == n - 1)
			{
				printf("#");
				continue;
			}
			else if (y == 0 || y == n - 1)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		puts("");
	}
}