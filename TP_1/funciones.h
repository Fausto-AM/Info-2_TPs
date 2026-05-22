#ifndef FUNCIONES_H
#define FUNCIONES_H

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define TOTAL_SUC 3

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[TOTAL_SUC];
    int total;
} articulos_t;

int buscar_o_agregar_articulo(articulos_t articulos[], int n, const char *descripcion);

void actualizar_total(articulos_t *art);

void ingresar_articulos(articulos_t articulos[], int n);

void mostrar_inventario(const articulos_t articulos[], int n, const char *titulo);

void ordenar_articulos_por_total(articulos_t articulos[], int n);

void mostrar_bienvenida(void);

void mostrar_separador_ordenado(void);

#endif
