//c��� p445 ����1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int checkNumber(char array[]); 
int convertToInt(char c);

int main()
{
	char array[50];
	fputs("���ڸ� �����ϴ� ������ ������ ���ڿ� �Է� : ", stdout);
	fgets(array, sizeof(array), stdin);

	int sumOfArray = checkNumber(array);

	printf("�Է��� ���ڿ� �߿��� ������ �� : %d \n", sumOfArray);
	printf("���ڿ��� ����: %d ", strlen(array));

	return 0;
}

int checkNumber(char array[]) //�Է¹��� ���ڿ��� ù��° �迭���� �˻��Ͽ� ���ڸ� �����ϴ� �Լ�
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

int convertToInt(char c) //���ڿ��� ���ڷ� �ٲ��ִ� �Լ�
{
	return c-48;
}