#include<stdio.h>
#include<math.h>

int main() {
	
	const double Epsilon = 1E-9;

	const double triangleASideX = 1.6;
	const double triangleASideY = 1;

	const double triangleBSideX = 1;
	const double triangleBSideY = 2;

	const double triangleCSideX = 1;
	const double triangleCSideY = 1;

	const double yellowCircleCenterX = -0.5;
	const double yellowCircleCenterY = 2.5;
	const double yellowCircleRadius = 0.4;

	const double transparentCircleCenterX = -0.2;
	const double transparentCircleCenterY = 2.8;
	const double transparentCircleRadius = 0.7;

	double pointX, pointY;

	puts("Please insert (x,y) coordinates:");
	int result = scanf_s("%lf %lf", &pointX, &pointY);

	if (result != 2){
		puts("invalid input!");
		return 1;
	}
	else if (pointY < 0 || pointX < -1.6 || pointX > 1.6){
		puts("Point matches no color!");
		return 0;
	}

	int color = 0;
	if ((pointX >= -1 && pointY >= 0) && (pointX <= 1 && pointY <= 1)) // inside grey
	{
		int insideCyan = (pointX <= 0.9 && pointY <= 0.8) && (pointX >= 0.5 && pointY >= 0.5);
		int insideGreen = (pointX <= -0.6 && pointY <= 0.8) && (pointX > -0.9 && pointY >= 0);

		if (insideCyan)
		{
			color = 5; //cyan
		}
		else if (insideGreen)
		{
			color = 3; //green
		}
		else
		{
			color = 4; // grey
		}

	}
	else if ((pointX >= -1.6 && pointY >= 1) && (pointX <= 1.6 && pointY <= 2)) // inside blue
	{
		#pragma region Triangle logic

		// Main triangle
		double triangleCA = sqrt(pow(triangleASideX - triangleCSideX, 2) + pow(triangleASideY - triangleCSideY, 2));
		double triangleCB = sqrt(pow(triangleBSideX - triangleCSideX, 2) + pow(triangleBSideY - triangleCSideY, 2));
		double triangleAB = sqrt(pow(triangleBSideX - triangleASideX, 2) + pow(triangleBSideY - triangleASideY, 2));

		double triangleArea = (triangleCA * triangleCB) / 2;

		//Positive triangle (right one)

		double pointXTemp = pointX < 0 ? -pointX : pointX;

		double PointToADistance = sqrt(pow(triangleASideX - pointXTemp, 2) + pow(triangleASideY - pointY, 2));
		double PointToBDistance = sqrt(pow(triangleBSideX - pointXTemp, 2) + pow(triangleBSideY - pointY, 2));
		double PointToCDistance = sqrt(pow(triangleCSideX - pointXTemp, 2) + pow(triangleCSideY - pointY, 2));

		//PAC
		double trianglePACSemiPerimeter = (PointToADistance + triangleCA + PointToCDistance) / 2;
		double trianglePACArea =
			sqrt(trianglePACSemiPerimeter *
				(trianglePACSemiPerimeter - PointToCDistance) *
				(trianglePACSemiPerimeter - PointToADistance) *
				(trianglePACSemiPerimeter - triangleCA));

		//PAB
		double trianglePABSemiPerimeter = (PointToADistance + PointToBDistance + triangleAB) / 2;
		double trianglePABArea =
			sqrt(trianglePABSemiPerimeter *
				(trianglePABSemiPerimeter - PointToADistance) *
				(trianglePABSemiPerimeter - PointToBDistance) *
				(trianglePABSemiPerimeter - triangleAB));

		//PCB
		double trianglePCBSemiPerimeter = (PointToCDistance + PointToBDistance + triangleCB) / 2;
		double trianglePCBArea =
			sqrt(trianglePCBSemiPerimeter *
				(trianglePCBSemiPerimeter - PointToCDistance) *
				(trianglePCBSemiPerimeter - PointToBDistance) *
				(trianglePCBSemiPerimeter - triangleCB));

		double sumOfSmallAreas = trianglePABArea + trianglePACArea + trianglePCBArea;

		#pragma endregion

		int insideTriangle = fabs(triangleArea - sumOfSmallAreas) <= Epsilon;

		if (insideTriangle || (pointX > -1 && pointX < 1))
		{
			color = 1; // blue
		}
	}
	else if ((pointX >= 0.6 && pointY >= 2.0) && (pointX <= 0.8 && pointY <= 2.3)) { color = 2; }
	else 
	{
		double distanceToYellowCircle = sqrt(((pointX - yellowCircleCenterX) * (pointX - yellowCircleCenterX)) + 
											  (pointY - yellowCircleCenterY) * (pointY - yellowCircleCenterY));

		double distanceToTransperantCircle = sqrt((pointX - transparentCircleCenterX) * (pointX - transparentCircleCenterX) + 
												  (pointY - transparentCircleCenterY) * (pointY - transparentCircleCenterY));

		if (distanceToYellowCircle <= yellowCircleRadius && distanceToTransperantCircle > transparentCircleRadius)
		{
			color = 6; // yellow
		}
	}

	switch (color)
	{
		case 1:
			puts("Blue");
			break;
		case 2:
			puts("Brown");
			break;
		case 3:
			puts("Green");
			break;
		case 4:
			puts("Grey");
			break;
		case 5:
			puts("Cyan");
			break;
		case 6:
			puts("Yellow");
			break;
		default:
			puts("Point matches no color!");
			break;
	}
}