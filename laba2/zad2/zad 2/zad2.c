#include <stdio.h>
int main()
{
	int n, i, j, k;
	printf("Enter number : ");
	if (scanf_s("%d", &n) == 1)
	{
		i = 0;
		k = 0;
		while (i * i * i < n)
		{
			j = 0;
			while (j * j * j < n && j <= i)
			{
				j++;
				if (j * j * j + i * i * i == n)
				{
					k++;
				}
				
			}
			i++;
		}
		j = 0;
		i = 0;
		while (i * i * i < n)
		{
			i++;
			if (i* i* i == n) {
				k++;
			}
		}
		printf("k = %d", k);
		return 0;
	}
	else
		printf("Error ");
	return 0;
}