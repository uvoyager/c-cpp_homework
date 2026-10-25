#ifndef CLIONPROJECTS_PAR_H
#define CLIONPROJECTS_PAR_H
#include <stdbool.h>

typedef double GTYPE;

typedef struct TPOINT_ {
    GTYPE x;
    GTYPE y;
    GTYPE z;
}TPOINT;

    typedef struct RECTPAR_ {
    TPOINT a;
    TPOINT b;
    TPOINT c;
} RECTPAR;

extern void print_point(const TPOINT *p);
extern bool input_point(TPOINT *p);

extern void print_rectpar(const RECTPAR *p);
extern bool input_rectpar(RECTPAR *p);
#endif //CLIONPROJECTS_PAR_H
