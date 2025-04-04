#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "estructuras.h"

// Elimina saltos de línea al final de una cadena
void quitar_salto_de_linea(char *cadena);

// Convierte un string a minúsculas (útil para comparar strings)
void a_minuscula(char *cadena);

// Libera un arreglo dinámico de strings
void liberar_resultados(char **resultados, int cantidad);

// Elimina espacios iniciales y finales
void trim(char *str);

#endif // UTILIDADES_H
