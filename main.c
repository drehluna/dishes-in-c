#include <stdio.h>
#include "data_management.h"
#include "order_management.h"
#include "table_management.h"
#include "report_management.h"

int main() {
    Dish *dishes = NULL;
    int dishCount = 0;
    Order *orders = NULL;
    int orderCount = 0;

    // Carregar dados dos pratos do arquivo
    loadDishesFromFile("data/dishes.csv", &dishes, &dishCount);
    if (dishes == NULL) {
        printf("Erro ao carregar os pratos.\n");
        return 1;
    }

    // Exemplo de adição de um novo prato
    Dish newDish = {"Bacalhau à Brás", "Bacalhau desfiado, com batatas e ovos", 15.50, "Peixe"};
    dishes = realloc(dishes, (dishCount + 1) * sizeof(Dish));
    dishes[dishCount++] = newDish;

    // Salvar os dados dos pratos modificados de volta ao arquivo
    saveDishesToFile("data/dishes.csv", dishes, dishCount);

    // Exemplo de manipulação de pedidos
    Order newOrder = {1, "Bacalhau à Brás", 5, "em espera"};
    addOrder(&orders, &orderCount, newOrder);

    // Remover um pedido
    removeOrder(orders, &orderCount, 1);

    // Gerar relatórios (implementação depende das funções específicas)
    generateDishReport();
    generateTableReport();

    // Liberação de memória alocada
    free(dishes);
    free(orders);

    return 0;
}