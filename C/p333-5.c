//C언어 연습 2020 07 07 도전 프로그래밍 p333

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void DesSort(int array[], int len);
void inputArray(int array[],int len);
void printArray(int array[], int len);


int main ()
{
	int array[7];

	inputArray(array, 7);

	DesSort(array, 7);

	printArray(array, 7);
}


void inputArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d번 째 숫자 입력 : ", i + 1);
		scanf("%d", &array[i]);
	}
}



void DesSort(int array[], int len)  
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}


}


void printArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", array[i]);
	}

}
