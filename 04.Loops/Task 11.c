#include<stdio.h>

/*
Напишете програма, която прочита от конзолата цяло неотрицателно число n, след което принтира всички подмножества на дадено множество от n елемента. Като елементите ще са числата от 1 до n.

ЗАБЕЛЕЖКА: Изходните данни не е задължително да са в същият ред като долупоказаните.
#1 Пример
Вход:
3

Изход:
{ }
{ 1 }
{ 2 }
{ 1 2 }
{ 3 }
{ 1 3 }
{ 2 3 }
{ 1 2 3 }
*/
int main_11()
{
	int n;
	scanf_s("%d", &n);

	int step = 1;
	puts("{ }");
	for (int begining = 0; begining <= n; begining++)
	{
		//0
		step = 1;
		for (int currentFirstNumber = 0; currentFirstNumber < begining; currentFirstNumber++)
		{
			//0
			printf("{ ");
			for (int currentNumber = currentFirstNumber + 1; currentNumber <= begining; currentNumber += step)
			{
				printf("%d ", currentNumber);
				/*for (int i = currentNumber; currentNumber < begining; currentNumber++)
				{
					printf("%d ", currentNumber);
				}*/

			}
			puts("}");
			step++;
			
			
		}
	}
	
	
	return 0;
}