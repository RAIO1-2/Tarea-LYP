#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

// Estructura para representar cada línea del archivo CSV
struct Pedido {
    int pizza_id;
    int order_id;
    char pizza_name_id[64];
    int cantidad;
    char fecha[16];
    char hora[16];
    float precio_unitario;
    float precio_total;
    char tamano[4];
    char categoria[32];
    char ingredientes[256];
    char nombre[64];
};

#endif
