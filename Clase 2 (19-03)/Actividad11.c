#include <stdio.h> // Incluimos la librería stdio.h para poder usar las funciones printf y scanf.

int main()
{
    // Definimos el valor del IVA (21%) como constante
    const float iva = 0.21;

    // Declaramos las variables
    char nombreProducto[50];          // Array de caracteres para almacenar el nombre del producto
    float valorProducto, totalConIVA; // Variables para almacenar el precio sin IVA y el precio con IVA

    // Pedimos al usuario que ingrese el nombre del producto
    printf("Ingrese el Nombre del Producto: ");
    scanf("%s", nombreProducto); // Leemos el nombre del producto.

    // Pedimos al usuario que ingrese el precio del producto
    printf("Ingrese el Precio del Producto: ");
    scanf("%f", &valorProducto); // Leemos el precio del producto sin IVA.

    // Calculamos el precio con IVA (21%)
    totalConIVA = valorProducto + (valorProducto * iva); // Multiplicamos el precio por el 21% y sumamos al valor original.

    // Mostramos los resultados
    printf("\nProducto: %s\n", nombreProducto);           // Imprimimos el nombre del producto.
    printf("Precio sin IVA: %.2f\n", valorProducto);      // Imprimimos el precio sin IVA.
    printf("Precio con IVA (21%%): %.2f\n", totalConIVA); // Imprimimos el precio con IVA.

    return 0; // El programa finaliza correctamente.
}