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
		printf("비교 횟수 : %d \n", num2 + 1);
		return -1;
	}

	if (target == arr[mid])
	{
		printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(500);
		printf("비교 횟수 : %d \n", num2 + 1);
		return mid;
	}

	else if (target < arr[mid])
	{
		printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(500);
		Recur_Bsearch(arr, target, first, mid - 1, num2 + 1);
	}

	else
	{
		printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
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

	printf("몇 개의 배열을 입력받으시겠습니까? : ");
	scanf("%d", &last);

	for (int i = 0; i < last; i++)
	{
		arr[i] = i*2;
		printf(" %d ", arr[i]);
	}
	printf("\n");

	last -= 1;
	printf("찾으려는 타겟 입력 : ");
	scanf("%d", &target);

	result = Recur_Bsearch(arr, target, first, last, num2);

	if (result == -1)
	{
		printf("타겟을 찾지 못했습니다. \n");
	}

	else
	{
		printf("찾으려는 타겟 [ %d ]는 [ %d ]번째 인덱스에 있습니다. \n", target, result);
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
				printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
				printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
				cnt++;
				printf("\n");
				Sleep(200);
				return mid;
				break;
			}

			else if (target < arr[mid])
			{
				printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
				last = mid - 1;
				printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
				cnt++;
				printf("\n");
				Sleep(200);
			}

			else
			{
				printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
				first = mid + 1;
				printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
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

	printf("몇 개의 배열을 입력받으시겠습니까? : ");
	scanf("%d", &last);

	for (int i = 0; i < last; i++)
	{
		arr[i] = i * 2;
		printf(" %d ", arr[i]);
	}
	printf("\n");

	last -= 1;
	printf("찾으려는 타겟 입력 : ");
	scanf("%d", &target);

	result = Iter_Bsearch(arr, target, first, last);

	printf("비교 횟수 : %d \n", cnt);
	cnt = 0;

	if (result == -1)
	{
		printf("타겟을 찾지 못했습니다. \n");
	}

	else
	{
		printf("찾으려는 타겟 [ %d ]는 [ %d ]번째 인덱스에 있습니다. \n", target, result);
		
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

	printf("몇 개의 배열을 입력받으시겠습니까? : ");
	scanf("%d", &last);

	for (int i = 0; i < last; i++)
	{
		arr[i] = i * 2;
		printf(" %d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < last; i++)
	{
		printf("================[%d 번째]=====================\n", i+1);
		result=Iter_Bsearch(arr, arr[i], first, last-1);
		aver += cnt;
		if (worst < cnt)
			worst = cnt;
		printf("비교 횟수 : %d \n", cnt);
		printf("찾은 값 : %d \n", arr[result]);
		cnt = 0;
		printf("==============================================\n");
	}
	
	aver /= last;
	printf("평균 : %lf \n", aver);
	printf("최악의 경우 : %d \n", worst);
}

int num = 0;
int Fibo(int n)
{
	num++;
	printf("Fibo(%d)를 호출 \n", n);
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

	printf("몇 번쨰 값을 구하시겠습니까? : ");
	scanf("%d", &n);

	result = Fibo(n);
	printf("결과값 : %d \n", result);
	printf("호출 횟수 : %d", num);
	num = 0;
	printf("\n");
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 재귀함수 이진 검색 \n");
	printf("2. 반복문 이진 검색 \n");
	printf("3. 피보나치 \n");
	printf("4. 평균값과 최악의 경우 계산 \n");
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
			printf("다시 입력하세요. \n");
			break;
		}
	}
}