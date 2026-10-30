#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct Rect {
    int id;
    double x1; ;
    double x2;
    double y1;
    double y2;
}Rect;

void print_rect(const Rect* rect) {
    printf("rectangle id: %d\n", rect->id);
    printf("coordinates: (%lf, %lf) to (%lf, %lf)\n", rect->x1, rect->y1, rect->x2, rect->y2);
}

bool input_rect(Rect* rect) {
    if (rect == NULL) {
        return false;
    }
    printf("enter rectangle's id: ");
    if (scanf("%d", &rect->id)!= 1) {
        return false;
    }
    printf("enter coordinates: (x1, y1, x2, y2): ");
    if (scanf("%lf %lf %lf %lf", &rect->x1, &rect->y1, &rect->x2, &rect->y2) != 4) {
        return false;
    }
    return true;
}

bool write_rect_file(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return false;
    }
    int n;
    printf("Enter number of rectangles: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fclose(file);
        return false;
    }
    for (int i = 0; i < n; i++) {
        Rect rect;
        printf("\nRectangle %d\n", i + 1);
        if (!input_rect(&rect)) {
            fclose(file);
            return false;
        }
        if (fwrite(&rect, sizeof(Rect), 1, file) != 1) {
            fclose(file);
            return false;
        }
    }
    fclose(file);
    return true;
}

double rect_area(const Rect* rect) {
    double area = 0.0;
    if (rect == NULL) {
        return 0;
    }
    area = fabs(rect->x2 - rect->x1) * fabs(rect->y2 - rect->y1);
    return area;
}

int max_area(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return -1;
    }
    Rect rect;
    int max_id = -1;
    double max_area = 0.0;
    while (fread(&rect, sizeof(Rect), 1, file) == 1) {
        double area = rect_area(&rect);
        if (area <  max_area) {
            max_area = area;
            max_id = rect.id;
        }
    }
    fclose(file);
    return max_id;
}

bool remove_rect(const char* filename, int id) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return false;
    }
    FILE* temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        fclose(file);
        return false;
    }
    Rect rect;
    bool found = false;
    while (fread(&rect, sizeof(Rect), 1, file) == 1) {
        if (rect.id == id) {
            found = true;
            continue;
        }
        fwrite(&rect, sizeof(Rect), 1, temp);
    }
    fclose(file);
    fclose(temp);
    if (found) {
        remove(filename);
        rename("temp.bin", filename);
    }
    else {
        remove("temp.bin");
    }
    return found;
}

int main() {
    const char* filename = "rectangles.bin";
    if (!write_rect_file(filename)) {
        return 1;
    }
    int max_id = max_area(filename);
    if (max_id != -1) {
        printf("ractangle with max area has id: %d\n", max_id);
    }
    else {
        printf("failed to find rectangle with max area\n");
    }
    int remove_id;
    printf("enter id to remove: ");
    if (scanf("%d", &remove_id) == 1) {
        if (remove_rect(filename, remove_id)) {
            printf("rectangle with id %d removed successfully\n", remove_id);
        }
        else {
            printf("rectangle with id %d not found\n", remove_id);
        }
    }
    return 0;
}