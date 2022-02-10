#include <stdio.h>
#include <string.h>
#include <windows.h>

int Recursive(int *arr, int n)
{
	if (n == 0)
		return arr[0];
	int maxnum = Recursive(arr, n - 1);

	if (maxnum < arr[n])
	{
		return arr[n];
	}
	else
		arr[n] = maxnum;
	return arr[n];
}

int UseFor(int *arr)
{
	int max = arr[0];

	for (int i = 0;i < 10;i++)
	{
		if (max <= arr[i])
			max = arr[i];
	}

	return max;
}

int main(void)
{
	int arr[10] = { 0, };
	int random;
	int n = 9;

	printf("�迭 10�� ������ �Է� : ");
	for (int i = 0;i < 10;i++)
	{
		random = rand() % 101;
		arr[i] = random;
		printf("%d ", arr[i]);
	}
	printf("\n");

	int max1 = Recursive(arr, n);
	int max2 = UseFor(arr);
	printf("��ȯ ȣ�� : %d \n", max1);
	printf("�ݺ��� : %d", max2);

	return 0;
}