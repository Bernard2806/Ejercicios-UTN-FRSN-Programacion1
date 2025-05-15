#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
typedef struct
{
    char nombre[50];
    char edad[4]; // <-- Corregido
    char legajo[10];
} Estudiante;

// Prototipos de funciones
void cargarEstudiante(Estudiante *e);
void mostrarEstudiante(Estudiante e);

int main()
{
    Estudiante est1;
    Estudiante est2;

    printf("Cargar datos del primer estudiante:\n");
    cargarEstudiante(&est1);

    printf("\nCargar datos del segundo estudiante:\n");
    cargarEstudiante(&est2);

    printf("\nDatos del primer estudiante:\n");
    mostrarEstudiante(est1);

    printf("\nDatos del segundo estudiante:\n");
    mostrarEstudiante(est2);

    return 0;
}

void cargarEstudiante(Estudiante *e)
{
    printf("Ingrese el nombre del estudiante: ");
    fgets(e->nombre, sizeof(e->nombre), stdin);
    e->nombre[strcspn(e->nombre, "\n")] = '\0';

    printf("Ingrese la edad del estudiante: ");
    fgets(e->edad, sizeof(e->edad), stdin);
    e->edad[strcspn(e->edad, "\n")] = '\0';

    printf("Ingrese el legajo del estudiante: ");
    fgets(e->legajo, sizeof(e->legajo), stdin);
    e->legajo[strcspn(e->legajo, "\n")] = '\0';
}

void mostrarEstudiante(Estudiante e)
{
    printf("Nombre: %s\n", e.nombre);
    printf("Edad: %s\n", e.edad);
    printf("Legajo: %s\n", e.legajo);
}
