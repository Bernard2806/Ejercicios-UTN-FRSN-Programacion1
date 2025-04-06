#include <stdio.h>

// Función que recibe dos números e imprime cuál es el mayor
void imprimirMayor(int numero1, int numero2)
{
    if (numero1 > numero2)
    {
        printf("El mayor es %d\n", numero1);
    }
    else if (numero2 > numero1)
    {
        printf("El mayor es %d\n", numero2);
    }
    else
    {
        printf("Ambos números son iguales: %d\n", numero1);
    }
}

int main()
{
    int num1, num2;

    // Solicita al usuario que ingrese dos números
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    // Llama a la función para determinar e imprimir el mayor
    imprimirMayor(num1, num2);

    return 0;
}