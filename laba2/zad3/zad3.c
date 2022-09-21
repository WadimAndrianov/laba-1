#include <stdio.h>
int main()
{
	int x, y, divisor = 1, divisory = 1;
	printf("Enter Numbers x and y: ");
	if(scanf_s("%d%d", &x, &y)==2)
	{
		printf("divisors of x : ");
		while (x >= divisor)
		{
			while (x % divisor == 0)
			{
				printf("%d  ", divisor);
				divisor = divisor + 1;
			}
			divisor = divisor + 1;

		}

		printf("\n");
		printf("divisors of y : ");
		while (y >= divisory)
		{
			while (y % divisory == 0)
			{
				printf("%d  ", divisory);
				divisory = divisory + 1;
			}
			divisory = divisory + 1;
		}

		while (x != 1 && y != 1)
		{
			if (x > y)
				x = x - y;
			else
				y = y - x;
			if (x == y)
				break;
		}
		printf("\n");
		if (x == y)
			printf("Not Coprime numbers");
		if (x == 1 || y == 1)
			printf("Coprime numbers");
		return 0;
	}
	else
	{
		printf("Error");
	}
	return 0;
}
