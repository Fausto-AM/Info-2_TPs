#include <stdio.h>
#include <string.h>
#include "funciones.h"

int buscar_o_agregar_articulo(articulos_t articulos[], int n, const char *descripcion) {
    int i = 0;

    while (i < n && articulos[i].descripcion[0] != '\0') {
        if (strcmp(articulos[i].descripcion, descripcion) == 0) {
            return i;
        }
        i++;
    }

    if (i < n) {
        strcpy(articulos[i].descripcion, descripcion);

        for (int j = 0; j < TOTAL_SUC; j++) {
            articulos[i].cantidad_sucursal[j] = 0;
        }
        articulos[i].total = 0;
        return i;
    }

    return -1;
}

void actualizar_total(articulos_t *art) {
    art->total = 0;
    for (int i = 0; i < TOTAL_SUC; i++) {
        art->total += art->cantidad_sucursal[i];
    }
}

void ingresar_articulos(articulos_t articulos[], int n) {
    int opcion = 1;
    char descripcion[90];
    int sucursal, cantidad, idx;

    do {
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s", descripcion);

        idx = buscar_o_agregar_articulo(articulos, n, descripcion);
        if (idx == -1) {
            printf("No hay espacio para mas articulos.\n");
            break;
        }

        printf("\n%s, Indice: %d\n", articulos[idx].descripcion, idx);

        do {
            printf("Para que sucursal va a realizar la carga? (1,2,3): ");
            scanf("%d", &sucursal);
        } while (sucursal < 1 || sucursal > 3);

        printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
        scanf("%d", &cantidad);

        articulos[idx].cantidad_sucursal[sucursal - 1] = cantidad;
        actualizar_total(&articulos[idx]);

        printf("Desea ingresar otro articulo? 1-Si, 2-No: ");
        scanf("%d", &opcion);
    } while (opcion == 1);
}

void mostrar_inventario(const articulos_t articulos[], int n, const char *titulo) {
    int i = 0;
    if (titulo) {
        printf("\n%s\n", titulo);
    }
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    while (i < n && articulos[i].descripcion[0] != '\0') {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",
               articulos[i].descripcion,
               articulos[i].cantidad_sucursal[SUCURSAL_1],
               articulos[i].cantidad_sucursal[SUCURSAL_2],
               articulos[i].cantidad_sucursal[SUCURSAL_3],
               articulos[i].total);
        i++;
    }
}

void ordenar_articulos_por_total(articulos_t articulos[], int n) {

    int limite = 0;
    while (limite < n && articulos[limite].descripcion[0] != '\0') limite++;

    for (int i = 0; i < limite - 1; i++) {
        for (int j = 0; j < limite - 1 - i; j++) {
            if (articulos[j].total < articulos[j+1].total) {
                articulos_t temp = articulos[j];
                articulos[j] = articulos[j+1];
                articulos[j+1] = temp;
            }
        }
    }

void mostrar_bienvenida(void) {
    printf("Bienvenido al final de Info 1\n\n");
}

void mostrar_separador_ordenado(void) {
    printf("\n###################################");
    printf("\n##############ORDENADO############");
    printf("\n###################################\n");
}
