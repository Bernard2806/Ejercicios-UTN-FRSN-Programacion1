#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones

// Funciones de uso recurrente
void mostrarArray(float array[], int size);
void clearConsole();

// Funciones para imprimir arte ASCII y menú
void imprimirArteAscii();
void imprimirInicio();
int imprimirMenu();

// Funcion de la lógica del menú
void logicaMenu(int opcion, float notas[]);

int main()
{
    imprimirInicio(); // Imprime el arte ASCII y espera a que el usuario presione una tecla

    float notasOriginal[10] = {7.5, 5.0, 9.2, 6.8, 8.1, 4.3, 7.0, 5.5, 9.9, 6.0};

    while (1)
    {
        int opcion = imprimirMenu();       // Imprime el menú y obtiene la opción del usuario
        logicaMenu(opcion, notasOriginal); // Llama a la función que maneja la lógica del menú
    }

    return 0;
}

void logicaMenu(int opcion, float notas[])
{
    int largoArray = sizeof(notas) / sizeof(notas[0]); // Calcula el tamaño del array

    switch (opcion)
    {
    case 1:
        // Lógica para ordenar usando Bubble Sort
        break;
    case 2:
        // Lógica para ordenar usando Insertion Sort
        break;
    case 3:
        // Lógica para ordenar usando Selection Sort
        break;
    case 4:
        mostrarArray(notas, largoArray); // Muestra el array original
        printf("\nPresiona cualquier tecla para continuar...\n");
        getchar(); // Espera a que el usuario presione una tecla
        break;
    case 5:
        exit(0); // Salir del programa
    }
}

int imprimirMenu()
{
    int opcion = 0;

    do
    {
        clearConsole(); // Limpia la consola
        printf("====== MENÚ ======\n");
        printf("1. Ordenar usando Bubble Sort\n");
        printf("2. Ordenar usando Insertion Sort\n");
        printf("3. Ordenar usando Selection Sort\n");
        printf("4. Mostrar array original\n");
        printf("5. Salir\n");
        printf("==================\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 5); // Validar opción

    return opcion;
}

void imprimirInicio()
{
    imprimirArteAscii();
    printf("\n\n");
    printf("\n\n");
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();      // Espera a que el usuario presione una tecla
    clearConsole(); // Limpia la consola
}

void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void imprimirArteAscii()
{
    clearConsole(); // Limpia la consola

    // Arte ASCII
    printf(
        "           _                  _ _                             _         ____          _                            _            _        \n"
        "     /\\   | |                (_) |                           | |       / __ \\        | |                          (_)          | |       \n"
        "    /  \\  | | __ _  ___  _ __ _| |_ _ __ ___   ___  ___    __| | ___  | |  | |_ __ __| | ___ _ __   __ _ _ __ ___  _  ___ _ __ | |_ ___  \n"
        "   / /\\ \\ | |/ _` |/ _ \\| '__| | __| '_ ` _ \\ / _ \\/ __|  / _` |/ _ \\ | |  | | '__/ _` |/ _ \\ '_ \\ / _` | '_ ` _ \\| |/ _ \\ '_ \\| __/ _ \\ \n"
        "  / ____ \\| | (_| | (_) | |  | | |_| | | | | | (_) \\__ \\ | (_| |  __/ | |__| | | | (_| |  __/ | | | (_| | | | | | | |  __/ | | | || (_) |\n"
        " /_/    \\_\\_|\\__, |\\___/|_|  |_|\\__|_| |_| |_|\\___/|___/  \\__,_|\\___|  \\____/|_|  \\__,_|\\___|_| |_|\\__,_|_| |_| |_|_|\\___|_| |_|\\__\\___/ \n"
        "              __/ |                                                                                                                      \n"
        "             |___/                                                                                                                       \n");
}