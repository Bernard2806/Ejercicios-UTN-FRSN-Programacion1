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
Nodo *crearNodo(Estudiante estudiante);                                // Crea un nuevo nodo con un estudiante
Estudiante crearEstudiante();                                          // Crea un nuevo estudiante solicitando datos al usuario
void insertarEstudianteAlFinal(Nodo **cabeza, Estudiante estudiante);  // Inserta un estudiante al final de la lista
void insertarEstudianteAlInicio(Nodo **cabeza, Estudiante estudiante); // Inserta un estudiante al inicio de la lista
void insertarEstudiante(Nodo **cabeza, Estudiante estudiante);         // Inserta un estudiante en la lista según su nota definitiva
void imprimirLista(Nodo *cabeza);                                      // Imprime la lista de estudiantes
void liberarLista(Nodo **cabeza);                                      // Libera la memoria de la lista de estudiantes

// Prototipo de Funciones de los Ejercicios
void buscarEstudiantePorLegajo(Nodo *cabeza, int legajo);    // Busca un estudiante por su legajo
void eliminarEstudiantePorLegajo(Nodo **cabeza, int legajo); // Elimina un estudiante por su legajo
int totalEstudiantesAprobados(Nodo *cabeza);                 // Cuenta el total de estudiantes aprobados
int totalEstudiantesDesaprobados(Nodo *cabeza);              // Cuenta el total de estudiantes desaprobados

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

    // Buscar un estudiante por legajo
    int legajoABuscar;
    printf("\nIngrese el legajo del estudiante a buscar: ");
    scanf("%d", &legajoABuscar);

    buscarEstudiantePorLegajo(listaEstudiantes, legajoABuscar);

    // Eliminar un estudiante por legajo (opcional)
    printf("\n¿Desea Eliminar un Estudiante? (Y/N): ");
    char respuesta;
    scanf(" %c", &respuesta);

    if (respuesta == 'Y' || respuesta == 'y')
    {
        int legajoAEliminar;
        printf("Ingrese el legajo del estudiante a eliminar: ");
        scanf("%d", &legajoAEliminar);
        eliminarEstudiantePorLegajo(&listaEstudiantes, legajoAEliminar);

        // Imprimir lista de estudiantes después de eliminar
        printf("\n--- Lista de estudiantes después de eliminar ---\n");
        imprimirLista(listaEstudiantes);
    }
    else
    {
        printf("No se elimino ningún estudiante.\n");
    }

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

void buscarEstudiantePorLegajo(Nodo *cabeza, int legajo)
{
    Nodo *actual = cabeza;
    while (actual != NULL)
    {
        if (actual->estudiante.legajo == legajo)
        {
            printf("Estudiante encontrado: Legajo: %d, Nombre: %s, Apellido: %s, Nota Definitiva: %.2f\n",
                   actual->estudiante.legajo,
                   actual->estudiante.nombre,
                   actual->estudiante.apellido,
                   actual->estudiante.notaDefinitiva);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Estudiante con legajo %d no encontrado.\n", legajo);
}

void eliminarEstudiantePorLegajo(Nodo **cabeza, int legajo)
{
    Nodo *actual = *cabeza;
    Nodo *anterior = NULL;

    while (actual != NULL && actual->estudiante.legajo != legajo)
    {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL)
    {
        printf("Estudiante con legajo %d no encontrado.\n", legajo);
        return;
    }

    if (anterior == NULL)
    {
        *cabeza = actual->siguiente; // Eliminar el primer nodo
    }
    else
    {
        anterior->siguiente = actual->siguiente; // Eliminar un nodo intermedio o final
    }

    free(actual);
    printf("Estudiante con legajo %d eliminado.\n", legajo);
}