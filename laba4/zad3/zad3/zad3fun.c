/*В квадратной матрице размером NxN найти сумму элементов в 1-ой области*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void fun_vvoda_n(int* p_n);
void fun_sposoba_vvoda(int* t);
void fun_vvod(int n, int** a);
int fun_sluch_vvod(int n, int** a[100][100], int pred_znach);
void fun_vivod(int n, int** a[100][100]);
void fun_summa(int n, int** a[100][100]);
int main()
{
	int n, pred_znach=0, t=0;
	int a[100][100];
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
	 fun_summa(n, a);
	return 0;
}
void fun_vvoda_n(int* p_n)
{
	printf("Enter the size of the square matrix :");
	while (scanf_s("%d", p_n) != 1 || *p_n <= 0 || *p_n > 100 || getchar() != '\n')
	{
		printf("error\n");
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
int fun_sluch_vvod(int n, int** a[100][100], int pred_znach)
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
	return 0;
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
void fun_summa(int n, int** a[100][100])
{
	int c = 0, p = 0;
	p = n;
	int x;
	int sum=0;
	for (int i = 0; i <= n / 2; i++)
	{
		for (int j = c; j < p; j++)
		{
			x = a[i][j];
			sum = sum + x;
		}
		c++;
		p--;
	}
	printf("Sum = %d", sum);
}