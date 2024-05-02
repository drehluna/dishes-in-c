#ifndef TABLE_MANAGEMENT_H
#define TABLE_MANAGEMENT_H

typedef struct {
    int tableId;
    int capacity;
    char status[50]; // Ex: "livre", "ocupada"
} Table;

void assignOrderToTable(int tableId, int orderId);
void checkTableAvailability(int tableId);

#endif