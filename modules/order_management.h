#ifndef ORDER_MANAGEMENT_H
#define ORDER_MANAGEMENT_H

typedef struct {
    int orderId;
    char dishName[100];
    int tableId;
    char status[50]; // Ex: "em espera", "em preparação", "pronto para servir"
} Order;

void addOrder(Order **orders, int *orderCount, Order newOrder);
void removeOrder(Order *orders, int *orderCount, int orderId);
void editOrder(Order *orders, int orderCount, int orderId, Order newOrderDetails);

#endif