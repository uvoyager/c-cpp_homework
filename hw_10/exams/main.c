#include <stdio.h>
#include "exams_res.h"

int tests() {
    STUDENT students[3] = {
        {"Mitchell",    "KB-21", "Math", 90, "Physics", 85, "Programming", 95},
        {"Johansson",  "KB-21", "Math", 75, "Physics", 80, "Programming", 88},
        {"Carter", "KB-22", "Math", 95, "Physics", 92, "Programming", 98}
    };
    for (int i = 0; i < 3; i++) {
        print_student(&students[i]);
        print_worst_course(&students[i]);
        printf("\n");
    }
}

int main() {
    printf("tests are: \n");
    tests();

    //user's input part
    STUDENT student;
    input_student(&student);
    printf("your student is: ");
    print_student(&student);
    printf("\n");
    print_worst_course(&student);
}