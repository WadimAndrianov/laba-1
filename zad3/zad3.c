#include <stdio.h>
int main()
{
	float a, b, c;
	printf("Input a: ");
	scanf_s("%f", &a);
	printf("Input b: ");
	scanf_s("%f", &b);
	printf("Input c: ");
	scanf_s("%f", &c);
	if (a == -b) {
		printf("%.2f\n", c);
	}
	else if (a == -c)
	{
		printf("%.2f\n", b);
	}

	else if (b == -c) {
		printf("%.2f\n", a);
	}
	else printf("No");

	return 0;
}
