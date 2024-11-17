#include<stdio.h>
#include<math.h>

/*
Дадена е декартова координатна система. Всеки правоъгълник със страни успоредни на координатните оси в нея може да се определи с четири числа с плаваща точка: координатите на долния си ляв ъгъл (x,y), ширината и дължината си. Напише програма, която прочита от стандартния вход данни за два правоъгълника и извежда на екрана лицето на общата им част. Ако правоъгълниците нямат обща част, приемаме лицето за нула.

Вход:
0 0 5 3
4 1 3 3

Изход:
2
*/
int main()
{
	double rec1x1, rec1y1, rec1width, rec1height;
	double rec2x1, rec2y1, rec2width, rec2height;

	puts("Insert values for first rectangle: (x1,y1), width, height");
	scanf_s("%lf %lf %lf %lf", &rec1x1, &rec1y1, &rec1width, &rec1height);

	double rec1x2 = rec1x1 + rec1width;
	double rec1y2 = rec1y1 + rec1height;

	puts("Insert values for first rectangle: (x1,y1), width, height");
	scanf_s("%lf %lf %lf %lf", &rec2x1, &rec2y1, &rec2width, &rec2height);
	
	double rec2x2 = rec2x1 + rec2width;
	double rec2y2 = rec2y1 + rec2height;

	double overlapingAreaWidth = fmin(rec1x2, rec2x2) - fmax(rec1x1, rec2x1);
	double overlapingAreaHeight = fmin(rec1y2, rec2y2) - fmax(rec1y1, rec2y1);

	double area;

	if (overlapingAreaWidth < 0 || overlapingAreaHeight < 0) { area = 0; }
	else { area = overlapingAreaWidth * overlapingAreaHeight; }

	printf("area: %.2lf", area);

}