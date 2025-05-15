#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
// Esta estructura representa un estudiante con su nombre, edad y legajo
typedef struct
{
    char nombre[50];
    char edad[2];
    char legajo[10];
} Estudiante;

// Prototipos de funciones
void cargarEstudiante(Estudiante *e);
void mostrarEstudiante(Estudiante e);

int main()
{
    // Declaración de una variable de tipo Estudiante
    Estudiante est1;
    Estudiante est2;

    // Carga de datos del estudiante
    cargarEstudiante(&est1);
    cargarEstudiante(&est2);

    // Mostrar los datos del estudiante
    mostrarEstudiante(est1);
    mostrarEstudiante(est2);

    return 0;
}

// Función para cargar los datos de un estudiante
void cargarEstudiante(Estudiante *e)
{
    // Solicitar al usuario que ingrese el nombre del estudiante
    printf("Ingrese el nombre del estudiante: ");
    fgets(e->nombre, sizeof(e->nombre), stdin);
    e->nombre[strcspn(e->nombre, "\n")] = '\0'; // Eliminar el salto de línea

    // Solicitar al usuario que ingrese la edad del estudiante
    printf("Ingrese la edad del estudiante: ");
    fgets(e->edad, sizeof(e->edad), stdin);
    e->edad[strcspn(e->edad, "\n")] = '\0'; // Eliminar el salto de línea

    // Solicitar al usuario que ingrese el legajo del estudiante
    printf("Ingrese el legajo del estudiante: ");
    fgets(e->legajo, sizeof(e->legajo), stdin);
    e->legajo[strcspn(e->legajo, "\n")] = '\0'; // Eliminar el salto de línea
}

// Función para mostrar los datos de un estudiante
void mostrarEstudiante(Estudiante e)
{
    // Mostrar los datos del estudiante
    printf("Nombre: %s\n", e.nombre);
    printf("Edad: %s\n", e.edad);
    printf("Legajo: %s\n", e.legajo);
}