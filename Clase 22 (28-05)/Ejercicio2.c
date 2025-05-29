#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Contacto
// Esta estructura representa un contacto con su nombre, teléfono, email y categoría.
typedef struct { 
    char nombre[50]; 
    char telefono[15]; 
    char email[50]; 
    int categoria;  // 1=Familia, 2=Trabajo, 3=Amigos 
} Contacto;

// Prototipos de Funciones
int mostrarMenuIncial();
void logicaMenuInicial(int opcion);

int main()
{

    while (1)
    {
        int opcion = mostrarMenuIncial();
        logicaMenuInicial(opcion);
        printf("\n");
    }

    return 0;
}

void logicaMenuInicial(int opcion)
{
    switch (opcion)
    {
    case 1:
        printf("Mostrar todos\n");
        // Aquí iría la lógica para mostrar todos los elementos
        break;
    case 2:
        printf("Buscar por categoría\n");
        // Aquí iría la lógica para buscar por categoría
        break;
    case 3:
        printf("Ordenar por nombre\n");
        // Aquí iría la lógica para ordenar por nombre
        break;
    case 4:
        printf("Contar por categoría\n");
        // Aquí iría la lógica para contar por categoría
        break;
    case 5:
        exit(0);
    default:
        printf("Opción no válida.\n");
    }
}
int mostrarMenuIncial()
{
    int opcion;

    printf("1. Mostrar todos\n");
    printf("2. Buscar por categoría\n");
    printf("3. Ordenar por nombre\n");
    printf("4. Contar por categoría\n");
    printf("5. Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    while (opcion < 1 || opcion > 5)
    {
        printf("Opción inválida. Por favor, ingrese una opción entre 1 y 5: ");
        scanf("%d", &opcion);
    }

    return opcion;
}