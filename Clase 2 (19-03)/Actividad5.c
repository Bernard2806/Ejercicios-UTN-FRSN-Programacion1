#include <stdio.h>

int main(){
    const float precioDolarTurista = 1364.03;
    float pesos, dolares;

    printf("Ingrese la cantidad de dolares a convertir: ");
    scanf("%f", &dolares);

    pesos = dolares * precioDolarTurista;

    printf("\n");

    printf("La cantidad de pesos es: %.2f", pesos);

    return 0;
}