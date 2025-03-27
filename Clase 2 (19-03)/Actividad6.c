#include <stdio.h> // Incluimos la librería stdio.h para poder usar las funciones printf y scanf.

int main()
{
    // Declaramos las variables necesarias
    float baseImponible, totalFactura; // baseImponible es el precio sin IVA, totalFactura es el monto final con IVA.
    const float IVA = 0.21;            // Definimos el valor del IVA como una constante del 21%.

    // Solicitamos al usuario que ingrese la base imponible (precio sin IVA)
    printf("Ingrese la base imponible (precio sin IVA): ");
    scanf("%f", &baseImponible); // Leemos el valor de la base imponible ingresado por el usuario.

    // Calculamos el total de la factura sumando el IVA
    totalFactura = baseImponible * (1 + IVA); // Multiplicamos la base imponible por 1 + IVA para obtener el total.

    // Mostramos los resultados
    printf("\nBase imponible: $%.2f", baseImponible);   // Imprimimos el precio sin IVA.
    printf("\nIVA (21%%): $%.2f", baseImponible * IVA); // Calculamos y mostramos el IVA (21% de la base imponible).
    printf("\nTotal factura: $%.2f\n", totalFactura);   // Imprimimos el precio total, con el IVA incluido.

    return 0; // El programa finaliza correctamente.
}