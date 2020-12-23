//c언어 p445 문제3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



void checkNameAndAge(char arr1[], char arr2[]);  //두 사용자의 이름과 나이를 비교하는 함수.


int main()
{
	char ch1 [30];
	char ch2 [30];

	fputs("사용자의 이름과 나이 입력 (이름 입력후 띄어쓰기후 나이 입력) : ", stdout);
	fgets(ch1, sizeof(ch1), stdin);
	
	fputs("사용자의 이름과 나이 입력 (이름 입력후 띄어쓰기후 나이 입력) : ", stdout);
	fgets(ch2, sizeof(ch2), stdin); 

	checkNameAndAge(ch1, ch2);


	return 0;
}



void checkNameAndAge(char arr1[], char arr2[])
{
	int len1 = 0;
	int len2 = 0;

	for (len1; arr1[len1] != ' '; len1++)
	{}

	for (len2; arr2[len2] != ' '; len2++)
	{}

	if (len1 == len2)
	{
		if ( !strncmp(arr1, arr2, len1) )
			printf("같은 이름 입니다.\n");
		else
			printf("다른 이름 입니다.\n");
	}
	else
		printf("다른 이름입니다.\n");


	if (arr1[len1+1] == arr2[len2+1] && arr1[len1 + 2] == arr2[len2 + 2])
		printf("같은 나이 입니다.\n");
	else
		printf("다른 나이 입니다");
}