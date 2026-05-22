#include "funciones.h"

int main(void) {
    articulos_t articulos[CANT_ARTICULOS] = {0};

    mostrar_bienvenida();

    ingresar_articulos(articulos, CANT_ARTICULOS);
    mostrar_inventario(articulos, CANT_ARTICULOS, "Inventario cargado:");

    ordenar_articulos_por_total(articulos, CANT_ARTICULOS);
    mostrar_separador_ordenado();
    mostrar_inventario(articulos, CANT_ARTICULOS, 0);

    return 0;
}
