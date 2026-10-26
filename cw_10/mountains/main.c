#include <stdio.h>
#include <stdlib.h>

#include "mountains.h"

int main() {
    Mountain mountains[]={
        {"Everest", 8848},
        {"K2", 8611},
        {"Kangchenjunga", 8586}
    };

    int count = sizeof(mountains)/sizeof(mountains[0]);

    printf("Highest mountain from mountains[]: \n");
    Mountain highest=highestMountain(mountains,count);
    printMountain(highest);

    printMountainByName(mountains,count, "Everest");
    printMountainByName(mountains,count, "Kilimanjaro");

    int n;
    printf("enter the number of mountains to input: ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    Mountain *m=malloc(sizeof(Mountain)*n);
    if (m==NULL) {
        return 1;
    }

    for (int i=0; i<n; i++) {
        if (!inputMountain(&m[i])) {
            free(m);
            return 1;
        }
    }
    for (int i=0; i<n; i++) {
        printMountain(m[i]);
    }

    char name[MAX_NAME_LENGTH];
    printf("enter the name of the mountain to search: ");
    if (scanf("%s", name) == 1) {
        printMountainByName(mountains, count, name);
    }

    free(m);
    return 0;
}