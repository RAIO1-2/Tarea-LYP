#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metricas.h"

// Retorna el nombre de la pizza más vendida
char* pms(int *size, Order *orders) {
    // Contar las ventas por pizza_name_id
    typedef struct {
        char nombre[MAX_STRING_LENGTH];
        int cantidad;
    } PizzaCount;

    PizzaCount conteo[MAX_ORDERS];
    int total = 0;

    for (int i = 0; i < *size; i++) {
        int encontrado = 0;
        for (int j = 0; j < total; j++) {
            if (strcmp(conteo[j].nombre, orders[i].pizza_name_id) == 0) {
                conteo[j].cantidad += orders[i].quantity;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            strcpy(conteo[total].nombre, orders[i].pizza_name_id);
            conteo[total].cantidad = orders[i].quantity;
            total++;
        }
    }

    // Buscar la más vendida
    int max = 0;
    char *resultado = malloc(MAX_STRING_LENGTH);
    strcpy(resultado, conteo[0].nombre);

    for (int i = 1; i < total; i++) {
        if (conteo[i].cantidad > max) {
            max = conteo[i].cantidad;
            strcpy(resultado, conteo[i].nombre);
        }
    }

    return resultado;
}

// Retorna la pizza menos vendida
char* pls(int *size, Order *orders) {
    typedef struct {
        char nombre[MAX_STRING_LENGTH];
        int cantidad;
    } PizzaCount;

    PizzaCount conteo[MAX_ORDERS];
    int total = 0;

    for (int i = 0; i < *size; i++) {
        int encontrado = 0;
        for (int j = 0; j < total; j++) {
            if (strcmp(conteo[j].nombre, orders[i].pizza_name_id) == 0) {
                conteo[j].cantidad += orders[i].quantity;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            strcpy(conteo[total].nombre, orders[i].pizza_name_id);
            conteo[total].cantidad = orders[i].quantity;
            total++;
        }
    }

    // Buscar la menos vendida
    int min = conteo[0].cantidad;
    char *resultado = malloc(MAX_STRING_LENGTH);
    strcpy(resultado, conteo[0].nombre);

    for (int i = 1; i < total; i++) {
        if (conteo[i].cantidad < min) {
            min = conteo[i].cantidad;
            strcpy(resultado, conteo[i].nombre);
        }
    }

    return resultado;
}

// Promedio de pizzas por orden (sumar todas y dividir por número de órdenes)
char* apo(int *size, Order *orders) {
    int suma = 0;
    int total_ordenes = 0;

    char ult_id[MAX_STRING_LENGTH] = "";

    for (int i = 0; i < *size; i++) {
        suma += orders[i].quantity;
        if (strcmp(orders[i].order_id, ult_id) != 0) {
            total_ordenes++;
            strcpy(ult_id, orders[i].order_id);
        }
    }

    float promedio = (float)suma / total_ordenes;

    char *resultado = malloc(50);
    snprintf(resultado, 50, "Promedio por orden: %.2f", promedio);
    return resultado;
}

// Ingrediente más vendido
char* ims(int *size, Order *orders) {
    typedef struct {
        char nombre[MAX_STRING_LENGTH];
        int cantidad;
    } IngredienteCount;

    IngredienteCount conteo[200];
    int total = 0;

    for (int i = 0; i < *size; i++) {
        for (int j = 0; j < orders[i].num_ingredients; j++) {
            int encontrado = 0;
            for (int k = 0; k < total; k++) {
                if (strcmp(conteo[k].nombre, orders[i].ingredients[j]) == 0) {
                    conteo[k].cantidad += orders[i].quantity;
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                strcpy(conteo[total].nombre, orders[i].ingredients[j]);
                conteo[total].cantidad = orders[i].quantity;
                total++;
            }
        }
    }

    int max = 0;
    char *resultado = malloc(MAX_STRING_LENGTH);
    strcpy(resultado, conteo[0].nombre);

    for (int i = 1; i < total; i++) {
        if (conteo[i].cantidad > max) {
            max = conteo[i].cantidad;
            strcpy(resultado, conteo[i].nombre);
        }
    }

    return resultado;
}
