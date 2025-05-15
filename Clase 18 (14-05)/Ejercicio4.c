#include <stdio.h>
#include <string.h>

// Definición de la estructura Empleado
typedef struct
{
    int id;
    char nombre[50];
    float salario;
} Empleado;

// Prototipos de funciones
void ingresarEmpleados(Empleado empleados[], int cantidad);
int encontrarIndiceSalarioMayor(Empleado empleados[], int cantidad);
void mostrarEmpleado(Empleado emp);

int main()
{
    const int CANTIDAD = 5;
    Empleado empleados[CANTIDAD];

    ingresarEmpleados(empleados, CANTIDAD);

    int indiceMayor = encontrarIndiceSalarioMayor(empleados, CANTIDAD);

    printf("\nEmpleado con el salario más alto:\n");
    mostrarEmpleado(empleados[indiceMayor]);

    return 0;
}

// Función para ingresar los datos de los empleados
void ingresarEmpleados(Empleado empleados[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("Empleado %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &empleados[i].id);

        printf("Nombre: ");
        scanf(" %[^\n]", empleados[i].nombre); // Lee cadena con espacios

        printf("Salario: ");
        scanf("%f", &empleados[i].salario);

        printf("\n");
    }
}

// Función para encontrar el índice del empleado con el salario más alto
int encontrarIndiceSalarioMayor(Empleado empleados[], int cantidad)
{
    int indiceMayor = 0;
    for (int i = 1; i < cantidad; i++)
    {
        if (empleados[i].salario > empleados[indiceMayor].salario)
        {
            indiceMayor = i;
        }
    }
    return indiceMayor;
}

// Función para mostrar la información de un empleado
void mostrarEmpleado(Empleado emp)
{
    printf("ID: %d\n", emp.id);
    printf("Nombre: %s\n", emp.nombre);
    printf("Salario: %.2f\n", emp.salario);
}