#ifndef CLIONPROJECTS_RECTANGLE_H
#define CLIONPROJECTS_RECTANGLE_H
#include <stdbool.h>

typedef double GTYPE;

typedef struct TPOINT_ {
    GTYPE x;
    GTYPE y;
} TPOINT;
typedef struct RECT_ {
    TPOINT A;
    TPOINT B;
} RECT;

extern void printPoint(const TPOINT *p);
extern bool inputPoint(TPOINT *p);

extern void printRect(const RECT *p);
extern bool inputRect(RECT *p);

#endif //CLIONPROJECTS_RECTANGLE_H
