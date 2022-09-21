#include <stdio.h>
int main()
{
	double sum;
	sum = 0;
	int n=1;
	while ( sum < 5)
	{
		
		sum = sum + (1./n);
		n++;
	}
	printf("n = - %d\n", n);
	printf("sum = %lf", sum);
	
	return 0;
}