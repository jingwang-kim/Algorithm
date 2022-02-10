#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define MAX_ARR 100

void matrix_main()
{
	int n;
	int arr[MAX_ARR][MAX_ARR];

	printf("n x n 행렬 생성 : ");
	scanf("%d", &n);

	for (int i = 0;i <= n;i++)
		arr[i][0] = 0;
	for (int j = 1;j <= n;j++)
		arr[0][j] = 0;

	srand(time(NULL));
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			arr[i][j] = rand() % 21-5;
			printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int maxi;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			maxi = max(arr[i - 1][j], arr[i][j - 1]);
			maxi = max(maxi, arr[i - 1][j - 1]);
			printf("%d + %d = ", maxi, arr[i][j]);
			arr[i][j] += maxi;
			printf("%d \n", arr[i][j]);
		}
	}
	printf("\n");

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("경로의 합 : %d \n", arr[n][n]);
}

void stair_main()
{
	int n;
	printf("계단 수 입력 : ");
	scanf("%d", &n);
	int arr[20];
	arr[0] = arr[1] = 1;

	printf("1층: %d \n", arr[1]);
	for (int i = 2;i <= n;i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		printf("%d층: %d \n", i, arr[i]);
	}

	printf("계단을 오르는 방법의 수 : %d \n", arr[n]);
}

void stamp_dynamic()
{
	int money[3] = { 80,50,10 };
	int n;
	printf("우편 요금 입력 : ");
	scanf("%d", &n);
	int arr[1000];
	arr[0] = 0;
	int e, t, f;
	for (int i = 10;i <= n;i+=10) {
		arr[i] = -1;
		e = t = f = 0;
		printf("----------<%d원>----------\n", i);
		for (int j = 0;j < 3;j++)
		{
			if (money[j] <= i)
			{
				if (arr[i - money[j]] < 0)  //arr[i]가 -1이면 진행 x
					continue;

				if (arr[i] < 0) {
					arr[i] = arr[i - money[j]] + 1;
				}

				else if (arr[i - money[j]] + 1 < arr[i]) {
					arr[i] = arr[i - money[j]] + 1;
				}

				if (money[j] == 80)
					e = arr[i];
				else if (money[j] == 50)
					f = arr[i];
				else
					t = arr[i];
			}
		}
		if (arr[i] != -1)
			printf("80원: %d개, 50원: %d개, 10원: %d개\n", e, f, t);

		printf("%d원 최소 우표 개수 : %d개 \n",i, arr[i]);
		printf("\n");
	}

	//printf("최소 우표 개수 : %d개 \n", arr[n]);
}

void stamp_greedy()
{
	int money[3] = { 80,50,10 };
	int n;
	printf("우편 요금 입력 : ");
	scanf("%d", &n);

	int result = 0;
	int i = 0;
	for (int j = 10;j <= n;j += 10)
	{
		printf("----------<%d원>----------\n", j);
		int a = j;
		i = 0;
		result = 0;
		while (a != 0)
		{
			int stamp = a / money[i];
			printf("%d원 :%d개, ", money[i], stamp);
			a -= stamp * money[i++];
			result += stamp;
		}
		printf("\n");
		printf("%d원 최소 우표 개수 : %d \n",j, result);
		printf("\n");
	}
}

/*
1. 교재 290쪽 연습문제 06을 동적프로그래밍 방법으로 완성하시오.

2. N개 계단을 올라가려고 한다. 매번 계단을 1칸 또는 2칸을 올라갈 수 있다.

맨 위까지 올라갈 수 있는 방법의 수는 몇 개인지 구하는 프로그램을 동적 프로그래밍 방법으로

완성하시오.

3. 어느 우체국에는 80원짜리, 50원짜리, 10원짜리 우표가 있다.

(1) 특정 금액의 우편요금을 위해 사용하는 최소 개수의 우표 개수를 동적프로그래밍으로 구하시오. 
(10, 20, 30, 40, 50 … 300원을 만드는 최소 우표 개수를 구하는 표를 완성하시오).

선택사항으로, 최적의 해가 각 우표를 몇 장씩 사용하는는지도 출력하시오.

(2) 만약, 우체국 직원이 그리디 알고리즘을 적용한다면 어떤 조합으로 우표들을 받게 되는지

계산하는 프로그램을 작성하고, 그 결과가 최적)의 결과인지 (1)과 비교하시오.
*/

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 행렬 경로 문제\n");
	printf("2. 계단을 올라가는 방법의 수 \n");
	printf("3. 최소 우표 개수(동적) \n");
	printf("4. 최소 우표 개수(그리디) \n");
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
			matrix_main();
			break;

		case 2:
			stair_main();
			break;

		case 3:
			stamp_dynamic();
			break;

		case 4:
			stamp_greedy();
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}