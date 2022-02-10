#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define INF 1000000

void number_one_main()
{
	int n;
	printf("정수 개수 입력(1~20) : ");
	scanf("%d", &n);
	int *arr = malloc(sizeof(int)*n);

	srand(time(NULL));
	for (int i = 0;i < n;i++)
	{
		arr[i] = rand() % 101-25;
		printf("%d ", arr[i]);
	}
	printf("\n \n");
	int maxi = arr[0];

	for (int i = 1;i < n;i++)
	{
		if (arr[i - 1] > 0 && arr[i] + arr[i - 1] > 0) {
			printf("%d와(과) %d의 합 = ", arr[i], arr[i - 1]);
			arr[i] += arr[i - 1];
			printf("%d \n", arr[i]);
		}

		if (maxi < arr[i]) {
			maxi = arr[i];
			printf("현재 maxi : %d \n", maxi);
		}
		printf("--------------------------------------------------------------\n");
	}

	printf("최대 합 = %d \n", maxi);

	free(arr);
}

void number_two_main()
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

void number_three_main()
{
	int money[5] = { 100,60,8,5,1 };
	int n;
	printf("우편 요금 입력 : ");
	scanf("%d", &n);
	int arr[1000];
	arr[0] = 0;

	for (int i = 1;i <= n;i++) {
		arr[i] = -1;
		for (int j = 0;j < 5;j++)
		{
			if (money[j] <= i)
			{
				if (arr[i - money[j]] < 0)  //arr[i]가 -1이면 진행 x
					continue;

				if (arr[i] < 0) {
					arr[i] = arr[i - money[j]] + 1;
					//printf("%d, %d \n",i ,arr[i]);
				}

				else if (arr[i - money[j]] + 1 < arr[i]) {
					arr[i] = arr[i - money[j]] + 1;
					//printf("%d \n", arr[i]);
				}
				//printf("%d, %d \n", i, arr[i]);
			}
			if(j==4)
				printf("%d, %d, %d \n", i, money[j],arr[i]);
		}
	}

	printf("최소 우표 개수 : %d개 \n", arr[n]);
}

void number_four_main()
{
	int arr[4][11];
	arr[0][0] = 0;
	for (int i = 1;i < 4;i++)
		arr[i][0] = 0;
	for (int i = 1;i < 11;i++)
		arr[0][i] = 0;

	int w[3] = { 3,4,5 };
	int p[3] = { 6,3,5 };
	int maxi = 0;

	for (int i = 1;i < 4;i++)
	{
		//printf("크기가 %d, 가치가 %d인 보석을 넣을 준비중... \n", w[i - 1], p[i - 1]);
		for (int j = 1;j < 11;j++)
		{
			if (w[i - 1] < j) {
				arr[i][j] = max(p[i - 1] + arr[i - 1][j - w[i - 1]], arr[i - 1][j]);
				//printf("가방에 크기가 %d, 가치가 %d인 보석 넣음 \n", w[i-1], arr[i][j]);
			}

			else
			{
				arr[i][j] = arr[i - 1][j];
				//printf("보석 무게가 더 커서 가방에 담을 수 없습니다. \n");
			}
			maxi = max(arr[i][j], maxi);
		}
		printf("%d번째 최대값 : %d \n", i, maxi);
		printf("\n");
	}
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 11;j++)
		{
			printf(" %2d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("보석의 가치의 최대 합 : %d \n", maxi);
}

/*

1.	n개의 정수로 이루어진 임의의 수열이 주어졌을 때, 
이 중 한 개 이상의 연속된 숫자를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하시오.
예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어지면, 정답은 12+21인 33이다.

2.	N개 계단을 올라가려고 한다. 매번 계단을 1칸 또는 2칸을 올라갈 수 있다.
맨 위까지 올라갈 수 있는 방법의 수는 몇 개인지 구하시오.

3.	어느 우체국에는 100원, 60원, 8원짜리, 5원짜리, 1원짜리 우표가 있다. 
특정 금액의 우편요금을 위해 사용하는 최소 개수의 우표 개수를 구하시오. 

4.	크기 3, 4, 5 이고, 가치가 각각 6, 3, 5인 보석들과 크기 10인 가방이 있다. 
가방에 넣는 보석의 가치의 합이 최대가 되도록 고르면 그 합은 얼마인지 구하시오. 
단, 보석은 잘라서 넣을 수 없고, 넣거나 넣지 않는 경우 중 선택해야 한다. 

*/

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 한 개 이상의 연속된 숫자를 선택해서 구할 수 있는 합 중 가장 큰 합\n");
	printf("2. 계단을 올라가는 방법의 수 \n");
	printf("3. 최소 우표 개수 \n");
	printf("4. 가방에 넣는 보석 가치 최댓값 \n");
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
			number_one_main();
			break;

		case 2:
			number_two_main();
			break;

		case 3:
			number_three_main();
			break;

		case 4:
			number_four_main();
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	}
}