//C��� ���� 2020 07 06 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void inputGrade(int array[][5])  //����ڷκ��� �����Է¹޾Ƽ� �迭�� �����ϵ��� �ϴ� �Լ�
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf(" %d ��° �����Է� : \n", i + 1);
			scanf("%d", &array[i][j]);
		}
	}
}

void calculateArray(int array[][5])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			array[i][4] += array[i][j];
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			array[4][i] += array[j][i];
		}
	}
}

void outputArray(int array[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}
}


int main() 
{
	int array[5][5] = {0};

	inputGrade(array);

	calculateArray(array);

	outputArray(array);



	return 0;
}