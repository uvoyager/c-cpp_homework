#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "date.h"

const int DAY_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap_year(Date d) {
    return d.year%4 == 0 || (d.year%100 == 0 && d.year%400 == 0);
}

int day_month(Date d) {
    if (d.month == 2 && leap_year(d)){
        return 29;
    }
    return DAY_MONTH[d.month-1];
}

void print_date(Date d) {
    printf("%d/%d/%d", d.day, d.month, d.year);
}

bool input_date(Date* d) {
    printf("input year, month and a day: ");

    int r1=scanf("%d", &d->year);
    if(r1 != 1) return false;
    int r2=scanf("%d", &d->month);
    if(r2 != 1) return false;
    if (d->month < 1 || d->month > 12) return false;
    int r3=scanf("%d", &d->day);
    if(r3 != 1) return false;
    if (d->day < 1 || d->day > DAY_MONTH[d->month -1]) return false;

    return true;
}

Date tomorrow(Date d) {
    Date res = d;
    int last_day_month = day_month(d);
    if (d.day < last_day_month) {
        res.day++;
    }
    else {
        res.day = 1;
        if (d.month < 12) {
            res.month ++;
        }
        else {
            res.month = 1;
            res. year++;
        }
    }
    return res;
}

Date yesterday(Date d) {
    Date res = d;
    if (d.day>1) {
        res.day --;
    }
    else {
        if (d.month > 1) {
            res.month --;
        }
        else {
            res.month = 12;
            res.year --;
        }
        res.day = day_month(res);
    }
    return res;
}

void day_of_week(Date d) {
    if (d.month < 3) {
        d.month += 12;
        d.year -= 1;
    }
    int D = d.year%100;
    int C = d.year/100;
    int day = (d.day + 13*(d.month+1)/5+D+D/4+C/4 - 2*C)%7;
    day = (day%7 + 7)%7;
    const char *days[] = {"saturday", "sunday", "monday", "tuesday", "thursday", "friday"};
    printf("%s\n", days[day]);
}