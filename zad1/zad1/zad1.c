#include <stdio.h>
int main()
{
	float h, r, sb, sp, v;
	printf("Input the height value: ");
	scanf_s("%f", &h);
	printf("Enter the radius value: ");
	scanf_s("%f", &r);
	sb = 2 * 3.14 * r * h;
	sp = 2 * 3.14 * r * (r + h);
	v = 3.14 * r * r * h;
	printf("the area of the side surface of the cylinder = %.2f\n", sb);
	printf("The total surface area of the cylinder = %.2f\n", sp);
	printf("cylinder volume = %.2f\n", v);
	return 0;
}
