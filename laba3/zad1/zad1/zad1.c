/*	� ���������� �������, ��������� �� n ������������ ���������, ���������:
-����� ������������� ��������� �������;
-������������ ��������� �������, ������������� ����� ������������ � ����������� ����������.*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include<time.h>
int main()
{
	setlocale(LC_ALL, "RUS");
	int a[100], i, j, pred_znach, n, sum = 0, ind_min_el, ind_max_el, p = 1, max_el, min_el, h;
	printf("������ ������� : ");
	while (scanf_s("%d", &n) != 1 || n <= 0)
	{
		printf("������");
		printf("\n");
		printf("������ ������� : ");
		rewind(stdin);
	} 
	printf("���� ������ ������ ���� ��������, �� ������� 1, ���� ���������, �� ������� 0 :");
	while (scanf_s("%d", &h) != 1 || h != 1 && h != 0)
	{
		printf("������");
		printf("\n");
		printf("������� ��� ��� :");
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
				printf("������!");
				printf("\n");
				printf("a[%d] = ", i);
				rewind(stdin);
			}
		}
	}
	else
	{//��������� �����
		srand(time(NULL));
		printf("������� ������ ��������� ����� : ");
		while (scanf_s("%d", &pred_znach) != 1 || pred_znach <= 0)
		{
			printf("������");
			printf("\n");
			printf("������� ������ ��������� ����� : ");
			rewind(stdin);
		}
		for (i = 0;i < n;i++)
		{
			a[i] = (rand() % pred_znach) - (rand() % pred_znach);
		}
	}
	//����� �������
	for(i = 0; i < n; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
	//����� ����� ������������� ��������
		for (i = 0;i < n;i++)
		{
			if (a[i] < 0)
			{
				sum = sum + a[i];
			}
		}
		printf("����� ������������� ����� = %d", sum);
		printf("\n");
		//������������ ����� ������������ � ����������� ���������
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

		if (ind_max_el < ind_min_el)
		{
			ind_max_el++;
			for (ind_max_el; ind_max_el < ind_min_el; ind_max_el++)
			{
				p = p * a[ind_max_el];
			}
			if (p == 1)
			{
				p = 0;
			}
			printf("������������ = %d", p);
			printf("\n");
		}
		if (ind_max_el > ind_min_el)
		{
			ind_min_el++;
			for (ind_min_el; ind_min_el < ind_max_el; ind_min_el++)
			{
				p = p * a[ind_min_el];
			}
			if (p == 1)
			{
				p = 0;
			}
			printf("������������ = %d", p);
			printf("\n");
		}
	return 0; 
}