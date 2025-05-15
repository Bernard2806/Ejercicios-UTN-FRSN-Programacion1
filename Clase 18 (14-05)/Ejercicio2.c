#include <stdio.h>
#include <string.h>

// Definición de la estructura Tiempo
typedef struct
{
    int horas;
    int minutos;
    int segundos;
} Tiempo;

// Prototipos de funciones
void cargarTiempo(Tiempo *t);
void mostrarTiempo(Tiempo t);
void sumarTiempos(Tiempo t1, Tiempo t2);

int main()
{
    Tiempo t1, t2;

    // Cargar los tiempos
    printf("Cargar el primer tiempo:\n");
    cargarTiempo(&t1);
    printf("Cargar el segundo tiempo:\n");
    cargarTiempo(&t2);

    // Mostrar los tiempos
    printf("\nPrimer tiempo: ");
    mostrarTiempo(t1);
    printf("Segundo tiempo: ");
    mostrarTiempo(t2);

    // Sumar los tiempos
    printf("\nSuma de los tiempos: ");
    sumarTiempos(t1, t2);

    return 0;
}

// Función para cargar un tiempo
void cargarTiempo(Tiempo *t)
{
    // Validar horas (permitimos horas >= 0)
    do
    {
        printf("Ingrese horas (>= 0): ");
        if (scanf("%d", &t->horas) != 1 || t->horas < 0)
        {
            printf("Entrada inválida. Intente de nuevo.\n");
            while (getchar() != '\n')
                ; // limpiar buffer
        }
        else
            break;
    } while (1);

    // Validar minutos
    do
    {
        printf("Ingrese minutos (0-59): ");
        if (scanf("%d", &t->minutos) != 1 || t->minutos < 0 || t->minutos > 59)
        {
            printf("Entrada inválida. Intente de nuevo.\n");
            while (getchar() != '\n')
                ;
        }
        else
            break;
    } while (1);

    // Validar segundos
    do
    {
        printf("Ingrese segundos (0-59): ");
        if (scanf("%d", &t->segundos) != 1 || t->segundos < 0 || t->segundos > 59)
        {
            printf("Entrada inválida. Intente de nuevo.\n");
            while (getchar() != '\n')
                ;
        }
        else
            break;
    } while (1);
}

// Función para mostrar un tiempo
void mostrarTiempo(Tiempo t)
{
    printf("%02d:%02d:%02d\n", t.horas, t.minutos, t.segundos);
}

// Función para sumar dos tiempos
void sumarTiempos(Tiempo t1, Tiempo t2)
{
    Tiempo resultado;
    resultado.segundos = t1.segundos + t2.segundos;
    resultado.minutos = t1.minutos + t2.minutos + resultado.segundos / 60;
    resultado.horas = t1.horas + t2.horas + resultado.minutos / 60;

    // Ajustar segundos y minutos
    resultado.segundos %= 60;
    resultado.minutos %= 60;

    // Mostrar el resultado
    mostrarTiempo(resultado);
}