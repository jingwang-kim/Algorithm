#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int range = 0;
int level = 1;

int partition1(int* arr, int left, int right)  //������ ���� �Ǻ�����
{
	printf("-------------< %d�ܰ� >--------------- \n", level);

	int pivot = right;
	int i = left - 1;
	int temp;
	for (int j = left; j < right; j++)
	{
		for (int k = 0; k < range; k++)
		{
			if (k == pivot)
				printf("[ %d ] ", arr[k]);
			else
				printf(" %d ", arr[k]);
		}
		printf("\n \n");

		if (arr[j] < arr[pivot])
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

	printf("-------------< %d�ܰ� ��>--------------- \n", level);
	for (int k = 0; k < range; k++)
	{
		if (k == pivot)
			printf("[ %d ] ", arr[k]);
		else
			printf(" %d ", arr[k]);
	}
	printf("\n");

	printf("pivot : %d \n", arr[pivot]);
	printf("\n");
	
	level++;
	return i + 1;
}
int partition2(int* arr, int left, int right)  //ù��° ���� �Ǻ�����
{
	printf("-------------< %d�ܰ� >--------------- \n", level);



	int pivot = left;
	int i = right + 1;
	int temp;
	for (int j = right; j > left; j--)
	{

		for (int k = 0; k < range; k++)
		{
			if (k == pivot)
				printf("[ %d ] ", arr[k]);
			else
				printf(" %d ", arr[k]);
		}
		printf("\n \n");

		if (arr[j] > arr[pivot])
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

	printf("-------------< %d�ܰ� ��>--------------- \n", level);
	for (int k = 0; k < range; k++)
	{
		if (k == pivot)
			printf("[ %d ] ", arr[k]);
		else
			printf(" %d ", arr[k]);
	}
	printf("\n");
	printf("pivot : %d \n", arr[pivot]);
	printf("\n");

	level++;
	return i - 1;
}
int partition3(int* arr, int left, int right)  //�߰����� �Ǻ�����
{
	printf("-------------< %d�ܰ� >--------------- \n", level);

	int pivot = (left + right) / 2;
	int value = arr[pivot];
	int i = left;
	int j = right;
	int temp;

	while (i < j)
	{
		for (int k = 0; k < range; k++)
		{
			if (k == pivot)
				printf("[ %d ] ", arr[k]);
			else
				printf(" %d ", arr[k]);
		}
		printf("\n \n");

		while (arr[i] < value && i < j)
			i++;

		while (arr[j] >= value && i < j)
			j--;

		if (i < j )
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		if(arr[i]==value || arr[j]==value)     //���� �ڵ�~ 
		{
			for (int t = 0; t < range; t++)    //��� �ɾ����� ������ �ǹ��� ���� ���� �𸣱� ������ ���� i�� j��° �ε�����
			{                                  //�ִ� ������ �ǹ��� value�� ���ٸ� �迭�ȿ� value�� ���� ���� �ε����� ã�Ƽ�
				if (value == arr[t])           //�� ���� �ǹ����� ��ȯ�Ѵ�.
				{
					pivot = t;
				}
			}
		}                                      //~����
	}

	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;

	printf("-------------< %d�ܰ� ��>--------------- \n", level);
	for (int k = 0; k < range; k++)
	{
		if (k == pivot)
			printf("[ %d ] ", arr[k]);
		else
			printf(" %d ", arr[k]);
	}
	printf("\n");
	printf("pivot : %d \n", arr[pivot]);
	printf("\n");

	level++;
	return j;
}

void quick_sort1(int* arr, int left, int right)
{
	if (left < right)
	{
		int q = partition1(arr, left, right);
		quick_sort1(arr, left, q - 1);
		quick_sort1(arr, q + 1, right);
	}
}

void quick_sort2(int* arr, int left, int right)
{
	if (left < right)
	{
		int q = partition2(arr, left, right);
		quick_sort2(arr, left, q - 1);
		quick_sort2(arr, q + 1, right);
	}
}

void quick_sort3(int* arr, int left, int right)
{
	if (left < right)
	{
		int q = partition3(arr, left, right);
		quick_sort3(arr, left, q - 1);
		quick_sort3(arr, q + 1, right);
	}
}

void quick_sort_main()
{
	//�迭 ����
	int arr[100] = { 0, };
	int left = 0;
	int right;
	int part = 0;
	printf("�迭�� ������ ���� ���� �Է� : ");
	scanf("%d", &right);
	range = right;

	//arr�� �� �Է�
	srand(time(NULL));
	printf("-------------< ���� �� >--------------- \n");
	for (int i = 0; i < right; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	//��Ƽ�� ���� �� quick_sort����
	printf("��Ƽ�� ���� ( 1. ����, 2. ù��, 3. �߰��� ) : ");
	scanf("%d", &part);
	
	switch (part)
	{
	case 1:
		quick_sort1(arr, left, right - 1);
		break;

	case 2:
		quick_sort2(arr, left, right - 1);
		break;

	case 3:
		quick_sort3(arr, left, right - 1);
		break;

	default:
		printf("�Է� ����.\n");
		break;
	}
	

	//���� ���
	printf("-------------< �� �� >--------------- \n");
	for (int i = 0; i < right; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	range = 0;
	level = 1;
}

int main(void)
{
	printf("\n");
	printf("-------------< ������ >--------------- \n");
	printf("\n");

	int choice;
	quick_sort_main();

	do {

		printf("\n");
		printf("�ٽ� �����Ͻðڽ��ϱ�? (1.Yes 0.No) : ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			quick_sort_main();
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	} while (1);

}