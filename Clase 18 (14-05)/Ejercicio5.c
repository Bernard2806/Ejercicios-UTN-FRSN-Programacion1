#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

// Arreglo con días por mes (sin considerar bisiestos)
int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Prototipos de funciones
Fecha leerFecha();
void mostrarFecha(Fecha f);
int convertirADias(Fecha f);
int calcularDiferencia(Fecha f1, Fecha f2);

int main()
{
    printf("Ingrese la primera fecha:\n");
    Fecha fecha1 = leerFecha();

    printf("Ingrese la segunda fecha:\n");
    Fecha fecha2 = leerFecha();

    printf("\nPrimera fecha ingresada: ");
    mostrarFecha(fecha1);

    printf("Segunda fecha ingresada: ");
    mostrarFecha(fecha2);

    int diferencia = calcularDiferencia(fecha1, fecha2);

    printf("\nLa diferencia en días es: %d\n", diferencia);

    return 0;
}

// Función para leer una fecha desde el teclado
Fecha leerFecha()
{
    Fecha f;
    printf("Día: ");
    scanf("%d", &f.dia);
    printf("Mes: ");
    scanf("%d", &f.mes);
    printf("Año: ");
    scanf("%d", &f.anio);
    return f;
}

// Función para mostrar una fecha
void mostrarFecha(Fecha f)
{
    printf("%02d/%02d/%04d\n", f.dia, f.mes, f.anio);
}

// Función para convertir una fecha a total de días
int convertirADias(Fecha f)
{
    int total = f.anio * 365 + f.dia;

    for (int i = 0; i < f.mes - 1; i++)
    {
        total += diasPorMes[i];
    }

    return total;
}

// Función para calcular la diferencia absoluta en días entre dos fechas
int calcularDiferencia(Fecha f1, Fecha f2)
{
    int dias1 = convertirADias(f1);
    int dias2 = convertirADias(f2);
    return abs(dias1 - dias2);
}