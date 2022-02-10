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

//�ʱ�ȭ
void init(ListType * p)
{
	p->front = 0;
	p->end = 0;
}

//���� Ȯ�� �Լ�
int Is_Empty(ListType * p)
{
	return (p->front == NULL);
}

//���� �Լ�
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

//���� �Լ�
element Dequeue(ListType* q)
{
	Listnode* temp = q->front;
	element data;
	if (Is_Empty(q))
	{
		fprintf(stderr, "������� \n");
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

//��� �Լ�
void print_queue(ListType* q)
{
	Listnode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

//��� ����
int len;
void radixsort(ListType *q, int num)       //���� ����
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
				//����Ʈ ù ������ �ٽ� ä���
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
	printf("1. ���� ���� Ȯ�� \n");
	printf("2. ���� \n");
	printf("3. ���� \n");
	printf("4. ���� \n");
	printf("0. ���� \n");
	printf("---------------------------------- \n");
	printf("\n");
}


int main(void)
{
	int choice;
	int temp;
	int n;
	ListType* queue;      //�̰� ����
	init(&queue);

	printf("--------------<�ʱ� ���Ḯ��Ʈ ����>--------------\n");
	printf("�� ���� ����Ʈ�� �����Ͻðڽ��ϱ�? : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("%d��° ����Ʈ : ", (i + 1));
		scanf("%d", &temp);
		enqueue(&queue, temp);
	}
	len = n;

	while (1)
	{
		menu();
		printf("\n");
		printf("�޴� ����: ");
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
			printf("���� ����Ʈ �Է� : ");
			scanf("%d", &temp);
			enqueue(&queue, temp);
			len += 1;
			break;

		case 4:

			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}