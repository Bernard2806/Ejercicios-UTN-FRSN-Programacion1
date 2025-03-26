#include <stdio.h>

int main(){
    float Lado1, Lado2, Lado3;

    printf("Ingrese el primer lado del triangulo: ");
    scanf("%f", &Lado1);

    printf("\nIngrese el segundo lado del triangulo: ");
    scanf("%f", &Lado2);

    printf("\nIngrese el tercer lado del triangulo: ");
    scanf("%f", &Lado3);

    printf("\n");

   
    if(Lado1 + Lado2 >= Lado3 || Lado1 + Lado3 >= Lado2 || Lado2 + Lado3 >= Lado1)
    {
        if(Lado1 == Lado2 && Lado2 == Lado3)
        {
            printf("Triangulo equilatero");
        }
        else if(Lado1 == Lado2 || Lado2 == Lado3 || Lado1 == Lado3)
        {
            printf("Triangulo isosceles");
        }
        else
        {
            printf("Triangulo escaleno");
        }   
    }
    else
    {
        printf("Los lados ingresados no forman un triangulo");
    }
    

    return 0;
}