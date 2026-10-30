#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_sqrt(int x) {
    if (x<0) return false;
    int root = (int) sqrt(x+0.5);
    return x==root*root;
}

size_t input_array_elements(int *array, size_t max_size) {
    size_t count = 0;
    do {
        if (count >= max_size) {
            printf("Maximum array size reached (%zu).\n", max_size);
            break;
        }
        printf("Enter element %zu (0 to stop): ", count + 1);
        if (scanf("%d", &array[count]) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            continue;
        }
        if (array[count] == 0) {
            break;
        }
        count++;
    } while (1);
    return count;
}

void write_array_elements(const int* array, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("element %zu: %d, ", i+1, array[i]);
    }
}

size_t write_to_file(const int *array, size_t count, const char *filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return 0;
    }
    for (size_t i = 0; i < count; i ++) {
        int written = fprintf(file, "%d\n", array[i]);
        if ( written < 0 ) {
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    return count;
}

size_t read_from_file(int* array, size_t count, const char* filename) {
    FILE* file = fopen(filename, "rt");
    if (file == NULL) {
        return 0;
    }
    size_t i = 0;
    while (i < count && fscanf(file, "%d", &array[i]) == 1) {
        i ++;
    }
    fclose(file);
    return i;
}

int select_square_root(const char *input_filename, const char *output_filename) {
    FILE *infile = fopen(input_filename, "rt");
    if (infile == NULL) {
        return 0;
    }
    FILE *outfile = fopen(output_filename, "w");
    if (outfile == NULL) {
        fclose(infile);
        return 0;
    }
    int value;
    int select_count = 0;
    while (fscanf(infile, "%d", &value) == 1) {
        if (is_sqrt(value)) {
            if (fprintf(outfile, "%d\n", value) < 0) {
                break;
            }
            select_count++;
        }
    }
    fclose(infile);
    fclose(outfile);
    return select_count;
}

int main() {
    size_t max = 300;
    int array[max];
    size_t count = input_array_elements(array, max);
    if (count == 0) {
        printf("there is an error  with reading array\n");
    }
    write_array_elements(array, count);
    write_to_file(array, count, "output_11_3.txt");
    read_from_file(array, count, "output_11_3.txt");
    select_square_root("output_11_3.txt", "output_selected_11_3.txt");
}