#include <stdio.h>
#include <stdlib.h>

// Constante para la cantidad de estudiantes a insertar
#define CANTIDAD_ESTUDIANTES 5

// Definición de la estructura de un Estudiante de Universidad Tecnológica Nacional (UTN)
typedef struct Estudiante
{
    int legajo;           // Número de legajo del estudiante
    char nombre[50];      // Nombre del estudiante
    char apellido[50];    // Apellido del estudiante
    float notaDefinitiva; // Nota definitiva del estudiante
} Estudiante;

// Definición de la estructura de un nodo
typedef struct Nodo
{
    Estudiante estudiante;  // Valor del nodo, que es un Estudiante
    struct Nodo *siguiente; // Puntero al siguiente nodo en la lista
} Nodo;

// Prototipos de Funciones
Nodo *crearNodo(Estudiante estudiante);                                // Crea un nuevo nodo con el estudiante dado
Estudiante crearEstudiante();                                          // Crea un estudiante con datos ingresados por el usuario
void insertarEstudianteAlFinal(Nodo **cabeza, Estudiante estudiante);  // Inserta un estudiante al final de la lista
void insertarEstudianteAlInicio(Nodo **cabeza, Estudiante estudiante); // Inserta un estudiante al inicio de la lista
void imprimirLista(Nodo *cabeza);                                      // Imprime la lista de estudiantes
void liberarLista(Nodo **cabeza);                                      // Libera la memoria de la lista de estudiantes

int main()
{
    Nodo *listaEstudiantes = NULL; // Inicializar una lista vacía de estudiantes

    return 0;
}

Nodo *crearNodo(Estudiante estudiante)
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
    nuevoNodo->estudiante = estudiante;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

Estudiante crearEstudiante()
{
    Estudiante nuevoEstudiante;

    // Ingresar los datos del estudiante
    printf("Ingrese el número de legajo: ");
    scanf("%d", &nuevoEstudiante.legajo);
    printf("Ingrese el nombre: ");
    scanf("%s", nuevoEstudiante.nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", nuevoEstudiante.apellido);
    printf("Ingrese la nota definitiva: ");
    scanf("%f", &nuevoEstudiante.notaDefinitiva);

    return nuevoEstudiante;
}

void insertarEstudianteAlFinal(Nodo **cabeza, Estudiante estudiante)
{
    // Crear un nuevo nodo
    Nodo *nuevoNodo = crearNodo(estudiante);

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

void imprimirLista(Nodo *cabeza)
{
    Nodo *actual = cabeza;

    if (actual == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    printf("Lista de Estudiantes:\n");
    // Recorrer la lista e imprimir cada estudiante
    while (actual != NULL)
    {
        printf("Legajo: %d, Nombre: %s, Apellido: %s, Nota Definitiva: %.2f\n",
               actual->estudiante.legajo,
               actual->estudiante.nombre,
               actual->estudiante.apellido,
               actual->estudiante.notaDefinitiva);
        actual = actual->siguiente;
    }
}