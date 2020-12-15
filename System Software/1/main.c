#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    char *id = "#id : 2016317028\n";
    char *name = "#name : Lee yu sang\n";
    char *age = "#age : 24\n";
    char buf[100];

    int newDir = mkdir("2016317028", 0755);
    if (newDir == -1) {
        perror("error - make dir");
        exit(1);
    }

    int cd = chdir("2016317028");
    if (cd == -1) {
        perror("error - chage dir");
        exit(1);
    }

    int fd = open("./info.bin", O_CREAT | O_RDWR, 0755);
    if (fd == -1) {
        perror("error - make bin file");
        exit(1);
    }

    int wr = write(fd, (char *)name, strlen(name));
    if (wr == -1) {
        perror("error - write1");
        exit(1);
    }

    wr = write(fd, (char *)id, strlen(id));
    if (wr == -1) {
        perror("error - write2");
        exit(1);
    }

    wr = write(fd, (char *)age, strlen(age));
    if (wr == -1) {
        perror("error - write3");
        exit(1);
    }

    close(fd);

    fd = open("./info.bin", O_RDONLY);
    if (fd == -1) {
        perror("error - open bin file ");
        exit(1);
    }

    int rd = read(fd, buf, sizeof(buf));
    if (rd == -1) {
        perror("error - read bin file");
        exit(1);
    }

    printf("%s", buf);

    close(fd);

    return 0;
}
