#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int Insertion_Sort(int* arr, int n)
{
	int num = 0;
	int allnum = 0;
	int temp;
	int level = 1;
	int j;

	for (int i = 1; i < n; i++)
	{
		printf("%d�ܰ�>> \n", level);
		level += 1;
		temp = arr[i];
		for ( j = i - 1; j >= 0; j--)
		{
			num++;
			if (arr[j] > temp)
			{
				arr[j + 1] = arr[j];
			}
			else
				break;
		}

		arr[j + 1] = temp;

		printf("<< ");
		for (int k = 0; k < n; k++)
		{
			printf("%d ", arr[k]);
			if (k == i)
				printf(">> ");
		}
		printf("\n");

		printf("��Ƚ�� : %d \n", num);
		printf("\n");

		allnum += num;
		num = 0;
	}
	return allnum;
}
void Insertion_Sort_main()
{
	int arr[100] = { 0, };
	int n;
	int allnum = 0;
	printf("�迭�� ������ ���� ���� �Է� : ");
	scanf("%d", &n);

	srand(time(NULL));
	printf("-------------<������ ����>--------------- \n");
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	printf("-------------<���� ���� ����>--------------- \n");
	allnum = Insertion_Sort(arr, n);
	/*for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/

	printf("�� �� Ƚ�� : %d \n", allnum);
	allnum = 0;
}

int bubblenum;
int Bubble_Sort(int* arr, int n)
{
	int temp;
	int sorted;
	int level = 1;
	int num = 0;

	for (int i = n; i > 1; i--)
	{
		printf("%d�ܰ�>> \n", level);
		level += 1;
		sorted = 1;
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				sorted = 0;
			}

			for (int k = 0; k < n; k++)
			{
				printf("%d ", arr[k]);
				if (k == n-level+1)
					printf("| ");
			}
			printf("\n \n");
			num++;
		}

		printf("��Ƚ�� : %d \n", num);
		printf("\n");
		bubblenum += num;
		num = 0;

		if (sorted == 1)
		{
			return sorted;
		}
	}
}
void Bubble_Sort_main()
{
	int n;
	int bubarr[100] = { 0, };
	int sorted;

	srand(time(NULL));
	printf("�� ���� ������ �����ðڽ��ϱ�? ");
	scanf("%d", &n);

	printf("-------------<������ ����>--------------- \n");
	for (int i = 0; i < n; i++)
	{
		bubarr[i] = rand() % 100 + 1;
		printf("%d ", bubarr[i]);
	}
	printf("\n \n");

	printf("-------------<���� ���� ����>--------------- \n");
	sorted = Bubble_Sort(bubarr, n);
	printf("\n");
	if (sorted == 1)
	{
		printf("���� ���� \n");
	}

	else
		printf("���� �Ϸ� \n");

	printf("�� �� Ƚ�� : %d \n", bubblenum);
	bubblenum = 0;
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. �������� \n");
	printf("2. �������� \n");
	printf("0. ���� \n");
	printf("---------------------------------- \n");
	printf("\n");
}

int main(void)
{
	int choice;

	while (1)
	{
		menu();
		printf("\n");
		printf("�޴� ����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			Insertion_Sort_main();
			break;

		case 2:
			Bubble_Sort_main();
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}