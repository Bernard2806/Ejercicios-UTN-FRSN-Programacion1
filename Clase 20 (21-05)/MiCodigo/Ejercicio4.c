#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
typedef struct Nodo
{
    int valor; // El valor numérico almacenado en el nodo
    struct Nodo *siguiente; // Puntero al siguiente nodo en la lista
} Nodo;

// Prototipos de Funciones
Nodo *crearNodo(int valor); // Crea un nuevo nodo con el valor dado
void imprimirLista(Nodo *cabeza); // Imprime los valores de la lista enlazada
void insertarNumeroAlFinal(Nodo **cabeza, int valor); // Inserta un número al final de la lista enlazada
void copiarListaPositivaONegativa(Nodo *cabeza, Nodo **lista2, int positivo); // Copia los números positivos o negativos de la lista original a una nueva lista
int generarNumeroAleatorio(int min, int max); // Genera un número aleatorio entre min y max (incluidos)

int main()
{
    Nodo *lista = NULL; // Inicializar una lista vacía

    Nodo *listaPositiva = NULL; // Inicializar una lista para números positivos

    Nodo *listaNegativa = NULL; // Inicializar una lista para números negativos

    // Insertar 10 números reales entre -1000 y 1000 aleatorios al final de la lista
    for (int i = 0; i < 10; i++)
    {
        insertarNumeroAlFinal(&lista, generarNumeroAleatorio(-1000, 1000));
    }

    // Imprimir la lista
    printf("Lista original:\n");
    imprimirLista(lista);

    // Copiar los números positivo de la lista original a la lista de positivos
    copiarListaPositivaONegativa(lista, &listaPositiva, 1);

    // Copiar los números negativos de la lista original a la lista de negativos
    copiarListaPositivaONegativa(lista, &listaNegativa, 0);

    // Imprimir la lista de números negativos
    printf("Lista de números negativos:\n");
    imprimirLista(listaNegativa);

    // Imprimir la lista de números positivos
    printf("Lista de números positivos:\n");
    imprimirLista(listaPositiva);
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

void insertarNumeroAlFinal(Nodo **cabeza, int valor)
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

// Copia los números positivos o negativos de la lista original a una nueva lista
void copiarListaPositivaONegativa(Nodo *cabeza, Nodo **lista2, int positivo)
{
    Nodo *actual = cabeza;

    // Recorrer la lista original
    while (actual != NULL)
    {
        // Si el valor es negativo, insertarlo en la lista2
        if (actual->valor < 0 && !positivo)
        {
            insertarNumeroAlFinal(lista2, actual->valor);
        }
        // Si el valor es positivo, insertarlo en la lista2
        else if (actual->valor > 0 && positivo)
        {
            insertarNumeroAlFinal(lista2, actual->valor);
        }
        actual = actual->siguiente;
    }
}