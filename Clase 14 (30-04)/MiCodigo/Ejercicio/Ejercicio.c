#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Funciones de ordenamiento
void bubbleSort(int arr[], int n, int *comparaciones, int *intercambios);
void insertionSort(int arr[], int n, int *comparaciones, int *intercambios);
void selectionSort(int arr[], int n, int *comparaciones, int *intercambios);

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

    float notasCopia[largoArray]; // Crea un array copia para no modificar el original

    memcpy(notasCopia, notas, sizeof(notas)); // Copia el contenido del array original al array copia

    int comparaciones = 0, intercambios = 0; // Inicializa contadores de comparaciones e intercambios

    clearConsole(); // Limpia la consola

    // Lógica del menú según la opción seleccionada
    switch (opcion)
    {
    case 1:
        // Lógica para ordenar usando Bubble Sort
        bubbleSort(notasCopia, largoArray, &comparaciones, &intercambios);
        printf("Bubble Sort:\n");
        printf("Comparaciones: %d\n", comparaciones);
        printf("Intercambios: %d\n", intercambios);
        printf("Array ordenado:\n");
        mostrarArray(notasCopia, largoArray); // Muestra el array ordenado
        break;
    case 2:
        // Lógica para ordenar usando Insertion Sort
        insertionSort(notasCopia, largoArray, &comparaciones, &intercambios);
        printf("Insertion Sort:\n");
        printf("Comparaciones: %d\n", comparaciones);
        printf("Intercambios: %d\n", intercambios);
        printf("Array ordenado:\n");
        mostrarArray(notasCopia, largoArray); // Muestra el array ordenado
        break;
    case 3:
        // Lógica para ordenar usando Selection Sort
        selectionSort(notasCopia, largoArray, &comparaciones, &intercambios);
        printf("Selection Sort:\n");
        printf("Comparaciones: %d\n", comparaciones);
        printf("Intercambios: %d\n", intercambios);
        printf("Array ordenado:\n");
        mostrarArray(notasCopia, largoArray); // Muestra el array ordenado
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

// Función Selection Sort que cuenta comparaciones e intercambios
void selectionSort(int arr[], int n, int *comparaciones, int *intercambios) {
    *comparaciones = 0;
    *intercambios = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            (*comparaciones)++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Solo intercambiamos si es necesario
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*intercambios)++;
        }

        printf("Después de pasada %d: ", i + 1);
        mostrarArray(arr, n);
    }
}

// Función de Bubble Sort que cuenta comparaciones e intercambios
void bubbleSort(int arr[], int n, int *comparaciones, int *intercambios)
{
    *comparaciones = 0;
    *intercambios = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            (*comparaciones)++;
            if (arr[j] > arr[j + 1])
            {
                // Intercambiar
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*intercambios)++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int *comparaciones, int *intercambios)
{
    *comparaciones = 0;
    *intercambios = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            (*comparaciones)++; // Contamos la comparación j >= 0 && arr[j] > key
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                (*intercambios)++; // Contamos el movimiento como intercambio
                j--;
            }
            else
            {
                break; // Si no se cumple, rompemos el ciclo
            }
        }
        arr[j + 1] = key;

        printf("Después de pasada %d: ", i);
        mostrarArray(arr, n);
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