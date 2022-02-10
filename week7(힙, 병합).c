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
	
	printf("�迭�� ������ ���� ���� �Է� : ");
	scanf("%d", &last);

	range = last;

	srand(time(NULL));
	printf("-------------< ���� �� >--------------- \n");
	for (int i = 0; i < last; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	printf("-------------< ���� ���� >--------------- \n");
	merge_sort(arr, first, last - 1);

	printf("-------------< �� �� >--------------- \n");
	for (int i = 0; i < last; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	range = 0;
}

void heapify(int* arr, int root, int n)       //�� ������ �����ϵ��� ����
{
	int left = root * 2;            //���� �ڽ�
	int right = (root * 2) + 1;     //������ �ڽ�
	int larger = root;
	int temp;

	if (right <= n)                 //�ڽ��� �� ���� ��� �� ū �ڽ� ����
	{
		if (arr[left] > arr[right])
			larger = left;
		else
			larger = right;
	}

	else if (left <= n)             //���� �ڽĸ� �ִ� ���
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

void buildheap(int* arr, int n)       //�迭�� ������ ����� �Լ�
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
	printf("�迭�� ������ ���� ���� �Է� : ");
	scanf("%d", &n);

	srand(time(NULL));
	arr[0] = NULL;

	printf("-------------<������ ����>--------------- \n");
	for (int i = 1; i <= n; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	heap_sort(arr, n);

	printf("-------------<�� ���� �ϼ�>--------------- \n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	printf("heapify ��Ƚ�� : %d \n", heapnum);
	heapnum = 0;
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. �������� \n");
	printf("2. �ִ������� \n");
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
			merge_sort_main();
			break;

		case 2:
			heap_sort_main();
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}