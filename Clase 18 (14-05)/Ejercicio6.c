#include <stdio.h>

// Definición de la estructura
typedef struct
{
    char titular[100];
    int numeroCuenta;
    float saldo;
} CuentaBancaria;

// Prototipos de funciones
void leerDatosCuenta(CuentaBancaria *cuenta);
float leerCantidadDeposito();
void depositar(CuentaBancaria *cuenta, float cantidad);
void mostrarCuenta(const CuentaBancaria *cuenta);

int main()
{
    CuentaBancaria cuenta;

    leerDatosCuenta(&cuenta); // Leer datos de la cuenta

    float cantidad = leerCantidadDeposito(); // Leer cuánto se quiere depositar

    depositar(&cuenta, cantidad); // Realizar el depósito

    mostrarCuenta(&cuenta); // Mostrar datos actualizados

    return 0;
}

// Función para leer los datos iniciales de la cuenta bancaria
void leerDatosCuenta(CuentaBancaria *cuenta)
{
    printf("Ingrese el nombre del titular: ");
    fgets(cuenta->titular, sizeof(cuenta->titular), stdin);

    printf("Ingrese el número de cuenta: ");
    scanf("%d", &cuenta->numeroCuenta);

    printf("Ingrese el saldo inicial: ");
    scanf("%f", &cuenta->saldo);
    getchar(); // Limpiar el buffer del salto de línea
}

// Función para leer el monto a depositar
float leerCantidadDeposito()
{
    float cantidad;
    printf("Ingrese la cantidad a depositar: ");
    scanf("%f", &cantidad);
    return cantidad;
}

// Función para realizar el depósito en la cuenta (por referencia)
void depositar(CuentaBancaria *cuenta, float cantidad)
{
    if (cantidad > 0)
    {
        cuenta->saldo += cantidad;
        printf("\nDepósito exitoso.\n");
    }
    else
    {
        printf("\nLa cantidad a depositar debe ser positiva.\n");
    }
}

// Función para mostrar la información actualizada de la cuenta
void mostrarCuenta(const CuentaBancaria *cuenta)
{
    printf("\n--- Información de la Cuenta ---\n");
    printf("Titular: %s", cuenta->titular); // fgets incluye '\n'
    printf("Número de Cuenta: %d\n", cuenta->numeroCuenta);
    printf("Saldo Actual: $%.2f\n", cuenta->saldo);
}