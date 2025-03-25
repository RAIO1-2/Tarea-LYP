#ifndef METRICAS_H
#define METRICAS_H

#include "estructuras.h"

// Declaración de todas las métricas (aunque estén vacías todavía)
char* pizza_mas_vendida(int*, struct Pedido*);
char* pizza_menos_vendida(int*, struct Pedido*);
char* fecha_mas_dinero(int*, struct Pedido*);
char* fecha_menos_dinero(int*, struct Pedido*);
char* fecha_mas_pizzas(int*, struct Pedido*);
char* fecha_menos_pizzas(int*, struct Pedido*);
char* promedio_por_orden(int*, struct Pedido*);
char* promedio_por_dia(int*, struct Pedido*);
char* ingrediente_mas_vendido(int*, struct Pedido*);
char* pizzas_por_categoria(int*, struct Pedido*);

#endif
