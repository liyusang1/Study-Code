//c��� p445 ����2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int main()
{
	char str1[20];
	char str2[20];
	char str3[40];

	fputs("ù��° �迭�� ���ڿ� �Է� : ", stdout);
	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1) - 1] = 0;

	fputs("�ι�° �迭�� ���ڿ� �Է� : ", stdout);
	fgets(str2, sizeof(str2), stdin);
	str2[strlen(str2) - 1] = 0;

	strcpy(str3, str1);
	strcat(str3, str2);

	puts(str3);


	// ���ǻ��� : ���ڿ��� �����Ҷ� /n���ڱ��� �Բ� ���� �Ǳ� ������ str2[strlen(str2) - 1] = 0;�� ���ؼ� �ι��ڸ� �Ҹ���� �־�� �Ѵ�!




	return 0;
}