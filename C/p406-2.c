//C��� ���� 2020 07 08 ���� ���α׷��� p406-2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void snail(int array[][50], int len);


int main()
{
	int array[50][50] = { 0 };
	int len;
	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf("%d", &len);

	snail(array, len); //������ �迭 �Լ� ȣ��

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			printf("%7d", array[i][j]);
		}
		printf("\n");
	}

	return 0;
}


void snail(int array[][50], int len)
{
	int num = 0;
	int k = 0;

	while (k < len-1)
	{
		for (int i = k; i <= len - 1-k; i++) //����1
		{
			array[k][i]=++num;
		}

		for (int i = k; i < len - 1-k; i++)  //����1
		{
			array[i][len - k - 1] = ++num;
		}

		for (int i = k; i < len - 1-k; i++) //����2
		{
			array[len - k - 1][len - i - 1] = ++num;
		}

		for (int i = k; i < len - 1-k; i++) //����2
		{
			array[len - i - 1][k] = ++num;
		}

		k++;

	}
}