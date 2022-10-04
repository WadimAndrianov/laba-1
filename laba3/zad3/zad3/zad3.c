//Дан массив А размера n, не содержащий нулевых элементов. Необходимо получить массив А, в которой вначале идут положительные элементы, а затем отрицательные. 
#include <stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int a[100], i, n, h, pred_znach;
	printf("Введите размер массива = ");
	while (scanf_s("%d", &n) != 1 || n <= 0)
	{
		printf("Ошибка!");
		printf("\n");
		rewind(stdin);
		printf("Введите размер массива = ");
	}
	printf("Если хотите ввести свои значения - введите 1, если случайные - введите 0 :");
	while (scanf_s("%d", &h) != 1 || h != 1 && h!=0)
	{
		printf("Ошибка!");
		printf("\n");
		rewind(stdin);
		printf("Введите ещё раз = ");
	}
	if (h == 1)
	{
		
		for (i = 0; i < n; i++)
		{
			printf("a[%d] = ", i);
			while (scanf_s("%d", &a[i]) != 1 || a[i]==0)
			{

				printf("Ошибка!");
				printf("\n");
				rewind(stdin);
				printf("a[%d] = ", i);
			}
		}
	}
	else
	{
		srand(time(NULL));
		printf("Введите предел значений : ");
		while (scanf_s("%d", &pred_znach) != 1 || pred_znach <= 0)
		{
			printf("Ошибка");
			printf("\n");
			printf("Введите предел значений : ");
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
		for (i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				printf("%3d", a[i]);
			}
		}
		for (i = 0; i < n; i++)
		{
			if (a[i] < 0)
			{
				printf("%3d", a[i]);
			}
		}
	
	return 0;
}