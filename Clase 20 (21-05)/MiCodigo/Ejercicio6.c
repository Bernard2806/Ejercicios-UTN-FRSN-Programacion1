#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de un Auto
typedef struct Auto
{
    char patente[10];     // Patente del auto
    char modelo[50];      // Modelo del auto
    int anio;             // Año del auto
    char color[20];       // Color del auto
    char propietario[50]; // Nombre del propietario del auto
} Auto;

// Estructura de un Nodo
typedef struct Nodo
{
    Auto valor;             // Valor del nodo, que es un Auto
    struct Nodo *siguiente; // Puntero al siguiente nodo en la lista
} Nodo;

// Función para crear un nuevo nodo
Nodo *crearNodo(Auto autoInfo)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevo->valor = autoInfo;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Función para insertar un nodo al final de la lista
void insertarNodo(Nodo **cabeza, Auto autoInfo)
{
    Nodo *nuevo = crearNodo(autoInfo);
    if (*cabeza == NULL)
    {
        *cabeza = nuevo;
    }
    else
    {
        Nodo *actual = *cabeza;
        while (actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

// Función para mostrar todos los autos y contar cuántos hay
int mostrarAutos(Nodo *cabeza)
{
    int contador = 0;
    Nodo *actual = cabeza;
    while (actual != NULL)
    {
        printf("\nAuto %d:\n", contador + 1);
        printf("Patente: %s\n", actual->valor.patente);
        printf("Modelo: %s\n", actual->valor.modelo);
        printf("Año: %d\n", actual->valor.anio);
        printf("Color: %s\n", actual->valor.color);
        printf("Propietario: %s\n", actual->valor.propietario);
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

int main()
{
    Nodo *listaAutos = NULL;
    Auto temp;
    char continuar = 's';

    printf("Registro de vehículos - Estacionamiento UTN\n");

    while (continuar == 's' || continuar == 'S')
    {
        printf("\nIngrese los datos del vehículo:\n");
        printf("Patente: ");
        scanf("%s", temp.patente);

        printf("Modelo: ");
        scanf(" %[^\n]", temp.modelo); // para leer cadenas con espacios

        printf("Año: ");
        scanf("%d", &temp.anio);

        printf("Color: ");
        scanf(" %[^\n]", temp.color);

        printf("Propietario: ");
        scanf(" %[^\n]", temp.propietario);

        insertarNodo(&listaAutos, temp);

        printf("\n¿Desea ingresar otro vehículo? (s/n): ");
        scanf(" %c", &continuar);
    }

    int total = mostrarAutos(listaAutos);
    printf("\nCantidad total de vehículos registrados: %d\n", total);

    // Liberar memoria
    Nodo *actual = listaAutos;
    while (actual != NULL)
    {
        Nodo *tmp = actual;
        actual = actual->siguiente;
        free(tmp);
    }

    return 0;
}