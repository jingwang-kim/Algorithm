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

	printf("n x n ��� ���� : ");
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

	printf("����� �� : %d \n", arr[n][n]);
}

void stair_main()
{
	int n;
	printf("��� �� �Է� : ");
	scanf("%d", &n);
	int arr[20];
	arr[0] = arr[1] = 1;

	printf("1��: %d \n", arr[1]);
	for (int i = 2;i <= n;i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		printf("%d��: %d \n", i, arr[i]);
	}

	printf("����� ������ ����� �� : %d \n", arr[n]);
}

void stamp_dynamic()
{
	int money[3] = { 80,50,10 };
	int n;
	printf("���� ��� �Է� : ");
	scanf("%d", &n);
	int arr[1000];
	arr[0] = 0;
	int e, t, f;
	for (int i = 10;i <= n;i+=10) {
		arr[i] = -1;
		e = t = f = 0;
		printf("----------<%d��>----------\n", i);
		for (int j = 0;j < 3;j++)
		{
			if (money[j] <= i)
			{
				if (arr[i - money[j]] < 0)  //arr[i]�� -1�̸� ���� x
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
			printf("80��: %d��, 50��: %d��, 10��: %d��\n", e, f, t);

		printf("%d�� �ּ� ��ǥ ���� : %d�� \n",i, arr[i]);
		printf("\n");
	}

	//printf("�ּ� ��ǥ ���� : %d�� \n", arr[n]);
}

void stamp_greedy()
{
	int money[3] = { 80,50,10 };
	int n;
	printf("���� ��� �Է� : ");
	scanf("%d", &n);

	int result = 0;
	int i = 0;
	for (int j = 10;j <= n;j += 10)
	{
		printf("----------<%d��>----------\n", j);
		int a = j;
		i = 0;
		result = 0;
		while (a != 0)
		{
			int stamp = a / money[i];
			printf("%d�� :%d��, ", money[i], stamp);
			a -= stamp * money[i++];
			result += stamp;
		}
		printf("\n");
		printf("%d�� �ּ� ��ǥ ���� : %d \n",j, result);
		printf("\n");
	}
}

/*
1. ���� 290�� �������� 06�� �������α׷��� ������� �ϼ��Ͻÿ�.

2. N�� ����� �ö󰡷��� �Ѵ�. �Ź� ����� 1ĭ �Ǵ� 2ĭ�� �ö� �� �ִ�.

�� ������ �ö� �� �ִ� ����� ���� �� ������ ���ϴ� ���α׷��� ���� ���α׷��� �������

�ϼ��Ͻÿ�.

3. ��� ��ü������ 80��¥��, 50��¥��, 10��¥�� ��ǥ�� �ִ�.

(1) Ư�� �ݾ��� �������� ���� ����ϴ� �ּ� ������ ��ǥ ������ �������α׷������� ���Ͻÿ�. 
(10, 20, 30, 40, 50 �� 300���� ����� �ּ� ��ǥ ������ ���ϴ� ǥ�� �ϼ��Ͻÿ�).

���û�������, ������ �ذ� �� ��ǥ�� �� �徿 ����ϴ´����� ����Ͻÿ�.

(2) ����, ��ü�� ������ �׸��� �˰����� �����Ѵٸ� � �������� ��ǥ���� �ް� �Ǵ���

����ϴ� ���α׷��� �ۼ��ϰ�, �� ����� ����)�� ������� (1)�� ���Ͻÿ�.
*/

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. ��� ��� ����\n");
	printf("2. ����� �ö󰡴� ����� �� \n");
	printf("3. �ּ� ��ǥ ����(����) \n");
	printf("4. �ּ� ��ǥ ����(�׸���) \n");
	printf("0. ���� \n");
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
		printf("�޴� ����: ");
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
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}