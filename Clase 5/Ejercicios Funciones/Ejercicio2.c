#include <stdio.h>

// Función que calcula el área de un triángulo
float calcularAreaTriangulo(float base, float altura) {
    return (base * altura) / 2;
}

int main() {
    float base, altura, area;

    // Ingreso de Datos
    printf("Ingrese la base del triangulo: ");
    scanf("%f", &base);
    printf("Ingrese la altura del triangulo: ");
    scanf("%f", &altura);

    // Calcular el area del triangulo
    // Llamada a la función calcularAreaTriangulo
    area = calcularAreaTriangulo(base, altura);

    // Salida de Datos
    printf("El area del triangulo es: %.2f\n", area);

    return 0;
}