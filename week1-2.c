#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void UseFor(int n, int b)
{
	char arr[30] = { 0, };
	int count = 0;

	while (1)
	{
		int remain = n % b;

		if (remain < 10)
			arr[count] = remain + 48;

		else
			arr[count] = (remain - 10) + 65;

		n /= b;
		count++;

		if (n == 0)
			break;
	}
	
	for (int i = count-1;i >=0;i--)
	{
		printf("%c", arr[i]);
	}
	
}

void Recursive(int n, int b)
{
	int remain;
	remain = n % b;
	n /= b;
	if (n > 0)
		Recursive(n, b);
	if (remain < 10)
		printf("%d", remain);
	else
		printf("%c", (remain - 10) + 65);
}

int main(void)
{

	int n = 0;
	printf("10진수 n 입력 : ");
	scanf("%d", &n);

	int b = 0;
	printf("b 진수로 변환(2~16진수까지) : ");
	scanf("%d", &b);

	printf("반복 : ");
	UseFor(n, b);
	printf("(%d)", b);
	printf("\n");

	printf("순환 : ");
	Recursive(n, b);
	printf("(%d)", b);


	return 0;
}