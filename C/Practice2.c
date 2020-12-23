//C언어 연습 2020 07 06 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void input(char array[])
{
	printf("알파벳을 입력해 주세요 : ");
	scanf("%s", array);
}

int arrayLength(char array[])
{
	int len = 0;
	while (array[len] != '\0')
	{
		len++;
	}

	return len;
}

void changeArray(char array[],int len)
{
	char* first = array;
	char* last = &array[len - 1];

	for (int i = 0; i < len / 2; i++)
	{
		char temp = *first;
		*first = *last;
		*last = temp;
		first++;
		last--;
	}

}
int main() {

	char array[30];

	input(array);
	int len = arrayLength(array);
	changeArray(array, len);

	printf("%s\n", array);
	printf("---------\n");
	printf("---------\n");
	printf("---------\n");
	printf("---------\n");

	char array2[30];

	input(array2);
	len = arrayLength(array2);
	changeArray(array2, len);
	printf("%s", array2);



	return 0;
}