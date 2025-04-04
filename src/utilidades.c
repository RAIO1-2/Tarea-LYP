#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "utilidades.h"

void quitar_salto_de_linea(char *cadena) {
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}

void a_minuscula(char *cadena) {
    for (int i = 0; cadena[i]; i++) {
        cadena[i] = tolower((unsigned char)cadena[i]);
    }
}

void liberar_resultados(char **resultados, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        free(resultados[i]);
    }
    free(resultados);
}

void trim(char *str) {
    // Elimina espacios al inicio
    while (isspace((unsigned char)*str)) str++;

    // Elimina espacios al final
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}
