#ifndef CLIONPROJECTS_EXAMS_RES_H
#define CLIONPROJECTS_EXAMS_RES_H
#include <stdbool.h>

typedef struct STUDENT {
    char surname[30];
    char group[20];
    char course_1[30];
    int note_1;
    char course_2[30];
    int note_2;
    char course_3[30];
    int note_3;
}STUDENT;

extern bool input_student(STUDENT *student);
extern void print_student(const STUDENT *student);


void print_worst_course(const STUDENT *student);

#endif //CLIONPROJECTS_EXAMS_RES_H
