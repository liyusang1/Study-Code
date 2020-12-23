
#include "LpcStub.h"
#include "Lpc.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

LpcRequest lpcRequest;
key_t mykey;
int msqid;

void Init(void) {

    mykey = ftok("mymsgkey", 1);
    msqid = msgget(mykey, IPC_CREAT | 0777);

    while (1) {
        puts("Waiting message....");
        memset(&lpcRequest, 0x00, sizeof(LpcRequest));
        int Error =
            msgrcv(msqid, &lpcRequest, sizeof(LpcRequest) - sizeof(long), 0, 0);
        if (Error == -1) {
            perror("msgrcv error");
        }

        else if (lpcRequest.service == LPC_MAKE_DIRECTORY) {

            printf("MAKE DIRECTORY '%s' command is confirmed....\n",
                   lpcRequest.lpcArgs[0].argData);
            MakeDirectory(lpcRequest.lpcArgs[0].argData,
                          lpcRequest.lpcArgs[1].argSize, lpcRequest.pid);
        }

        else if (lpcRequest.service == LPC_REMOVE_DIRECTORY) {

            printf("REMOVE DIRECTORY '%s' command is confirmed....\n",
                   lpcRequest.lpcArgs[0].argData);
            RemoveDirectory(lpcRequest.lpcArgs[0].argData, lpcRequest.pid);
        }

        else if (lpcRequest.service == LPC_CLOSE_FILE) {

            printf("CLOSE FILE command is confirmed, file fd : %d ....\n",
                   lpcRequest.lpcArgs[0].argSize);
            CloseFile(lpcRequest.lpcArgs[0].argSize, lpcRequest.pid);
        }

        else if (lpcRequest.service == LPC_WRITE_FILE) {

            printf("WRITE FILE command is confiremd, file fd : %d , content : "
                   "%s \n",
                   lpcRequest.lpcArgs[0].argSize,
                   lpcRequest.lpcArgs[1].argData);
            WriteFile(lpcRequest.lpcArgs[0].argSize,
                      lpcRequest.lpcArgs[1].argData,
                      lpcRequest.lpcArgs[1].argSize, lpcRequest.pid);
        }

        else if (lpcRequest.service == LPC_READ_FILE) {
            printf("READ FILE command is confirmed, file fd : %d ....\n",
                   lpcRequest.lpcArgs[0].argSize);
            ReadFile(lpcRequest.lpcArgs[0].argSize,
                     lpcRequest.lpcArgs[1].argSize, lpcRequest.pid);
        }

        else if (lpcRequest.service == LPC_OPEN_FILE) {
            printf("OPEN FILE '%s' command is confirmed .....\n",
                   lpcRequest.lpcArgs[0].argData);
            OpenFile(lpcRequest.lpcArgs[0].argData,
                     lpcRequest.lpcArgs[1].argSize, lpcRequest.pid);
        }

        else if (lpcRequest.service == LPC_SEEK_FILE) {
            printf("SEEKFILE command is comfirmed.....\n");
            SeekFile(lpcRequest.lpcArgs[0].argSize,
                     lpcRequest.lpcArgs[1].argSize,
                     lpcRequest.lpcArgs[2].argSize, lpcRequest.pid);
        }
        printf("\n");
    }
}

int OpenFile(char *path, int flag, int clientPid) {

    LpcResponse lpcResponse;

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));

    int fd = open(path, flag, 0777);

    if (fd == -1)
        perror("Open error ");

    lpcResponse.errorno = fd;
    lpcResponse.pid = clientPid;

    int error =
        msgsnd(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 0);
    if (error == -1) {
        perror("open msgsnd error");
    }
}

int ReadFile(int fd, int readCount, int clientPid) {
    LpcResponse lpcResponse;

    char buf[LPC_DATA_MAX];
    memset(&buf, 0x00, sizeof(buf));
    // char *buf = (char *)malloc(sizeof(char) * 512);

    lpcResponse.responseSize = read(fd, buf, readCount);

    if (lpcResponse.responseSize == -1)
        perror("Read error ");

    lpcResponse.pid = clientPid;
    strcpy(lpcResponse.responseData, buf);

    // free(buf);

    int error =
        msgsnd(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 0);
    if (error == -1) {
        perror("read msgsnd error");
    }
}

int WriteFile(int fd, char *pBuf, int writeCount, int clientPid) {
    LpcResponse lpcResponse;

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    lpcResponse.responseSize = write(fd, pBuf, writeCount);

    if (lpcResponse.responseSize == -1)
        perror("Write error ");

    lpcResponse.pid = clientPid;

    int error =
        msgsnd(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 0);
    if (error == -1) {
        perror("write msgsnd error");
    }
}

off_t SeekFile(int fd, off_t offset, int whence, int clientPid) {
    LpcResponse lpcResponse;

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    lpcResponse.errorno = lseek(fd, offset, whence);
    if (lpcResponse.errorno == -1)
        perror("Seek error ");
    lpcResponse.pid = clientPid;

    int error =
        msgsnd(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 0);
    if (error == -1) {
        perror("seek msgsnd error");
    }
}

int CloseFile(int fd, int clientPid) {

    LpcResponse lpcResponse;
    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    lpcResponse.errorno = close(fd);
    if (lpcResponse.errorno == -1)
        perror("Close error ");
    lpcResponse.pid = clientPid;

    int error =
        msgsnd(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 0);
    if (error == -1) {
        perror("close msgsnd error");
    }
}

int MakeDirectory(char *path, int mode, int clientPid) {
    LpcResponse lpcResponse;

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    lpcResponse.errorno = mkdir(path, mode);
    if (lpcResponse.errorno == -1)
        perror("mkdir error ");
    lpcResponse.pid = clientPid;

    int error =
        msgsnd(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 0);
    if (error == -1) {
        perror("mkdir msgsnd error");
    }
}

int RemoveDirectory(char *path, int clientPid) {
    LpcResponse lpcResponse;

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    lpcResponse.errorno = rmdir(path);
    if (lpcResponse.errorno == -1)
        perror("rmdir error ");
    lpcResponse.pid = clientPid;

    int error =
        msgsnd(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 0);
    if (error == -1) {
        perror("rmdir msgsnd error");
    }
}
