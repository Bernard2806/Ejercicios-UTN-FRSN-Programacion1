#include <stdio.h>

int main(){
    int num1, num2, num3;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("\nIngrese el segundo numero: ");
    scanf("%d", &num2);

    printf("\nIngrese el tercer numero: ");
    scanf("%d", &num3);

    if(num1 > num2 && num1 > num3)
    {
        printf("\nEl numero mayor es: %d", num1);
    }
    else if(num2 > num1 && num2 > num3)
    {
        printf("\nEl numero mayor es: %d", num2);
    }
    else if(num3 > num1 && num3 > num2)
    {
        printf("\nEl numero mayor es: %d", num3);
    }
    else
    {
        printf("\nLos tres numeros son iguales");
    }
    
    return 0;
}