#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
//
//int main()
//{
//	const int songDuration = 3;
//
//	int songs;
//	char time[10]; // sorry ama kak bez string tuka 🙃
//
//	scanf_s("%d", &songs);
//	scanf("%s", &time);
//
//	int hour = (0 + (time[0] - '0') * 10) + (time[1] - '0'); // tova e tolkova gresho che me e sram, ne mojah da shvana splita na stringove po token
//	int minutes = (0 + (time[3] - '0') * 10) + (time[4] - '0');
//
//	int minutesToAdd = songs * songDuration;
//	int hoursToAdd = (minutes + minutesToAdd) / 60;
//
//	hour = (hour + hoursToAdd) % 24;
//	minutes = ( minutes + minutesToAdd) % 60; 
//
//	printf("%d:", hour);
//	minutes < 9 ? printf("%c%d", '0', minutes) : printf("%d", minutes); // tuka vtorata nula e pipkava rabota bez logicheski operator. Samo tova mi hrumna 
//
//	return 0;
//}