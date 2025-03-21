#include <stdio.h>

int main(){
    const float precioDolarTurista = 1364.03;
    float pesos, dolares;

    printf("Ingrese la cantidad de pesos a convertir: ");
    scanf("%f", &pesos);

    dolares = pesos / precioDolarTurista;

    printf("\nLa cantidad de dolares es: %.2f", dolares);

    return 0;
}