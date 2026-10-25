#include "exams_res.h"
#include <stdio.h>
#include <stdlib.h>

void print_student(const STUDENT *p) {
    printf("surname: %s\n", p -> surname);
    printf("group: %s\n", p -> group);
    printf("subjects: %s, %s, %s\n", p -> course_1, p -> course_2, p -> course_3);
    printf("grades: %d, %d, %d", p -> note_1, p -> note_2, p -> note_3);
}

bool input_student(STUDENT *p) {
    if (p == NULL) return false;
    printf("surname: ");
    if (scanf("%29s", p->surname) != 1) return false;
    printf("group: ");
    if (scanf("%19s", p->group) != 1) return false;
    printf("Enter course 1 name and grade (out of 100): ");
    if (scanf("%29s %d", p->course_1, &p->note_1) != 2) return false;
    printf("Enter course 2 name and grade (out of 100): ");
    if (scanf("%29s %d", p->course_2, &p->note_2) != 2) return false;
    printf("Enter course 3 name and grade (out of 100): ");
    if (scanf("%29s %d", p->course_3, &p->note_3) != 2) return false;
    return true;
}

void print_worst_course(const STUDENT *p) {
    int grades[] = {p->note_1, p->note_2, p->note_3};
    int min_grade = grades[0];
    for (int i = 0; i < 3; i++) {
        if (grades[i] < min_grade) min_grade = grades[i];
    }
    if (min_grade == p -> note_1) {
        printf("the worst grade is %d in %s\n", min_grade, p->course_1);
    }
    if (min_grade == p -> note_2) {
        printf("the worst grade is %d in %s\n", min_grade, p->course_2);
    }
    if (min_grade == p -> note_3) {
        printf("the worst grade is %d in %s\n", min_grade, p->course_3);
    }
}