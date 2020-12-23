#include "Lpc.h"
#include "LpcProxy.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

extern int OpenFile(char *path, int flags);
extern int ReadFile(int fd, void *pBuf, int size);
extern int WriteFile(int fd, void *pBuf, int size);
extern int CloseFile(int fd);
extern off_t SeekFile(int fd, off_t offset, int whence);
extern int MakeDirectory(char *path, int mode);
extern int RemoveDirectory(char *path);

int main(void) {

    Init();
    char data[50]; // ReadFile function data
    char data2[255] = "is kevin here? ..";
    char data3[255] = "hi every one.."; // writefile data

    int fd = OpenFile("testcase.txt", O_CREAT | O_RDWR);

    MakeDirectory("kevin", 0600);

    int writeSize = WriteFile(fd, data2, sizeof(data2));
    printf("size : %d\n", writeSize);

    SeekFile(fd, 0, SEEK_SET);

    int readSize = ReadFile(fd, data, sizeof(data));
    printf("size : %d\n", readSize);
    printf("%s \n", data);

    RemoveDirectory("testcaseDir");

    CloseFile(fd);

    fd = OpenFile("testcase2.txt", O_CREAT | O_RDWR);
    writeSize = WriteFile(fd, data3, sizeof(data3));
    printf("size : %d\n", writeSize);

    CloseFile(fd);
    fd = OpenFile("testcase2.txt", O_CREAT | O_RDWR);

    readSize = ReadFile(fd, data, sizeof(data));
    printf("size : %d\n", readSize);
    printf("%s \n", data);
    CloseFile(fd);

    return 0;
}
