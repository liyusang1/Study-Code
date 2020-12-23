#include "MyMsg.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

void signalHandler(int signum);
int checkAge(Student student);

key_t mykey = 0;
int msqid = 0;

int main() {
    MsgCalc msgCalc;
    MsgRslt msgRslt;

    mykey = ftok("mymsgkey", 1);
    msqid = msgget(mykey, IPC_CREAT | 0600);

    signal(SIGINT, signalHandler);

    while (1) {
        puts("Wait....");
        memset(&msgCalc, 0x00, sizeof(MsgCalc));
        msgrcv(msqid, &msgCalc, MSG_SIZE_CALC, MSG_TYPE_CALC, 0);
        printf("Recevie information : \n");
        printf("#Name : %s\n", msgCalc.student.name);
        printf("#Phone-Number : %s\n", msgCalc.student.phoneNum);
        printf("#age : %d\n", msgCalc.student.age);

        memset(&msgRslt, 0x00, sizeof(MsgRslt));
        msgRslt.mtype = MSG_TYPE_RSLT;
        msgRslt.rslt = checkAge(msgCalc.student);
        msgsnd(msqid, &msgRslt, MSG_SIZE_RSLT, 0);
        printf("\n");

        fflush(stdout);
    }

    return 0;
}

void signalHandler(int signum) {
    if (signum == SIGINT) {
        msgctl(msqid, IPC_RMID, NULL);
        exit(0);
    }
}

int checkAge(Student student) {

    if (student.age > 19)
        return 1;
    else if (student.age < 19)
        return 0;
}
