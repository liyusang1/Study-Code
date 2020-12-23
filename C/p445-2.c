//c언어 p445 문제2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int main()
{
	char str1[20];
	char str2[20];
	char str3[40];

	fputs("첫번째 배열의 문자열 입력 : ", stdout);
	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1) - 1] = 0;

	fputs("두번째 배열의 문자열 입력 : ", stdout);
	fgets(str2, sizeof(str2), stdin);
	str2[strlen(str2) - 1] = 0;

	strcpy(str3, str1);
	strcat(str3, str2);

	puts(str3);


	// 주의사항 : 문자열을 복사할때 /n문자까지 함께 복사 되기 때문에 str2[strlen(str2) - 1] = 0;을 통해서 널문자를 소멸시켜 주어야 한다!




	return 0;
}