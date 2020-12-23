#ifndef __MYMSG_H_
#define __MYMSG_H

#define MSG_TYPE_CALC 1
#define MSG_TYPE_RSLT 2

#define MSG_SIZE_CALC (sizeof(MsgCalc) - sizeof(long))
#define MSG_SIZE_RSLT (sizeof(MsgRslt) - sizeof(long))

struct Student {
    char name[20];
    int age;
    char phoneNum[20];
};
typedef struct Student Student;

struct MsgCalc {
    long mtype;
    struct Student student;
};
typedef struct MsgCalc MsgCalc;

struct MsgRslt {
    long mtype;
    int rslt;
};
typedef struct MsgRslt MsgRslt;

#endif
