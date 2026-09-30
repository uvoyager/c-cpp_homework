#include <stdio.h>
#include <stdint.h>
typedef int16_t fixed_point_t;

int main() {
    double x, y;
    printf("input real number x: ");
    scanf("%lf", &x);
    printf("input real number y: ");
    scanf("%lf", &y);
    double d = x - y;
    double m = x*y;

    int frac_bits = 8;
    double scale = 256.0;
    fixed_point_t fix_x = (fixed_point_t)(x*scale);
    fixed_point_t fix_y = (fixed_point_t)(y*scale);
    fixed_point_t fix_d = (fixed_point_t)(d*scale);
    fixed_point_t fix_m = (fixed_point_t)(((uint32_t)fix_x * fix_y) >> frac_bits);

    printf("x-y = %d\n", fix_d);
    printf("x*y = %u", fix_m);
    
}