//c언어 p445 문제1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int checkNumber(char array[]); 
int convertToInt(char c);

int main()
{
	char array[50];
	fputs("숫자를 포함하는 적당한 길이의 문자열 입력 : ", stdout);
	fgets(array, sizeof(array), stdin);

	int sumOfArray = checkNumber(array);

	printf("입력한 문자열 중에서 숫자의 합 : %d \n", sumOfArray);
	printf("문자열의 길이: %d ", strlen(array));

	return 0;
}

int checkNumber(char array[]) //입력받은 문자열을 첫번째 배열부터 검사하여 숫자면 저장하는 함수
{
	int count = 0;
	int len = strlen(array);
	

	for (int i = 0; i < len-1; i++)
	{
		if (array[i] >= '1' && array[i] <= '9')
			count += convertToInt(array[i]);
	}

	return count;
}

int convertToInt(char c) //문자열을 숫자로 바꿔주는 함수
{
	return c-48;
}