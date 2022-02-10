#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

#define HASH_MAX 13
#define HASH_MAX2 11

#define FUNC_MAX 11
#define FUNC_MAX2 7

typedef struct list {
	int key;
	struct list *link;
}list;

list *table3[HASH_MAX2];

//해시 함수
int hash(int x, int i, int m)
{
	return ((x + i) % m);
}

//더블 해싱 함수
int func_hash(int x)
{
	return 1 + (x % FUNC_MAX);
}

int func_hash2(int x)
{
	return 7 - (x % FUNC_MAX2);
}

//테이블 초기화
void init_table(int *table, int m)
{
	int i;
	for (i = 0;i < m;i++)
		table[i] = NULL;
}

//선형 조사법
int linear_hashinsert(int *arr, int x, int m)
{
	int i = 0;
	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		int j = hash(x, i, m); //i가 1씩 증가

		if (arr[j] == NULL) {
			arr[j] = x;
			return j;
		}

		else {
			i++;
			SetConsoleTextAttribute(h_console, 0x000C);
			printf("[%d]에 %d가 이미 있습니다. \n", j, arr[j]);
			SetConsoleTextAttribute(h_console, 0x7);
		}

	} while (i != m);    //i가 테이블의 크기보다 커지면 반복문 종료

	fprintf(stderr, "테이블이 가득찼습니다.\n");
}

//이차 조사법
int quad_hashinsert(int *arr, int x, int m)
{
	int i = 0;
	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		int j = hash(x, i * i, m);    //i가 제곱으로 증가

		if (arr[j] == NULL) {
			arr[j] = x;
			return j;
		}

		else {
			i++;
			SetConsoleTextAttribute(h_console, 0x000C);
			printf("[%d]에 %d가 이미 있습니다. \n", j, arr[j]);
			SetConsoleTextAttribute(h_console, 0x7);
		}

	} while (i != m);

	fprintf(stderr, "테이블이 가득찼습니다.\n");
}

//더블 해싱
int double_hashinsert(int *arr, int x, int m)
{
	int i = 0;
	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		int j = hash(x, i*func_hash(x), m);  //해시함수 2개 사용

		if (arr[j] == NULL) {
			arr[j] = x;
			return j;
		}

		else {
			i++;
			SetConsoleTextAttribute(h_console, 0x000C);
			printf("[%d]에 %d가 이미 있습니다. \n", j, arr[j]);
			SetConsoleTextAttribute(h_console, 0x7);
		}

	} while (i != m);

	fprintf(stderr, "테이블이 가득찼습니다.\n");
}

int double_hashinsert2(int *arr, int x, int m)
{
	int i = 0;
	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	do {
		int j = hash(x, i*func_hash2(x), m);

		if (arr[j] == NULL) {
			arr[j] = x;
			return j;
		}

		else {
			i++;
			SetConsoleTextAttribute(h_console, 0x000C);
			printf("[%d]에 %d가 이미 있습니다. \n", j, arr[j]);
			SetConsoleTextAttribute(h_console, 0x7);
		}

	} while (i != m);

	fprintf(stderr, "테이블이 가득찼습니다.\n");
}

//체이닝, 해시테이블에 삽입
void insert_hash(list *node, int x)
{
	int key = x % HASH_MAX2;
	if (table3[key] == NULL)
		table3[key] = node;

	else {
		node->link = table3[key];
		table3[key] = node;
	}
}

//출력
void prob_print(int *table, int m)
{
	printf("=================<저장 결과>=================\n");
	for (int i = 0;i < m;i++) {
		printf("[%d] %d \n", i, table[i]);
	}
	printf("============================================\n");
	init_table(table, m);
}

//리스트 출력
void chain_print()
{
	list *node;
	printf("=================<저장 결과>=================\n");
	for (int i = 0;i < HASH_MAX2;i++)
	{
		printf("[%d]->", i);
		for (node = table3[i];node;node = node->link)
		{
			printf("%d->", node->key);
		}
		printf("\n");
	}
	printf("============================================\n");
}

void menu()
{
	printf("==============<p.242 연습문제>==============\n");
	printf("1. 선형 조사 사용 \n");
	printf("2. 이차원 조사 사용 \n");
	printf("3. 더블 해싱 사용 \n");
	printf("===========================================\n");
	printf("4. 선형조사법 \n");
	printf("5. 이차조사법 \n");
	printf("6. 더블해싱 \n");
	printf("7. 체이닝 \n");
	printf("0. 종료 \n");
	printf("===========================================\n");
}

int main(void)
{
	int choice;
	int index;
	int table1[HASH_MAX] = { NULL, };
	int table2[HASH_MAX2] = { NULL, };
	int arr[8] = { 10,20,30,40,33,46,50,60 };
	int arr2[11] = { 12,44,13,88,23,94,11,39,20,16,5 };

	while (1)
	{
		menu();
		printf("\n");
		printf("메뉴 선택: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			for (int i = 0;i < 8;i++) {
				index = linear_hashinsert(table1, arr[i], HASH_MAX);
				printf("%d는 [%d]에 저장되었습니다. \n", arr[i], index);
			}
			prob_print(table1, HASH_MAX);
			break;

		case 2:
			for (int i = 0;i < 8;i++) {
				index = quad_hashinsert(table1, arr[i], HASH_MAX);
				printf("%d는 [%d]에 저장되었습니다. \n", arr[i], index);
			}
			prob_print(table1, HASH_MAX);
			break;

		case 3:
			for (int i = 0;i < 8;i++) {
				index = double_hashinsert(table1, arr[i], HASH_MAX);
				printf("%d는 [%d]에 저장되었습니다. \n", arr[i], index);
			}
			prob_print(table1, HASH_MAX);
			break;

		case 4:
			for (int i = 0;i < 11;i++) {
				index = linear_hashinsert(table2, arr2[i], HASH_MAX2);
				printf("%d는 [%d]에 저장되었습니다. \n", arr2[i], index);
			}
			prob_print(table2, HASH_MAX2);
			break;

		case 5:
			for (int i = 0;i < 11;i++) {
				index = quad_hashinsert(table2, arr2[i], HASH_MAX2);
				printf("%d는 [%d]에 저장되었습니다. \n", arr2[i], index);
			}
			prob_print(table2, HASH_MAX2);
			break;

		case 6:
			for (int i = 0;i < 11;i++) {
				index = double_hashinsert2(table2, arr2[i], HASH_MAX2);
				printf("%d는 [%d]에 저장되었습니다. \n", arr2[i], index);
			}
			prob_print(table2, HASH_MAX2);
			break;

		case 7:
			for (int i = 0; i < 11;i++) {
				list *node = (list*)malloc(sizeof(list));
				node->key = arr2[i];
				node->link = NULL;
				insert_hash(node, node->key);
			}
			chain_print();
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}