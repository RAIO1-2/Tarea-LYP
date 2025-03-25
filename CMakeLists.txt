cmake_minimum_required(VERSION 3.10)
project(Tarea_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(Tarea_1
        src/principal.c
        src/lector_csv.c
        src/metricas.c
        src/utilidades.c
)
