#include <stdio.h> // Biblioteca estándar para entrada y salida de datos

int main()
{
    int diaDeLaSemana; // Variable para guardar el número ingresado por el usuario

    // Pedimos al usuario que ingrese un número del 1 al 7
    printf("Ingrese un numero del 1 al 7: ");
    scanf("%d", &diaDeLaSemana);

    // Usamos un switch para determinar qué día de la semana corresponde al número ingresado
    switch (diaDeLaSemana)
    {
    case 1:
        printf("\nLunes"); // Si el usuario ingresó 1, mostramos "Lunes"
        break;             // Salimos del switch
    case 2:
        printf("\nMartes"); // Si ingresó 2, mostramos "Martes"
        break;
    case 3:
        printf("\nMiercoles"); // Si ingresó 3, mostramos "Miércoles"
        break;
    case 4:
        printf("\nJueves"); // Si ingresó 4, mostramos "Jueves"
        break;
    case 5:
        printf("\nViernes"); // Si ingresó 5, mostramos "Viernes"
        break;
    case 6:
        printf("\nSabado"); // Si ingresó 6, mostramos "Sábado"
        break;
    case 7:
        printf("\nDomingo"); // Si ingresó 7, mostramos "Domingo"
        break;
    default:
        // Si el usuario ingresó un número que no está entre 1 y 7, le avisamos que es incorrecto
        printf("\nNumero incorrecto");
        break;
    }

    return 0; // Fin del programa, devolvemos 0 para indicar que todo salió bien
}