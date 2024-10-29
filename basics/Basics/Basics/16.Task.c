#include<stdio.h>
//
//int main()
//{
//	#pragma region I dont want to see this
//
//	const int leva100 = 100;
//	const int leva50 = 50;
//	const int leva20 = 20;
//	const int leva10 = 10;
//	const int leva5 = 5;
//	const int leva2 = 2;
//	const int leva1 = 1;
//	
//	int leva100Used = 0;
//	int leva50Used = 0;
//	int leva20Used = 0;
//	int leva10Used = 0;
//	int leva5Used = 0;
//	int leva2Used = 0;
//	int leva1Used = 0;
//
//#pragma endregion
//	
//	int sum = 0;
//
//	scanf_s("%d", &sum); 
//
//	leva100Used = sum / 100;
//	sum -= (100 * leva100Used);
//
//	leva50Used = sum / 50;
//	sum -= (50 * leva50Used);
//
//	leva20Used = sum / 20;
//	sum -= (20 * leva20Used);
//
//	leva10Used = sum / 10;
//	sum -= (10 * leva10Used);
//
//	leva5Used = sum / 5;
//	sum -= (5 * leva5Used);
//
//	leva2Used = sum / 2;
//	sum -= (2 * leva2Used);
//
//	leva1Used = sum / 1;
//	sum -= (1 * leva1Used);
//
//	printf("100 -> ");
//	printf("%d\n", leva100Used);
//
//	printf("50 -> ");
//	printf("%d\n", leva50Used);
//
//	printf("20 -> ");
//	printf("%d\n", leva20Used);
//
//	printf("10 -> ");
//	printf("%d\n", leva10Used);
//
//	printf("5 -> ");
//	printf("%d\n", leva5Used);
//
//	printf("2 -> ");
//	printf("%d\n", leva2Used);
//
//	printf("1 -> ");
//	printf("%d\n", leva1Used);
//
//
//	return 0;
//}