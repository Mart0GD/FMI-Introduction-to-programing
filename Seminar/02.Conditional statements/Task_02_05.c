#include<stdio.h>
#include<math.h>
/*
������ 5: �� �� ������ ��������, ����� ��� �������� ������ r � �������� ����� (�, �) ��������� ���� ������� �� ������ �����/����� ��� �� ������� �� ��������� � ������ (0,0).
����: 5 0 5, �����: On the circle
����: 5 10 30, �����: Out of the circle
����: 5 0 2, �����: In the circle
*/
int main_02_05()
{
	const Epsilon = 1E-9;
	const double centerX, centerY;
	
	double pointX, pointY;
	double radius;

	puts("radius:");
	scanf_s("%lf", &radius);
	
	puts("please insert a point (x,y):");
	scanf_s("%lf %lf", &pointX, &pointY);

	double distance = sqrt(pow(pointX, 2) + pow(pointY, 2));
	int isPointInside = fabs(distance) < radius;
	int isPointOnTheEdge = fabs(distance - radius) <= Epsilon;

	if (isPointOnTheEdge) { puts("On the border!"); }
	else if (isPointInside) { puts("Inside!"); }
	else { puts("Outside!"); }

	return 0;
}