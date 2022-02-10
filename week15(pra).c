#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define INF 1000000

void number_one_main()
{
	int n;
	printf("���� ���� �Է�(1~20) : ");
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
			printf("%d��(��) %d�� �� = ", arr[i], arr[i - 1]);
			arr[i] += arr[i - 1];
			printf("%d \n", arr[i]);
		}

		if (maxi < arr[i]) {
			maxi = arr[i];
			printf("���� maxi : %d \n", maxi);
		}
		printf("--------------------------------------------------------------\n");
	}

	printf("�ִ� �� = %d \n", maxi);

	free(arr);
}

void number_two_main()
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

void number_three_main()
{
	int money[5] = { 100,60,8,5,1 };
	int n;
	printf("���� ��� �Է� : ");
	scanf("%d", &n);
	int arr[1000];
	arr[0] = 0;

	for (int i = 1;i <= n;i++) {
		arr[i] = -1;
		for (int j = 0;j < 5;j++)
		{
			if (money[j] <= i)
			{
				if (arr[i - money[j]] < 0)  //arr[i]�� -1�̸� ���� x
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

	printf("�ּ� ��ǥ ���� : %d�� \n", arr[n]);
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
		//printf("ũ�Ⱑ %d, ��ġ�� %d�� ������ ���� �غ���... \n", w[i - 1], p[i - 1]);
		for (int j = 1;j < 11;j++)
		{
			if (w[i - 1] < j) {
				arr[i][j] = max(p[i - 1] + arr[i - 1][j - w[i - 1]], arr[i - 1][j]);
				//printf("���濡 ũ�Ⱑ %d, ��ġ�� %d�� ���� ���� \n", w[i-1], arr[i][j]);
			}

			else
			{
				arr[i][j] = arr[i - 1][j];
				//printf("���� ���԰� �� Ŀ�� ���濡 ���� �� �����ϴ�. \n");
			}
			maxi = max(arr[i][j], maxi);
		}
		printf("%d��° �ִ밪 : %d \n", i, maxi);
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
	printf("������ ��ġ�� �ִ� �� : %d \n", maxi);
}

/*

1.	n���� ������ �̷���� ������ ������ �־����� ��, 
�� �� �� �� �̻��� ���ӵ� ���ڸ� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ͻÿ�.
���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 �̶�� ������ �־�����, ������ 12+21�� 33�̴�.

2.	N�� ����� �ö󰡷��� �Ѵ�. �Ź� ����� 1ĭ �Ǵ� 2ĭ�� �ö� �� �ִ�.
�� ������ �ö� �� �ִ� ����� ���� �� ������ ���Ͻÿ�.

3.	��� ��ü������ 100��, 60��, 8��¥��, 5��¥��, 1��¥�� ��ǥ�� �ִ�. 
Ư�� �ݾ��� �������� ���� ����ϴ� �ּ� ������ ��ǥ ������ ���Ͻÿ�. 

4.	ũ�� 3, 4, 5 �̰�, ��ġ�� ���� 6, 3, 5�� ������� ũ�� 10�� ������ �ִ�. 
���濡 �ִ� ������ ��ġ�� ���� �ִ밡 �ǵ��� ���� �� ���� ������ ���Ͻÿ�. 
��, ������ �߶� ���� �� ����, �ְų� ���� �ʴ� ��� �� �����ؾ� �Ѵ�. 

*/

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. �� �� �̻��� ���ӵ� ���ڸ� �����ؼ� ���� �� �ִ� �� �� ���� ū ��\n");
	printf("2. ����� �ö󰡴� ����� �� \n");
	printf("3. �ּ� ��ǥ ���� \n");
	printf("4. ���濡 �ִ� ���� ��ġ �ִ� \n");
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
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}