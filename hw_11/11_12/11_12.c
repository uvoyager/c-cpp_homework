//task 11.12double
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TOY {
    char name[50];
    double price;
    int min_age;
    int max_age;
} TOY;

double find_by_name(const char *filename, const char *name) {
    FILE *file = fopen(filename, "rt");
    if (file == NULL) {
        printf("cannot open file\n");
        return 0;
    }
    char buffer[256];
    double total_price = 0.0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        buffer[strcspn(buffer, "\r\n")] = 0;
        char *token_name = strtok(buffer, ",");
        char *token_price = strtok(NULL, ",");
        char *token_min = strtok(NULL, ",");
        char *token_max = strtok(NULL, ",");
        if (token_name != NULL) {
            while (*token_name == ' ') token_name++;
            TOY toy;
            strncpy(toy.name, token_name, sizeof(toy.name) - 1);
            toy.name[sizeof(toy.name) - 1] = '\0';
            if (token_price != NULL) toy.price = strtod(token_price, NULL);
            if (token_min != NULL) toy.min_age = atoi(token_min);
            if (token_max != NULL) toy.max_age = atoi(token_max);
            if (strcmp(toy.name, name) == 0) {
                total_price += toy.price;
            }
        }
    }

    fclose(file);
    return total_price;
}

int main() {
    char name[100];
    printf("input name: ");
    if (scanf("%49s", name) != 1) {
        printf("error reading input\n");
        return 1;
    }
    double total_price = find_by_name("input.txt", name);
    printf("Total found: %lf\n", total_price);
    FILE* file = fopen("output.bin", "wb");
    if (file == NULL) {
        printf("error opening output.bin\n");
        return 1;
    }
    const char *label = "total price is: ";
    fwrite(label, sizeof(char), strlen(label) + 1, file);
    fwrite(&total_price, sizeof(double), 1, file);
    fclose(file);
    printf("result saved to output.bin successfully!\n");
    return 0;
}