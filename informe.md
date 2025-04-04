#  Informe de Diseño - Tarea 1: Pizzería en C

##  Objetivo del proyecto

Desarrollar un programa en lenguaje C que permita leer un archivo de ventas de una pizzería (`ventas.csv`) y calcular distintas métricas útiles para el análisis, tales como:

- Pizza más vendida (`pms`)
- Pizza menos vendida (`pls`)
- Ingrediente más usado (`ims`)
- Promedio de pizzas por orden (`apo`)

Estas métricas deben calcularse utilizando punteros a funciones, respetando un enfoque modular, lógico y ordenado.

---

##  Organización del código

El proyecto se organizó en módulos separados, respetando el principio de responsabilidad única para cada archivo:

| Archivo | Descripción |
|--------|-------------|
| `estructuras.h` | Define el `struct Order`, que modela cada venta del archivo CSV. |
| `lector_csv.c/h` | Contiene la lógica para leer el archivo `.csv` y llenar un arreglo de estructuras. Se encarga también de separar los ingredientes de cada pizza. |
| `metricas.c/h` | Implementa cada métrica solicitada usando punteros a funciones. Cada función retorna un `char*` dinámico con el resultado. |
| `utilidades.c/h` | Funciones auxiliares para limpiar strings, pasar a minúsculas, eliminar saltos de línea, etc. |
| `principal.c` | Contiene el `main()`. Procesa los argumentos desde consola, carga los datos y ejecuta las métricas solicitadas. |
| `Makefile` | Permite compilar automáticamente el proyecto completo usando `make`, generando el ejecutable `app1`. |

---

## ️ Herramientas utilizadas

- Lenguaje: C (estándar C99)
- Compilador: `gcc`
- Editor de código: VSCode
- Sistema operativo: Windows 11
- Herramienta de compilación: `Makefile` (para entornos compatibles)
- Control de versiones: Git
- Repositorio: GitHub

---

##  Lógica de funcionamiento

1. Se recibe el nombre del archivo CSV y una lista de métricas como argumentos por consola.
2. El programa usa `cargar_ordenes_csv()` para leer y parsear el archivo completo, llenando un arreglo de estructuras `Order`.
3. Cada métrica solicitada se busca mediante la función `obtener_funcion_metrica()`, que retorna un puntero a la función correspondiente.
4. La métrica se ejecuta y devuelve un string con el resultado.
5. El resultado se imprime en consola y se libera la memoria dinámica utilizada.
6. Este proceso se repite para todas las métricas solicitadas.

---

##  Uso de Inteligencia Artificial

Se utilizó **ChatGPT** para:

- Modularizar el proyecto
- Sugerir estructuras y nombres de funciones
- Explicar el uso de punteros a funciones
- Generar parte del contenido de `README.md` e `informe.md`
- Simular un archivo `ventas.csv` válido
- Identificar errores comunes de segmentación o lectura de CSV

**Importante:** Cada parte del código fue comprendida, revisada, adaptada y probada para asegurar su correcto funcionamiento. No se copiaron soluciones externas sin entendimiento.

---

##  Reflexión personal

Esta tarea me ayudó a:

- Consolidar el uso de punteros y estructuras en C
- Entender cómo organizar proyectos grandes de forma modular
- Aprender a usar `Makefile` para compilar automáticamente
- Trabajar con archivos CSV reales
- Aplicar el paradigma procedural y evitar uso de variables globales

Además, valoré la importancia de documentar correctamente cada módulo para facilitar la mantención del código.

---

##  Archivos entregados

- `src/`: contiene todo el código fuente organizado en módulos
- `Makefile`: archivo que compila todos los `.c` del proyecto
- `datos/ventas.csv`: archivo de prueba con 100 registros
- `README.md`: instrucciones de uso y estructura
- `informe.md`: este informe

