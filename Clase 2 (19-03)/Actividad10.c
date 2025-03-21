#include <stdio.h>

int main(){
    float celcius, fahrenheit;

    printf("Ingrese la cantidad de grados Celcius: ");
    scanf("%f", &celcius);

    fahrenheit = (celcius * 9/5) + 32;

    printf("\n");

    printf("La cantidad de grados Fahrenheit es %f", fahrenheit);
    
    return 0;
}