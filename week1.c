#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

typedef struct element {           //x축 y축
	int x1;
	int y1;
}element;

typedef struct Listnode {         //리스트 생성
	int x2;
	int y2;
	struct Listnode *link;
}Listnode;

int Recur_Max(int *arr, int n)      //순환 최대값
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

int UseFor_Max(int *arr)          //반복 최대값
{
	int max = arr[0];

	for (int i = 0;i < 10;i++)
	{
		if (max <= arr[i])
			max = arr[i];
	}

	return max;
}//----------------------------------------------------------------case 1

void UseFor_Base(int n, int b)           //10진수 변환 반복
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

void Recur_Base(int n, int b)          //10진수 변환 순환
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



double calculate(element *coor)           //거리 계산
{
	return sqrt((coor->x1 * coor->x1) + (coor->y1 * coor->y1));
}

double distance_For(element *coor, int cnt)       //배열 반복
{
	double result = 0;

	for (int i = 0;i < cnt;i++)
	{
		result += calculate(coor + i);
	}
	result /= cnt;
	return result;
}

double distance_Recur(element *coor, int cnt, int ran)         //배열 순환
{
	if (cnt == ran)
		return 0;
	else {
		double result = calculate(coor) / cnt;
		return result + distance_Recur(coor + 1, cnt, ran + 1);  //거리 / 총 개수 +호출
	}
}//------------------------------------------------------------------------case3

void print_list(Listnode *head)       //리스트 출력
{

	for (Listnode *p = head;p != NULL; p = p->link)
	{
		printf("[ %d, %d ] \n", p->x2, p->y2);
	}
}

Listnode* insert_node(Listnode *head)           //리스트 삽입
{
	Listnode *p = (Listnode *)malloc(sizeof(Listnode));
	
	int random;
	
	random = rand() % 11;
	p->x2 = random;
	random = rand() % 11;
	p->y2 = random;
	

	p->link = head;         //p가 현재 head를 가리키게 함
	head = p;               //head 가 p값이 됨
	return head;
}

double List_For(Listnode *head, int cnt)      //리스트 반복
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

double List_Recur(Listnode *head, int cnt, int ran)        //리스트 순환
{
	if (cnt == ran)
		return 0;
	else
		return calculate(head) / cnt + List_Recur(head->link, cnt, ran + 1);

}//------------------------------------------------------------------------------case4



void menu()          //메뉴
{
	printf("---------------menu--------------- \n");
	printf("1. 최대값 \n");
	printf("2. 10진수 n진수 변환 \n");
	printf("3. 배열 거리 계산 \n");
	printf("4. 연결리스트 거리 계산 \n");
	printf("0. 종료 \n");
	printf("---------------------------------- \n");
}

int main(void)        //메인
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
		printf("메뉴 선택: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("배열 10개 무작위 입력 : ");
			for (int i = 0;i < 10;i++)
			{
				random = rand() % 101 + 1;
				arr[i] = random;
				printf("%d ", arr[i]);
			}
			printf("\n");

			max1 = Recur_Max(arr, range);
			max2 = UseFor_Max(arr);
			printf("순환 호출 : %d \n", max1);
			printf("반복문 : %d \n", max2);
			break;

		case 2:
			printf("10진수 n 입력 : ");
			scanf("%d", &n);

			printf("b 진수로 변환(2~16진수까지) : ");
			scanf("%d", &b);

			printf("반복 : ");
			UseFor_Base(n, b);
			printf("(%d)", b);
			printf("\n");

			printf("순환 : ");
			Recur_Base(n, b);
			printf("(%d)", b);
			printf("\n");
			break;

		case 3:
			printf("좌표 개수 설정(1~10): ");
			scanf("%d", &cnt);
			printf("좌표 %d개 무작위 입력 \n", cnt);
			for (int i = 0;i < cnt;i++)
			{
				random = rand() % 11;
				coor[i].x1 = random;
				random = rand() % 11;
				coor[i].y1 = random;
				printf("[ %d, %d ] \n", coor[i].x1, coor[i].y1);
			}
			
			result1=distance_For(coor, cnt);
			printf("배열 반복 : %lf \n", result1);

			result2=distance_Recur(coor, cnt, ran1);
			printf("배열 순환 호출 : %lf \n", result2);
			break;

		case 4:
			printf("좌표 개수 설정(1~10): ");
			scanf("%d", &cnt);

			printf("좌표 %d개 무작위 입력 \n", cnt);
			for (int i = 0;i < cnt;i++)
				head=insert_node(head);
			print_list(head);
			
			list_result1 = List_For(head, cnt);
			printf("연결리스트 반복 : %lf \n", list_result1);
			list_result2 = List_Recur(head, cnt, ran2);
			printf("연결리스트 순환 : %lf \n", list_result2);
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;


		}
	}

	return 0;
}