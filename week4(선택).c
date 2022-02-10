#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Listnode {
	int data;
	struct Listnode* link;
}Listnode;

void print_list(Listnode* head)
{
	for (Listnode* p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

Listnode* insert(Listnode* head, int data)
{
	Listnode* p = (Listnode*)malloc(sizeof(Listnode));

	p->data = data;
	p->link = head;
	head = p;
	return head;
}

void Swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

Listnode* List_Selection(Listnode *head1, int n)
{
	Listnode* maxi;
	Listnode* cur;
	Listnode* p = head1;
	int i = 1;
	int cnt = 0;
	int allcnt = 0;

	for (Listnode* q = head1; q != NULL; q = q->link)
	{
		cur = p->link;
		maxi = p;
		for (Listnode* h = q->link; h !=NULL; h=h->link)
		{
			cnt++;
			if (cur->data > maxi->data)
			{
				maxi = cur;
			}
			cur = cur->link;
			allcnt++;
		}


		Swap(&maxi->data, &p->data);
		printf("%d단계 : ", i);
		print_list(head1);
		printf("%d 단계의 비교 횟수 : %d \n", i, cnt);
		//Sleep(500);
		cnt = 0;
		printf("\n");
		p = p->link;
		i++;
	}
	printf("총 비교 횟수 : %d \n", allcnt);
	return head1;
}
void List_Selection_main()
{
	int n;
	Listnode* head = NULL;

	printf("리스트에 입력할 수 설정 : ");
	scanf("%d", &n);
	printf("현재 : ");
	for (int i = 0; i < n; i++)
	{
		head=insert(head, rand() % 101);
	}
	print_list(head);

	head=List_Selection(head,n);
	printf("selection : ");
	print_list(head);

}


int Selection(int *arr, int n)
{
	int temp;
	int cnt = 0;
	int allcnt = 0;
	int l = 1;

	for (int i = 0; i < n; i++)
	{

		for (int j = i+1; j < n; j++)
		{
			cnt++;
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				printf("%d 단계 : ", l);
				for (int k = 0; k < n; k++)
				{
					printf(" %d ", arr[k]);
				}
				printf("\n");
				printf("%d 단계의 비교 횟수 : %d \n", l, cnt);
				l++;
				//Sleep(500);
				printf("\n");
			}
			allcnt++;
		}
		cnt = 0;
	}
	printf("총 비교 횟수 : %d \n", allcnt);
}
void Selection_main()
{
	int arr[100] = { 0, };
	int n;
	srand(time(NULL));

	printf("배열에 입력할 정수 설정 : ");
	scanf("%d", &n);

	printf("배열에 %d개만큼의 정수 랜덤 저장: ", n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("\n");
	Selection(arr, n);
	printf("최종 : ");
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 선택 정렬 \n");
	printf("2. 연결리스트 선택 정렬 \n");
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
			Selection_main();
			break;

		case 2:
			List_Selection_main();
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}