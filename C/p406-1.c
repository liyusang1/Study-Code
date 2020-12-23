//C언어 연습 2020 07 08 도전 프로그래밍 p406-1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void changeOrder(int array[][4], int len)  
{
	int temp[4][4];

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			temp[i][j] = array[i][j];
		}
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			array[i][j] = temp[3 - j][i];
		}
	}
}

void printArray(int array[][4], int len)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int array[][4] = {
		{1,2,3,4},
		{5,6,7,8,},
		{9,10,11,12},
		{13,14,15,16}
	};

	printf("기존 배열\n");
	printArray(array, 4);
	changeOrder(array, 4);
	printf("\n");

	printf("90도 돌린 배열\n");
	printArray(array, 4);
	changeOrder(array, 4);
	printf("\n");

	printf("90도 돌린 배열\n");
	printArray(array, 4);
	changeOrder(array, 4);
	printf("\n");

	printf("90도 돌린 배열\n");
	printArray(array, 4);
	changeOrder(array, 4);
	printf("\n");

	printf("90도 돌린 배열\n");
	printArray(array, 4);
	changeOrder(array, 4);
	printf("\n");



	

	return 0;
}