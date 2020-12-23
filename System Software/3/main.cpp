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
    while (1) {
        string input;

        cout << " ID (input 'q' to terminate ) : ";
        cin >> input;

        if (input.compare("q") == 0) {
            cout << "input terminate ";
            break;
        }

        int id = stoi(input);

        string name = " ";
        cout << "Name : ";
        cin >> name;

        double score = -1.0;
        cout << "Score : ";
        cin >> score;

        Student stu(id, name, score);

        StuList.push_back(stu);
    }

    string filepath = "./StudentList.dat";
    int fd = open(filepath.c_str(), O_CREAT | O_APPEND | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open error");
        return 1;
    }

    list<Student>::iterator iter;
    for (iter = StuList.begin(); iter != StuList.end(); ++iter) {
        if (write(fd, &(*iter), sizeof(Student)) == -1) {
            perror("write() error");
            return 2;
        }
    }
    close(fd);

    return 0;
}
