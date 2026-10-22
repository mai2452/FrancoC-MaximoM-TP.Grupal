#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> // Cambiar caracter (a -> A)
#include <string.h> // Comparar strings (Busqueda de auto)
#define PLACA 8 // Tama;o de placa de auto
#define STR 30 // String tamaño
#define YEAR 2020 // Año para listar autos

/*Estructura de datos*/
typedef struct {
    char patente[PLACA];
    char marca[STR];
    char tipo;
    int anio;
    double precio;
    bool disponible;
} Auto;

/* Declaracion de funciones */
void agregarAuto(void);
void listarAutos(void);
void listarAnioAdelante(void);
void buscarAuto(void);
void separar(void);

int main(void) {
    int opcion;

    do {
        printf("\n===== REGISTRO DE AUTOS =====\n");
        printf("1. Agregar un auto\n");
        printf("2. Listar autos\n");
        printf("3. Listar autos %d en adelante\n", YEAR);
        printf("4. Buscar auto\n");
        printf("5. Separar autos(disponible / NO disponible)\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Debe ingresar un numero.\n");

            while (getchar() != '\n'); // Limpiza del buffer

            opcion = -1;
        }else{
            switch (opcion) {
            case 1:
                agregarAuto();
                break;
            case 2:
                listarAutos();
                break;
            case 3:
                listarAnioAdelante();
                break;
            case 4:
                buscarAuto();
                break;
            case 5:
                separar();
                break;
            case 0:
                printf("Fin del programa.\n");
                break;
            default:
                printf("Opcion incorrecta.\n");
            }
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

    printf("\nIngrese la patente (Sin espacios y 7 caracteres): ");
    if (scanf("%7s", autoActual.patente) != 1) {
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

        // Cambio de caracter (a -> A), para validacion correcta
        autoActual.tipo = toupper(autoActual.tipo);
    } while (autoActual.tipo != 'A' && autoActual.tipo != 'C');

    do {
        printf("Ingrese el anio: ");

        if (scanf("%d", &autoActual.anio) != 1) {
            printf("Anio invalido.\n");
            return;
        }

        if (autoActual.anio <= 0) {
            printf("El anio debe ser mayor que cero.\n");
        }

    } while (autoActual.anio <= 0);

    do {
        printf("Ingrese el precio: ");

        if (scanf("%lf", &autoActual.precio) != 1) {
            printf("Precio invalido.\n");
            return;
        }

        if (autoActual.precio < 0) {
            printf("El precio no puede ser negativo.\n");
        }

    } while (!(autoActual.precio >= 0));

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
        autoActual.anio,
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

// Opcion 2: Listar autos

void listarAutos(void) {
    FILE *archivo;
    Auto autoActual;
    int disponible;
    int cantidad = 0;

    archivo = fopen("autos.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    printf("\n===== LISTADO DE AUTOS =====\n");
    printf("PATENTE | MARCA | TIPO | ANIO | PRECIO | DISPONIBLE\n");
    printf("----------------------------------------------------------\n");

    while (fscanf(archivo, "%7s %29s %c %d %lf %d",
                  autoActual.patente,
                  autoActual.marca,
                  &autoActual.tipo,
                  &autoActual.anio,
                  &autoActual.precio,
                  &disponible) == 6) {

        autoActual.disponible = (disponible == 1);

        printf("%s | %s | %c | %d | $%.2f | ",
               autoActual.patente,
               autoActual.marca,
               autoActual.tipo,
               autoActual.anio,
               autoActual.precio);

        if (autoActual.disponible) {
            printf("Si\n");
        } else {
            printf("No\n");
        }

        cantidad++;
                  }

    fclose(archivo);

    printf("\nCantidad de autos: %d\n", cantidad);
}

// Opcion 3: Listar autos de a;o (2020) en adelante
void listarAnioAdelante(){
    FILE *archivo;
    Auto autoActual;

    archivo = fopen("autos.txt", "r");

    if(archivo == NULL){
        printf("No se pudo abrir el archivo.\n");
    }else{
        int disponible;

        printf("\n===== AUTOS DEL ANIO %d EN ADELANTE =====\n", YEAR);
        printf("PATENTE | MARCA  | TIPO | ANIO | PRECIO | DISPONIBLE\n");
        printf("----------------------------------------------------------\n");
        while(fscanf(archivo, "%7s %29s %c %d %lf %d",
                autoActual.patente,
                autoActual.marca,
                &autoActual.tipo,
                &autoActual.anio,
                &autoActual.precio,
                &disponible) == 6){

            autoActual.disponible = (disponible == 1);

            if(autoActual.anio >= YEAR){
                printf("%s %s %c %d $%.2lf %d\n",
                    autoActual.patente,
                    autoActual.marca,
                    autoActual.tipo,
                    autoActual.anio,
                    autoActual.precio,
                    autoActual.disponible);
            }
        }
        fclose(archivo);
    }
}
// Opcion 4: Buscar auto por patente
void buscarAuto(){
    FILE *archivo;
    Auto autoActual;
    int encontrado = -1;
    char patenteBuscar[PLACA];
    int disponible;

    printf("Ingrese patente: ");

    if (scanf("%7s", patenteBuscar) != 1) {
        printf("Patente invalida.\n");
        return;
    }

     archivo = fopen("autos.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    while (fscanf(archivo, "%7s %29s %c %d %lf %d",
                  autoActual.patente,
                  autoActual.marca,
                  &autoActual.tipo,
                  &autoActual.anio,
                  &autoActual.precio,
                  &disponible) == 6 && encontrado == -1) {

            autoActual.disponible = (disponible == 1);

        if (strcmp(autoActual.patente, patenteBuscar) == 0) {
            printf("\nAuto encontrado:\n");
            printf("Patente: %s\n", autoActual.patente);
            printf("Marca: %s\n", autoActual.marca);
            printf("Tipo: %c\n", autoActual.tipo);
            printf("Anio: %d\n", autoActual.anio);
            printf("Precio: %.2f\n", autoActual.precio);
            printf("Disponible? :");
            if(autoActual.disponible == 0){
                printf("No\n");
            }else{
                printf("Si\n");
            }

            encontrado = 1;
        }
    }

    fclose(archivo);

    if (encontrado == -1) {
        printf("No se encontro un auto con esa patente.\n");
    }
}

// Opcion 5: Separar disponible y no disponible (diferente archivos)
void separar(){
    FILE *archivo;
    Auto autoActual;
    int disponible;
    archivo = fopen("autos.txt", "r");

    if(archivo == NULL){
        printf("No se pudo abrir el archivo.\n");
    }else{

        FILE *archDisponible = fopen("disponible.txt", "w");
        FILE *arch_no_Disponible = fopen("no_disponible.txt", "w");

        if (archDisponible == NULL || arch_no_Disponible == NULL) {
            printf("No se pudieron abrir los archivos de salida.\n");
            if (archDisponible != NULL) {
                fclose(archDisponible);
            }
            if (arch_no_Disponible != NULL) {
                fclose(arch_no_Disponible);
            }

            fclose(archivo);
            return;
        }

        while(fscanf(archivo, "%7s %29s %c %d %lf %d",
                autoActual.patente,
                autoActual.marca,
                &autoActual.tipo,
                &autoActual.anio,
                &autoActual.precio,
                &disponible) == 6){

            autoActual.disponible = (disponible == 1);

            if(autoActual.disponible == 1){
                fprintf(archDisponible, "%s %s %c %d %lf %d\n",
                    autoActual.patente,
                    autoActual.marca,
                    autoActual.tipo,
                    autoActual.anio,
                    autoActual.precio,
                    autoActual.disponible);
            }else{
                fprintf(arch_no_Disponible, "%s %s %c %d %lf %d\n",
                    autoActual.patente,
                    autoActual.marca,
                    autoActual.tipo,
                    autoActual.anio,
                    autoActual.precio,
                    autoActual.disponible);
            }
        }

        printf("Autos separados correctamente.\n");

        fclose(archivo);
        fclose(archDisponible);
        fclose(arch_no_Disponible);
    }
}