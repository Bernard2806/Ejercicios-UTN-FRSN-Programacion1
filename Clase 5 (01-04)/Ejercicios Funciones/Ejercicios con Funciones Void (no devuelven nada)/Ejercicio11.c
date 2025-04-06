#include <stdio.h>

// Función para sumar dos números
float sumar(float num1, float num2)
{
    return num1 + num2;
}

// Función para restar dos números
float restar(float num1, float num2)
{
    return num1 - num2;
}

// Función para multiplicar dos números
float multiplicar(float num1, float num2)
{
    return num1 * num2;
}

// Función para dividir dos números (con validación de división por cero)
float dividir(float num1, float num2)
{
    if (num2 == 0)
    {
        printf("¡Error! No se puede dividir por cero.\n");
        return 0;
    }
    return num1 / num2;
}

int main()
{
    int opcion;
    float numero1, numero2, resultado;

    do
    {
        // Menú de opciones
        printf("\n--- Calculadora ---\n");
        printf("1. Sumar dos números\n");
        printf("2. Restar dos números\n");
        printf("3. Multiplicar dos números\n");
        printf("4. Dividir dos números\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        // Si la opción es entre 1 y 4, se piden los números
        if (opcion >= 1 && opcion <= 4)
        {
            printf("Ingrese el primer número: ");
            scanf("%f", &numero1);
            printf("Ingrese el segundo número: ");
            scanf("%f", &numero2);
        }

        // Evaluamos la opción seleccionada
        switch (opcion)
        {
        case 1:
            resultado = sumar(numero1, numero2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 2:
            resultado = restar(numero1, numero2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 3:
            resultado = multiplicar(numero1, numero2);
            printf("Resultado: %.2f\n", resultado);
            break;
        case 4:
            resultado = dividir(numero1, numero2);
            if (numero2 != 0)
            {
                printf("Resultado: %.2f\n", resultado);
            }
            break;
        case 5:
            printf("¡Hasta luego!\n");
            break;
        default:
            printf("Opción inválida. Intente nuevamente.\n");
            break;
        }

    } while (opcion != 5);

    return 0;
}