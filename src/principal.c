#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "lector_csv.h"
#include "metricas.h"
#include "utilidades.h"

#define MAX_METRICAS 10

// Asocia los códigos de métrica con su función correspondiente
FuncionMetrica obtener_funcion_metrica(const char *codigo) {
    if (strcmp(codigo, "pms") == 0) return pms;
    if (strcmp(codigo, "pls") == 0) return pls;
    if (strcmp(codigo, "apo") == 0) return apo;
    if (strcmp(codigo, "ims") == 0) return ims;

    // Puedes agregar más métricas aquí (dms, dls, etc.)

    return NULL; // No encontrada
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <archivo.csv> <metrica1> [metrica2] ...\n", argv[0]);
        return 1;
    }

    const char *nombre_csv = argv[1];
    Order ordenes[MAX_ORDERS];
    int total_ordenes = cargar_ordenes_csv(nombre_csv, ordenes);

    if (total_ordenes == 0) {
        printf("No se pudieron cargar las órdenes.\n");
        return 1;
    }

    printf("Se cargaron %d órdenes desde '%s'.\n", total_ordenes, nombre_csv);

    for (int i = 2; i < argc; i++) {
        const char *codigo_metrica = argv[i];
        FuncionMetrica funcion = obtener_funcion_metrica(codigo_metrica);

        if (funcion == NULL) {
            printf("Métrica '%s' no reconocida.\n", codigo_metrica);
            continue;
        }

        char *resultado = funcion(&total_ordenes, ordenes);

        if (resultado != NULL) {
            printf("[%s]: %s\n", codigo_metrica, resultado);
            free(resultado); // liberar memoria asignada por la métrica
        } else {
            printf("[%s]: No se pudo calcular.\n", codigo_metrica);
        }
    }

    return 0;
}
