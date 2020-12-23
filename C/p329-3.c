//C언어 연습 2020 07 06 도전프로그래밍3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int array[10];
	int num;
	int countFirst = 0;
	int countLast = 0;

	for (int i = 0; i < 10; i++)
	{
		printf("정수 입력 : ");
		scanf("%d", &num);
		if (num % 2 != 0)
		{
			array[0 + countFirst] = num;
			countFirst++;
		}
		
		else
		{
			array[9 - countLast] = num;
			countLast++;
		}
	}

	for (int i = 0; i < 10; i++)
	{

		printf("%d ", array[i]);
	}

	return 0;
}

