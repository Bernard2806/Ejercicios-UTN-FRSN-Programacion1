#include <stdio.h>
#include <string.h>

#define CANTIDAD_EMPLEADOS 200

typedef struct
{
    int codigo;      // 4 dígitos
    char nombre[31]; // Nombre del empleado
    char categoria;  // 'A', 'B' o 'C'
    float salario;
} Empleado;

// Prototipos
void cargarEmpleados(Empleado *empleados, int n);
void procesarInforme(const Empleado *empleados, int n);

int main()
{
    Empleado empleados[CANTIDAD_EMPLEADOS];

    cargarEmpleados(empleados, CANTIDAD_EMPLEADOS);
    procesarInforme(empleados, CANTIDAD_EMPLEADOS);

    return 0;
}

// Cargar empleados
void cargarEmpleados(Empleado *empleados, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Empleado %d:\n", i + 1);

        do
        {
            printf("  Código (4 dígitos): ");
            scanf("%d", &empleados[i].codigo);
        } while (empleados[i].codigo < 1000 || empleados[i].codigo > 9999);

        printf("  Nombre: ");
        getchar(); // Limpiar buffer
        fgets(empleados[i].nombre, sizeof(empleados[i].nombre), stdin);
        empleados[i].nombre[strcspn(empleados[i].nombre, "\n")] = '\0'; // Eliminar '\n'

        do
        {
            printf("  Categoría (A, B, C): ");
            scanf(" %c", &empleados[i].categoria);
        } while (empleados[i].categoria != 'A' && empleados[i].categoria != 'B' && empleados[i].categoria != 'C');

        printf("  Salario: ");
        scanf("%f", &empleados[i].salario);

        printf("\n");
    }
}

// Procesar informe
void procesarInforme(const Empleado *empleados, int n)
{
    float totalSalarios = 0.0;
    int masDe20000 = 0;
    int menosDe5000CatC = 0;
    float sueldoMasBajo = empleados[0].salario;
    int codigoMayorSueldo = empleados[0].codigo;
    float mayorSueldo = empleados[0].salario;

    float totalCategoriaA = 0.0, totalCategoriaB = 0.0, totalCategoriaC = 0.0;

    printf("\n--- Empleados llamados 'Juan' ---\n");

    for (int i = 0; i < n; i++)
    {
        totalSalarios += empleados[i].salario;

        if (empleados[i].salario > 20000)
            masDe20000++;

        if (empleados[i].categoria == 'C' && empleados[i].salario < 5000)
            menosDe5000CatC++;

        if (empleados[i].salario > mayorSueldo)
        {
            mayorSueldo = empleados[i].salario;
            codigoMayorSueldo = empleados[i].codigo;
        }

        if (empleados[i].salario < sueldoMasBajo)
        {
            sueldoMasBajo = empleados[i].salario;
        }

        // Total por categoría
        switch (empleados[i].categoria)
        {
        case 'A':
            totalCategoriaA += empleados[i].salario;
            break;
        case 'B':
            totalCategoriaB += empleados[i].salario;
            break;
        case 'C':
            totalCategoriaC += empleados[i].salario;
            break;
        }

        // Mostrar empleados llamados Juan
        if (strcmp(empleados[i].nombre, "Juan") == 0)
        {
            printf("Código: %d | Categoría: %c | Salario: %.2f\n",
                   empleados[i].codigo, empleados[i].categoria, empleados[i].salario);
        }
    }

    float salarioPromedio = totalSalarios / n;

    printf("\n--- Informe Final ---\n");
    printf("Importe total de salarios: $%.2f\n", totalSalarios);
    printf("Empleados con salario > $20000: %d\n", masDe20000);
    printf("Empleados categoría 'C' con salario < $5000: %d\n", menosDe5000CatC);
    printf("Código del empleado que más gana: %d\n", codigoMayorSueldo);
    printf("Sueldo más bajo: $%.2f\n", sueldoMasBajo);
    printf("Total sueldos por categoría:\n");
    printf("  A: $%.2f\n", totalCategoriaA);
    printf("  B: $%.2f\n", totalCategoriaB);
    printf("  C: $%.2f\n", totalCategoriaC);
    printf("Salario promedio: $%.2f\n", salarioPromedio);
}