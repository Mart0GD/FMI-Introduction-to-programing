#include<stdio.h>

/*
�������� ��������, ����� ������� �� ��������� ���� ������������� ����� n, ���� ����� �������� ������ ������������ �� ������ ��������� �� n ��������. ���� ���������� �� �� ������� �� 1 �� n.

���������: ��������� ����� �� � ������������ �� �� � ������ ��� ���� ��������������.
#1 ������
����:
3

�����:
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