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

void BubbleSort(int *arr, int n)
{
	int temp;

	for (int i = n;i >1;i--)
	{
		for (int j = 0;j < i-1;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void arr_merge(int *arr1, int *arr2, int *result)
{
	int a1=0, a2=0, r1=0;
	while (a1 < 5 && a2 < 6)
	{
		if (arr1[a1] > arr2[a2])
		{
			result[r1] = arr2[a2];
			a2++;
			r1++;
		}

		else if (arr1[a1] < arr2[a2])
		{
			result[r1] = arr1[a1];
			a1++;
			r1++;
		}
	}

	while (a1 < 5)
	{
		result[r1] = arr1[a1];
		a1++;
		r1++;
	}

	while (a2 < 6)
	{
		result[r1] = arr2[a2];
		a2++;
		r1++;
	}

}

Listnode *List_merge(Listnode *head1, Listnode *head2)
{

	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else
	{
		Listnode *p1 = head1;
		Listnode *p2 = head2;
		Listnode *temp = NULL;

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

			else if (p1->data > p2->data)
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
			p2->link = p1;

		else if (p2->link != NULL)
			p1->link = p2;

		if (head1->data < head2->data)
			return head1;
		else
			return head2;

	}

}

int num = 0;
void Hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("<%d>원판을 <%c>에서 <%c>로 옮긴다. \n", n, A, C);
	}

	else
	{
		Hanoi(n - 1, A, C, B);
		printf("\n");
		printf("<%d>원판을 <%c>에서 <%c>로 옮긴다. \n", n, A, C);
		printf("\n");
		Hanoi(n - 1, B, A, C);
	}
	num++;
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 버블정렬 \n");
	printf("2. 배열 병합 \n");
	printf("3. 연결리스트 병합<1> \n");
	printf("4. 연결리스트 병합<2> \n");
	printf("5. 하노이의 탑 \n");
	printf("0. 종료 \n");
	printf("---------------------------------- \n");
	printf("\n");
}

int main(void)
{
	//case1
	int random;
	int bubarr[100] = { 0, };
	int n1;

	//case2
	int arr1[5] = { 6,8,26,57,63 };
	int arr2[6] = { 19, 47, 62, 80, 94, 99};
	int result[11] = { 0, };

	//case3, case4
	Listnode *head1 = NULL;
	Listnode *head2 = NULL;
	Listnode *head3 = NULL;
	Listnode *head4 = NULL;

	//case5
	int n2;

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
			//배열에 넣을 정수 개수 입력
			printf("몇 개의 정수를 넣으시겠습니까? ");
			scanf("%d", &n1);

			//랜덤 함수로 배열에 저장
			for (int i = 0;i < n1;i++)
			{
				random = rand() % 100 + 1;
				bubarr[i] = random;
				printf("%d ", bubarr[i]);
			}
			printf("\n");

			//버블 정렬
			BubbleSort(bubarr, n1);
			for (int i = 0;i < n1;i++)
			{
				printf("%d ", bubarr[i]);
			}
			printf("\n");
			break;

		case 2:
			//첫 번째 배열 출력
			printf("첫 번째 배열 : ");
			for(int i=0;i<5;i++)
				printf("%d ", arr1[i]);
			printf("\n");

			//두 번째 배열 출력
			printf("두 번째 배열 : ");
			for (int i = 0;i < 6;i++)
				printf("%d ", arr2[i]);
			printf("\n");

			//병합된 배열 출력
			arr_merge(arr1, arr2, result);
			printf("병합된 배열 : ");
			for (int i = 0;i < 11;i++)
				printf("%d ", result[i]);
			printf("\n");
			break;

		case 3:
			//head1 insert
			//6->8->26->57->63
			head1 = insert(head1, 63);
			head1 = insert(head1, 57);
			head1 = insert(head1, 26);
			head1 = insert(head1, 8);
			head1 = insert(head1, 6);
			printf("-----< headl >----- \n");
			print_list(head1);
			printf("\n");

			//head2 insert
			//19->47->62->80->94->99
			head2 = insert(head2, 99);
			head2 = insert(head2, 94);
			head2 = insert(head2, 80);
			head2 = insert(head2, 62);
			head2 = insert(head2, 47);
			head2 = insert(head2, 19);
			printf("-----< head2 >----- \n");
			print_list(head2);
			printf("\n");

			//merge insert
			printf("-----< merge >----- \n");
			print_list(List_merge(head1, head2));
			break;
		
		case 4:
			//head3 insert
			//11->38->56->90->98
			head3 = insert(head3, 98);
			head3 = insert(head3, 90);
			head3 = insert(head3, 56);
			head3 = insert(head3, 38);
			head3 = insert(head3, 11);
			printf("-----< head3 >----- \n");
			print_list(head3);
			printf("\n");

			//head4 insert
			//2->17->44->53->72->83
			head4 = insert(head4, 83);
			head4 = insert(head4, 72);
			head4 = insert(head4, 53);
			head4 = insert(head4, 44);
			head4 = insert(head4, 17);
			head4 = insert(head4, 2);
			printf("-----< head4 >----- \n");
			print_list(head4);
			printf("\n");

			//merge
			printf("-----< merge >----- \n");
			print_list(List_merge(head3, head4));
			break;

		case 5:
			printf("옮길 개수 선택: ");
			scanf("%d", &n2);
			Hanoi(n2, 'A', 'B', 'C');
			printf("옮긴 횟수 : %d \n", num);
			num = 0;
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}

}