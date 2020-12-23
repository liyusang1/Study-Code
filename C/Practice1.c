//C언어 연습 2020 07 06 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Fibo(int n)             //피보나치 수열 함수 
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else  
		return Fibo(n - 1) + Fibo(n - 2);	
}

void PrintFibo(int n)     //사용자로부터 숫자하나를 받아서 첫번째 부터 그 숫자까지의 피보나치 함수를 출력
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
	printf("양의 정수를 입력해 주세요 : ");
	scanf("%d", &userNum);

	PrintFibo(userNum);

	return 0;
}
