#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define BUCKET_NUM 10

typedef struct Listnode {
	int data;
	struct Listnode* front;
	struct Listnode* end;
}Listnode;

//��� �Լ�
void print_list(Listnode* head)
{
	Listnode* p;
	for (p = head; p != NULL; p = p->front)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

//���� �Լ�
Listnode* insert(Listnode *head, int value)
{
	Listnode* p = (Listnode*)malloc(sizeof(Listnode));
	Listnode* pre = (Listnode*)malloc(sizeof(Listnode));
	if (head == NULL)
	{
		p->data = value;
		p->front = head;
		head = p;
		head->end = p;
	}

	else
	{
		pre = head;
		while (pre->front != NULL)
			pre = pre->front;

		p->data = value;
		p->front = NULL;
		pre->front = p;
		head->end = p;
	}
	return head;
}

//��� ����
Listnode* radixsort(Listnode* head)
{
	Listnode bucket[BUCKET_NUM] = { NULL, };
	Listnode* p = NULL;         //�������� �����Ͽ� head�� ����
	Listnode* temp = head;      //bucket�� �ֱ� �� �ӽ� ����
	int radix;
	int a = 1;                  // *10 ���ָ� radix�� ����

	for (int i = 0; i < BUCKET_NUM; i++)     //�ʱ�ȭ
		bucket[i].front = NULL;

	for (int len = 0; len < 6; len++)   //������ ���� ��� 6�ڸ� �̹Ƿ�
	{
		//temp�� ��Ŷ�� �� ���������� �ݺ�
		while(temp!=NULL)
		{
			radix = (temp->data / a) % 10;
			if (bucket[radix].front == NULL) //ù �� �Է�
			{
				bucket[radix].front = temp;
				bucket[radix].end = temp;
				temp = temp->front;
				bucket[radix].end->front = NULL;
			}

			else
			{
				bucket[radix].end->front = temp;
				bucket[radix].end = temp;
				temp = temp->front;
				bucket[radix].end->front = NULL;
			}
		}

		for (int i = 0; i < BUCKET_NUM; i++)
		{
			//��Ŷ�� ����� ������� ������ p�� ����
			if (bucket[i].front != NULL)
			{
				if (p == NULL)     //ù �� �Է�
				{
					p = bucket[i].front;
					p->end = bucket[i].end;
				}

				else 
				{
					p->end->front = bucket[i].front;
					p->end = bucket[i].end;
				}
			}
		}
		head = p;
		a *= 10;

		for (int i = 0; i < BUCKET_NUM; i++)
			bucket[i].front = NULL;
		p = NULL;
		temp = head;
	}
	return head;
}

//�޴�
void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. ���� ���� Ȯ�� \n");
	printf("2. ���� \n");
	printf("3. ���� \n");
	printf("0. ���� \n");
	printf("---------------------------------- \n");
	printf("\n");
}

//����
int main(void)
{
	int choice;
	int temp;
	int n;
	Listnode* head = NULL;

	printf("--------------<�ʱ� ���Ḯ��Ʈ ����>--------------\n");
	printf("�� ���� ����Ʈ�� �����Ͻðڽ��ϱ�? : ");
	scanf("%d", &n);
	printf("����Ʈ �Է� (ex : 991206) \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d��° ����Ʈ : ", (i + 1));
		scanf("%d", &temp);
		head = insert(head, temp);
	}

	while (1)
	{
		menu();
		printf("\n");
		printf("�޴� ����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			print_list(head);
			break;

		case 2:
			head = radixsort(head);
			break;

		case 3:
			printf("���� ����Ʈ �Է� : ");
			scanf("%d", &temp);
			insert(head, temp);
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}