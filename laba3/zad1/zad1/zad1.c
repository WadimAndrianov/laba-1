/*	В одномерном массиве, состоящем из n вещественных элементов, вычислить:
-сумму отрицательных элементов массива;
-произведение элементов массива, расположенных между максимальным и минимальным элементами.*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include<time.h>
int main()
{
	int a[100], i, j, pred_znach, n, sum = 0, ind_min_el, ind_max_el, p = 1, max_el, min_el, h;
	printf("Enter size array = ");
	while (scanf_s("%d", &n) != 1 || n <= 0 || n >= 100)
	{
		printf("error");
		printf("\n");
		printf("Enter size array = ");
		rewind(stdin);
	} 
	printf("If you want to enter your own values, enter 1, if random, enter 0 :");
	while (scanf_s("%d", &h) != 1 || h != 1 && h != 0)
	{
		printf("error");
		printf("\n");
		printf("Enter again :");
		rewind(stdin);
	}
	//свои значения
	if (h == 1)
	{
		for (i = 0;i < n;i++)
		{
			printf("a[%d] = ", i);
			while (scanf_s("%d", &a[i]) != 1)
			{
				printf("error!");
				printf("\n");
				printf("a[%d] = ", i);
				rewind(stdin);
			}
		}
	}
	else
	{//Случайные числа
		srand(time(NULL));
		printf("maximum value :  ");
		while (scanf_s("%d", &pred_znach) != 1 || pred_znach <= 0)
		{
			printf("error");
			printf("\n");
			printf("maximum value : ");
			rewind(stdin);
		}
		for (i = 0;i < n;i++)
		{
			a[i] = (rand() % pred_znach) - (rand() % pred_znach);
		}
	}
	//Вывод массива
	for(i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
	// сумма отрицательных значений
		for (i = 0;i < n;i++)
		{
			if (a[i] < 0)
			{
				sum = sum + a[i];
			}
		}
		printf("Sum of negative numbers = %d", sum);
		printf("\n");
		//Произведение между максимальным и минимальным элементов
		ind_max_el = 0;
		max_el = a[0];
		for (i = 0; i < n; i++)
		{
			if (a[i] > max_el)
			{
				max_el = a[i];
				ind_max_el = i;

			}
		}
		ind_min_el = 0;
		min_el = a[0];
		for (j = 0; j < n; j++)
		{
			if (a[j] < min_el)
			{
				min_el = a[j];
				ind_min_el = j;
			}
		}
		if (ind_max_el - ind_min_el == 1 || ind_max_el - ind_min_el == -1)
		{
			p = 0;
		}
		if (ind_max_el < ind_min_el)
		{
			ind_max_el++;
			for (ind_max_el; ind_max_el < ind_min_el; ind_max_el++)
			{
				p = p * a[ind_max_el];
			}
			printf("Composition = %d", p);
			printf("\n");
		}
		if (ind_max_el > ind_min_el)
		{
			ind_min_el++;
			for (ind_min_el; ind_min_el < ind_max_el; ind_min_el++)
			{
				p = p * a[ind_min_el];
			}
			
			printf("Composition = %d", p);
			printf("\n");
		}
	return 0; 
}