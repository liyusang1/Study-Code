//C언어 연습 2020 07 06 도전 프로그래밍2 p329

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char Pailndrome(char word[],int len)   //회문인지, 회문이 아닌지 판별해 주는 함수
{
	int correctCount = 0;
	char * first = word;
	char * last = &word[len - 1];
	
	for (int i = 0; i < (len / 2); i++)
	{
		if (*first == *last)
		{
			correctCount++;
		}

		first++;
		last--;

		if (correctCount == (len / 2))
		{
			printf("회문입니다.");
			return 0;
		}
	}
	printf("회문이 아닙니다.");

	return 0;
}

int lengthOfArray(char word[])   //문자열의 길이를 구하는 함수 
{
	int len = 0;
	while (word[len] != '\0')
		len++;

	return len;
}

int main()
{
	char word[50];
	printf("문자열 입력 : ");
	scanf("%s", word);

	int len = lengthOfArray(word);
	Pailndrome(word,len);

	
	return 0;
}

