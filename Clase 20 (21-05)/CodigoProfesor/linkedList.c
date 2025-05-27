/**
 * Implementación de una Lista Enlazada Simple en C
 *
 * Este programa demuestra cómo implementar una lista enlazada
 * simple para almacenar números enteros utilizando structs.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Definición de la estructura de un nodo
 * Cada nodo contiene un valor entero y un puntero al siguiente nodo
 */

typedef struct Nodo
{
    int valor;              // El valor numérico almacenado en el nodo
    struct Nodo *siguiente; // Puntero al siguiente nodo en la lista
} Nodo;

// Prototipos de Funciones
Nodo *crearNodo(int valor);
void insertarAlInicio(Nodo **cabeza, int valor);
void insertarAlFinal(Nodo **cabeza, int valor);
int buscar(Nodo *cabeza, int valor);
int eliminar(Nodo **cabeza, int valor);
void imprimirLista(Nodo *cabeza);
void liberarLista(Nodo **cabeza);

/**
 * Función principal para demostrar el uso de la lista enlazada
 */
int main()
{
    Nodo *lista = NULL; // Inicializar una lista vacía

    // Insertar algunos valores
    insertarAlFinal(&lista, 10);
    insertarAlFinal(&lista, 20);
    insertarAlInicio(&lista, 5);
    insertarAlFinal(&lista, 30);

    // Imprimir la lista
    imprimirLista(lista);

    // Buscar valores
    printf("¿El valor 20 está en la lista? %s\n",
           buscar(lista, 20) ? "Sí" : "No");
    printf("¿El valor 25 está en la lista? %s\n",
           buscar(lista, 25) ? "Sí" : "No");

    // Eliminar un valor
    printf("Eliminando el valor 20...\n");
    eliminar(&lista, 20);
    imprimirLista(lista);

    // Liberar la memoria al final
    liberarLista(&lista);
    printf("Memoria liberada\n");

    return 0;
}

/**
 * Función para crear un nuevo nodo
 * @param valor El valor entero a almacenar en el nodo
 * @return Puntero al nuevo nodo creado
 */
Nodo *crearNodo(int valor)
{
    // Reservar memoria para el nuevo nodo
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    // Verificar si se pudo asignar memoria
    if (nuevoNodo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nodo\n");
        exit(1);
    }

    // Inicializar el nodo con el valor dado y sin siguiente nodo
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

/**
 * Función para insertar un nodo al inicio de la lista
 * @param cabeza Puntero al puntero de la cabeza de la lista
 * @param valor El valor a insertar
 */
void insertarAlInicio(Nodo **cabeza, int valor)
{
    // Crear un nuevo nodo
    Nodo *nuevoNodo = crearNodo(valor);

    // El siguiente del nuevo nodo será la cabeza actual
    nuevoNodo->siguiente = *cabeza;

    // La nueva cabeza será el nuevo nodo
    *cabeza = nuevoNodo;
}

/**
 * Función para insertar un nodo al final de la lista
 * @param cabeza Puntero al puntero de la cabeza de la lista
 * @param valor El valor a insertar
 */
void insertarAlFinal(Nodo **cabeza, int valor)
{
    // Crear un nuevo nodo
    Nodo *nuevoNodo = crearNodo(valor);

    // Si la lista está vacía, el nuevo nodo será la cabeza
    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
        return;
    }

    // Encontrar el último nodo
    Nodo *temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }

    // Insertar el nuevo nodo después del último nodo
    temp->siguiente = nuevoNodo;
}

/**
 * Función para buscar un valor en la lista
 * @param cabeza Puntero a la cabeza de la lista
 * @param valor El valor a buscar
 * @return 1 si el valor se encuentra, 0 si no
 */
int buscar(Nodo *cabeza, int valor)
{
    Nodo *actual = cabeza;

    // Recorrer la lista
    while (actual != NULL)
    {
        // Si encontramos el valor, devolver 1
        if (actual->valor == valor)
        {
            return 1;
        }
        actual = actual->siguiente;
    }

    // Si llegamos aquí, el valor no se encontró
    return 0;
}

/**
 * Función para eliminar un nodo con un valor específico
 * @param cabeza Puntero al puntero de la cabeza de la lista
 * @param valor El valor a eliminar
 * @return 1 si el valor se eliminó, 0 si no se encontró
 */
int eliminar(Nodo **cabeza, int valor)
{
    // Si la lista está vacía
    if (*cabeza == NULL)
    {
        return 0;
    }

    // Si el valor está en la cabeza
    if ((*cabeza)->valor == valor)
    {
        Nodo *temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp);
        return 1;
    }

    // Buscar el nodo a eliminar
    Nodo *actual = *cabeza;
    while (actual->siguiente != NULL && actual->siguiente->valor != valor)
    {
        actual = actual->siguiente;
    }

    // Si se encontró el valor
    if (actual->siguiente != NULL)
    {
        Nodo *temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        free(temp);
        return 1;
    }

    // Si llegamos aquí, el valor no se encontró
    return 0;
}

/**
 * Función para imprimir todos los elementos de la lista
 * @param cabeza Puntero a la cabeza de la lista
 */
void imprimirLista(Nodo *cabeza)
{
    Nodo *actual = cabeza;

    if (actual == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    printf("Lista: ");
    // Recorrer la lista e imprimir cada valor
    while (actual != NULL)
    {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

/**
 * Función para liberar toda la memoria ocupada por la lista
 * @param cabeza Puntero al puntero de la cabeza de la lista
 */
void liberarLista(Nodo **cabeza)
{
    Nodo *actual = *cabeza;
    Nodo *siguiente;

    // Liberar cada nodo
    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    // Establecer la cabeza como NULL (lista vacía)
    *cabeza = NULL;
}