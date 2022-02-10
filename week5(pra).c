#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int Insertion_Sort(int* arr, int n)
{
	int num=0;
	int allnum=0;
	int temp;
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >=0; j--)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				printf("부분정렬 완료된 범위(인덱스) : [%d ~ %d] \n", j, i);
			}
			num++;
		}

		printf("중간 결과 : ");
		for (int k = 0; k < n; k++)
		{
			printf("%d ", arr[k]);
		}
		printf("\n");

		printf("비교횟수 : %d \n", num);
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
	printf("배열에 저장할 정수 개수 입력 : ");
	scanf("%d", &n);

	srand(time(NULL));
	printf("-------------<정렬 전>--------------- \n");
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	allnum = Insertion_Sort(arr, n);
	printf("-------------<정렬 후>--------------- \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("총 비교 횟수 : %d \n", allnum);

}

int Bubble_Sort(int *arr, int n)
{
	int temp;
	int sorted;

	for (int i = n; i > 1; i--)
	{
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
		}
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
	printf("몇 개의 정수를 넣으시겠습니까? ");
	scanf("%d", &n);

	printf("-------------<정렬 전>--------------- \n");
	for (int i = 0; i < n; i++)
	{
		bubarr[i] = rand() % 100 + 1;
		printf("%d ", bubarr[i]);
	}
	printf("\n");

	sorted=Bubble_Sort(bubarr, n);
	
	printf("-------------<정렬 후>--------------- \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", bubarr[i]);
	}
	printf("\n");
	printf("\n");
	if (sorted == 1)
	{
		printf("정렬 조기 종료 \n");
	}
	else
		printf("정렬 완료 \n");

}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 삽입정렬 \n");
	printf("2. 버블정렬 \n");
	printf("0. 종료 \n");
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
		printf("메뉴 선택: ");
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
			printf("다시 입력하세요. \n");
			break;
		}
	}
}