#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//이유상

void getArray(int array[]);
int getMax(int array[]);
int getMin(int array[]);


int main() {

	int array[10];
	getArray(array);
	int min = getMin(array);
	int max = getMax(array);

	printf("max = %d\n", max);
	printf("min = %d\n", min);

	return 0;
}


void getArray(int array[]) {

	int temp;

	for (int i = 0; i < 10; i++) {

		printf("100보다 작은 정수를 입력하세요 (99를 입력하면 입력종료) : ");
		scanf("%d", &temp);
		if (temp >= 100) {
			printf("100보다 작은 정수를 입력하세요\n");
			--i;
			continue;
		}
		if (temp <= 0) {
			printf("0보다 큰 정수를 입력하세요\n");
			--i;
			continue;
		}
		if (i == 0 && temp == 99) {
			printf("입력된 값이 없으므로, 최대/최소 값은 존재하지 않습니다.");
			exit(1);
		}
		if (temp == 99) {
			break;
		}
		array[i] = temp;
	}
}


int getMax(int array[]) {

	int max = array[0];

	for (int i = 0; i < 10; i++) {

		if (array[i] > max)
			max = array[i];
	}

	return max;
}


int getMin(int array[]) {

	int min = array[0];

	for (int i = 0; i < 10; i++) {
		if (array[i] < 0)
			continue;

		if (array[i] < min)
			min = array[i];
	}
	return min;
}