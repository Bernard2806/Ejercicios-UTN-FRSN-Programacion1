#include <stdio.h>

int main(){
    int temperatura;

    printf("Ingrese la temperatura: ");
    scanf("%d", &temperatura);

    if(temperatura > 30)
        printf("\nHace mucho calor");
    else if(temperatura >= 15)
        printf("\nEl clima esta templado");
    else
        printf("\nHace frío");

    return 0;
}