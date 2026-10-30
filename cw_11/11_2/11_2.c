#include <stdio.h>
#include <stdlib.h>


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

size_t write_to_binary(const double* array, size_t count, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return 0;
    }
    size_t written = fwrite(array, sizeof(double), count, file);
    fclose(file);
    return written;
}

size_t read_array_from_binary(double* array, size_t max_size, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return 0;
    }
    size_t count = 0;
    while (count < max_size && !feof(file)) {
        size_t read = fread(&array[count], sizeof(double), 1, file);
        if (read != 1) {
            break;
        }
        if (count == 0) {
            printf("%g", array[count]);
        }
        else {
            printf("%g", array[count]);
        }
        count ++;
    }
    fclose(file);
    return count;
}

int select_greater_than(const double* array, size_t count, double threshold, const char* input_filename, const char* output_filename) {
    FILE* infile = fopen(input_filename, "rb");
    if (infile == NULL) {
        return 0;
    }
    FILE* outfile = fopen(output_filename, "wb");
    if (outfile == NULL) {
        fclose(infile);
        return 0;
    }
    FILE* tmpfile = fopen("tmp.dat", "wb");
    if (tmpfile == NULL) {
        fclose(infile);
        fclose(outfile);
        return 0;
    }
    size_t select_count = 0;
    for (size_t i = 0; i < count; i++) {
        if (array[i] > threshold) {
            if (fwrite(&array[i], sizeof(double), 1, outfile) != 1) {
                fclose(infile);
                fclose(outfile);
                return select_count;
            }
            select_count++;
        }
    }
    fclose(infile);
    fclose(outfile);
    fclose(tmpfile);
    rename("tmp.dat", input_filename);
    return select_count;
}

int main() {
    const size_t max_size = 100;
    double array[max_size];
    size_t count = input_array_elements(array, max_size);
    if (count == 0) {
        printf("there is an error when reading an array\n");
        return 1;
    }
    write_array_elements(array, count);
    write_to_binary(array, count, "output_11_2.bin");
    read_array_from_binary(array, count, "output_11_2.bin");
    select_greater_than(array, count, 3.5, "output_11_2.bin", "output_selected_11_2.bin");
}