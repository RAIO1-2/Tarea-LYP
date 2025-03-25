#include <stdio.h>          // printf, fprintf
#include <stdlib.h>         // malloc, free
#include <string.h>         // strcmp
#include "estructuras.h"    // Definición de struct Pedido
#include "lector_csv.h"     // leer_csv()
#include "metricas.h"       // Funciones de métricas: pms, pls, etc.

/*
 * Tipo de función que representa una métrica.
 * Todas las métricas deben tener esta forma:
 * - Reciben:
 *    -> un puntero a int (cantidad de pedidos)
 *    -> un arreglo de struct Pedido
 * - Devuelven:
 *    -> un puntero a char con la respuesta (string formateado con malloc)
 */
typedef char* (*funcion_metrica)(int*, struct Pedido*);

/*
 * Esta estructura asocia:
 *  - un nombre corto de la métrica (como "pms")
 *  - con su función correspondiente (como pizza_mas_vendida)
 */
struct Metrica {
    const char* nombre;
    funcion_metrica funcion;
};

/*
 * Este arreglo define todas las métricas disponibles en el sistema.
 * Cada entrada conecta el string que el usuario puede ingresar
 * con la función real que implementa esa métrica.
 */
struct Metrica metricas_disponibles[] = {
    {"pms", pizza_mas_vendida},
    {"pls", pizza_menos_vendida},
    {"dms", fecha_mas_dinero},
    {"dls", fecha_menos_dinero},
    {"dmsp", fecha_mas_pizzas},
    {"dlsp", fecha_menos_pizzas},
    {"apo", promedio_por_orden},
    {"apd", promedio_por_dia},
    {"ims", ingrediente_mas_vendido},
    {"hp", pizzas_por_categoria}
};

/*
 * Buscar y devolver el puntero a función correspondiente al nombre de una métrica.
 * Si no se encuentra, devuelve NULL.
 */
funcion_metrica obtener_funcion(const char* nombre) {
    int total = sizeof(metricas_disponibles) / sizeof(metricas_disponibles[0]);
    for (int i = 0; i < total; i++) {
        if (strcmp(nombre, metricas_disponibles[i].nombre) == 0) {
            return metricas_disponibles[i].funcion;
        }
    }
    return NULL; // Métrica no encontrada
}

/*
 * Función principal del programa:
 * - Valida argumentos
 * - Lee el archivo CSV
 * - Ejecuta las métricas solicitadas
 * - Imprime los resultados
 */
int main(int argc, char *argv[]) {
    // Validación mínima: se necesita un archivo + al menos una métrica
    if (argc < 3) {
        printf("Uso: %s archivo.csv metrica1 metrica2 ...\n", argv[0]);
        return 1;
    }

    const char* ruta_archivo = argv[1];  // Ruta del archivo CSV
    int cantidad_pedidos = 0;           // Se guardará la cantidad de pedidos leídos

    /*
     * Llamamos a leer_csv() que:
     * - Abre el archivo
     * - Lee cada línea
     * - Llena un arreglo dinámico de struct Pedido
     * - Devuelve ese arreglo
     * - Guarda en cantidad_pedidos cuántas líneas se procesaron
     */
    struct Pedido* pedidos = leer_csv(ruta_archivo, &cantidad_pedidos);
    if (pedidos == NULL) {
        fprintf(stderr, "Error al leer el archivo CSV.\n");
        return 1;
    }

    /*
     * Recorremos cada métrica ingresada por el usuario,
     * buscando su función y ejecutándola con los datos leídos.
     */
    for (int i = 2; i < argc; i++) {
        funcion_metrica funcion = obtener_funcion(argv[i]);  // Buscar función
        if (funcion != NULL) {
            // Llamamos la función de la métrica con los datos cargados
            char* resultado = funcion(&cantidad_pedidos, pedidos);
            printf("%s\n", resultado);  // Mostramos el resultado
            free(resultado);            // Liberamos memoria (las métricas devuelven malloc)
        } else {
            // Si la métrica no existe, avisamos
            printf("Métrica '%s' no reconocida.\n", argv[i]);
        }
    }

    // Liberamos el arreglo de pedidos creado por leer_csv()
    free(pedidos);

    return 0;
}
