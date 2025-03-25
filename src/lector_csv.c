#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "lector_csv.h"

#define MAX_LINEA 1024
#define MAX_PEDIDOS 1000

// Quita las comillas dobles de los ingredientes (si existen)
void limpiar_comillas(char* str) {
    char* inicio = strchr(str, '"');
    char* fin = strrchr(str, '"');

    if (inicio && fin && inicio != fin) {
        memmove(str, inicio + 1, fin - inicio - 1);
        str[fin - inicio - 1] = '\0';
    }
}

// Función principal para leer el archivo CSV y llenar los pedidos
struct Pedido* leer_csv(const char* ruta, int* cantidad) {
    FILE* archivo = fopen(ruta, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    struct Pedido* pedidos = malloc(sizeof(struct Pedido) * MAX_PEDIDOS);
    if (pedidos == NULL) {
        fprintf(stderr, "Error al reservar memoria\n");
        fclose(archivo);
        return NULL;
    }

    char linea[MAX_LINEA];
    int index = 0;

    // Saltar cabecera
    fgets(linea, MAX_LINEA, archivo);

    while (fgets(linea, MAX_LINEA, archivo) != NULL && index < MAX_PEDIDOS) {
        struct Pedido pedido;

        char* token = strtok(linea, ",");
        pedido.pizza_id = atof(token);

        token = strtok(NULL, ",");
        pedido.order_id = atof(token);

        token = strtok(NULL, ",");
        strncpy(pedido.pizza_name_id, token, sizeof(pedido.pizza_name_id));

        token = strtok(NULL, ",");
        pedido.cantidad = atof(token);

        token = strtok(NULL, ",");
        strncpy(pedido.fecha, token, sizeof(pedido.fecha));

        token = strtok(NULL, ",");
        strncpy(pedido.hora, token, sizeof(pedido.hora));

        token = strtok(NULL, ",");
        pedido.precio_unitario = atof(token);

        token = strtok(NULL, ",");
        pedido.precio_total = atof(token);

        token = strtok(NULL, ",");
        strncpy(pedido.tamano, token, sizeof(pedido.tamano));

        token = strtok(NULL, ",");
        strncpy(pedido.categoria, token, sizeof(pedido.categoria));

        token = strtok(NULL, ",");
        strncpy(pedido.ingredientes, token, sizeof(pedido.ingredientes));
        limpiar_comillas(pedido.ingredientes);

        token = strtok(NULL, "\n");
        strncpy(pedido.nombre, token, sizeof(pedido.nombre));

        pedidos[index++] = pedido;
    }

    fclose(archivo);
    *cantidad = index;
    return pedidos;
}
