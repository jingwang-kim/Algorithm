#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//int arr[10] = { 2, 4,6,8,10,12,14,16,18,20 };

int Recur_Bsearch(int *arr, int target, int first, int last, int num2)
{
	int mid = (first + last) / 2;

	if (first > last)
	{
		printf("�� Ƚ�� : %d \n", num2 + 1);
		return -1;
	}

	if (target == arr[mid])
	{
		printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(500);
		printf("�� Ƚ�� : %d \n", num2 + 1);
		return mid;
	}

	else if (target < arr[mid])
	{
		printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(500);
		Recur_Bsearch(arr, target, first, mid - 1, num2 + 1);
	}

	else
	{
		printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(500);
		Recur_Bsearch(arr, target, mid + 1, last, num2 + 1);
	}
	
}
void Recur_Bsearch_main()
{
	int arr[100] = { 0, };
	int first=0;
	int last;
	int num2=0;
	int result;
	int target;

	printf("�� ���� �迭�� �Է¹����ðڽ��ϱ�? : ");
	scanf("%d", &last);

	for (int i = 0; i < last; i++)
	{
		arr[i] = i*2;
		printf(" %d ", arr[i]);
	}
	printf("\n");

	last -= 1;
	printf("ã������ Ÿ�� �Է� : ");
	scanf("%d", &target);

	result = Recur_Bsearch(arr, target, first, last, num2);

	if (result == -1)
	{
		printf("Ÿ���� ã�� ���߽��ϴ�. \n");
	}

	else
	{
		printf("ã������ Ÿ�� [ %d ]�� [ %d ]��° �ε����� �ֽ��ϴ�. \n", target, result);
	}

	

}

int cnt = 0;
int Iter_Bsearch(int *arr, int target, int first, int last)
{

	while (1)
	{
		if (first <= last)
		{
			int mid = (first + last) / 2;

			if (target == arr[mid])
			{
				printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
				printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
				cnt++;
				printf("\n");
				Sleep(200);
				return mid;
				break;
			}

			else if (target < arr[mid])
			{
				printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
				last = mid - 1;
				printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
				cnt++;
				printf("\n");
				Sleep(200);
			}

			else
			{
				printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
				first = mid + 1;
				printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
				cnt++;
				printf("\n");
				Sleep(200);
			}
		}

		else
		{
			return -1;
		}
	}

}
void Iter_Bsearch_main()
{
	int arr[100] = { 0, };
	int first = 0;
	int last;
	int target;
	int result;
	int aver[100] = { 0, };
	int j = 0;

	printf("�� ���� �迭�� �Է¹����ðڽ��ϱ�? : ");
	scanf("%d", &last);

	for (int i = 0; i < last; i++)
	{
		arr[i] = i * 2;
		printf(" %d ", arr[i]);
	}
	printf("\n");

	last -= 1;
	printf("ã������ Ÿ�� �Է� : ");
	scanf("%d", &target);

	result = Iter_Bsearch(arr, target, first, last);

	printf("�� Ƚ�� : %d \n", cnt);
	cnt = 0;

	if (result == -1)
	{
		printf("Ÿ���� ã�� ���߽��ϴ�. \n");
	}

	else
	{
		printf("ã������ Ÿ�� [ %d ]�� [ %d ]��° �ε����� �ֽ��ϴ�. \n", target, result);
		
	}
	
	
}

void Aver()
{
	int arr[100] = { 0, };
	int first = 0;
	int last;
	int result;
	double aver = 0;
	int worst=0;

	printf("�� ���� �迭�� �Է¹����ðڽ��ϱ�? : ");
	scanf("%d", &last);

	for (int i = 0; i < last; i++)
	{
		arr[i] = i * 2;
		printf(" %d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < last; i++)
	{
		printf("================[%d ��°]=====================\n", i+1);
		result=Iter_Bsearch(arr, arr[i], first, last-1);
		aver += cnt;
		if (worst < cnt)
			worst = cnt;
		printf("�� Ƚ�� : %d \n", cnt);
		printf("ã�� �� : %d \n", arr[result]);
		cnt = 0;
		printf("==============================================\n");
	}
	
	aver /= last;
	printf("��� : %lf \n", aver);
	printf("�־��� ��� : %d \n", worst);
}

int num = 0;
int Fibo(int n)
{
	num++;
	printf("Fibo(%d)�� ȣ�� \n", n);
	printf("\n");

	if (n == 0)
		return 0;

	else if (n == 1)
		return 1;

	else
		return Fibo(n - 2) + Fibo(n - 1);
}
void Fibo_main()
{
	int n;
	int result;

	printf("�� ���� ���� ���Ͻðڽ��ϱ�? : ");
	scanf("%d", &n);

	result = Fibo(n);
	printf("����� : %d \n", result);
	printf("ȣ�� Ƚ�� : %d", num);
	num = 0;
	printf("\n");
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. ����Լ� ���� �˻� \n");
	printf("2. �ݺ��� ���� �˻� \n");
	printf("3. �Ǻ���ġ \n");
	printf("4. ��հ��� �־��� ��� ��� \n");
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
			Recur_Bsearch_main();
			break;

		case 2:
			Iter_Bsearch_main();
			break;

		case 3:
			Fibo_main();
			break;

		case 4:
			Aver();
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���. \n");
			break;
		}
	}
}