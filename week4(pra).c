#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int Insertion_Sort(int *arr, int n)
{
	int temp;
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{

			}
		}
	}
}

void Insertion_Sort_main()
{
	int arr[100] = { 0, };
	int n;
	printf("�迭�� ������ ���� ���� �Է� : ");
	scanf("%d", &n);

	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n");

	Insertion_Sort(arr, n);

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
			
			break;

		case 2:
			
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}