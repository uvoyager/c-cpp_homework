//task 11.9 v
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

size_t input_array_elements(int* array, size_t max_size) {
    size_t count;
    printf("enter number of elements in array: (max) ");
    if (scanf("%zu", &count) != 1 || count > max_size) {
        return 0;
    }
    for (size_t i = 0; i < count; i++) {
        printf("enter element %zu: ", i+1);
        if (scanf("%d", &array[i]) != 1) {
            return 0;
        }
    }
    return count;
}

size_t write_to_binary(const int* array, size_t count, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return 0;
    }
    size_t written = fwrite(array, sizeof(int), count, file);
    fclose(file);
    return written;
}

bool process_files(const char *file_f, const char *file_g) {
    FILE *f = fopen(file_f, "rb");
    if (f == NULL) {
        printf("error when opening file.\n");
        return false;
    }
    int pos_count = 0;
    int neg_count = 0;
    int val;
    while (fread(&val, sizeof(int), 1, f) == 1) {
        if (val > 0) pos_count++;
        else if (val < 0) neg_count++;
    }
    fclose(f);
    if (pos_count != neg_count) {
        printf("error: number of positive numbers (%d) is not equal to  number (%d) of negative numbers.\n",
               pos_count, neg_count);
        return false;
    }
    f = fopen(file_f, "rb");
    FILE *g = fopen(file_g, "wb");
    FILE *h = fopen("file_h.bin", "wb");
    if (!f || !g || !h) {
        if (f) fclose(f);
        if (g) fclose(g);
        if (h) fclose(h);
        printf("error when creating buffer files.\n");
        return false;
    }

    while (fread(&val, sizeof(int), 1, f) == 1) {
        if (val > 0) {
            fwrite(&val, sizeof(int), 1, g);
        } else if (val < 0) {
            fwrite(&val, sizeof(int), 1, h);
        }
    }
    fclose(f);
    fclose(g);
    fclose(h);
    g = fopen(file_g, "rb");
    h = fopen("file_h.bin", "rb");
    FILE *final_g = fopen(file_g, "wb");
    if (!g || !h || !final_g) {
        if (g) fclose(g);
        if (h) fclose(h);
        if (final_g) fclose(final_g);
        return false;
    }
    int p1, p2, n1, n2;
    int read_p, read_n;
    int last_two[2];
    int last_count = 0;
    while (true) {
        read_p = 0;
        if (fread(&p1, sizeof(int), 1, g) == 1) {
            read_p++;
            if (fread(&p2, sizeof(int), 1, g) == 1) {
                read_p++;
            }
        }
        read_n = 0;
        if (fread(&n1, sizeof(int), 1, h) == 1) {
            read_n++;
            if (fread(&n2, sizeof(int), 1, h) == 1) {
                read_n++;
            }
        }
        if (read_p == 0 && read_n == 0) break;
        if (read_p >= 1) fwrite(&p1, sizeof(int), 1, final_g);
        if (read_p == 2) fwrite(&p2, sizeof(int), 1, final_g);
        if (read_n >= 1) fwrite(&n1, sizeof(int), 1, final_g);
        if (read_n == 2) fwrite(&n2, sizeof(int), 1, final_g);
        if (read_p < 2 || read_n < 2) {
            if (read_p == 1) { last_two[last_count++] = p1; }
            if (read_n == 1) { last_two[last_count++] = n1; }
            break;
        }
    }
    fclose(g);
    fclose(h);
    fclose(final_g);
    if (last_count > 0) {
        printf("\nlast two numbers that do not follow the rule: \n");
        for (int i = 0; i < last_count; i++) {
            printf("%d ", last_two[i]);
        }
        printf("\n");
    } else {
        printf("\nfile has been created successfully.\n");
    }
    remove("file_h.bin");
    return true;
}

int main() {
    size_t max_size = 300;
    int array[max_size];
    size_t count = input_array_elements(array, max_size);
    write_to_binary(array, count, "file_f.bin");
    const char *file_g = "file_g.bin";
    process_files("file_f.bin", file_g);
    return 0;
}