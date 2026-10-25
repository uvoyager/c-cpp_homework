#ifndef CLIONPROJECTS_DATE_H
#define CLIONPROJECTS_DATE_H
#include <stdbool.h>

typedef struct Date_ {
    int year;
    int month;
    int day;
} Date;

extern const int DAY_MONTH[];
extern void print_date(Date d);
extern bool leap_year(Date d);
extern int day_month(Date d);
extern bool input_date(Date* d);
extern Date tomorrow(Date d);
extern Date yesterday(Date d);
extern void day_of_week(Date d);

#endif //CLIONPROJECTS_DATE_H
