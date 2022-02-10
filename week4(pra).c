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
	printf("배열에 저장할 정수 개수 입력 : ");
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
	printf("1. 삽입정렬 \n");
	printf("2. 병합정렬 \n");
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
			
			break;

		case 2:
			
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}