#include "order_management.h"
#include <stdio.h>

typedef struct {
    int orderId;
    char dishName[100];
    int tableId;
    char status[50]; // Ex: "em espera", "em preparação", "pronto para servir"
} Order;

void addOrder(Order **orders, int *orderCount, Order newOrder) {
    if (*orderCount == 0) {
        *orders = malloc(sizeof(Order));
    } else {
        *orders = realloc(*orders, (*orderCount + 1) * sizeof(Order));
    }
    (*orders)[*orderCount] = newOrder;
    (*orderCount)++;
}

void removeOrder(Order *orders, int *orderCount, int orderId) {
    int found = 0;
    for (int i = 0; i < *orderCount; i++) {
        if (orders[i].orderId == orderId) {
            found = 1;
            for (int j = i; j < *orderCount - 1; j++) {
                orders[j] = orders[j + 1];
            }
            (*orderCount)--;
            orders = realloc(orders, (*orderCount) * sizeof(Order));
            break;
        }
    }
    if (!found) {
        printf("Pedido não encontrado.\n");
    }
}

void editOrder(Order *orders, int orderCount, int orderId, Order newOrderDetails) {
    for (int i = 0; i < orderCount; i++) {
if (orders[i].orderId == orderId) {
orders[i] = newOrderDetails;
break;
}
    }
}