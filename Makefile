# Nombre del ejecutable
EXEC = app1

# Archivos fuente
SRC = src/principal.c src/lector_csv.c src/metricas.c src/utilidades.c

# Flags de compilación
CFLAGS = -Wall -Wextra -std=c99

# Compilador
CC = gcc

# Regla principal
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# Limpiar el ejecutable
clean:
	rm -f $(EXEC)
