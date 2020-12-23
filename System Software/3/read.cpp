#include "MyStudent.hpp"
#include <fcntl.h>
#include <iostream>
#include <list>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main() {
    list<Student> StuList;
    Student temp;

    string filepath = "./StudentList.dat";
    int fd = open("./StudentList.dat", O_CREAT | O_APPEND | O_RDWR, 777);
    if (fd == -1) {
        perror("open error");
        return 1;
    }

    while (read(fd, &temp, sizeof(Student)) != 0) {
        StuList.push_back(temp);
    }

    int num = 1;

    list<Student>::iterator iter;
    for (iter = StuList.begin(); iter != StuList.end(); ++iter) {
        cout << num << "번째 학생 정보" << endl;
        cout << "ID:" << (*iter).getId() << ", "
             << "Name: " << (*iter).getName() << ", "
             << "Score: " << (*iter).getScore() << endl;
        num++;
    }
    close(fd);

    return 0;
}
