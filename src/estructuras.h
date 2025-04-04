#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define MAX_LINE_LENGTH 512
#define MAX_STRING_LENGTH 100
#define MAX_ORDERS 1000     // Puedes ajustarlo según el tamaño de tu CSV
#define MAX_INGREDIENTS 10  // Máximo de ingredientes por pizza

// Estructura que representa una orden (una fila del archivo CSV)
typedef struct {
    char pizza_id[MAX_STRING_LENGTH];         // ID interna (ej. "1.00")
    char order_id[MAX_STRING_LENGTH];         // ID de la orden
    char pizza_name_id[MAX_STRING_LENGTH];    // Nombre interno de la pizza
    int quantity;                              // Cantidad de pizzas en esta orden
    char order_date[MAX_STRING_LENGTH];       // Fecha (ej. "1/1/2015")
    char order_time[MAX_STRING_LENGTH];       // Hora (ej. "11:38:36.13")
    char pizza_size[MAX_STRING_LENGTH];       // Tamaño (S, M, L, XL)
    float unit_price;                         // Precio unitario
    float total_price;                        // Precio total
    char pizza_category[MAX_STRING_LENGTH];   // Categoría (ej. "Classic")
    char ingredients[MAX_INGREDIENTS][MAX_STRING_LENGTH]; // Lista de ingredientes
    int num_ingredients;                      // Cantidad de ingredientes
} Order;

#endif // ESTRUCTURAS_H
