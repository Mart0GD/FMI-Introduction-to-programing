#include<stdio.h>
#include<math.h>

int main1()
{
	#pragma region Const values

	const double Epsilon = 0.01;

	//Rectangles
	
	//cyan 
	const double cyanRectMiddlePointX = 0.70;
	const double cyanRectMiddlePointY = 0.65;

	const double cyanRectWidth = 0.4;
	const double cyanRectHeight = 0.3;

	// gery
	const double greyRectMiddlePointX = 0;
	const double greyRectMiddlePointY = 0.50;

	const double greyRectWidth = 2;
	const double greyRectHeight = 1;

	//green
	const double greenRectMiddlePointX = -0.75;
	const double greenRectMiddlePointY = 0.40;

	const double greenRectWidth = 0.30;
	const double greenRectHeight = 0.80;

	//brown
	const double brownRectMiddlePointX = 0.70;
	const double brownRectMiddlePointY = 2.15;

	const double brownRectWidth = 0.20;
	const double brownRectHeight = 0.30;

	//blue
	const double blueRectMiddlePointX = 0;
	const double blueRectMiddlePointY = 1.5;

	const double blueRectWidth = 2;
	const double blueRectHeight = 1;

	//Circles
	const double yellowCircleCenterX = -0.5;
	const double yellowCircleCenterY = 2.5;
	const double yellowCircleRadius = 0.4;

	const double transparentCircleCenterX = -0.2;
	const double transparentCircleCenterY = 2.8;
	const double transparentCircleRadius = 0.7;

	//Triangles 
	const double triangleOneAx = 1.6;
	const double triangleOneAy = 1;
						 
	const double triangleOneBx = 1;
	const double triangleOneBy = 2;
						 
	const double triangleOneCx = 1;
	const double triangleOneCy = 1;

	const double triangleTwoAx = -1.6;
	const double triangleTwoAy = 1;
						 
	const double triangleTwoBx = -1;
	const double triangleTwoBy = 2;
						 
	const double triangleTwoCx = -1;
	const double triangleTwoCy = 1;


	//TO DO add the blue triangles and yellow 1/4 circle
#pragma endregion

	double pointX, pointY;

	puts("Please insert (x,y) coordinates:");
	int result = scanf_s("%lf %lf", &pointX, &pointY);

	if (result != 2)
	{
		puts("invalid input!");
		return 1;
	}

	#pragma region Main logic

	//rectangles
	double pointXToCyanDistance = fabs(pointX - cyanRectMiddlePointX);
	double pointYToCyanDistance = fabs(pointY - cyanRectMiddlePointY);

	double pointXToGreyDistance = fabs(pointX - greyRectMiddlePointX);
	double pointYToGreyDistance = fabs(pointY - greyRectMiddlePointY);

	double pointXToGreenDistance = fabs(pointX - greenRectMiddlePointX);
	double pointYToGreenDistance = fabs(pointY - greenRectMiddlePointY);

	double pointXToBrownDistance = fabs(pointX - brownRectMiddlePointX);
	double pointYToBrownDistance = fabs(pointY - brownRectMiddlePointY);

	double pointXToBlueDistance = fabs(pointX - blueRectMiddlePointX);
	double pointYToBlueDistance = fabs(pointY - blueRectMiddlePointY);

	//circles
	double distanceToYellowCircle = sqrt(pow(pointX - yellowCircleCenterX, 2) + pow(pointY - yellowCircleCenterY, 2));
	double distanceToTransperantCircle = sqrt(pow(pointX - transparentCircleCenterX, 2) + pow(pointY - transparentCircleCenterY, 2));

	#pragma endregion

	#pragma region Triangles Logic

	// Main triangle
	double triangleCA = sqrt(pow(triangleOneAx - triangleOneCx, 2) + pow(triangleOneAy - triangleOneCy, 2));
	double triangleCB = sqrt(pow(triangleOneBx - triangleOneCx, 2) + pow(triangleOneBy - triangleOneCy, 2));
	double triangleAB = sqrt(pow(triangleOneBx - triangleOneAx, 2) + pow(triangleOneBy - triangleOneAy, 2));

	double triangleArea = (triangleCA * triangleCB) / 2;

	//Positive triangle (right one)

	double PointToADistance = sqrt(pow(triangleOneAx - pointX, 2) + pow(triangleOneAy - pointY, 2));
	double PointToBDistance = sqrt(pow(triangleOneBx - pointX, 2) + pow(triangleOneBy - pointY, 2));
	double PointToCDistance = sqrt(pow(triangleOneCx - pointX, 2) + pow(triangleOneCy - pointY, 2));

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

	double sumOfAreasOne = trianglePABArea + trianglePACArea + trianglePCBArea;

	// Nevative triangle (left one)

		double PointToA1Distance = sqrt(pow(triangleTwoAx - pointX, 2) + pow(triangleTwoAy - pointY, 2));
		double PointToB1Distance = sqrt(pow(triangleTwoBx - pointX, 2) + pow(triangleTwoBy - pointY, 2));
		double PointToC1Distance = sqrt(pow(triangleTwoCx - pointX, 2) + pow(triangleTwoCy - pointY, 2));

		//PA1C1
		double trianglePA1C1SemiPerimeter = (PointToA1Distance + triangleCA + PointToC1Distance) / 2;
		double trianglePA1C1Area =
			sqrt(trianglePA1C1SemiPerimeter *
				(trianglePA1C1SemiPerimeter - PointToC1Distance) *
				(trianglePA1C1SemiPerimeter - PointToA1Distance) *
				(trianglePA1C1SemiPerimeter - triangleCA));

		//PA1B1
		double trianglePA1B1SemiPerimeter = (PointToA1Distance + PointToB1Distance + triangleAB) / 2;
		double trianglePA1B1Area =
			sqrt(trianglePA1B1SemiPerimeter *
				(trianglePA1B1SemiPerimeter - PointToA1Distance) *
				(trianglePA1B1SemiPerimeter - PointToB1Distance) *
				(trianglePA1B1SemiPerimeter - triangleAB));

		//PC1B1
		double trianglePC1B1SemiPerimeter = (PointToC1Distance + PointToB1Distance + triangleCB) / 2;
		double trianglePC1B1Area =
			sqrt(trianglePC1B1SemiPerimeter *
				(trianglePC1B1SemiPerimeter - PointToC1Distance) *
				(trianglePC1B1SemiPerimeter - PointToB1Distance) *
				(trianglePC1B1SemiPerimeter - triangleCB));

		double sumOfAreasTwo = trianglePA1B1Area + trianglePA1C1Area + trianglePC1B1Area;

	#pragma endregion

	#pragma region Logical operations

	if ((pointXToCyanDistance <= cyanRectWidth / 2 || fabs(pointXToCyanDistance - cyanRectWidth / 2) <= Epsilon) &&
		(pointYToCyanDistance <= cyanRectHeight / 2 || fabs(pointYToCyanDistance - cyanRectHeight / 2) <= Epsilon))
	{
		puts("cyan");
	}
	else if ((pointXToGreenDistance <= greenRectWidth / 2 || fabs(pointXToGreenDistance - greenRectWidth / 2) <= Epsilon) &&
		(pointYToGreenDistance <= greenRectHeight / 2 || fabs(pointYToGreenDistance - greenRectHeight / 2) <= Epsilon))
	{
		puts("green");
	}
	else if ((pointXToGreyDistance <= greyRectWidth / 2 || fabs(pointXToGreyDistance - greyRectWidth / 2) <= Epsilon) &&
			 (pointYToGreyDistance <= greyRectHeight / 2 || fabs(pointYToGreyDistance - greyRectHeight / 2) <= Epsilon))
	{
		puts("grey");
	}
	else if ((pointXToBrownDistance <= brownRectWidth / 2 || fabs(pointXToBrownDistance - brownRectWidth / 2) <= Epsilon) &&
			 (pointYToBrownDistance <= brownRectHeight / 2 || fabs(pointYToBrownDistance - brownRectHeight / 2) <= Epsilon))
	{
		puts("brown");
	}
	else if (
			 ((pointXToBlueDistance <= blueRectWidth / 2 || fabs(pointXToBlueDistance - blueRectWidth / 2) <= Epsilon)   &&
			 (pointYToBlueDistance <= blueRectHeight / 2 || fabs(pointYToBlueDistance - blueRectHeight / 2) <= Epsilon)) ||
			 (fabs(sumOfAreasOne - triangleArea) <= Epsilon) ||
			 (fabs(sumOfAreasTwo - triangleArea) <= Epsilon)
			)
	{
		puts("blue");
	}
	else if( distanceToYellowCircle <= yellowCircleRadius && distanceToTransperantCircle > transparentCircleRadius)
	{
		puts("yellow");
	}
	else
	{
		puts("Point matches no color!");
	}
	#pragma endregion

	return 0;
}