#ifndef __MYSTUDENT_H
#define __MYSTUDENT_H

#include <string>

#define MAX_NAME_LEN 32

class Student {

  private:
    int id;
    char name[MAX_NAME_LEN + 1];
    double score;

  public:
    Student();
    Student(int id, std::string name, double score);

    void setId(int id);
    void setName(std::string name);
    void setScore(double score);

    int getId();
    std::string getName();
    double getScore();
};

#endif
