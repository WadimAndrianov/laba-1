
/*Двумерный массив, содержащий равное число строк и столбцов, называется магическим квадратом, если суммы чисел,
записанных в каждой строке, каждом столбце и каждой из двух больших диагоналей, равны одному и тому же числу.
Определить, является ли данный массив А из n строк и n столбцов магическим квадратом.*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void fun_vvoda_n(int *p_n);
void fun_sposoba_vvoda(int* t);
void fun_vvod(int n, int** a);
void fun_sluch_vvod(int n, int** a[100][100], int pred_znach);
void fun_vivod(int n, int** a[100][100]);
void fun_sum_glav_diog(int n, int** a[100][100], int *p_sum_glav_diog);
void fun_sum_vtor_diog(int n, int** a[100][100], int *p_sum_vtor_diog);
void fun_sum_stolbca(int n, int** a[100][100], int sum_stolbca, int* h, int p_sum_glav_diog);
void fun_sum_stroki(int n, int** a[100][100], int sum_stroki, int* h, int sum_glav_diog);
int main()
{
	int a[100][100];
	int n=0, pred_znach = 0, sum_stroki = 0, sum_stolbca = 0, sum_glav_diog = 0, sum_vtor_diog = 0, h = 1, t;
	fun_vvoda_n(&n);
	fun_sposoba_vvoda(&t);
	if (t == 1)
	{
		fun_vvod(n, a);
	}
	else
	{
		fun_sluch_vvod(n, a, pred_znach);
	}
	fun_vivod(n, a);
	fun_sum_vtor_diog(n, a, &sum_vtor_diog);
	fun_sum_glav_diog(n, a, &sum_glav_diog);
	fun_sum_stolbca(n, a, sum_stolbca, &h, sum_glav_diog);
	fun_sum_stroki(n, a, sum_stroki, &h, sum_glav_diog);
	if ( h == 1 && sum_vtor_diog == sum_glav_diog)
	{
		printf("matrix is magical");
	}
	else
	{
		printf("matrix is not magical");
	}

	return 0;
}
//ФУНКЦИИ
void fun_vvoda_n(int* p_n)
{
	printf("Enter the size of the square matrix :");
	while (scanf_s("%d", p_n) != 1 || *p_n <= 0 || *p_n > 100 || getchar() != '\n')
	{
		printf("error!\n");
		printf("Enter the size of the square matrix :");
		rewind(stdin);
	}
}
void fun_sposoba_vvoda(int* t)
{
	printf("If you want to enter your own values, enter 1, if random, enter 0 :");
	while (scanf_s("%d", t) != 1 || *t != 1 && *t != 0 || getchar() != '\n')
	{
		printf("error\n");
		printf("If you want to enter your own values, enter 1, if random, enter 0 :");
		rewind(stdin);
	}
}
	void fun_vvod(int n, int** a[100][100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			while (scanf_s("%d", &a[i][j]) != 1 || getchar() != '\n')
			{
				printf("error\n");
				printf("a[%d][%d] = ", i, j);
				rewind(stdin);
			}
		}
	}
}
void fun_sluch_vvod(int n, int** a[100][100], int pred_znach)
{
	srand(time(NULL));
	printf("Enter the random number limit : ");
	while (scanf_s("%d", &pred_znach) != 1 || pred_znach <= 0 || getchar() != '\n')
	{
		printf("error\n");
		printf("Enter the random number limit : ");
		rewind(stdin);
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			{
				a[i][j] = (rand() % pred_znach) - (rand() % pred_znach);
			}
		}
	}
}
void fun_vivod(int n, int** a[100][100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}

}
void fun_sum_glav_diog(int n, int** a[100][100], int* p_sum_glav_diog)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				x = a[i][j];
				*p_sum_glav_diog = *p_sum_glav_diog + x;
			}
		}
	}
}
void fun_sum_vtor_diog(int n, int** a[100][100], int* p_sum_vtor_diog)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j == n - 1)
			{
				x = a[i][j];
				*p_sum_vtor_diog = *p_sum_vtor_diog + x;
			}
		}
	}
}
void fun_sum_stolbca(int n, int** a[100][100], int sum_stolbca, int* p_h, int sum_glav_diog)
{
	int x;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			x = a[i][j];
			sum_stolbca = sum_stolbca + x;
		}
		if (sum_stolbca != sum_glav_diog)
		{
			*p_h = 0;
		}	
		sum_stolbca = 0;
	}
}
void fun_sum_stroki(int n, int** a[100][100], int sum_stroki, int* p_h, int sum_glav_diog)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x = a[i][j];
			sum_stroki = sum_stroki + x;
		}
		if (sum_stroki != sum_glav_diog)
		{
			*p_h = 0;
		}
		sum_stroki = 0;
	}
}
