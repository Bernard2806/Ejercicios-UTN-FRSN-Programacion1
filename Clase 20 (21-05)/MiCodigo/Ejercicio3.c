#include <stdio.h>
#include <stdlib.h>

// Cantidad de Numeros a insertar
#define CANTIDAD_NUMEROS 10

// Definición de la estructura de un nodo
typedef struct Nodo
{
    int valor;              // El valor numérico almacenado en el nodo
    struct Nodo *siguiente; // Puntero al siguiente nodo en la lista
} Nodo;

// Prototipos de Funciones
Nodo *crearNodo(int valor);                           // Crea un nuevo nodo con el valor dado
void imprimirLista(Nodo *cabeza);                     // Imprime todos los elementos de la lista
void insertarNumeroAlFinal(Nodo **cabeza, int valor); // Inserta un número al final de la lista
int generarNumeroAleatorio(int min, int max);         // Genera un número aleatorio entre min y max (incluidos)
int cantidadDeVeces(Nodo *cabeza, int valor);         // Cuenta cuántas veces aparece un valor en la lista

int main()
{
    Nodo *lista = NULL; // Inicializar una lista vacía

    // Insertar números positivos entre 1 y 1000 aleatorios al final de la lista
    for (int i = 0; i < CANTIDAD_NUMEROS; i++)
    {
        insertarNumeroAlFinal(&lista, generarNumeroAleatorio(1, 1000));
    }

    // Imprimir la lista
    imprimirLista(lista);

    // Pedir al usuario un número para contar cuántas veces aparece en la lista
    int numeroABuscar;
    printf("Ingrese un numero para contar cuantas veces aparece en la lista: ");
    scanf("%d", &numeroABuscar);

    // Contar cuántas veces aparece el número en la lista
    int cantidad = cantidadDeVeces(lista, numeroABuscar);

    // Imprimir el resultado
    if (cantidad > 0)
    {
        printf("El numero %d aparece %d veces en la lista.\n", numeroABuscar, cantidad);
    }
    else
    {
        printf("El numero %d no aparece en la lista.\n", numeroABuscar);
    }

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

    printf("Lista: ");
    // Recorrer la lista e imprimir cada valor
    while (actual != NULL)
    {
        printf("%d -> ", actual->valor);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int cantidadDeVeces(Nodo *cabeza, int valor)
{
    int contador = 0;
    Nodo *actual = cabeza;

    // Recorrer la lista
    while (actual != NULL)
    {
        if (actual->valor == valor)
        {
            contador++;
        }
        actual = actual->siguiente;
    }

    return contador;
}