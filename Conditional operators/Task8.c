#include<stdio.h>

int main8()
{
	int month, nights;
	scanf_s("%d %d", &month, &nights);

	if (month < 5 || month > 10 || nights < 0 || nights > 200) {
		puts("invalid input");
		return;
	}

	double apartmentPrice = 0;
	double studioPrice = 0;

	switch (month)
	{
		case 5:
		case 10:

			studioPrice += 50 * nights;
			apartmentPrice += 65 * nights;

			if (nights > 14) { studioPrice *= 0.7; }
			else if (nights > 7) { studioPrice *= 0.95; }

			break;

		case 6:
		case 9:

			studioPrice += 75.20 * nights;
			apartmentPrice += 68.70 * nights;

			if (nights > 14) { studioPrice *= 0.8; }
			break;

		case 7:
		case 8:

			studioPrice += 76 * nights;
			apartmentPrice += 77 * nights;

			break;
	}

	if (nights > 14)
	{
		apartmentPrice *= 0.9;
	}

	printf("apartment price %.2lf\n", apartmentPrice);
	printf("studio price %.2lf", studioPrice);

	return 0;
}