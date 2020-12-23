//code up 1420 3µÓ√£±‚ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	int len;
	char name[30][30];
	int score[30];
	char thrid_name[20];

	scanf("%d", &len);

	for (int i = 0; i < len; i++) {
		scanf("%s %d", &name[i], &score[i]);
	}

	int max = 0;
	int max_2 = 0;
	int max_3 = 0;

	for (int i = 0; i < len; i++) {

		if (score[i] > max)
			max = score[i];
	}

	for (int i = 0; i < len; i++) {

		if ((score[i] > max_2) && (score[i] < max))
			max_2 = score[i];
	}
    
	for (int i = 0; i < len; i++) {

		if ((score[i] > max_3 ) && (score[i] < max_2)) {
			max_3 = score[i];
			strcpy(thrid_name, name[i]);
		}
	}

	printf("%s", thrid_name);

	return 0;
}
