#include "LpcProxy.h"
#include "Lpc.h"
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

long makePid = 1;
key_t mykey = 0;
int msqid = 0;

void Init(void) {
    mykey = ftok("mymsgkey", 1);
    msqid = msgget(mykey, IPC_CREAT);
}

int OpenFile(char *path, int flags) {

    LpcResponse lpcResponse;
    LpcRequest lpcRequest;

    memset(&lpcRequest, 0x00, sizeof(LpcRequest));
    lpcRequest.pid = 1;
    lpcRequest.service = LPC_OPEN_FILE;
    lpcRequest.numArg = 2;
    // lpcRequest.lpcArgs[0].argSize = sizeof(path);
    strcpy(lpcRequest.lpcArgs[0].argData, path);

    lpcRequest.lpcArgs[1].argSize = flags; // mode;

    int error =
        msgsnd(msqid, &lpcRequest, sizeof(LpcRequest) - sizeof(long), 0);
    if (error == -1) {
        perror("open msgsnd error");
    }

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    msgrcv(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 1, 0);

    /*if (lpcResponse.errorno < 0) {
        printf("Fail file open.... \n");
    } else {
        printf("Success File Open....\n");
    }*/

    return lpcResponse.errorno;
}

int ReadFile(int fd, void *pBuf, int size) {

    LpcResponse lpcResponse;
    LpcRequest lpcRequest;

    memset(&lpcRequest, 0x00, sizeof(LpcRequest));
    lpcRequest.pid = 2;
    lpcRequest.service = LPC_READ_FILE;
    lpcRequest.numArg = 2;
    lpcRequest.lpcArgs[0].argSize = fd;   // fd
    lpcRequest.lpcArgs[1].argSize = size; // buf size;

    int error =
        msgsnd(msqid, &lpcRequest, sizeof(LpcRequest) - sizeof(long), 0);
    if (error == -1) {
        perror("read msgsnd error");
    }

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    msgrcv(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 2, 0);

    strcpy(pBuf, lpcResponse.responseData);

    /*if (lpcResponse.responseData < 0) {
        printf("Fail file read.... \n");
    } else {
        printf("Success File Read....\n");
    }*/

    return lpcResponse.responseSize;
}

int WriteFile(int fd, void *pBuf, int size) {

    LpcResponse lpcResponse;
    LpcRequest lpcRequest;

    memset(&lpcRequest, 0x00, sizeof(LpcRequest));
    lpcRequest.pid = 3;
    lpcRequest.service = LPC_WRITE_FILE;
    lpcRequest.numArg = 3;
    lpcRequest.lpcArgs[0].argSize = fd;   // fd
    lpcRequest.lpcArgs[1].argSize = size; // buf size;
    strcpy(lpcRequest.lpcArgs[1].argData,
           pBuf); // pBuf -> lpcRequest.lpcArgs[1].argData

    int error =
        msgsnd(msqid, &lpcRequest, sizeof(LpcRequest) - sizeof(long), 0);
    if (error == -1) {
        perror("write msgsnd error");
    }

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    msgrcv(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 3, 0);

    /* if (lpcResponse.responseData < 0) {
         printf("Fail WRITE... \n");
     } else {
         printf("Success WRITE....\n");
     }*/

    return lpcResponse.responseSize;
}

off_t SeekFile(int fd, off_t offset, int whence) {

    LpcResponse lpcResponse;
    LpcRequest lpcRequest;

    memset(&lpcRequest, 0x00, sizeof(LpcRequest));
    lpcRequest.pid = 4;
    lpcRequest.service = LPC_SEEK_FILE;
    lpcRequest.numArg = 3;
    lpcRequest.lpcArgs[0].argSize = fd;     // fd
    lpcRequest.lpcArgs[1].argSize = offset; // offset
    lpcRequest.lpcArgs[2].argSize = whence; // whence
    int error =
        msgsnd(msqid, &lpcRequest, sizeof(LpcRequest) - sizeof(long), 0);
    if (error == -1) {
        perror("Seek msgsnd error");
    }

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    msgrcv(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 4, 0);

    /*if (lpcResponse.errorno < -1) {
        printf("SeekFile Error!!..... \n");
    } else {
        printf("Success SeekFile..... \n");
    }*/

    return lpcResponse.errorno;
}

int CloseFile(int fd) {

    LpcResponse lpcResponse;
    LpcRequest lpcRequest;

    memset(&lpcRequest, 0x00, sizeof(LpcRequest));
    lpcRequest.pid = 5;
    lpcRequest.service = LPC_CLOSE_FILE;
    lpcRequest.numArg = 1;
    lpcRequest.lpcArgs[0].argSize = fd; // fd

    int error =
        msgsnd(msqid, &lpcRequest, sizeof(LpcRequest) - sizeof(long), 0);
    if (error == -1) {
        perror("close msgsnd error");
    }

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    msgrcv(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 5, 0);

    /* if (lpcResponse.errorno == 0)
         printf("Success File Close....\n");
     else if (lpcResponse.errorno == 0) {
         printf("File Close error!!\n");
     }*/

    return lpcResponse.errorno;
}

int MakeDirectory(char *path, int mode) {

    LpcResponse lpcResponse;
    LpcRequest lpcRequest;

    memset(&lpcRequest, 0x00, sizeof(LpcRequest));
    lpcRequest.pid = 6;
    lpcRequest.service = LPC_MAKE_DIRECTORY;
    lpcRequest.numArg = 2;
    lpcRequest.lpcArgs[0].argSize = sizeof(path);
    strcpy(lpcRequest.lpcArgs[0].argData, path);
    lpcRequest.lpcArgs[1].argSize = mode; // mode;

    int error =
        msgsnd(msqid, &lpcRequest, sizeof(LpcRequest) - sizeof(long), 0);
    if (error == -1) {
        perror("mkdir msgsnd error");
    }

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    msgrcv(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 6, 0);

    /* if (lpcResponse.errorno == 0) {
         printf("Success Create Dierctory.... \n");
     } else {
         printf("Fail Creat Directory....\n");
     }*/

    return lpcResponse.errorno;
}

int RemoveDirectory(char *path) {

    LpcResponse lpcResponse;
    LpcRequest lpcRequest;

    memset(&lpcRequest, 0x00, sizeof(LpcRequest));
    lpcRequest.pid = 7;
    lpcRequest.service = LPC_REMOVE_DIRECTORY;
    lpcRequest.numArg = 1;
    strcpy(lpcRequest.lpcArgs[0].argData, path);

    int error =
        msgsnd(msqid, &lpcRequest, sizeof(LpcRequest) - sizeof(long), 0);
    if (error == -1) {
        perror("rmdir msgsnd error");
    }

    memset(&lpcResponse, 0x00, sizeof(LpcResponse));
    msgrcv(msqid, &lpcResponse, sizeof(LpcResponse) - sizeof(long), 7, 0);

    /*  if (lpcResponse.errorno < 0) {
          printf("Fail Remove DIRECTROY.... \n");
      } else if (lpcResponse.errorno == 0) {
          printf("Success Remove DIRECTROY....\n");
      }*/

    return lpcResponse.errorno;
}
