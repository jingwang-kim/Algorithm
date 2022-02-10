#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int range = 0;
int level = 1;

int partition1(int* arr, int left, int right)  //마지막 값을 피봇으로
{
	printf("-------------< %d단계 >--------------- \n", level);

	int pivot = right;
	int i = left - 1;
	int temp;
	for (int j = left; j < right; j++)
	{
		for (int k = 0; k < range; k++)
		{
			if (k == pivot)
				printf("[ %d ] ", arr[k]);
			else
				printf(" %d ", arr[k]);
		}
		printf("\n \n");

		if (arr[j] < arr[pivot])
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

	}

	temp = arr[i + 1];
	arr[i + 1] = arr[right];
	arr[right] = temp;

	printf("-------------< %d단계 끝>--------------- \n", level);
	for (int k = 0; k < range; k++)
	{
		if (k == pivot)
			printf("[ %d ] ", arr[k]);
		else
			printf(" %d ", arr[k]);
	}
	printf("\n");

	printf("pivot : %d \n", arr[pivot]);
	printf("\n");
	
	level++;
	return i + 1;
}
int partition2(int* arr, int left, int right)  //첫번째 값을 피봇으로
{
	printf("-------------< %d단계 >--------------- \n", level);



	int pivot = left;
	int i = right + 1;
	int temp;
	for (int j = right; j > left; j--)
	{

		for (int k = 0; k < range; k++)
		{
			if (k == pivot)
				printf("[ %d ] ", arr[k]);
			else
				printf(" %d ", arr[k]);
		}
		printf("\n \n");

		if (arr[j] > arr[pivot])
		{
			i--;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

	}

	temp = arr[i - 1];
	arr[i - 1] = arr[left];
	arr[left] = temp;

	printf("-------------< %d단계 끝>--------------- \n", level);
	for (int k = 0; k < range; k++)
	{
		if (k == pivot)
			printf("[ %d ] ", arr[k]);
		else
			printf(" %d ", arr[k]);
	}
	printf("\n");
	printf("pivot : %d \n", arr[pivot]);
	printf("\n");

	level++;
	return i - 1;
}
int partition3(int* arr, int left, int right)  //중간값을 피봇으로
{
	printf("-------------< %d단계 >--------------- \n", level);

	int pivot = (left + right) / 2;
	int value = arr[pivot];
	int i = left;
	int j = right;
	int temp;

	while (i < j)
	{
		for (int k = 0; k < range; k++)
		{
			if (k == pivot)
				printf("[ %d ] ", arr[k]);
			else
				printf(" %d ", arr[k]);
		}
		printf("\n \n");

		while (arr[i] < value && i < j)
			i++;

		while (arr[j] >= value && i < j)
			j--;

		if (i < j )
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}

		if(arr[i]==value || arr[j]==value)     //수정 코드~ 
		{
			for (int t = 0; t < range; t++)    //제어를 걸어주지 않으면 피벗이 어디로 갈지 모르기 때문에 현재 i와 j번째 인덱스에
			{                                  //있는 값들이 피벗의 value와 같다면 배열안엣 value의 값과 같은 인덱스를 찾아서
				if (value == arr[t])           //그 값을 피벗으로 변환한다.
				{
					pivot = t;
				}
			}
		}                                      //~까지
	}

	temp = arr[pivot];
	arr[pivot] = arr[j];
	arr[j] = temp;

	printf("-------------< %d단계 끝>--------------- \n", level);
	for (int k = 0; k < range; k++)
	{
		if (k == pivot)
			printf("[ %d ] ", arr[k]);
		else
			printf(" %d ", arr[k]);
	}
	printf("\n");
	printf("pivot : %d \n", arr[pivot]);
	printf("\n");

	level++;
	return j;
}

void quick_sort1(int* arr, int left, int right)
{
	if (left < right)
	{
		int q = partition1(arr, left, right);
		quick_sort1(arr, left, q - 1);
		quick_sort1(arr, q + 1, right);
	}
}

void quick_sort2(int* arr, int left, int right)
{
	if (left < right)
	{
		int q = partition2(arr, left, right);
		quick_sort2(arr, left, q - 1);
		quick_sort2(arr, q + 1, right);
	}
}

void quick_sort3(int* arr, int left, int right)
{
	if (left < right)
	{
		int q = partition3(arr, left, right);
		quick_sort3(arr, left, q - 1);
		quick_sort3(arr, q + 1, right);
	}
}

void quick_sort_main()
{
	//배열 선언
	int arr[100] = { 0, };
	int left = 0;
	int right;
	int part = 0;
	printf("배열에 저장할 정수 개수 입력 : ");
	scanf("%d", &right);
	range = right;

	//arr에 값 입력
	srand(time(NULL));
	printf("-------------< 정렬 전 >--------------- \n");
	for (int i = 0; i < right; i++)
	{
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	printf("\n \n");

	//파티션 선택 및 quick_sort실행
	printf("파티션 선택 ( 1. 끝값, 2. 첫값, 3. 중간값 ) : ");
	scanf("%d", &part);
	
	switch (part)
	{
	case 1:
		quick_sort1(arr, left, right - 1);
		break;

	case 2:
		quick_sort2(arr, left, right - 1);
		break;

	case 3:
		quick_sort3(arr, left, right - 1);
		break;

	default:
		printf("입력 오류.\n");
		break;
	}
	

	//최종 결과
	printf("-------------< 최 종 >--------------- \n");
	for (int i = 0; i < right; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	range = 0;
	level = 1;
}

int main(void)
{
	printf("\n");
	printf("-------------< 퀵정렬 >--------------- \n");
	printf("\n");

	int choice;
	quick_sort_main();

	do {

		printf("\n");
		printf("다시 실행하시겠습니까? (1.Yes 0.No) : ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			quick_sort_main();
			break;

		case 0:
			return 0;

		default:
			printf("다시 입력하세요. \n");
			break;
		}
	} while (1);

}