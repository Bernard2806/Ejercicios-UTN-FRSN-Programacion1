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
Nodo *crearNodo(Estudiante estudiante); // Crea un nuevo nodo con un estudiante
Estudiante crearEstudiante(); // Crea un nuevo estudiante solicitando datos al usuario
void insertarEstudianteAlFinal(Nodo **cabeza, Estudiante estudiante); // Inserta un estudiante al final de la lista
void insertarEstudianteAlInicio(Nodo **cabeza, Estudiante estudiante); // Inserta un estudiante al inicio de la lista
void insertarEstudiante(Nodo **cabeza, Estudiante estudiante); // Inserta un estudiante en la lista según su nota definitiva
void imprimirLista(Nodo *cabeza); // Imprime la lista de estudiantes
void liberarLista(Nodo **cabeza); // Libera la memoria de la lista de estudiantes

int main()
{
    Nodo *listaEstudiantes = NULL; // Inicializar la lista de estudiantes como vacía

    // Ingresar y agregar estudiantes a la lista
    for (int i = 0; i < CANTIDAD_ESTUDIANTES; i++)
    {
        printf("\nEstudiante #%d:\n", i + 1);
        Estudiante est = crearEstudiante();
        insertarEstudiante(&listaEstudiantes, est);
    }

    // Imprimir lista de estudiantes
    printf("\n--- Lista final de estudiantes ---\n");
    imprimirLista(listaEstudiantes);

    // Liberar memoria
    liberarLista(&listaEstudiantes);

    return 0;
}

Nodo *crearNodo(Estudiante estudiante)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nodo\n");
        exit(1);
    }
    nuevoNodo->estudiante = estudiante;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

Estudiante crearEstudiante()
{
    Estudiante nuevoEstudiante;
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
    Nodo *nuevoNodo = crearNodo(estudiante);
    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
        return;
    }
    Nodo *temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevoNodo;
}

void insertarEstudianteAlInicio(Nodo **cabeza, Estudiante estudiante)
{
    Nodo *nuevoNodo = crearNodo(estudiante);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

void insertarEstudiante(Nodo **cabeza, Estudiante estudiante)
{
    if (estudiante.notaDefinitiva >= 6.0)
    {
        insertarEstudianteAlInicio(cabeza, estudiante);
    }
    else
    {
        insertarEstudianteAlFinal(cabeza, estudiante);
    }
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

void liberarLista(Nodo **cabeza)
{
    Nodo *actual = *cabeza;
    Nodo *siguiente;

    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    *cabeza = NULL;
}
