#include <stdio.h>

#define TAMANIO_MUESTRA 5

// Definición de la estructura para almacenar datos de tornillos
typedef struct
{
    float longitud;
    float diametro;
} Tornillo;

// Prototipos de funciones
void cargarMuestra(Tornillo muestra[], int tamaño);
float calcularMediaLongitud(const Tornillo muestra[], int tamaño);
float calcularMediaDiametro(const Tornillo muestra[], int tamaño);
void mostrarResultados(float mediaLong, float mediaDiam);

int main()
{
    Tornillo muestra[TAMANIO_MUESTRA];

    // Paso 1: Cargar datos
    cargarMuestra(muestra, TAMANIO_MUESTRA);

    // Paso 2: Calcular medias
    float mediaLongitud = calcularMediaLongitud(muestra, TAMANIO_MUESTRA);
    float mediaDiametro = calcularMediaDiametro(muestra, TAMANIO_MUESTRA);

    // Paso 3: Mostrar resultados
    mostrarResultados(mediaLongitud, mediaDiametro);

    return 0;
}

// Función para pedir datos al usuario
void cargarMuestra(Tornillo muestra[], int tamaño)
{
    printf("Ingrese los datos de %d tornillos:\n", tamaño);
    for (int i = 0; i < tamaño; i++)
    {
        printf("Tornillo %d:\n", i + 1);
        printf("  Longitud (mm): ");
        scanf("%f", &muestra[i].longitud);

        printf("  Diametro (mm): ");
        scanf("%f", &muestra[i].diametro);
    }
}

// Función para calcular media de longitudes
float calcularMediaLongitud(const Tornillo muestra[], int tamaño)
{
    float suma = 0.0;
    for (int i = 0; i < tamaño; i++)
    {
        suma += muestra[i].longitud;
    }
    return suma / tamaño;
}

// Función para calcular media de diámetros
float calcularMediaDiametro(const Tornillo muestra[], int tamaño)
{
    float suma = 0.0;
    for (int i = 0; i < tamaño; i++)
    {
        suma += muestra[i].diametro;
    }
    return suma / tamaño;
}

// Función para mostrar los resultados por pantalla
void mostrarResultados(float mediaLong, float mediaDiam)
{
    printf("\n--- Estadísticas de la muestra ---\n");
    printf("Media de longitudes: %.2f mm\n", mediaLong);
    printf("Media de diámetros: %.2f mm\n", mediaDiam);
}