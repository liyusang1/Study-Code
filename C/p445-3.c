//c��� p445 ����3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



void checkNameAndAge(char arr1[], char arr2[]);  //�� ������� �̸��� ���̸� ���ϴ� �Լ�.


int main()
{
	char ch1 [30];
	char ch2 [30];

	fputs("������� �̸��� ���� �Է� (�̸� �Է��� ������ ���� �Է�) : ", stdout);
	fgets(ch1, sizeof(ch1), stdin);
	
	fputs("������� �̸��� ���� �Է� (�̸� �Է��� ������ ���� �Է�) : ", stdout);
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
			printf("���� �̸� �Դϴ�.\n");
		else
			printf("�ٸ� �̸� �Դϴ�.\n");
	}
	else
		printf("�ٸ� �̸��Դϴ�.\n");


	if (arr1[len1+1] == arr2[len2+1] && arr1[len1 + 2] == arr2[len2 + 2])
		printf("���� ���� �Դϴ�.\n");
	else
		printf("�ٸ� ���� �Դϴ�");
}