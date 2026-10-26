#include <stdio.h>
#include "date.h"
int main() {
    Date data_test[]=
    {
        {2026, 10, 8},
        {2026, 12, 31},
        {2025, 4, 30},
        {2020, 2, 28},
        {2020, 2, 29},
    };
    Date data_test_res[]={
        {2026, 10, 9},
        {2027, 1, 1},
        {2025, 5, 1},
        {2020, 2, 29},
        {2020, 3, 1},
    };
    int n_test=sizeof(data_test)/sizeof(Date);
    for (int i=0;i<n_test;i++) {
        print_date(data_test[i]);
        printf("\n");
        print_date(tomorrow(data_test[i]));
        printf("\n");
        printf("Day of week: ");
        day_of_week(data_test[i]);
        printf("\n");
    }
    return 0;
}