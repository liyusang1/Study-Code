
#include "Lpc.h"
#include "LpcStub.h"

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

void signalHandler(int signum);
key_t mykey;
int msqid;

int main(void) {
    signal(SIGINT, signalHandler);

    Init();
    return 0;
}

void signalHandler(int signum) {
    if (signum == SIGINT) {
        msgctl(msqid, IPC_RMID, NULL);
        exit(0);
    }
}
