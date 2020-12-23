#include <pthread.h>
#include <stdio.h>

void *myThread(void *arg);

int main() {
    pthread_t tid = 0;
    int count = 5;
    int *status;

    printf("hello, i'm main thread : %ld\n", pthread_self());

    if (pthread_create(&tid, NULL, myThread, (void *)&count)) {
        perror("pthread_create error");
        return -1;
    }

    pthread_join(tid, (void **)&status);
    printf("Thread %ld exit\n", tid);

    return 0;
}

void *myThread(void *arg) {
    int i = 0;
    int count = *(int *)arg;
    int status = 0;

    printf("hello. l'm new thread : %ld\n", pthread_self());

    for (i = count; i > 0; --i) {
        printf("%d...\n", i);
    }

    pthread_exit((void *)&status);
}
