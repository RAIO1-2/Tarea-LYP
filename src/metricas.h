#ifndef METRICAS_H
#define METRICAS_H

#include "estructuras.h"

// Firma general de las funciones de métricas
typedef char* (*FuncionMetrica)(int*, Order*);

// Declaraciones de las funciones para cada métrica
char* pms(int *size, Order *orders);   // Pizza más vendida
char* pls(int *size, Order *orders);   // Pizza menos vendida
char* apo(int *size, Order *orders);   // Promedio de pizzas por orden
char* ims(int *size, Order *orders);   // Ingrediente más vendido

// Puedes agregar más aquí: dms, dls, hp, etc.

#endif // METRICAS_H
