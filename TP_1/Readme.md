# Trabajo Práctico N°1 - Funciones y Archivos
## Consignas
Hacer el refactor del código de "Resolucion_Final_Informatica_1" utilizando estructuras, funciones y separacion de archivos. [Ver código](https://github.com/DamRCorba/Informatica-2/blob/main/02_Estructuras/ejemplos/Ejemplo3/main.c)

- Crear archivos funciones.c y funciones.h.
- En funciones.c se deberan desarrollar las funciones.
- En funciones.h se deberan agregar los prototipos, definiciones y demas constantes.
- Modificar el codigo para el uso de estructuras
- Entregar el codigo y un readme explicativo en un repositorio git nuevo.

La separacion de codigo queda a criterio del alumno, aunque se debe intentar separar en la mayor cantidad de funciones posibles para la legibilidad del codigo.

## Explicación de la Resolución

### Estructura del proyecto
Se separó el código en tres archivos:
- **`funciones.h`**: contiene las constantes (`CANT_ARTICULOS`, `SUCURSAL_1`, `SUCURSAL_2`, `SUCURSAL_3`, `TOTAL_SUC`), la definición de la estructura `articulos_t` y los prototipos de todas las funciones públicas.
- **`funciones.c`**: implementa todas las funciones necesarias para la carga, procesamiento y visualización de artículos, así como las funciones auxiliares de entrada validada.
- **`main.c`**: función principal que orquesta la ejecución llamando exclusivamente a las funciones definidas en `funciones.h`.
### Uso de estructuras
Se definió la estructura `articulos_t` con los campos:
- `descripcion`: cadena de hasta 89 caracteres.
- `cantidad_sucursal`: arreglo de 3 enteros (uno por sucursal).
- `total`: suma de las cantidades.

Todas las funciones trabajan con arreglos de esta estructura, pasando punteros cuando es necesario modificar un artículo individual.

### Funciones implementadas en `funciones.c`

#### Funciones de entrada robusta (sin dependencias externas)
- `leer_linea`: utiliza `fgets` para leer líneas completas, eliminando el salto de línea final. Evita dejar basura en el buffer de entrada.
- `pedir_entero`: solicita un número entero y repite la pregunta hasta que el usuario ingrese un valor válido (usa `sscanf` sobre la línea leída).
- `pedir_entero_rango`: extiende `pedir_entero` para garantizar que el valor esté dentro de un intervalo `[min, max]`.
- `pedir_entero_no_negativo`: asegura que la cantidad ingresada sea mayor o igual a cero, rechazando negativos.

#### Funciones de la lógica del negocio
- `buscar_o_agregar_articulo`: busca un artículo por descripción; si no existe, lo agrega en la primera posición libre del arreglo (inicializando sus campos). Retorna el índice correspondiente o -1 si no hay espacio.
- `actualizar_total`: recalcula el campo `total` de un artículo sumando sus cantidades en las tres sucursales. Se llama después de cada modificación.
- `ingresar_articulos`: ciclo principal de carga. Utiliza las funciones de entrada validada para obtener descripción, sucursal (1-3), cantidad (≥0) y la opción de continuar (1/2). Se controla el límite de 60 artículos.
- `mostrar_inventario`: imprime la tabla de artículos con encabezados. Recibe un título opcional (cadena o `0` si no se desea título).
- `ordenar_articulos_por_total`: ordena el arreglo de mayor a menor según el campo `total`, utilizando el método de burbuja sobre los artículos con descripción no vacía.
- `mostrar_bienvenida` y `mostrar_separador_ordenado`: funciones dedicadas para los mensajes de inicio y el separador visual, manteniendo al `main` limpio de llamadas directas a `printf`.

### Correcciones y mejoras respecto al código original
- El total de cada artículo se **reinicia a cero** antes de recalcular, evitando acumulaciones erróneas.
- Se **validan todas las entradas** del usuario:
  - La sucursal debe ser 1, 2 o 3.
  - La cantidad no puede ser negativa.
  - La opción de continuar solo admite 1 o 2.
  - Ante cualquier valor incorrecto (incluyendo texto donde se espera un número) el programa vuelve a preguntar sin entrar en bucles infinitos.
- El ordenamiento **intercambia estructuras completas** (`articulos_t`) en lugar de copiar campo por campo, simplificando el código.

### Compilación
```bash
gcc -o programa main.c funciones.c
