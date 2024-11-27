#include<stdio.h>

/*
Ќапишете програма, ко€то прочита от конзолата ц€ло положително число a и принтира/рисува на конзолата квадрат с големина на страните a.
*/
int main13()
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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || i == n - 1)
			{
				printf("#");
				continue;
			}
			else if (j == 0 || j == n - 1)
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