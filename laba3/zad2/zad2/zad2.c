//� ������� �� n ��������� ������� ��� ������ ��������
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int a[100], i, n, h, pred_znach;
	printf("������� ������ ������� = ");
	while (scanf_s("%d", &n) != 1 || n <= 0)
	{
		printf("������");
		printf("\n");
		printf("������� ������ ������� = ");
		rewind(stdin);
	}
	printf("���� ������ ������ ���� �������� - ������� 1, ���� ��������� - ������� 0 : ");
	while (scanf_s("%d", &h) != 1 || h != 1 && h != 0)
	{
		printf("������");
		printf("\n");
		printf("������� ��� ��� : ");
		rewind(stdin);
	}
	//���� ��������
	if (h == 1)
	{

		for (i = 0;i < n;i++)
		{
			printf("a[%d] = ", i);
			while (scanf_s("%d", &a[i]) != 1)
			{
				printf("������");
				printf("\n");
				printf("a[%d] = ", i);
				rewind(stdin);
			}
		}
	}
	//��������� ��������
	else
	{
		srand(time(NULL));
		printf("������� ������ �������� : ");
		while (scanf_s("%d", &pred_znach) != 1 || pred_znach <= 0)
		{
			printf("������");
			printf("\n");
			printf("������� ������ �������� : ");
			rewind(stdin);
		}
		for (i = 0; i < n; i++)
		{
			a[i] = (rand() % pred_znach) - (rand() % pred_znach);
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%3d ", a[i]);
	}
	printf("\n");
	//�������� ������ ���������
	for (i = 0;i < n;i++)
	{
		if (a[i] % 2 == 0 || a[i] == 0)
		{
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
			i--;
		}
	}

	for (i = 0;i < n;i++)
	{
		printf("%3d", a[i]);
	}

	return 0;
}