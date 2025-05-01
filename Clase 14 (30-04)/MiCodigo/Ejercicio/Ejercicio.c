#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones

void clearConsole();

void imprimirArteAscii();
void imprimirInicio();
int imprimirMenu();

void logicaMenu(int opcion);

int main()
{
    imprimirInicio(); // Imprime el arte ASCII y espera a que el usuario presione una tecla

    float notas[10] = {7.5, 5.0, 9.2, 6.8, 8.1, 4.3, 7.0, 5.5, 9.9, 6.0};

    while(1)
    {
        int opcion = imprimirMenu(); // Imprime el menú y obtiene la opción del usuario
        logicaMenu(opcion); // Llama a la función que maneja la lógica del menú
    }

    return 0;
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

void ImprimirArteAscii()
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