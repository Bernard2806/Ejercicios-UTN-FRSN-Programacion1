#include <stdio.h> // Se incluye la librería stdio.h (Standard Input Output Header), que es una librería estándar en C que nos proporciona funciones para trabajar con la entrada y salida de datos (leer y escribir datos).

// El 'main' es la función principal de un programa en C. Es el punto de entrada, sin ella el programa no sabe por dónde arrancar.

int main()
{
    // Tipos de Variables:
    // int --> Número entero, para almacenar números sin decimales.
    // float --> Número de punto flotante (decimal), para almacenar números con decimales.
    // char --> Caracteres individuales, para almacenar letras o símbolos.
    // Para almacenar textos, se usa un array de caracteres (char), que es como un conjunto de caracteres.

    int edad;        // Variable para almacenar la edad (número entero).
    float altura;    // Variable para almacenar la altura (número con decimales).
    char inicial;    // Variable para almacenar la inicial del nombre (carácter).
    char nombre[15]; // Variable para almacenar el nombre, en este caso tiene espacio para 15 caracteres.

    // Asignación de Variables - Leer datos del usuario
    // Vamos a capturar los datos que el usuario ingrese a través de la consola.

    printf("Ingresa tu Nombre: ");
    scanf("%s", nombre); // Aquí usamos %s para leer una cadena de caracteres (nombre).
                         // No se necesita el '&' porque 'nombre' ya es una dirección de memoria (apunta al primer carácter).

    // Tomamos la primera letra del nombre para guardarla como la inicial
    inicial = nombre[0];

    printf("Ingresa la Edad: ");
    scanf("%d", &edad); // Usamos %d para leer un número entero, y pasamos la dirección de memoria de 'edad' con el '&' para almacenar el valor.

    printf("Ingresa la Altura: ");
    scanf("%f", &altura); // Usamos %f para leer un número flotante (decimal), y pasamos la dirección de memoria de 'altura'.

    // Especificadores de formato para imprimir datos:
    // %d -> Para imprimir números enteros.
    // %f -> Para imprimir números de punto flotante (decimales). Si le agregamos un número como %.2f, limitamos la cantidad de decimales a mostrar.
    // %s -> Para imprimir cadenas de caracteres (textos).
    // %c -> Para imprimir caracteres individuales.

    printf("Hola me llamo %s, la inicial de mi nombre es %c y tengo %d años. Mido %.2f", nombre, inicial, edad, altura);

    // Para generar un salto de línea (espacio en blanco) en la consola, usamos '\n' o '\n\n' si queremos un espacio más grande.
    printf("\n\n");

    return 0; // El 'return 0;' indica que la función main terminó correctamente. Esto es estándar en C para finalizar la ejecución de la función.
}