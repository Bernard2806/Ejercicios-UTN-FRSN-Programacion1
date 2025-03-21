#include <stdio.h>

int main(){
    const float iva = 0.21;
    char nombreProducto[50];
    float valorProducto, totalConIVA;

    printf("Ingrese el Nombre del Producto: ");
    scanf("%s", nombreProducto);

    printf("Ingrese el Precio del Producto: ");
    scanf("%f", &valorProducto);

    totalConIVA = valorProducto + (valorProducto * iva);

    printf("\n");
    printf("Producto: %s\n", nombreProducto);
    printf("Precio sin IVA: %.2f\n", valorProducto);
    printf("Precio con IVA (21%): %.2f\n", totalConIVA);

    return 0;
}