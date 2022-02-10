#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int range = 0;
int heapnum = 0;

void arr_merge(int* arr, int first, int mid, int last)
{
	int i = first, j = mid + 1, t = 0;
	int tmp[100] = { 0, };
	while (i <= mid && j <= last)
	{
		if (arr[i] <= arr[j])
		{
			tmp[t++] = arr[i++];
		}

		else
		{
			tmp[t++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		tmp[t++] = arr[i++];
	}

	while (j <= last)
	{
		tmp[t++] = arr[j++];
	}

	i = first;
	t = 0;
	while (i <= last)
		arr[i++] = tmp[t++];

}

void merge_sort(int* arr, int first, int last)
{
	int mid;
	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (first < last)
	{
		mid = (first + last) / 2;
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, last);
		arr_merge(arr, first, mid, last);

		for (int k = 0; k < range; k++)
		{
			if (k == first) {
				SetConsoleTextAttribute(h_console, 0x000C);
			}

			printf("%d ", arr[k]);
			if (k == last) {
				SetConsoleTextAttribute(h_console, 0x7);
			}
		}
		printf("\n \n");
	}
}

void merge_sort_main()
{
	int arr[100] = { 0, };
	int first = 0;
	int last;
	
	printf("배열에 저장할 정수 개수 입력 : ");
	scanf("%d", &last);

	range = last;

	srand(time(NULL));
	printf("-------------< 정렬 전 >--------------- \n");
	for (int i = 0; i < last; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	printf("-------------< 병합 과정 >--------------- \n");
	merge_sort(arr, first, last - 1);

	printf("-------------< 최 종 >--------------- \n");
	for (int i = 0; i < last; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	range = 0;
}

void heapify(int* arr, int root, int n)       //힙 성질을 만족하도록 수선
{
	int left = root * 2;            //왼쪽 자식
	int right = (root * 2) + 1;     //오른쪽 자식
	int larger = root;
	int temp;

	if (right <= n)                 //자식이 두 개일 경우 더 큰 자식 선택
	{
		if (arr[left] > arr[right])
			larger = left;
		else
			larger = right;
	}

	else if (left <= n)             //왼쪽 자식만 있는 경우
	{
		larger = left;
	}

	else
		return;

	if (arr[larger] > arr[root])
	{
		temp = arr[root];
		arr[root] = arr[larger];
		arr[larger] = temp;
		heapify(arr, larger, n);
	}

	heapnum += 1;
}

void buildheap(int* arr, int n)       //배열을 힙으로 만드는 함수
{
	printf("-------------<buildheap_test>--------------- \n");
	for (int i = n / 2; i >= 1; i--)
	{
		heapify(arr, i, n);

		for (int k = 1; k <= n; k++)
		{
			printf("%d ", arr[k]);
		}
		printf("\n \n");
	}
}

void heap_sort(int* arr, int n)
{
	int temp;

	buildheap(arr, n);

	printf("-------------<heap_sort_test>--------------- \n");
	for (int i = n; i >= 2; i--)
	{
		temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		heapify(arr, 1, i - 1);


		for (int k = i; k >= 1; k--)
		{
			printf("%d ", arr[k]);
		}
		printf("\n \n");
	}
}

void heap_sort_main()
{
	int arr[100] = { 0, };
	int n;
	printf("배열에 저장할 정수 개수 입력 : ");
	scanf("%d", &n);

	srand(time(NULL));
	arr[0] = NULL;

	printf("-------------<정렬할 원소>--------------- \n");
	for (int i = 1; i <= n; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	heap_sort(arr, n);

	printf("-------------<힙 정렬 완성>--------------- \n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	printf("heapify 비교횟수 : %d \n", heapnum);
	heapnum = 0;
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 병합정렬 \n");
	printf("2. 최대힙정렬 \n");
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
			merge_sort_main();
			break;

		case 2:
			heap_sort_main();
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}