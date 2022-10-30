//Дан массив А размера n, не содержащий нулевых элементов. Необходимо получить массив А, в которой вначале идут 
//положительные элементы, а затем отрицательные. 
#include <stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[100], i, n, h, p=0, pred_znach;
	printf("Enter size array = ");
	while (scanf_s("%d", &n) != 1 || n <= 0 || n>=100)
	{
		printf("error!");
		printf("\n");
		rewind(stdin);
		printf("Enter size array = ");
	}
	printf("If you want to enter your own values, enter 1, if random, enter 0 :");
	while (scanf_s("%d", &h) != 1 || h != 1 && h!=0)
	{
		printf("error!");
		printf("\n");
		rewind(stdin);
		printf("Enter again : ");
	}
	if (h == 1)
	{
		
		for (i = 0; i < n; i++)
		{
			printf("a[%d] = ", i);
			while (scanf_s("%d", &a[i]) != 1 || a[i]==0)
			{

				printf("error!");
				printf("\n");
				rewind(stdin);
				printf("a[%d] = ", i);
			}
		}
	}
	else
	{
		srand(time(NULL));
		printf("maximum value : ");
		while (scanf_s("%d", &pred_znach) != 1 || pred_znach <= 0)
		{
			printf("error");
			printf("\n");
			printf("maximum value : ");
			rewind(stdin);
		}
		for (i = 0; i < n; i++)
		{
			a[i] = (rand() % pred_znach) - (rand() % pred_znach);
		}
		for (i = 0; i < n; i++)
		{
			printf("%3d ", a[i]);
		}
	}
	printf("\n");
	for (i = 0;i < n;i++)
	{
		if (a[i] < 0)
		{
			p++;
		}
	}
	
		for (int h = 0; h < p; h++)
		{
			for (i = 0; i < n; i++)
			{
				if (a[i] < 0)
				{
					a[n] = a[i];
					for (int j = i; j < n; j++)
					{
						a[j] = a[j + 1];
					}
					break;
				}
			}
		}
	
		for (i = 0; i < n; i++)
		{
			printf("%3d", a[i]);
		}
	return 0;
}