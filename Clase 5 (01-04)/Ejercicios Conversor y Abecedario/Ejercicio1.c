#include <stdio.h>

// Definimos las monedas usando un enum
typedef enum
{
    MONEDA_INVALIDA = -1,
    DOLAR = 0,
    PESO_ARGENTINO,
    REAL,
    EURO
} Moneda;

// Función para mostrar las opciones al usuario
void mostrarOpcionesMoneda()
{
    printf("Seleccione una moneda:\n");
    printf("0 - Dólar estadounidense (USD)\n");
    printf("1 - Peso argentino (ARS)\n");
    printf("2 - Real brasileño (BRL)\n");
    printf("3 - Euro (EUR)\n");
}

// Función para convertir cualquier moneda a dólares
float convertirADolar(float cantidad, Moneda monedaOrigen)
{
    switch (monedaOrigen)
    {
    case DOLAR:
        return cantidad; // Ya está en dólares, capo
    case PESO_ARGENTINO:
        return cantidad / 1068.55;
    case REAL:
        return cantidad / 4.98;
    case EURO:
        return cantidad / 0.92;
    default:
        return -1.0f; // Algo salió mal
    }
}

// Función para convertir de dólares a la moneda destino
float convertirDesdeDolar(float cantidadUSD, Moneda monedaDestino)
{
    switch (monedaDestino)
    {
    case DOLAR:
        return cantidadUSD;
    case PESO_ARGENTINO:
        return cantidadUSD * 1068.55;
    case REAL:
        return cantidadUSD * 4.98;
    case EURO:
        return cantidadUSD * 0.92;
    default:
        return -1.0f;
    }
}

int main()
{
    Moneda monedaOrigen, monedaDestino;
    float cantidad, cantidadEnUSD, resultado;

    printf("===== CONVERSOR DE MONEDAS =====\n\n");

    // Seleccionar moneda de origen
    mostrarOpcionesMoneda();
    printf("Ingrese el número correspondiente a la moneda de origen: ");
    scanf("%d", (int *)&monedaOrigen);

    // Validamos la moneda de origen
    if (monedaOrigen < DOLAR || monedaOrigen > EURO)
    {
        printf("Moneda de origen inválida. No te zarpes, eh.\n");
        return 1;
    }

    // Seleccionar moneda de destino
    mostrarOpcionesMoneda();
    printf("Ingrese el número correspondiente a la moneda de destino: ");
    scanf("%d", (int *)&monedaDestino);

    // Validamos la moneda de destino
    if (monedaDestino < DOLAR || monedaDestino > EURO)
    {
        printf("Moneda de destino inválida. Fijate bien, mostro.\n");
        return 1;
    }

    // Si son la misma moneda, no tiene sentido convertir
    if (monedaOrigen == monedaDestino)
    {
        printf("Elegiste la misma moneda para origen y destino. No hace falta convertir nada.\n");
        return 0;
    }

    // Ingresar cantidad a convertir
    printf("Ingrese la cantidad de dinero a convertir: ");
    scanf("%f", &cantidad);

    if (cantidad <= 0)
    {
        printf("La cantidad debe ser mayor a cero. No seas laucha.\n");
        return 1;
    }

    // Convertimos primero a dólares y después a la moneda destino
    cantidadEnUSD = convertirADolar(cantidad, monedaOrigen);
    resultado = convertirDesdeDolar(cantidadEnUSD, monedaDestino);

    // Mostramos el resultado
    printf("\nResultado de la conversión: %.2f\n", resultado);

    return 0;
}