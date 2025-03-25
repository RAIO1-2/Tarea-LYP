#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

// Estructura que representa una línea del archivo CSV
struct Pedido {
    float pizza_id;
    float order_id;
    char pizza_name_id[64];
    float cantidad;
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
