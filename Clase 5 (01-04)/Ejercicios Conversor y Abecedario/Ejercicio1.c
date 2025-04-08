#include <stdio.h>

enum tipoMonedas
{
    DOLAR = 1,
    EURO = 2,
    PESO = 3
};

int main()
{
    // Definición de constantes
    const float TASA_DOLAR_EURO = 0.85; // Ejemplo de tasa de cambio
    const float TASA_DOLAR_PESO = 20;   // Ejemplo de tasa de cambio
    const float TASA_EURO_DOLAR = 1.18; // Ejemplo de tasa de cambio

    // Definición de variables

    float cantidad, resultado;
    int monedaOrigen, monedaDestino;

    printf("Ingrese la cantidad de dinero: ");
    scanf("%f", &cantidad);

    printf("Ingrese la moneda de origen (1: DOLAR, 2: EURO, 3: PESO): ");
    scanf("%d", &monedaOrigen);

    printf("Ingrese la moneda de destino (1: DOLAR, 2: EURO, 3: PESO): ");
    scanf("%d", &monedaDestino);

    // Conversión de monedas
    switch (monedaOrigen)
    {
    case DOLAR:
        switch (monedaDestino)
        {
        case DOLAR:
            resultado = cantidad;
            break;
        case EURO:
            resultado = cantidad * 0.85; // Ejemplo de tasa de cambio
            break;
        case PESO:
            resultado = cantidad * 20; // Ejemplo de tasa de cambio
            break;
        default:
            printf("Moneda de destino no válida.\n");
            return 1;
        }
        break;
    case EURO:
        switch (monedaDestino)
        {
        case DOLAR:
            resultado = cantidad * 1.18; // Ejemplo de tasa de cambio
            break;
        case EURO:
            resultado = cantidad;
            break;
        case PESO:
            resultado = cantidad * 23.5; // Ejemplo de tasa de cambio
            break;
        default:
            printf("Moneda de destino no válida.\n");
            return 1;
        }
        break;
    case PESO:
        switch (monedaDestino)
        {
        case DOLAR:
            resultado = cantidad * 0.05; // Ejemplo de tasa de cambio
            break;
        case EURO:
            resultado = cantidad * 0.042; // Ejemplo de tasa de cambio
            break;
        case PESO:
            resultado = cantidad;
            break;
        default:
            printf("Moneda de destino no válida.\n");
            return 1;
        }
        break;
    default:
        printf("Moneda de origen no válida.\n");
        return 1;
    }

    return 0;
}