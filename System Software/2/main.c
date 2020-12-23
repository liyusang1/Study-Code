#include <dirent.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024

void filemode(const struct stat *fileinfo);

int main(int argc, char const *argv[]) {

    char Cwd[MAX_PATH_LEN + 1] = {'\0'};
    getcwd(Cwd, MAX_PATH_LEN);

    struct stat fileInfo;
    DIR *dirp;
    struct dirent *dirInfo;
    struct passwd *userInfo;

    if (argc != 2) {
        printf("Usage : %s [pathname]\n", argv[0]);
        exit(-1);
    }

    if (stat(argv[1], &fileInfo) == -1) {
        perror("stat error");
        exit(-1);
    }

    if (!S_ISDIR(fileInfo.st_mode)) {
        fprintf(stderr, "%s is not directory!\n", argv[1]);
        exit(-1);
    }

    printf("Directory to search : %s \n", argv[1]);

    dirp = opendir(argv[1]);
    while ((dirInfo = readdir(dirp)) != NULL) {
        stat(dirInfo->d_name, &fileInfo);
        filemode(&fileInfo);
        userInfo = getpwuid(fileInfo.st_uid);
        printf("  %s  ", userInfo->pw_name);
        printf("%10ld  ", fileInfo.st_size);
        printf("%10ld  ", fileInfo.st_mtime);
        printf("%s\n", dirInfo->d_name);
    }

    closedir(dirp);

    return 0;
}

void filemode(const struct stat *fileInfo) {

    if (S_IRUSR & fileInfo->st_mode) {
        printf("r");
    } else {
        printf("-");
    }

    if (S_IWUSR & fileInfo->st_mode) {
        printf("w");
    } else {
        printf("-");
    }

    if (S_IXUSR & fileInfo->st_mode) {
        printf("x");
    } else {
        printf("-");
    }

    if (S_IRGRP & fileInfo->st_mode) {
        printf("r");
    } else {
        printf("-");
    }

    if (S_IWGRP & fileInfo->st_mode) {
        printf("w");
    } else {
        printf("-");
    }

    if (S_IXGRP & fileInfo->st_mode) {
        printf("x");
    } else {
        printf("-");
    }

    if (S_IROTH & fileInfo->st_mode) {
        printf("r");
    } else {
        printf("-");
    }

    if (S_IWOTH & fileInfo->st_mode) {
        printf("w");
    } else {
        printf("-");
    }

    if (S_IXOTH & fileInfo->st_mode) {
        printf("x");
    } else {
        printf("-");
    }
}
