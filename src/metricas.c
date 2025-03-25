#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "estructuras.h"
#include "metricas.h"

#define MAX_PIZZAS 200

// Estructura interna para contar ventas por pizza
typedef struct {
    char nombre[64];
    float cantidad_total;
} PizzaContador;

// Función para buscar índice de pizza en arreglo de contadores
int buscar_pizza(PizzaContador* lista, int len, const char* nombre) {
    for (int i = 0; i < len; i++) {
        if (strcmp(lista[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

// -------- MÉTRICA: pizza más vendida --------
char* pizza_mas_vendida(int* n, struct Pedido* pedidos) {
    PizzaContador pizzas[MAX_PIZZAS];
    int total_pizzas = 0;

    // Recorremos todos los pedidos
    for (int i = 0; i < *n; i++) {
        char* nombre = pedidos[i].nombre;
        float cantidad = pedidos[i].cantidad;

        int idx = buscar_pizza(pizzas, total_pizzas, nombre);

        if (idx == -1) {
            // Nueva pizza, agregar al arreglo
            strncpy(pizzas[total_pizzas].nombre, nombre, 64);
            pizzas[total_pizzas].cantidad_total = cantidad;
            total_pizzas++;
        } else {
            // Ya existe, sumar cantidad
            pizzas[idx].cantidad_total += cantidad;
        }
    }

    // Buscar pizza con mayor cantidad
    int indice_mayor = 0;
    for (int i = 1; i < total_pizzas; i++) {
        if (pizzas[i].cantidad_total > pizzas[indice_mayor].cantidad_total) {
            indice_mayor = i;
        }
    }

    // Preparar el string de salida
    char* resultado = malloc(128);
    snprintf(resultado, 128, "Pizza más vendida: %s (vendida %.0f veces)",
             pizzas[indice_mayor].nombre,
             pizzas[indice_mayor].cantidad_total);

    return resultado;
}

// --------- MÉTRICA: pizza menos vendida (placeholder) ---------
char* pizza_menos_vendida(int* n, struct Pedido* pedidos) {
    return strdup("Pizza menos vendida: (no implementado aún)");
}

// Agrega aquí el resto de métricas cuando estés listo...
char* fecha_mas_dinero(int* n, struct Pedido* pedidos) {
    return strdup("Fecha con más dinero: (no implementado aún)");
}
char* fecha_menos_dinero(int* n, struct Pedido* pedidos) {
    return strdup("Fecha con menos dinero: (no implementado aún)");
}
char* fecha_mas_pizzas(int* n, struct Pedido* pedidos) {
    return strdup("Fecha con más pizzas: (no implementado aún)");
}
char* fecha_menos_pizzas(int* n, struct Pedido* pedidos) {
    return strdup("Fecha con menos pizzas: (no implementado aún)");
}
char* promedio_por_orden(int* n, struct Pedido* pedidos) {
    return strdup("Promedio por orden: (no implementado aún)");
}
char* promedio_por_dia(int* n, struct Pedido* pedidos) {
    return strdup("Promedio por día: (no implementado aún)");
}
char* ingrediente_mas_vendido(int* n, struct Pedido* pedidos) {
    return strdup("Ingrediente más vendido: (no implementado aún)");
}
char* pizzas_por_categoria(int* n, struct Pedido* pedidos) {
    return strdup("Pizzas por categoría: (no implementado aún)");
}
