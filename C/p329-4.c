//C��� ���� 2020 07 06 ���� ���α׷���2 p329

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char Pailndrome(char word[],int len)   //ȸ������, ȸ���� �ƴ��� �Ǻ��� �ִ� �Լ�
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
			printf("ȸ���Դϴ�.");
			return 0;
		}
	}
	printf("ȸ���� �ƴմϴ�.");

	return 0;
}

int lengthOfArray(char word[])   //���ڿ��� ���̸� ���ϴ� �Լ� 
{
	int len = 0;
	while (word[len] != '\0')
		len++;

	return len;
}

int main()
{
	char word[50];
	printf("���ڿ� �Է� : ");
	scanf("%s", word);

	int len = lengthOfArray(word);
	Pailndrome(word,len);

	
	return 0;
}

