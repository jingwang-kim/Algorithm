#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int Recur_Bsearch(int* arr, int target, int first, int last, int num)
{
	int mid = (first + last) / 2;

	if (first > last)
		return -1;

	if (target == arr[mid])
	{
		printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(1000);
		printf("�� Ƚ�� : %d \n", num + 1);
		return mid;
	}

	else if (target > arr[mid])
	{
		printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(1000);
		Recur_Bsearch(arr, target, mid + 1, last, num+1);
	}

	else
	{
		printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(1000);
		Recur_Bsearch(arr, target, first, mid - 1, num+1);
	}

}
void Recur_Bsearch_main()
{
	int arr[100] = { 0, };
	int target = 0;
	int first = 0;
	int last;
	int num=0;
	int result;
	int temp;

	printf("�迭�� �Է��� ���� ���� : ");
	scanf("%d", &last);

	printf("�迭 %d�� ������ �Է�: ", last);
	for (int i = 0; i < last; i++)
	{
		arr[i] = rand() % 101 + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");

	//����
	for (int i = 0; i < last - 1; i++)
	{
		for (int j = 0; j < last - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	//���� Ȯ��
	printf("���� Ȯ�� : ");
	for (int i = 0; i < last; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	last -= 1;

	//�����˻�
	printf("ã������ Ÿ�� �Է� : ");
	scanf("%d", &target);

	printf("\n");
	result=Recur_Bsearch(arr, target, first, last, num);

	if (result == -1)
	{
		printf("Ÿ���� ã�� ���߽��ϴ�. \n");
	}

	else
	{
		printf("ã������ Ÿ�� %d�� %d��° �ε����� �ֽ��ϴ�. \n", target, result);
		printf("ã�� �� : %d \n", arr[result]);
	}

}

int For_Bsearch(int* arr, int target, int first, int last)
{
	int num = 0;

	while (1)
	{
		if (first <= last)
		{
			int mid = (first + last) / 2;

			if (target == arr[mid])
			{
				printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
				printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
				num++;
				printf("\n");
				Sleep(1000);
				printf("ã������ Ÿ�� %d�� %d��° �ε����� �ֽ��ϴ�. \n", target, mid);
				break;
			}

			else if (target > arr[mid])
			{
				printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
				first = mid + 1;
				printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
				num++;
				printf("\n");
				Sleep(1000);
			}

			else
			{
				printf("���� �˻� ���� : [ %d ~ %d ] \n", arr[first], arr[last]);
				last = mid - 1;
				printf("���� �߰����� �ε��� : [ %d ], [ %d ] \n", arr[mid], mid);
				num++;
				printf("\n");
				Sleep(1000);
			}
		}

		else
		{
			printf("���� �������� �ʽ��ϴ�. \n");
			break;
		}

	}

	return num;
}
void For_Bsearch_main()
{
	int arr[100] = { 0, };
	int target = 0;
	int first = 0;
	int last;
	int result;
	int temp;

	printf("�迭�� �Է��� ���� ���� : ");
	scanf("%d", &last);

	printf("�迭 %d�� ������ �Է�: ", last);
	for (int i = 0; i < last; i++)
	{
		arr[i] = rand() % 101 + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");

	//����
	for (int i = 0; i < last - 1; i++)
	{
		for (int j = 0; j < last - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	//���� Ȯ��
	printf("���� Ȯ�� : ");
	for (int i = 0; i < last; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	last -= 1;
	//�����˻�
	printf("ã������ Ÿ�� �Է� : ");
	scanf("%d", &target);
	printf("\n");
	result = For_Bsearch(arr, target, first, last);
	printf("�� Ƚ�� : %d \n", result);
}

void Selection(int *arr, int n)
{
	int j = 0;
	int i = 0;
	int temp;

	for(int i=0;i<n;i++)
	{
		for (j = i; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				printf("%d �ܰ� : ", (i + 1));
				for (int k = 0; k < n; k++)
				{
					printf(" %d ", arr[k]);
				}
				printf("\n");

			}
		}
	}
}
void Selection_main()
{
	int arr[100] = { 0, };
	int n;

	printf("�迭�� �Է��� ���� ���� : ");
	scanf("%d", &n);

	//����
	printf("�迭�� %d����ŭ�� ���� ���� ����: ", n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n");
	Selection(arr, n);
	printf("���� : ");
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");

}

int num = 0;
int Fibo(int n)
{
	num++;
	if (n == 0)
	{
		return 0;
	}

	else if (n == 1)
	{
		return 1;
	}

	else
	{
		return Fibo(n-2)+Fibo(n-1);
	}
}
void Fibo_main()
{
	int n;
	int result;

	printf("�� ��° ���� ���Ͻðڽ��ϱ�? ");
	scanf("%d", &n);

	result=Fibo(n);
	printf("����� : %d \n", result);
	printf("ȣ�� Ƚ�� : %d \n", num);
	num = 0;
	printf("\n");
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. ����Լ� ���� �˻� \n");
	printf("2. �ݺ��� ���� �˻� \n");
	printf("3. �������� \n");
	printf("4. �Ǻ���ġ ��� \n");
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
			For_Bsearch_main();
			break;

		case 3:
			Selection_main();
			break;

		case 4:
			Fibo_main();
			break;

		case 0:
			return 0;

		default:
			printf("�ٽ� �Է��ϼ���.");
			break;
		}
	}
}