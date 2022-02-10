#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct element {
	int key;
}element;

typedef struct heaptype {
	element heap[100];
	int heapsize;
}heaptype;

heaptype* create()
{
	return (heaptype*)malloc(sizeof(heaptype));
}

void init(heaptype *h)
{
	h->heapsize = 0;
}

void insert_max_heap(heaptype* h, element item)
{
	int i;
	i = ++(h->heapsize);

	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(heaptype* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heapsize)--];
	parent = 1;
	child = 2;

	while (child <= h->heapsize)
	{
		if ((child < h->heapsize) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;

		if (temp.key >= h->heap[child].key)
			break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void queue_heap_sort(element *list, int n)
{
	int i;
	heaptype* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++)
	{
		insert_max_heap(h, list[i]);
		
	}
	printf("\n \n");
	//printf("-------------<insert_max_heap_test>--------------- \n");
	

	for (i = (n - 1); i >= 0; i--)
	{
		list[i] = delete_max_heap(h);
		
	}
	free(h);
}

void queue_heap_sort_main()
{
	element list[100] = { 0, };
	int n;
	printf("�迭�� ������ ���� ���� �Է� : ");
	scanf("%d", &n);

	srand(time(NULL));

	printf("-------------<������ ����>--------------- \n");
	for (int i = 0; i < n; i++)
	{
		list[i].key = rand() % 101;
		printf("%d ", list[i].key);
	}
	printf("\n \n");

	queue_heap_sort(list, n);

	printf("-------------<�� ���� �ϼ�>--------------- \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", list[i].key);
	}
	printf("\n \n");
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
}

void buildheap(int *arr, int n)       //�迭�� ������ ����� �Լ�
{
	printf("-------------<buildheap_test>--------------- \n");
	for (int i = n/2; i >= 1; i--)
	{
		heapify(arr, i, n);

		for (int k = 1; k <= n; k++)
		{
			printf("%d ", arr[k]);
		}
		printf("\n \n");
	}
}

void heap_sort(int *arr, int n)
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
			printf("%d ",arr[k]);
		}
		printf("\n");
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

}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. �ִ������� \n");
	printf("2. �ִ�������(�켱���� ť) \n");
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
			heap_sort_main();
			break;

		case 2:
			queue_heap_sort_main();
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}