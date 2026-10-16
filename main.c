#include <stdio.h>
#include <stdbool.h>

/*Estructura de datos*/
typedef struct {
    char patente[10];
    char marca[30];
    char tipo;
    int año;
    double precio;
    bool disponible;
} Auto;

/* Declaracion de funciones */
void agregarAuto(void);
int main(void) {
    int opcion;

    do {
        printf("\n===== REGISTRO DE AUTOS =====\n");
        printf("1. Agregar un auto\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Debe ingresar un numero.\n");
            return 1;
        }

        switch (opcion) {
            case 1:
                agregarAuto();
                break;

            case 0:
                printf("Fin del programa.\n");
                break;

            default:
                printf("Opcion incorrecta.\n");
        }

    } while (opcion != 0);

    return 0;
}

/* Opcion 1: Pedir los datos y agregarlos al archivo */
void agregarAuto(void) {
    FILE *archivo;
    Auto autoActual;
    int disponible;
    int resultado;
    int cierre;

    printf("\nIngrese la patente (Sin espacios y 9 caracteres): ");
    if (scanf("%9s", autoActual.patente) != 1) {
        return;
    }

    printf("Ingrese la marca (Sin espacios y hasta 29 caracteres): ");
    if (scanf("%29s", autoActual.marca) != 1) {
        return;
    }

   do {
        printf("Ingrese el tipo (A = auto / C = camioneta): ");
        if (scanf(" %c", &autoActual.tipo) != 1) {
            return;
        }
    } while (autoActual.tipo != 'A' && autoActual.tipo != 'C');

    do {
        printf("Ingrese el año: ");
        if (scanf("%d", &autoActual.año) != 1) {
            printf("Año invalido.\n");
            return;

}
    } while (autoActual.año <= 0);

    do {
        printf("Ingrese el precio: ");

        if (scanf("%lf", &autoActual.precio) != 1) {
            printf("Precio invalido.\n");
            return;
        }


    } while (!(autoActual.precio > 0));

    do {
        printf("Disponible (1 = Si / 0 = No): ");

        if (scanf("%d", &disponible) != 1) {
            printf("Dato invalido.\n");
            return;
        }

    } while (disponible != 0 && disponible != 1);

    autoActual.disponible = (disponible == 1);

    archivo = fopen("autos.txt", "a");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    resultado = fprintf(
        archivo,
        "%s %s %c %d %.2f %d\n",
        autoActual.patente,
        autoActual.marca,
        autoActual.tipo,
        autoActual.año,
        autoActual.precio,
        autoActual.disponible
    );

    cierre = fclose(archivo);

    if (resultado < 0 || cierre != 0) {
        printf("Error al guardar el auto.\n");
    } else {
        printf("Auto guardado correctamente.\n");
    }
}
