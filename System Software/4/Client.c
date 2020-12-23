#include "MyMsg.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

int main() {
    key_t mykey = ftok("mymsgkey", 1);
    int msqid = msgget(mykey, IPC_CREAT);

    char name[20];
    char phoneNum[20];
    int age;

    MsgCalc msgCalc;
    MsgRslt msgRslt;

    while (1) {
        puts("Input Student's Name : ");
        scanf("%s", name);

        puts("Input Student's Phone Number : ");
        scanf("%s", phoneNum);

        puts("Input Student's Age : ");
        scanf("%d", &age);

        printf("<<<<<");
        fflush(stdout);
        fflush(stdin);

        memset(&msgCalc, 0x00, sizeof(MsgCalc));
        msgCalc.mtype = MSG_TYPE_CALC;
        strcpy(msgCalc.student.name, name);
        strcpy(msgCalc.student.phoneNum, phoneNum);
        msgCalc.student.age = age;
        msgsnd(msqid, &msgCalc, MSG_SIZE_CALC, 0);

        memset(&msgRslt, 0x00, sizeof(MsgRslt));
        msgrcv(msqid, &msgRslt, MSG_SIZE_RSLT, MSG_TYPE_RSLT, 0);
        if (msgRslt.rslt == 1)
            printf("성인입니다.\n");
        if (msgRslt.rslt == 0)
            printf("성인이 아닙니다.\n");
    }
    return 0;
}
