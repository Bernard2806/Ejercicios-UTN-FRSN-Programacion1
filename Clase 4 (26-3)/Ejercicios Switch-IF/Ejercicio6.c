#include <stdio.h>

int main(){
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("\n");
    
    if(num % 2 == 0 && num > 0)
    {
        printf("El numero es par y positivo");
    }
    else if(num % 2 != 0 && num > 0)
    {
        printf("El numero es impar y positivo");
    }
    else if(num % 2 == 0 && num < 0)
    {
        printf("El numero es par y negativo");
    }
    else if(num % 2 != 0 && num < 0)
    {
        printf("El numero es impar y negativo");
    }
    else
    {
        printf("El numero es 0");
    }

    return 0;
}