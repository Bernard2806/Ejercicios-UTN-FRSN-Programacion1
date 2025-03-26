#include <stdio.h>
#include <stdlib.h>

int main()
{
    int trabarMenu = 1;

    do
    {
        system("cls"); // Limpia la pantalla
        int opcion, num1, num2;
        printf("=== CALCULADORA ===\n");
        printf("1. Sumar dos numeros \n");
        printf("2. Restar dos numeros \n");
        printf("3. Multiplicar dos numeros \n");
        printf("4. Dividir dos numeros \n");
        printf("5. Salir \n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 5)
        {
            printf("Gracias por usar la calculadora!\n");
            trabarMenu = 0;
        }
        else if (opcion >= 1 && opcion <= 4)
        {
            printf("Ingrese el primer numero: ");
            scanf("%d", &num1);

            printf("Ingrese el segundo numero: ");
            scanf("%d", &num2);

            switch (opcion)
            {
            case 1:
                printf("La suma de %d y %d es %d\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("La resta de %d y %d es %d\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("La multiplicacion de %d y %d es %d\n", num1, num2, num1 * num2);
                break;
            case 4:
                if (num2 != 0)
                {
                    printf("La division de %d y %d es %.2f\n", num1, num2, (float)num1 / num2);
                }
                else
                {
                    printf("Error: No se puede dividir por cero!\n");
                }
                break;
            }
            
            printf("\nPresione Enter para continuar...");
            fflush(stdin);
            getchar();
        }
        else
        {
            printf("Opcion invalida!\n");
            printf("Presione Enter para continuar...");
            fflush(stdin);
            getchar();
        }
    } while (trabarMenu == 1);

    return 0;
}