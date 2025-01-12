#include<stdio.h>

int main_2()
{
	const int asciiLength = 128;

	for (int i = 0; i < asciiLength; i++)
	{
		printf("%d -> %c\n", i, (char)i);
	}
	return 0;
}