#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
typedef struct Nodo
{
    int valor;              // El valor numérico almacenado en el nodo
    struct Nodo *siguiente; // Puntero al siguiente nodo en la lista
} Nodo;

// Prototipos de Funciones
Nodo *crearNodo(int valor);
void imprimirLista(Nodo *cabeza);
void insertarNumeroPositivoAleatorioAlFinal(Nodo **cabeza);
void copiarListaImpares(Nodo *cabeza, Nodo **listaImpar);
void insertarNumeroPositivoAlFinal(Nodo **cabeza, int valor);
int generarNumeroAleatorio(int min, int max);

int main()
{
    Nodo *lista = NULL; // Inicializar una lista vacía

    Nodo *listaImpar = NULL; // Inicializar una lista para números impares

    // Insertar 10 números positivos entre 1 y 1000 aleatorios al final de la lista
    for (int i = 0; i < 10; i++)
    {
        insertarNumeroPositivoAleatorioAlFinal(&lista);
    }

    // Imprimir la lista
    printf("Lista original:\n");
    imprimirLista(lista);

    // Copiar los números impares de la lista original a la lista impar
    copiarListaImpares(lista, &listaImpar);

    // Imprimir la lista de números impares
    printf("Lista de números impares:\n");
    imprimirLista(listaImpar);
    return 0;
}

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

void insertarNumeroPositivoAleatorioAlFinal(Nodo **cabeza)
{
    // Crear un nuevo nodo
    Nodo *nuevoNodo = crearNodo(generarNumeroAleatorio(1, 1000));

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

void insertarNumeroPositivoAlFinal(Nodo **cabeza, int valor)
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

int generarNumeroAleatorio(int min, int max)
{
    // Genera un número aleatorio entre min y max (incluidos)
    return rand() % (max - min + 1) + min;
}

void imprimirLista(Nodo *cabeza)
{
    Nodo *actual = cabeza;

    if (actual == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    // Recorrer la lista e imprimir cada valor
    while (actual != NULL)
    {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void copiarListaImpares(Nodo *cabeza, Nodo **listaImpar)
{
    Nodo *actual = cabeza;

    // Recorrer la lista original
    while (actual != NULL)
    {
        // Si el valor es impar, insertarlo en la lista impar
        if (actual->valor % 2 != 0)
        {
            insertarNumeroPositivoAlFinal(listaImpar, actual->valor);
        }
        actual = actual->siguiente;
    }
}