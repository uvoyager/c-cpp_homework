#include <stdio.h>
#include <stdbool.h>

#include "mountains.h"

#include <string.h>

void printMountain(Mountain m) {
    printf("Mountain name in : %s\n", m.name);
    printf("Mountain height: %d\n", m.height);
}
void printMountainByName(Mountain mountains[], int count, const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(mountains[i].name, name) == 0) { //check for same strings
            printMountain(mountains[i]);
            return;
        }
    }
    printf("Mountain with name %s not found\n", name);
}
Mountain highestMountain(Mountain mountains[], int count) {
    Mountain highest=mountains[0];
    for (int i = 1; i < count; i++) {
        if (mountains[i].height > highest.height) {
            highest = mountains[i];
        }
    }
    return highest;
}
bool inputMountain(Mountain *m) {
    printf("Input mountain name: ");
    if (scanf("%s", m->name) != 1) {
        return false;
    }
    printf("Input mountain height: ");
    if (scanf("%d", &m->height) != 1) {
        return false;
    }
    return true;
}