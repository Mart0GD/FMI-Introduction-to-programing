#include<stdio.h>
#include<math.h>

/*
�������� ��������, ����� ������ ������ �����, �������������� ������������ �� ��� ������������ ������� � ���������� ������������. ���������� ������ �� �������� ���� ���� ��� ������� �� ��������������� ��� ��.

��������: ��������� �� ���������������, ��� ���������� �� ������������ � ����� �� 0.
*/
int main()
{
	int x1, y1, x2, y2;

	scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);

	double angleBetweenVectors = ((x1 * x2) + (y1 * y2)) / ((sqrt(pow(x1, 2) + pow(y1, 2))) * sqrt(pow(x2, 2) + pow(y2, 2)));
	double epsilon = 0.001;

	int areVectorsOrthogonal = angleBetweenVectors <= epsilon;

	printf("%s", areVectorsOrthogonal ? "Yes" : "No");

	return 0;
}