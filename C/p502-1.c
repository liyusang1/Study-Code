//c언어 p502 문제1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    char writer[20];
    char name[20];
    int page;

}Book;

int main()
{
    Book book[3];

    printf("도서 정보 입력 \n");
    for (int i = 0; i < 3; i++)
    {
        fputs("저자 : ", stdout);
        fgets(book[i].writer, sizeof(book[i].writer), stdin);

        fputs("제목 : ", stdout);
        fgets(book[i].name, sizeof(book[i].name), stdin);

        fputs("페이지 수 : ", stdout);
        scanf("%d", &book[i].page);

        printf("\n");
        while (getchar() != '\n');
    }

    printf("도서 정보 출력 \n");
    for (int i = 0; i < 3; i++)
    {
        printf("book %d\n", i+1);

        printf("저자 : %s ", book[i].writer);

        printf("제목 : %s ", book[i].name);

        printf("페이지 수 : %d \n", book[i].page);

        printf("\n");
    }



    return 0;
}