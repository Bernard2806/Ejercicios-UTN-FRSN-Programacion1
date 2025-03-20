#include <stdio.h> // Se incluye la Libreria stdio.h (Standart Input Output Header) es una bibloteca estandar de C proporciona funciones para la entrda y salida de datos

// el Main es la Funcion Principal de un Programa en C. Sin el Main el programa no sabe por donde arrancar.

int main()
{
    // Tipo de Variables

    // int --> Numero Entero
    // float --> Numero Real (Decimal)
    // char --> Caracteres
    // Texto --> para eso se usa un Array de Caracteres (char)

    int edad;
    float altura;
    char inicial;
    char nombre[15];

    // Asignación de Variables - Leer - Capturar datos del usuario

    printf("Ingresa tu Nombre: ");
    scanf("%s", nombre); // Aqui no se usa el & por que el nombre es la referencia de la dirección de memoria

    // Toma la inicial del Nombre
    inicial = nombre[0];

    printf("Ingresa la Edad: ");
    scanf("%d", &edad); // Se utiliza para pasar la dirección de memoria de la variable

    printf("Ingresa la Altura: ");
    scanf("%f", &altura);

    // Especificadores de Formato

    // %d para enteros.
    // %f para números de punto flotante (Decimales). --> Si si le agrega un numero tipo %.2f es para colocar la cantidad de numeros para ver despues de la Coma.
    // %s para cadenas de caracteres (Texto).
    // %c para carecteres.

    printf("Hola me llamo %s, la inicial de mi nombre es %c y tengo %d años. Mido %.2f", nombre, inicial, edad, altura);

    // Generar Espacio en Blanco - Salto de Linea
    printf("\n\n");

    return 0; // Devuelve 0 si todo funciona correctamente - Finaliza una función
}