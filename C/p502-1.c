//c��� p502 ����1

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

    printf("���� ���� �Է� \n");
    for (int i = 0; i < 3; i++)
    {
        fputs("���� : ", stdout);
        fgets(book[i].writer, sizeof(book[i].writer), stdin);

        fputs("���� : ", stdout);
        fgets(book[i].name, sizeof(book[i].name), stdin);

        fputs("������ �� : ", stdout);
        scanf("%d", &book[i].page);

        printf("\n");
        while (getchar() != '\n');
    }

    printf("���� ���� ��� \n");
    for (int i = 0; i < 3; i++)
    {
        printf("book %d\n", i+1);

        printf("���� : %s ", book[i].writer);

        printf("���� : %s ", book[i].name);

        printf("������ �� : %d \n", book[i].page);

        printf("\n");
    }



    return 0;
}