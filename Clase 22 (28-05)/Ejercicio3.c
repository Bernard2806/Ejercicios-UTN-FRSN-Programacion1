#include <stdio.h>

// Ejercicio 3: Ventas por Sucursal

// Definición de constantes
// Definimos el número de sucursales y meses como constantes

#define FILAS 3    // Sucursales
#define COLUMNAS 4 // Meses

// Prototipos de funciones
void cargarVentas(int ventas[FILAS][COLUMNAS]);
void mostrarTotalesPorSucursal(int ventas[FILAS][COLUMNAS]);
void mostrarTotalesPorMes(int ventas[FILAS][COLUMNAS]);
int sucursalMaxVentas(int ventas[FILAS][COLUMNAS]);
float promedioVentas(int ventas[FILAS][COLUMNAS]);

int main()
{
    int ventas[FILAS][COLUMNAS];

    // 1. Cargar la matriz
    cargarVentas(ventas);

    // 2. a) Totales por sucursal
    mostrarTotalesPorSucursal(ventas);

    // 2. b) Totales por mes
    mostrarTotalesPorMes(ventas);

    // 2. c) Sucursal con más ventas
    int maxSucursal = sucursalMaxVentas(ventas);
    printf("La sucursal con más ventas fue la Sucursal %d\n", maxSucursal + 1);

    // 2. d) Promedio total de ventas
    float promedio = promedioVentas(ventas);
    printf("El promedio total de ventas fue: %.2f\n", promedio);

    return 0;
}

// Función para cargar los datos
void cargarVentas(int ventas[FILAS][COLUMNAS])
{
    printf("Ingrese las ventas de cada sucursal por mes:\n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("Sucursal %d - Mes %d: ", i + 1, j + 1);
            scanf("%d", &ventas[i][j]);
        }
    }
}

// a) Mostrar totales por sucursal (suma por filas)
void mostrarTotalesPorSucursal(int ventas[FILAS][COLUMNAS])
{
    printf("\nTotal vendido por cada sucursal:\n");
    for (int i = 0; i < FILAS; i++)
    {
        int suma = 0;
        for (int j = 0; j < COLUMNAS; j++)
        {
            suma += ventas[i][j];
        }
        printf("Sucursal %d: %d\n", i + 1, suma);
    }
}

// b) Mostrar totales por mes (suma por columnas)
void mostrarTotalesPorMes(int ventas[FILAS][COLUMNAS])
{
    printf("\nTotal vendido por cada mes:\n");
    for (int j = 0; j < COLUMNAS; j++)
    {
        int suma = 0;
        for (int i = 0; i < FILAS; i++)
        {
            suma += ventas[i][j];
        }
        printf("Mes %d: %d\n", j + 1, suma);
    }
}

// c) Devolver la sucursal con más ventas (índice)
int sucursalMaxVentas(int ventas[FILAS][COLUMNAS])
{
    int maxSucursal = 0;
    int maxVentas = 0;

    for (int i = 0; i < FILAS; i++)
    {
        int suma = 0;
        for (int j = 0; j < COLUMNAS; j++)
        {
            suma += ventas[i][j];
        }
        if (suma > maxVentas || i == 0)
        {
            maxVentas = suma;
            maxSucursal = i;
        }
    }

    return maxSucursal;
}

// d) Promedio total de ventas
float promedioVentas(int ventas[FILAS][COLUMNAS])
{
    int sumaTotal = 0;
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            sumaTotal += ventas[i][j];
        }
    }
    return (float)sumaTotal / (FILAS * COLUMNAS);
}