#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//����Ʈ�����к� 2016317028 ������

int introtateArray(int x[][50], int degree, int len);
void change(int array[][50], int len);

int main()
{
	int array[50][50] = { 0 };
	int len;
	printf("�迭�� ����� �Է��Ͻÿ� : ");
	scanf("%d", &len);

	change(array, len); 

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			printf("%7d", array[i][j]);
		}
		printf("\n");
	}

	int degree;
	printf("\n");
	printf("�迭�� �󸶸�ŭ ȸ�� ��Ű�ڽ��ϱ�? (90,180,270 �� ���� �Է� ) : ");
	scanf("%d", &degree);
	

	if (introtateArray(array, degree, len) == 0)
		printf("�ùٸ��� ���� ������ �Է������Ƿ� ȸ������ �ʽ��ϴ�\n");
	else
		printf("ȸ�� ��Ų ��� : \n");

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

void change(int array[][50], int len)
{
	int num = 0;
	int k = 0;

	while (k < len - 1)
	{
		for (int i = k; i <= len - 1 - k; i++) //����1
		{
			array[k][i] = ++num;
		}

		for (int i = k; i < len - 1 - k; i++)  //����1
		{
			array[i+1][len - k - 1] = ++num;
		}

		for (int i = k; i < len - 1 - k; i++) //����2
		{
			array[len - k - 1][len - i -2] = ++num;
		}

		for (int i = k; i < len - 2 - k; i++) //����2
		{
			array[len - i - 2][k] = ++num;
		}

		k++;

	}
}

int introtateArray(int x[][50], int degree, int len)
{

	int temp[50][50];

	if (degree == 270) {
		for (int k = 0; k < 3; k++) {

			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					temp[i][j] = x[i][j];
				}
			}

			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					x[i][j] = temp[len - j -1][i];
				}
			}
		}
		return 1;
	}

	else if (degree == 180) {
		for (int k = 0; k < 2; k++) {

			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					temp[i][j] = x[i][j];
				}
			}

			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					x[i][j] = temp[len - j-1][i];
				}
			}
		}
		return 1;
	}

	else if (degree == 90) {

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				temp[i][j] = x[i][j];
			}
		}

		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				x[i][j] = temp[len - j-1][i];
			}
		}
		return 1;
	}
	else
		return 0;
}
