#include <stdio.h>
#include <stdlib.h>

// Defino una constante para el máximo de empleados
#define MAX_EMPLEADOS 5

// Definir estructura Empleado
typedef struct Empleado
{
    int legajo;
    char nombre[30];
    float sueldo;
} Empleado;

// Prototipos de funciones
void agregarEmpleado(Empleado *empleados, int *numEmpleados);                            // Agrega un solo empleado
void agregarEmpleados(Empleado *empleados, int *numEmpleados, int cantidad);             // Agrega varios empleados
void mostrarEmpleados(struct Empleado[], int numEmpleados);                              // Muestra los empleados
void buscarEmpleadoPorLegajo(Empleado empleados[], int numEmpleados, int legajo);        // Busca un empleado por legajo
void aumentarSueldosEmpleados(Empleado empleados[], int numEmpleados, float porcentaje); // Aumenta sueldos de empleados

int main()
{
    // Declarar un arreglo de empleados
    Empleado empleados[MAX_EMPLEADOS];

    int numEmpleados = 0; // Contador de empleados

    agregarEmpleados(empleados, &numEmpleados, 5); // Agregar 5 empleados

    // Mostrar los empleados agregados
    printf("Lista de empleados:\n");
    mostrarEmpleados(empleados, numEmpleados);

    printf("Ingrese el legajo del empleado a buscar: ");
    int legajoBuscado;
    scanf("%d", &legajoBuscado);

    // Buscar un empleado por legajo
    buscarEmpleadoPorLegajo(empleados, numEmpleados, legajoBuscado);

    printf("Ingrese el porcentaje de aumento de sueldo: ");
    float porcentajeAumento;
    scanf("%f", &porcentajeAumento);

    // Aumentar sueldos de todos los empleados
    aumentarSueldosEmpleados(empleados, numEmpleados, porcentajeAumento);

    printf("Lista de empleados después del aumento de sueldo:\n");
    mostrarEmpleados(empleados, numEmpleados); // Mostrar empleados después del aumento

    return 0;
}

void agregarEmpleado(Empleado *empleados, int *numEmpleados)
{
    if (*numEmpleados < MAX_EMPLEADOS)
    {
        Empleado nuevoEmpleado;
        printf("Ingrese el legajo del empleado: ");
        scanf("%d", &nuevoEmpleado.legajo);
        printf("Ingrese el nombre del empleado: ");
        scanf("%s", nuevoEmpleado.nombre);
        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &nuevoEmpleado.sueldo);

        empleados[*numEmpleados] = nuevoEmpleado;
        (*numEmpleados)++;
    }
    else
    {
        printf("No se pueden agregar más empleados.\n");
    }
}

void agregarEmpleados(Empleado *empleados, int *numEmpleados, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        agregarEmpleado(empleados, numEmpleados);
    }
}

void mostrarEmpleados(Empleado empleados[], int numEmpleados)
{
    for (int i = 0; i < numEmpleados; i++)
    {
        printf("%d - %s - %.2f\n", empleados[i].legajo, empleados[i].nombre, empleados[i].sueldo);
    }
}

void buscarEmpleadoPorLegajo(Empleado empleados[], int numEmpleados, int legajo)
{
    for (int i = 0; i < numEmpleados; i++)
    {
        if (empleados[i].legajo == legajo)
        {
            printf("Empleado encontrado: %d - %s - %.2f\n", empleados[i].legajo, empleados[i].nombre, empleados[i].sueldo);
            return;
        }
    }
    printf("Empleado con legajo %d no encontrado.\n", legajo);
}

void aumentarSueldosEmpleados(Empleado empleados[], int numEmpleados, float porcentaje)
{
    for (int i = 0; i < numEmpleados; i++)
    {
        empleados[i].sueldo += empleados[i].sueldo * (porcentaje / 100);
    }
}