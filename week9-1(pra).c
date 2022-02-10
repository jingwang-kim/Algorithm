#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define BUCKET_NUM 10

typedef int element;
typedef struct Listnode {
	element data;
	struct Listnode* link;
}Listnode;

typedef struct ListType {
	Listnode* front;
	Listnode* end;
}ListType;

//초기화
void init(ListType * p)
{
	p->front = 0;
	p->end = 0;
}

//공백 확인 함수
int Is_Empty(ListType * p)
{
	return (p->front == NULL);
}

//삽입 함수
void enqueue(ListType* q, element item)
{
	Listnode* temp = (Listnode*)malloc(sizeof(Listnode));
	temp->data = item;
	temp->link = NULL;
	if (Is_Empty(q))
	{
		q->front = temp;
		q->end = temp;
	}
	else
	{
		q->end->link = temp;
		q->end = temp;
	}
}

//삭제 함수
element Dequeue(ListType* q)
{
	Listnode* temp = q->front;
	element data;
	if (Is_Empty(q))
	{
		fprintf(stderr, "비어있음 \n");
		exit(1);
	}

	else
	{
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->end = NULL;
		free(temp);
		return data;
	}
}

//출력 함수
void print_queue(ListType* q)
{
	Listnode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

//기수 정렬
int len;
void radixsort(ListType *q, int num)       //여기 수정
{
	ListType bucket[BUCKET_NUM];
	int radix;
	int a = 1;

	for (int i = 0; i < BUCKET_NUM; i++)
		init(&bucket[i]);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < num; j++)
		{
			radix = (q->end->data / a) % 10;
			enqueue(&bucket[radix], q->end->data);
		}

		for (int k = 0; k < BUCKET_NUM; k++)
		{
			while (!Is_Empty(&bucket[k]))
			{
				//리스트 첫 값부터 다시 채우기
				init(&q);
				if (Is_Empty(q))
				{
					q->front = Dequeue(&bucket[k]);
					q->end = Dequeue(&bucket[k]);
				}
				else
				{
					q->end->link = Dequeue(&bucket[k]);
					q->end = Dequeue(&bucket[k]);
				}
				/*q->end = Dequeue(&bucket[k]);
				q = q->end->link;*/
			}
		}

		a *= 10;
	}
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 현재 상태 확인 \n");
	printf("2. 정렬 \n");
	printf("3. 삽입 \n");
	printf("4. 삭제 \n");
	printf("0. 종료 \n");
	printf("---------------------------------- \n");
	printf("\n");
}


int main(void)
{
	int choice;
	int temp;
	int n;
	ListType* queue;      //이거 수정
	init(&queue);

	printf("--------------<초기 연결리스트 생성>--------------\n");
	printf("몇 개의 리스트를 생성하시겠습니까? : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 리스트 : ", (i + 1));
		scanf("%d", &temp);
		enqueue(&queue, temp);
	}
	len = n;

	while (1)
	{
		menu();
		printf("\n");
		printf("메뉴 선택: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			print_queue(&queue);
			break;

		case 2:
			radixsort(&queue, n);
			break;

		case 3:
			printf("넣을 리스트 입력 : ");
			scanf("%d", &temp);
			enqueue(&queue, temp);
			len += 1;
			break;

		case 4:

			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}