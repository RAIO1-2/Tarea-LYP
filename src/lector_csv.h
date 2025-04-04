#ifndef LECTOR_CSV_H
#define LECTOR_CSV_H

#include "estructuras.h"

// Carga las órdenes desde un archivo CSV.
// Parámetros:
// - nombre_archivo: ruta al archivo CSV (ej: "datos/ventas.csv")
// - arreglo_orders: arreglo donde se almacenarán las órdenes leídas
// Retorna la cantidad de órdenes leídas.
int cargar_ordenes_csv(const char *nombre_archivo, Order arreglo_orders[]);

#endif // LECTOR_CSV_H
