#include <stdio.h>
int main()
{
	float a, b;
	printf("Input numbers : ");
	scanf_s("%f, %f", &a, &b);
	(a == b) ?
		printf("a=b") :
		printf("a!=b");
	return 0;
}

