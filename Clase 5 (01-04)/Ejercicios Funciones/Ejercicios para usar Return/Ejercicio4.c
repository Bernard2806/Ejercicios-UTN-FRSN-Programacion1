#include <stdio.h>
#define PI 3.141592

// Declaración de la función
double calcularAreaCirculo(double radio);

int main() {
    double radio, area;
    
    printf("Ingrese el radio del círculo: ");
    scanf("%lf", &radio);
    
    area = calcularAreaCirculo(radio);
    printf("El área del círculo es: %.2f\n", area);
    
    return 0;
}

// Función para calcular el área del círculo
double calcularAreaCirculo(double radio) {
    return PI * radio * radio;
}