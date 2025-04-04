#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lector_csv.h"

// Función auxiliar: elimina el salto de línea final si lo hay
void limpiar_salto_linea(char *linea) {
    size_t len = strlen(linea);
    if (len > 0 && linea[len - 1] == '\n') {
        linea[len - 1] = '\0';
    }
}

// Función auxiliar: divide una cadena de ingredientes en un arreglo
int separar_ingredientes(char *texto, char ingredientes[][MAX_STRING_LENGTH]) {
    int contador = 0;
    char *token = strtok(texto, ",");
    while (token != NULL && contador < MAX_INGREDIENTS) {
        while (isspace(*token)) token++; // eliminar espacios iniciales
        strncpy(ingredientes[contador], token, MAX_STRING_LENGTH - 1);
        ingredientes[contador][MAX_STRING_LENGTH - 1] = '\0';
        contador++;
        token = strtok(NULL, ",");
    }
    return contador;
}

// Implementación principal
int cargar_ordenes_csv(const char *nombre_archivo, Order arreglo_orders[]) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 0;
    }

    char linea[MAX_LINE_LENGTH];
    int cantidad_ordenes = 0;

    // Saltar la primera línea (encabezado)
    fgets(linea, MAX_LINE_LENGTH, archivo);

    // Leer línea por línea
    while (fgets(linea, MAX_LINE_LENGTH, archivo) != NULL && cantidad_ordenes < MAX_ORDERS) {
        limpiar_salto_linea(linea);

        // Separar campos
        char *token;
        int campo = 0;
        Order orden_temp;

        token = strtok(linea, ",");
        while (token != NULL && campo < 11) {
            switch (campo) {
                case 0: strncpy(orden_temp.pizza_id, token, MAX_STRING_LENGTH); break;
                case 1: strncpy(orden_temp.order_id, token, MAX_STRING_LENGTH); break;
                case 2: strncpy(orden_temp.pizza_name_id, token, MAX_STRING_LENGTH); break;
                case 3: orden_temp.quantity = atoi(token); break;
                case 4: strncpy(orden_temp.order_date, token, MAX_STRING_LENGTH); break;
                case 5: strncpy(orden_temp.order_time, token, MAX_STRING_LENGTH); break;
                case 6: strncpy(orden_temp.pizza_size, token, MAX_STRING_LENGTH); break;
                case 7: orden_temp.unit_price = atof(token); break;
                case 8: orden_temp.total_price = atof(token); break;
                case 9: strncpy(orden_temp.pizza_category, token, MAX_STRING_LENGTH); break;
                case 10:
                    // Quitar comillas si existen
                    if (token[0] == '"') token++;
                    size_t len = strlen(token);
                    if (len > 0 && token[len - 1] == '"') token[len - 1] = '\0';
                    orden_temp.num_ingredients = separar_ingredientes(token, orden_temp.ingredients);
                    break;
            }

            token = strtok(NULL, ",");
            campo++;
        }

        arreglo_orders[cantidad_ordenes++] = orden_temp;
    }

    fclose(archivo);
    return cantidad_ordenes;
}
