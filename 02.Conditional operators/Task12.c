#include<stdio.h>
#include<math.h>

/*
Напишете програма, която приема координати на точка (x, y) и проверява дали точката попада в зададена област на координатната система.
Областта представлява правоъгълник с координати на долния ляв ъгъл (0, 0) и горния десен ъгъл (5, 5).
						(x2,y2)
(x1,y1+ y2)	-----*-------(5,5)
			|			|
			*			|	
			|		*	|
			|			|
			------------(x1 + x2, y1 + y2)
			(0,0)
			(x1,y1)
*/
int main12()
{
	const int x1 = 0, y1 = 0, x2 = 5, y2 = 5;

	int pointX, pointY;
	scanf_s("%d %d", &pointX, &pointY);

	if (pointY == y1 || pointY == y2 || pointX == x1 || pointX == x2 )
	{
		printf("On the border");
	}
	else if ((pointX > x1 && pointX < x2) && (pointY > y1 && pointY < y2))
	{
		printf("inside the area");
	}
	else{
		printf("outside the area");
	}

}