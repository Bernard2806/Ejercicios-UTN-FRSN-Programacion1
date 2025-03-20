#include <stdio.h>

int main(){
    float celcius, fahrenheit;

    prinf("Ingrese la cantidad de grados Celcius: ");
    scanf("%f", &celcius);

    fahrenheit = (celcius * 9/5) + 32;

    prinf("\n");

    prinf("La cantidad de grados Fahrenheit es %f", fahrenheit);
    return 0;
}