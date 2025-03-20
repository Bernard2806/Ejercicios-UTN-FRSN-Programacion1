#include <stdio.h>

int main(){
    const float iva = 0.21;
    char nombreProducto[50];
    float valorProducto, totalConIVA;

    prinf("Ingrese el Nombre del Producto");
    scanf("%s", nombreProducto);

    prinf("Ingrese el Precio del Producto");
    scanf("%f", valorProducto);

    totalConIVA = valorProducto;

    return 0;
}