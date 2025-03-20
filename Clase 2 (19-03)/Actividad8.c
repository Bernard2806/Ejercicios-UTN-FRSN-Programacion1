#include <stdio.h>

int main(){
    double base, altura, area;

    printf("Ingrese la base del triángulo: ");
    scanf("%lf", &base);

    printf("Ingrese la altura del triángulo: ");
    scanf("%lf", &altura);

    area = (base * altura) / 2;

    printf("\n");

    printf("El área del triángulo es %.2lf", area);
}