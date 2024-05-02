#include "data_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[100];
    char description[255];
    float price;
    char type[50];
} Dish;

void loadDishesFromFile(char *filename, Dish **dishes, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    *count = 0;
    while (fgets(line, sizeof(line), file)) {
        if (*count == 0) {
            *dishes = malloc(sizeof(Dish));
        } else {
            *dishes = realloc(*dishes, (*count + 1) * sizeof(Dish));
        }
        sscanf(line, "%[^,],%[^,],%f,%[^\n]", (*dishes)[*count].name, (*dishes)[*count].description, &(*dishes)[*count].price, (*dishes)[*count].type);
        (*count)++;
    }
    fclose(file);
}

void saveDishesToFile(char *filename, Dish *dishes, int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%.2f,%s\n", dishes[i].name, dishes[i].description, dishes[i].price, dishes[i].type);
    }
    fclose(file);
}