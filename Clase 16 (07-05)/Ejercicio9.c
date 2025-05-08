#include <stdio.h>

// Función para leer datos en un arreglo
void leerArreglo(int *arr, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", arr + i); // Usando aritmética de punteros
    }
}

// Función para imprimir un arreglo
void imprimirArreglo(int *arr, int tam)
{
    printf("Arreglo: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", *(arr + i)); // Usando aritmética de punteros
    }
    printf("\n");
}

// Función para calcular estadísticas
void calcularEstadisticas(int *arr, int tam, int *suma, float *promedio, int *mayor, int *menor, int *pares, int *impares)
{
    *suma = 0;
    *pares = 0;
    *impares = 0;
    *mayor = *arr; // inicializar con el primer elemento
    *menor = *arr; // inicializar con el primer elemento

    for (int i = 0; i < tam; i++)
    {
        int valor = *(arr + i); // acceder con aritmética de punteros
        *suma += valor;

        if (valor > *mayor)
        {
            *mayor = valor;
        }
        if (valor < *menor)
        {
            *menor = valor;
        }
        if (valor % 2 == 0)
        {
            (*pares)++;
        }
        else
        {
            (*impares)++;
        }
    }

    *promedio = (float)(*suma) / tam;
}

int main()
{
    const int TAM = 15;
    int arreglo[TAM];
    int suma, mayor, menor, pares, impares;
    float promedio;

    // Leer datos
    leerArreglo(arreglo, TAM);

    // Mostrar arreglo
    imprimirArreglo(arreglo, TAM);

    // Calcular estadísticas
    calcularEstadisticas(arreglo, TAM, &suma, &promedio, &mayor, &menor, &pares, &impares);

    // Mostrar estadísticas
    printf("Suma: %d\n", suma);
    printf("Promedio: %.2f\n", promedio);
    printf("Mayor valor: %d\n", mayor);
    printf("Menor valor: %d\n", menor);
    printf("Cantidad de números pares: %d\n", pares);
    printf("Cantidad de números impares: %d\n", impares);

    return 0;
}