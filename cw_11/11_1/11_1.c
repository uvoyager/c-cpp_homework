#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

size_t input_array_elements(double* array, size_t max_size) {
    size_t count;
    printf("enter number of elements in array: (max) ");
    if (scanf("%zu", &count) != 1 || count > max_size) {
        return 0;
    }
    for (size_t i = 0; i < count; i++) {
        printf("enter element %zu: ", i+1);
        if (scanf("%lf", &array[i]) != 1) {
            return 0;
        }
    }
    return count;
}

void write_array_elements(const double* array, size_t max_size) {
    for (size_t i = 0; i < max_size; i++) {
        printf("element %zu: %lf, ", i+1, array[i]);
    }
}

size_t write_to_file(const double* array, size_t count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return 0;
    }
    for (size_t i = 0; i < count; i ++) {
        size_t written = fprintf(file, "%lf\n", array[i]);
        if ( written < 0 ) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return count;
}

size_t read_from_file(double* array, size_t max_size, const char* filename) {
    FILE* file = fopen(filename, "rt");
    if (file == NULL) {
        return 0;
    }
    size_t count = 0;
    while (count < max_size && fscanf(file, "%lf", &array[count]) == 1) {
        count ++;
    }
    fclose(file);
    return count;
}

int main() {
    const size_t max_size = 100;
    double array[max_size];
    size_t count = input_array_elements(array, max_size);
    if (count == 0) {
        printf("error reading array\n");
        return 0;
    }
    write_array_elements(array, count);
    write_to_file(array, count, "output_11_1.txt");
    read_from_file(array, count, "output_11_1.txt");
}