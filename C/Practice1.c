//C��� ���� 2020 07 06 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Fibo(int n)             //�Ǻ���ġ ���� �Լ� 
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else  
		return Fibo(n - 1) + Fibo(n - 2);	
}

void PrintFibo(int n)     //����ڷκ��� �����ϳ��� �޾Ƽ� ù��° ���� �� ���ڱ����� �Ǻ���ġ �Լ��� ���
{

	for (int i = 1; i <= n; i++)
	{
		printf("%d", Fibo(i));
		printf("\n");
	}
}

int main()
{
	int userNum;
	printf("���� ������ �Է��� �ּ��� : ");
	scanf("%d", &userNum);

	PrintFibo(userNum);

	return 0;
}
