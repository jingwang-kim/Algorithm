#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

typedef struct element {           //x�� y��
	int x1;
	int y1;
}element;

typedef struct Listnode {         //����Ʈ ����
	int x2;
	int y2;
	struct Listnode *link;
}Listnode;

int Recur_Max(int *arr, int n)      //��ȯ �ִ밪
{
	if (n == 0)
		return arr[0];
	int maxnum = Recur_Max(arr, n - 1);

	if (maxnum < arr[n])
	{
		return arr[n];
	}
	else
		arr[n] = maxnum;
	return arr[n];
}

int UseFor_Max(int *arr)          //�ݺ� �ִ밪
{
	int max = arr[0];

	for (int i = 0;i < 10;i++)
	{
		if (max <= arr[i])
			max = arr[i];
	}

	return max;
}//----------------------------------------------------------------case 1

void UseFor_Base(int n, int b)           //10���� ��ȯ �ݺ�
{
	char arr[30] = { 0, };
	int count = 0;

	while (1)
	{
		int remain = n % b;

		if (remain < 10)
			arr[count] = remain + 48;

		else
			arr[count] = (remain - 10) + 65;

		n /= b;
		count++;

		if (n == 0)
			break;
	}

	for (int i = count - 1;i >= 0;i--)
	{
		printf("%c", arr[i]);
	}

}

void Recur_Base(int n, int b)          //10���� ��ȯ ��ȯ
{
	int remain;
	remain = n % b;
	n /= b;
	if (n > 0)
		Recur_Base(n, b);
	if (remain < 10)
		printf("%d", remain);
	else
		printf("%c", (remain - 10) + 65);
}//------------------------------------------------------------------case 2



double calculate(element *coor)           //�Ÿ� ���
{
	return sqrt((coor->x1 * coor->x1) + (coor->y1 * coor->y1));
}

double distance_For(element *coor, int cnt)       //�迭 �ݺ�
{
	double result = 0;

	for (int i = 0;i < cnt;i++)
	{
		result += calculate(coor + i);
	}
	result /= cnt;
	return result;
}

double distance_Recur(element *coor, int cnt, int ran)         //�迭 ��ȯ
{
	if (cnt == ran)
		return 0;
	else {
		double result = calculate(coor) / cnt;
		return result + distance_Recur(coor + 1, cnt, ran + 1);  //�Ÿ� / �� ���� +ȣ��
	}
}//------------------------------------------------------------------------case3

void print_list(Listnode *head)       //����Ʈ ���
{

	for (Listnode *p = head;p != NULL; p = p->link)
	{
		printf("[ %d, %d ] \n", p->x2, p->y2);
	}
}

Listnode* insert_node(Listnode *head)           //����Ʈ ����
{
	Listnode *p = (Listnode *)malloc(sizeof(Listnode));
	
	int random;
	
	random = rand() % 11;
	p->x2 = random;
	random = rand() % 11;
	p->y2 = random;
	

	p->link = head;         //p�� ���� head�� ����Ű�� ��
	head = p;               //head �� p���� ��
	return head;
}

double List_For(Listnode *head, int cnt)      //����Ʈ �ݺ�
{
	double result = 0;

	for (int i = 0;i < cnt;i++)
	{
		result += calculate(head);
		head=head->link;
	}
	result /= cnt;
	return result;
}

double List_Recur(Listnode *head, int cnt, int ran)        //����Ʈ ��ȯ
{
	if (cnt == ran)
		return 0;
	else
		return calculate(head) / cnt + List_Recur(head->link, cnt, ran + 1);

}//------------------------------------------------------------------------------case4



void menu()          //�޴�
{
	printf("---------------menu--------------- \n");
	printf("1. �ִ밪 \n");
	printf("2. 10���� n���� ��ȯ \n");
	printf("3. �迭 �Ÿ� ��� \n");
	printf("4. ���Ḯ��Ʈ �Ÿ� ��� \n");
	printf("0. ���� \n");
	printf("---------------------------------- \n");
}

int main(void)        //����
{
	int random;
	int arr[10] = { 0, };
	int max1 = 0;
	int max2 = 0;
	int range = 9;  //---------------------------case1

	int n = 0;
	int b = 0;      //---------------------------case2

	element coor[10] = { {0,}, };
	int cnt = 0;
	int ran1 = 0;
	double result1 = 0;
	double result2 = 0;   //---------------------case3

	Listnode *head = NULL;
	int ran2 = 0;
	double list_result1 = 0;
	double list_result2 = 0; //------------------case4

	int choice = 0;
	while (1) {
		menu();
		printf("\n");
		printf("�޴� ����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("�迭 10�� ������ �Է� : ");
			for (int i = 0;i < 10;i++)
			{
				random = rand() % 101 + 1;
				arr[i] = random;
				printf("%d ", arr[i]);
			}
			printf("\n");

			max1 = Recur_Max(arr, range);
			max2 = UseFor_Max(arr);
			printf("��ȯ ȣ�� : %d \n", max1);
			printf("�ݺ��� : %d \n", max2);
			break;

		case 2:
			printf("10���� n �Է� : ");
			scanf("%d", &n);

			printf("b ������ ��ȯ(2~16��������) : ");
			scanf("%d", &b);

			printf("�ݺ� : ");
			UseFor_Base(n, b);
			printf("(%d)", b);
			printf("\n");

			printf("��ȯ : ");
			Recur_Base(n, b);
			printf("(%d)", b);
			printf("\n");
			break;

		case 3:
			printf("��ǥ ���� ����(1~10): ");
			scanf("%d", &cnt);
			printf("��ǥ %d�� ������ �Է� \n", cnt);
			for (int i = 0;i < cnt;i++)
			{
				random = rand() % 11;
				coor[i].x1 = random;
				random = rand() % 11;
				coor[i].y1 = random;
				printf("[ %d, %d ] \n", coor[i].x1, coor[i].y1);
			}
			
			result1=distance_For(coor, cnt);
			printf("�迭 �ݺ� : %lf \n", result1);

			result2=distance_Recur(coor, cnt, ran1);
			printf("�迭 ��ȯ ȣ�� : %lf \n", result2);
			break;

		case 4:
			printf("��ǥ ���� ����(1~10): ");
			scanf("%d", &cnt);

			printf("��ǥ %d�� ������ �Է� \n", cnt);
			for (int i = 0;i < cnt;i++)
				head=insert_node(head);
			print_list(head);
			
			list_result1 = List_For(head, cnt);
			printf("���Ḯ��Ʈ �ݺ� : %lf \n", list_result1);
			list_result2 = List_Recur(head, cnt, ran2);
			printf("���Ḯ��Ʈ ��ȯ : %lf \n", list_result2);
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;


		}
	}

	return 0;
}