#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int part = 0;

void arr_merge(int* arr, int first, int mid, int last)
{
	int i = first, j = mid + 1, t = 0;
	int tmp[10] = { 0, };
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

	if (first < last)
	{
		mid = (first + last) / 2;
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, last);
		arr_merge(arr, first, mid, last);

		printf("-------------< 현재 단계 >--------------- \n");
		printf("<< ");
		for (int k = 0; k < 10; k++)
		{
			printf("%d ", arr[k]);
			if (k == last)
				printf(">> ");
		}
		printf("\n \n");
	}
}

void merge_sort_main()
{
	int arr[100] = { 0, };
	int first = 0;
	int last;
	int allnum = 0;
	printf("배열에 저장할 정수 개수 입력 : ");
	scanf("%d", &last);

	srand(time(NULL));
	printf("-------------< 정렬 전 >--------------- \n");
	for (int i = 0; i < last; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	merge_sort(arr, first, last-1);

	printf("-------------< 최 종 >--------------- \n");
	for (int i = 0; i < last; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int partition1(int* arr, int left, int right)  //마지막 값을 피봇으로
{
	int pivot = arr[right];
	int i = left-1;
	int temp;
	for (int j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	temp = arr[i + 1];
	arr[i + 1] = arr[right];
	arr[right] = temp;

	return i + 1;
}
int partition2(int* arr, int left, int right)  //첫번째 값을 피봇으로
{
	int pivot = arr[left];
	int i = right+1;
	int temp;
	for (int j = right; j > left; j--)
	{
		if (arr[j] > pivot)
		{
			i--;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	temp = arr[i - 1];
	arr[i - 1] = arr[left];
	arr[left] = temp;

	return i - 1;
}
int partition3(int* arr, int left, int right)  //중간값을 피봇으로
{
	int pivot = (left + right) / 2;
	int i = left;
	int j = right+1;
	int temp;

	while (i < j)
	{
		while (arr[i] < arr[pivot] && i < j)
			i++;
		
		while (arr[j] >= arr[pivot] && i < j)
			j--;

		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;

	return j;
}

void quick_sort(int *arr,int left, int right)
{
	int q;

	if (left < right)
	{
		switch (part)
		{
		case 1:
			q = partition3(arr, left, right);
			break;

		case 2:
			q = partition3(arr, left, right);
			break;

		case 3:
			q = partition3(arr, left, right);
			break;

		default:
			printf("다시 입력");
			break;

		}
		//q = partition3(arr, left, right);
		quick_sort(arr, left, q - 1);
		quick_sort(arr, q+1, right);

		printf("-------------< 현재 단계 >--------------- \n");
		for (int k = 0; k < 10; k++)
		{
			printf("%d ", arr[k]);
		}
		printf("\n \n");
	}
}

void quick_sort_main()
{
	int arr[100] = { 0, };
	int left = 0;
	int right;
	int allnum = 0;
	printf("배열에 저장할 정수 개수 입력 : ");
	scanf("%d", &right);

	srand(time(NULL));
	printf("-------------< 정렬 전 >--------------- \n");
	for (int i = 0; i < right; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	printf("파티션 선택 (1. 끝값, 2. 첫값, 3. 중간값) : ");
	scanf("%d", &part);

	quick_sort(arr, left, right-1);

	printf("-------------< 최 종 >--------------- \n");
	for (int i = 0; i < right; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 병합정렬 \n");
	printf("2. 퀵정렬 \n");
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
			quick_sort_main();
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}