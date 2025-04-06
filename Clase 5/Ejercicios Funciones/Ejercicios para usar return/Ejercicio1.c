#include <stdio.h>

// Función que calcula el cuadrado de un número
int calcularCuadrado(int numero) {
    return numero * numero;
}

int main() {
    int numero;
    
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    
    int resultado = calcularCuadrado(numero);
    printf("El cuadrado de %d es: %d\n", numero, resultado);
    
    return 0;
}