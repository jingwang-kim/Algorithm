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

//출력 함수
void print_list(Listnode* head)
{
	Listnode* p;
	for (p = head; p != NULL; p = p->front)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

//삽입 함수
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

//기수 정렬
Listnode* radixsort(Listnode* head)
{
	Listnode bucket[BUCKET_NUM] = { NULL, };
	Listnode* p = NULL;         //마지막에 정렬하여 head와 연결
	Listnode* temp = head;      //bucket에 넣기 전 임시 저장
	int radix;
	int a = 1;                  // *10 해주며 radix값 변경

	for (int i = 0; i < BUCKET_NUM; i++)     //초기화
		bucket[i].front = NULL;

	for (int len = 0; len < 6; len++)   //데이터 길이 모두 6자리 이므로
	{
		//temp를 버킷에 다 넣을때까지 반복
		while(temp!=NULL)
		{
			radix = (temp->data / a) % 10;
			if (bucket[radix].front == NULL) //첫 값 입력
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
			//버킷에 저장된 순서대로 꺼내서 p에 저장
			if (bucket[i].front != NULL)
			{
				if (p == NULL)     //첫 값 입력
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

//메뉴
void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 현재 상태 확인 \n");
	printf("2. 정렬 \n");
	printf("3. 삽입 \n");
	printf("0. 종료 \n");
	printf("---------------------------------- \n");
	printf("\n");
}

//메인
int main(void)
{
	int choice;
	int temp;
	int n;
	Listnode* head = NULL;

	printf("--------------<초기 연결리스트 생성>--------------\n");
	printf("몇 개의 리스트를 생성하시겠습니까? : ");
	scanf("%d", &n);
	printf("리스트 입력 (ex : 991206) \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d번째 리스트 : ", (i + 1));
		scanf("%d", &temp);
		head = insert(head, temp);
	}

	while (1)
	{
		menu();
		printf("\n");
		printf("메뉴 선택: ");
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
			printf("넣을 리스트 입력 : ");
			scanf("%d", &temp);
			insert(head, temp);
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}