#include<stdio.h>

int main1()
{
	unsigned int age;
	scanf_s("%d", &age);

	if (age <= 0) 
	{
		printf("invalid age!");
		return;
	}

	if (age <= 18) 
	{
		printf("you are a minor");
	}
	else 
	{
		printf("you are an adult");
	}

	return 0;
}