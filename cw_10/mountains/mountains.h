#ifndef CLIONPROJECTS_MOUNTAINS_H
#define CLIONPROJECTS_MOUNTAINS_H
#include <stdbool.h>

#define MAX_NAME_LENGTH 50

typedef struct Mountain {
    char name[MAX_NAME_LENGTH];
    int height;
} Mountain;

void printMountain(Mountain m);
bool inputMountain(Mountain *m);
Mountain highestMountain(Mountain mountains[], int count);
void printMountainByName(Mountain mountains[], int count, const char* name);

#endif //CLIONPROJECTS_MOUNTAINS_H
