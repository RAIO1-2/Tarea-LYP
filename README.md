# Tarea 1 - Análisis de Ventas de Pizzas

##  Autor
- Nombre: Ignacio
- Curso: Lenguaje de Programación C
- Sección: [Completa si aplica]
- Profesor: [Completa si aplica]

---

##  Estructura del proyecto

```
Tarea1/
├── src/
│   ├── estructuras.h
│   ├── lector_csv.c / lector_csv.h
│   ├── metricas.c / metricas.h
│   ├── utilidades.c / utilidades.h
│   └── principal.c
├── datos/
│   └── ventas.csv
├── Makefile
├── README.md
└── informe.md
```

---

##  Compilación del programa

Desde la carpeta raíz del proyecto, ejecutar:

```bash
make
```

>  Si estás en Windows y no tienes `make`, puedes compilar desde tu entorno o IDE directamente. El `Makefile` está incluido para cumplir con el formato exigido.

---

##  Ejecución del programa

```bash
./app1 datos/ventas.csv pms pls apo ims
```

El primer argumento es el archivo `.csv`. Los siguientes son los códigos de las métricas que se desean calcular.

### Métricas disponibles:

| Código | Descripción                     |
|--------|---------------------------------|
| `pms`  | Pizza más vendida              |
| `pls`  | Pizza menos vendida            |
| `apo`  | Promedio de pizzas por orden   |
| `ims`  | Ingrediente más usado          |

---

##  Uso de inteligencia artificial (IA)

Se utilizó ChatGPT para:
- Organizar el proyecto de manera modular
- Escribir funciones con punteros a funciones
- Generar comentarios y documentación
- Simular el archivo de pruebas `ventas.csv`
- Resolver errores durante la compilación

---

##  Repositorio

Este proyecto debe entregarse mediante GitHub. Asegúrate de:
- Hacer **fork** del repositorio base entregado por el curso (si lo indicaron)
- Agregar a todos los integrantes del grupo como colaboradores (en este caso trabajo individual)
- Incluir **commits balanceados y con mensajes claros**
- Incluir el `Makefile`, el código fuente, el archivo `ventas.csv`, el `README.md` y el `informe.md`

URL del repositorio (completar al entregar):
```
[https://github.com/usuario/tarea1-pizzeria](https://github.com/usuario/tarea1-pizzeria)
```
