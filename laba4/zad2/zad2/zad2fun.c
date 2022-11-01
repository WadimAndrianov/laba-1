#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void fun_vvod_n_m(int *n, int *m);
void fun_sposoba_vvoda(int* t);
void fun_vvod(int n, int m, int** a[100][100]);
int fun_sluch_vvod(int n, int m, int** a[100][100], int pred_znach);
void fun_vivod(int n, int m, int** a[100][100]);
void fun_stroki(int n, int m, int** a[100][100], int *sum);
void fun_matr_new(int n, int m, int** a[100][100], int* sum);
int main()
{
	int a[100][100];
	int sum_stroki = 0, n=0, m=0, t=0, pred_znach = 0;
	fun_vvod_n_m(&n, &m);
	fun_sposoba_vvoda(&t);
	if (t == 1)
	{ //Ввод своих значений
		fun_vvod(n, m, a);
	}
	else
	{//Ввод случайных значений

		fun_sluch_vvod(n, m, a, pred_znach);
	}
	//Вывод исходного массива
	fun_vivod(n, m, a);
	fun_stroki(n, m, a, &sum_stroki);
	if (sum_stroki > 0)
	{
		fun_matr_new(n, m, a, &sum_stroki);
		fun_vivod(n, m, a);
	}
	else
	{
		printf("There are no rows with exclusively positive elements in the matrix\n");
	}
	return 0;
}
//ФУНКЦИИ

void fun_vvod_n_m(int* n, int *m)
{
	printf("Enter the number of rows of the matrix :");
	while (scanf_s("%d", n) != 1 || *n <= 0 || *n > 100 || getchar() != '\n')
	{
		printf("error\n");
		printf("Enter the number of rows of the matrix :");
		rewind(stdin);
	}
	printf("Enter the number of columns of the matrix :");
	while (scanf_s("%d", m) != 1 || *m <= 0 || *m > 100 || getchar() != '\n')
	{
		printf("error\n");
		printf("Enter the number of columns of the matrix :");
		rewind(stdin);
	}

}
void fun_sposoba_vvoda(int* t)
{
	printf("If you want to enter your own values - enter 1, if random - 0: ");
	while (scanf_s("%d", t) != 1 || *t != 1 && *t != 0 || getchar() != '\n')
	{
		printf("error\n");
		printf("If you want to enter your own values - enter 1, if random - 0: ");
		rewind(stdin);
	}
}
void fun_vvod(int n, int m, int** a[100][100])
{
	for (int i = 0;i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("a[%d][%d] = ", i, j);
			while (scanf_s("%d", &a[i][j]) != 1 || getchar() != '\n')
			{
				printf("error!\n");
				printf("a[%d][%d] = ", i, j);
				rewind(stdin);
			}
		}
	}
}
int fun_sluch_vvod(int n, int m, int** a[100][100], int pred_znach)
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
		for (int j = 0; j < m; j++)
		{
			
				a[i][j] = (rand() % pred_znach) - (rand() % pred_znach);
			
		}
	}
	return 0;
}
void fun_vivod(int n, int m, int** a[100][100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}
void fun_stroki(int n, int m, int* a[100], int* sum)
{
	int x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x = a[i * 100 + j];
			*sum = *sum + x;
			if (x <= 0)
			{
				*sum = 0;
				break;
			}
		}
		if (*sum > 0)
		{
			break;
		}
	}
}
	void fun_matr_new(int n, int m, int**a[100][100], int* sum)
	{
		int x;
		printf("Line amount = %d\n", *sum);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				x = a[i][j];
				x = x - *sum;
				a[i][j] = x;
			}
		}
	}


