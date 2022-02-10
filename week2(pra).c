#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Listnode {
	int data;
	struct Listnode *link;
}Listnode;

void print_list(Listnode *head)
{
	for (Listnode *p = head; p != NULL;p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

Listnode* insert(Listnode *head, int data)
{
	Listnode *p = (Listnode *)malloc(sizeof(Listnode));

	p->data = data;
	p->link = head;
	head = p;
	return head;
}

Listnode* concat_list(Listnode *head1, Listnode *head2)
{
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else
	{
		Listnode *p1=head1;
		Listnode *p2=head2;
		Listnode *temp = NULL;
		//Listnode *newhead = NULL;

		/*if (p1->data < p2->data)
		{
			temp = p1;
			while (p1->link != NULL && p2->link != NULL)
			{
				if (p1->link->data > p2->data)
				{
					temp->link = p2;
					temp = p2;
					p2 = p2->link;
					p1 = p1->link;
				}

				else
					p1 = p1->link;

				temp->link = NULL;
				print_list(p1);

			}

			for (;p2->link != NULL;p2 = p2->link)
			{
				temp->link = p2;
			}

			return p1;
		}*/
		
		while (p1->link != NULL && p2->link != NULL)
		{
			if (p1->data < p2->data)
			{
				if (p1->link->data > p2->data)
				{
					temp = p2->link;
					p2->link = p1->link;
					p1->link = p2;
					p2 = temp;
				}
				p1 = p1->link;
			}

			if (p1->data > p2->data)
			{
				if (p2->link->data > p1->data)
				{
					temp = p1->link;
					p1->link = p2->link;
					p2->link = p1;
					p1 = temp;
				}
				p2 = p2->link;
			}
		}
		
		if (p1->link != NULL)
			p2->link=p1;

	    else if (p2->link != NULL)
			p1->link=p2;

		if (head1->data < head2->data)
			return head1;
		else
			return head2;

		/*while (p1 != NULL && p2 != NULL)
		{
			if (newhead == NULL)
			{
				if (p1->data < p2->data)
				{
					newhead = p1;
					temp = newhead;
					p1 = p1->link;
				}

				else if (p1->data < p2->data)
				{
					newhead = p2;
					temp = newhead;
					p2 = p2->link;
				}
			}

			else
			{
				if (p1->data < p2->data)
				{
					temp->link = p1;
					temp = p1;
					p1 = p1->link;
				}

				else if (p1->data > p2->data)
				{
					temp->link = p2;
					temp = p2;
					p2 = p2->link;
				}
			}
			temp->link = NULL;
			print_list(newhead);

		}
		if (p1 != NULL)
			temp->link = p1;

		else if (p2 != NULL)
			temp->link = p2;

		return newhead;*/
	}
}

int Recur_Bsearch(int *arr, int target, int first, int last, int num)
{
	int mid = (first + last) / 2;

	if (first > last)
		return -1;

	if (target == arr[mid])
	{
		printf("���� �˻� ���� : [%d ~ %d] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [%d, %d] \n", arr[mid], mid);
		printf("�� Ƚ�� : %d \n", num+1);
		Sleep(1000);
		printf("\n");
		return mid;
	}

	else if (target < arr[mid])
	{
		printf("���� �˻� ���� : [%d ~ %d] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [%d, %d] \n", mid, arr[mid]);
		printf("\n");
		Sleep(1000);
		Recur_Bsearch(arr, target, first, mid-1, num+1);
	}

	else
	{
		printf("���� �˻� ���� : [%d ~ %d] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [%d, %d] \n", mid, arr[mid]);
		printf("\n");
		Sleep(1000);
		Recur_Bsearch(arr, target, mid+1, last, num+1);
	}

}

int For_Bsearch(int *arr, int target, int first, int last)
{
	int num = 0;

	while (1)
	{
		if (first <= last)
		{
			int mid = (first + last) / 2;

			if (target == arr[mid])
			{
				printf("���� �˻� ���� : [%d ~ %d] \n", arr[first], arr[last]);
				printf("���� �߰����� �ε��� : [%d, %d] \n", arr[mid], mid);
				printf("ã������ Ÿ�� %d��(��) %d��° �ε����� �ֽ��ϴ�. \n", target, mid);
				printf("\n");
				num++;
				Sleep(1000);
				break;
			}

			else if (target < arr[mid])
			{
				printf("���� �˻� ���� : [%d ~ %d] \n", arr[first], arr[last]);
				last = mid - 1;
				printf("���� �߰����� �ε��� : [%d, %d] \n", arr[mid], mid);
				printf("\n");
				num++;
				Sleep(1000);
			}

			else
			{
				printf("���� �˻� ���� : [%d ~ %d] \n", arr[first], arr[last]);
				first = mid + 1;
				printf("���� �߰����� �ε��� : [%d, %d] \n", arr[mid], mid);
				printf("\n");
				num++;
				Sleep(1000);
			}
		}

		else
		{
			printf("���� �������� �ʽ��ϴ�. \n");
			break;
		}
	}

	return num;
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. ����Լ� ���� �˻� \n");
	printf("2. �ݺ��� ���� �˻� \n");
	printf("3. ���Ḯ��Ʈ ���� \n");
	printf("0. ���� \n");
	printf("---------------------------------- \n");
	printf("\n");
}

int main(void)
{
	int arr[20] = { 0, };
	int random;
	int target;
	int first = 0;
	int last = 19;
	int temp = 0;
	int choice = 0;
	int result1;
	int result2;
	int num=0;

	Listnode *head1 = NULL;
	Listnode *head2 = NULL;

	while (1)
	{
		menu();
		printf("\n");
		printf("�޴� ����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			//���� �Լ��� �迭�� ����
			printf("�迭 20�� ������ �Է� : ");
			for (int i = 0;i < 20;i++)
			{
				random = rand() % 101 + 1;
				arr[i] = random;
				printf("%d ", arr[i]);
			}
			printf("\n");

			//����
			for (int i = 0;i < last - 1;i++)
			{
				for (int j = 0;j < last - i;j++)
				{
					if (arr[j + 1] < arr[j])
					{
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}

			//���� Ȯ��
			printf("���� Ȯ�� : ");
			for (int i = 0;i < 20;i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");

			//�����˻�
			printf("ã������ Ÿ�� �Է� : ");
			scanf("%d", &target);

			printf("\n");
			result1=Recur_Bsearch(arr, target, first, last, num);
			if (result1 == -1)
			{
				printf("���� �������� �ʽ��ϴ�. \n");
			}

			else
			{
				printf("ã������ Ÿ�� %d��(��) %d��° �ε����� �ֽ��ϴ�. \n", target, result1);
			}
			break;

		case 2:
			//���� �Լ��� �迭�� ����
			printf("�迭 20�� ������ �Է� : ");
			for (int i = 0;i < 20;i++)
			{
				random = rand() % 101 + 1;
				arr[i] = random;
				printf("%d ", arr[i]);
			}
			printf("\n");

			//����
			for (int i = 0;i < last - 1;i++)
			{
				for (int j = 0;j < last - i;j++)
				{
					if (arr[j + 1] < arr[j])
					{
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}

			//���� Ȯ��
			printf("���� Ȯ�� : ");
			for (int i = 0;i < 20;i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");

			//�����˻�
			printf("ã������ Ÿ�� �Է� : ");
			scanf("%d", &target);
			printf("\n");
			result2 = For_Bsearch(arr, target, first, last);
			printf("�� Ƚ�� : %d \n", result2);
			break;

		case 3:
			head1 = insert(head1, 56);
			head1 = insert(head1, 24);
			head1 = insert(head1, 7);
			head1 = insert(head1, 5);
			printf("-----< headl >----- \n");
			print_list(head1);
			printf("\n");

			head2 = insert(head2, 79);
			head2 = insert(head2, 61);
			head2 = insert(head2, 45);
			head2 = insert(head2, 19);
			printf("-----< head2 >----- \n");
			print_list(head2);
			printf("\n");

			printf("-----< concat >----- \n");
			print_list(concat_list(head1, head2));

			break;

		case 0:
			return 0;

		default :
			printf("����� �����Ͻʽÿ�. \n");
			break;
		}


	}
	
}