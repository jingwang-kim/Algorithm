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
		printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(1000);
		printf("비교 횟수 : %d \n", num + 1);
		return mid;
	}

	else if (target > arr[mid])
	{
		printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
		printf("\n");
		Sleep(1000);
		Recur_Bsearch(arr, target, mid + 1, last, num+1);
	}

	else
	{
		printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
		printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
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

	printf("배열에 입력할 정수 설정 : ");
	scanf("%d", &last);

	printf("배열 %d개 무작위 입력: ", last);
	for (int i = 0; i < last; i++)
	{
		arr[i] = rand() % 101 + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");

	//정렬
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

	//정렬 확인
	printf("정렬 확인 : ");
	for (int i = 0; i < last; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	last -= 1;

	//이진검색
	printf("찾으려는 타겟 입력 : ");
	scanf("%d", &target);

	printf("\n");
	result=Recur_Bsearch(arr, target, first, last, num);

	if (result == -1)
	{
		printf("타겟을 찾지 못했습니다. \n");
	}

	else
	{
		printf("찾으려는 타겟 %d는 %d번째 인덱스에 있습니다. \n", target, result);
		printf("찾은 값 : %d \n", arr[result]);
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
				printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
				printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
				num++;
				printf("\n");
				Sleep(1000);
				printf("찾으려는 타겟 %d는 %d번째 인덱스에 있습니다. \n", target, mid);
				break;
			}

			else if (target > arr[mid])
			{
				printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
				first = mid + 1;
				printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
				num++;
				printf("\n");
				Sleep(1000);
			}

			else
			{
				printf("현재 검색 범위 : [ %d ~ %d ] \n", arr[first], arr[last]);
				last = mid - 1;
				printf("현재 중간값과 인덱스 : [ %d ], [ %d ] \n", arr[mid], mid);
				num++;
				printf("\n");
				Sleep(1000);
			}
		}

		else
		{
			printf("값이 존재하지 않습니다. \n");
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

	printf("배열에 입력할 정수 설정 : ");
	scanf("%d", &last);

	printf("배열 %d개 무작위 입력: ", last);
	for (int i = 0; i < last; i++)
	{
		arr[i] = rand() % 101 + 1;
		printf("%d ", arr[i]);
	}
	printf("\n");

	//정렬
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

	//정렬 확인
	printf("정렬 확인 : ");
	for (int i = 0; i < last; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	last -= 1;
	//이진검색
	printf("찾으려는 타겟 입력 : ");
	scanf("%d", &target);
	printf("\n");
	result = For_Bsearch(arr, target, first, last);
	printf("비교 횟수 : %d \n", result);
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

				printf("%d 단계 : ", (i + 1));
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

	printf("배열에 입력할 정수 설정 : ");
	scanf("%d", &n);

	//랜덤
	printf("배열에 %d개만큼의 정수 랜덤 저장: ", n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n");
	Selection(arr, n);
	printf("최종 : ");
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

	printf("몇 번째 값을 구하시겠습니까? ");
	scanf("%d", &n);

	result=Fibo(n);
	printf("결과값 : %d \n", result);
	printf("호출 횟수 : %d \n", num);
	num = 0;
	printf("\n");
}

void menu()
{
	printf("---------------menu--------------- \n");
	printf("1. 재귀함수 이진 검색 \n");
	printf("2. 반복문 이진 검색 \n");
	printf("3. 선택정렬 \n");
	printf("4. 피보나치 재귀 \n");
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
			printf("다시 입력하세요.");
			break;
		}
	}
}