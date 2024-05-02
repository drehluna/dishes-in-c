#ifndef DATA_MANAGEMENT_H
#define DATA_MANAGEMENT_H

typedef struct {
    char name[100];
    char description[255];
    float price;
    char type[50];
} Dish;

void loadDishesFromFile(char *filename, Dish **dishes, int *count);
void saveDishesToFile(char *filename, Dish *dishes, int count);

#endif