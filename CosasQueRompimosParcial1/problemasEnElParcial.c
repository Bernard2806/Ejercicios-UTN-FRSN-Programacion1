
#include <stdio.h>

// Prototipos de funciones
void demostrar_arrays();
void demostrar_return();
void demostrar_continue();
void demostrar_switch();
void demostrar_promedio();

int main()
{
    printf("\n===== CONCEPTOS QUE SE CONFUNDIERON EN EL PARCIAL =====\n\n");

    printf("Enter para ver la demostración de Arrays...");
    getchar();
    demostrar_arrays();

    printf("\nEnter para ver la demostración de Return...");
    getchar();
    demostrar_return();

    printf("\nEnter para ver la demostración de Continue...");
    getchar();
    demostrar_continue();

    printf("\nEnter para ver la demostración de Switch...");
    getchar();
    demostrar_switch();

    printf("\nEnter para ver la demostración de Cálculo de Promedio...");
    getchar();
    demostrar_promedio();

    printf("\n===== FIN DEL PROGRAMA =====\n");
    return 0;
}

/**
 * CONCEPTO 1: ARRAYS E ÍNDICES
 */
void demostrar_arrays()
{
    printf("\n----- ARRAYS E ÍNDICES -----\n");

    // Un array es una colección de elementos del mismo tipo almacenados en posiciones de
    // memoria contiguas. En C, los índices comienzan en 0 (no en 1).

    // Declaración e inicialización de un array
    int numeros[5] = {10, 20, 30, 40, 50};

    // Los elementos se acceden mediante índices que comienzan en 0
    printf("El array 'numeros' tiene 5 elementos:\n");

    // Acceso a los elementos del array
    printf("numeros[0] = %d (primer elemento)\n", numeros[0]);
    printf("numeros[1] = %d (segundo elemento)\n", numeros[1]);
    printf("numeros[2] = %d (tercer elemento)\n", numeros[2]);
    printf("numeros[3] = %d (cuarto elemento)\n", numeros[3]);
    printf("numeros[4] = %d (quinto elemento)\n", numeros[4]);

    // ERROR COMÚN: Intento de acceso fuera de los límites del array
    printf("\nERROR COMÚN: Acceder a índices fuera de los límites\n");
    printf("numeros[5] provocaría un comportamiento indefinido porque el array\n");
    printf("solo tiene elementos de 0 a 4.\n");

    // Modificación de elementos
    printf("\nModificación de elementos:\n");
    printf("Antes: numeros[2] = %d\n", numeros[2]);
    numeros[2] = 99;
    printf("Después: numeros[2] = %d\n", numeros[2]);

    // Recorrido de un array con bucle for
    printf("\nRecorrido del array con bucle for:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Índice %d: %d\n", i, numeros[i]);
    }
}

/**
 * CONCEPTO 2: RETURN EN FUNCIONES
 */
// Función con tipo de retorno int
int sumar(int a, int b)
{
    // return devuelve un valor y termina la ejecución de la función
    return a + b;
}

// Función void que usa return para terminar anticipadamente
void saludar(char *nombre)
{
    // NOTA: return puede usarse en funciones void para terminar la ejecución
    // aunque no devuelva ningún valor
    if (nombre == "Matias")
    {
        printf("  No te saludo si te llamás así.\n");
        return; // Termina la función anticipadamente
    }

    printf("  ¡Hola %s!\n", nombre);
}

void demostrar_return()
{
    printf("\n----- RETURN EN FUNCIONES -----\n");

    // Return NO es una función, sino una instrucción (statement) que:
    // 1. Devuelve un valor (en funciones con tipo de retorno)
    // 2. Termina la ejecución de la función (incluso en funciones void)

    // Demostración de return en función con valor de retorno
    int resultado = sumar(5, 3);
    printf("sumar(5, 3) retorna: %d\n", resultado);

    // Demostración de return en función void
    printf("\nDemostración de return en función void:\n");
    saludar("Carlos");
    saludar("Matias"); // Se ejecutará return anticipadamente
}

/**
 * CONCEPTO 3: CONTINUE EN BUCLES
 */
void demostrar_continue()
{
    printf("\n----- CONTINUE EN BUCLES -----\n");

    // Continue salta a la siguiente iteración del bucle, omitiendo el código restante
    // en la iteración actual. A diferencia de break, no sale del bucle.

    printf("Números del 1 al 10, omitiendo los pares con continue:\n");

    for (int i = 1; i <= 10; i++)
    {
        // Si el número es par, saltamos a la siguiente iteración
        if (i % 2 == 0)
        {
            printf("[%d es par, usando continue para saltar]  ", i);
            continue; // Salta a la siguiente iteración
        }

        // Este código solo se ejecuta para números impares
        printf("%d  ", i);
    }

    printf("\n\nComparación con break (números del 1 al 10, parando en 5):\n");
    for (int i = 1; i <= 10; i++)
    {
        if (i > 5)
        {
            printf("[i > 5, usando break para salir completamente]");
            break; // Sale completamente del bucle
        }
        printf("%d  ", i);
    }
}

/**
 * CONCEPTO 4: SWITCH Y BREAK
 */
void demostrar_switch()
{
    printf("\n----- SWITCH Y BREAK -----\n");

    // Switch NO es un bucle, sino una estructura de control de selección múltiple.
    // Sin break, la ejecución "cae" (fallthrough) a los casos siguientes.

    printf("Demostración 1: Switch con break en cada case\n");
    char opcion1 = 'B';

    printf("  Para opción = '%c':\n", opcion1);
    switch (opcion1)
    {
    case 'A':
        printf("  Seleccionaste A\n");
        break; // Sale del switch

    case 'B':
        printf("  Seleccionaste B\n");
        break; // Sale del switch

    case 'C':
        printf("  Seleccionaste C\n");
        break; // Sale del switch

    default:
        printf("  Opción no reconocida\n");
    }

    printf("\nDemostración 2: Switch SIN break (fallthrough)\n");
    char opcion2 = 'B';

    printf("  Para opción = '%c':\n", opcion2);
    switch (opcion2)
    {
    case 'A':
        printf("  Seleccionaste A\n");
        // Sin break, "cae" al case B

    case 'B':
        printf("  Seleccionaste B\n");
        // Sin break, "cae" al case C

    case 'C':
        printf("  Seleccionaste C\n");
        // Sin break, "cae" al default

    default:
        printf("  También se ejecuta el código default\n");
    }

    // NOTA IMPORTANTE: Switch no es un bucle infinito sin break.
    // Es simplemente una caída (fallthrough) a los siguientes casos.
    printf("\nACLARACIÓN: Switch NO es un bucle infinito sin break.\n");
    printf("Es simplemente una 'caída' (fallthrough) a los siguientes casos.\n");
}

/**
 * CONCEPTO 5: CÁLCULO DE PROMEDIO
 */
void demostrar_promedio()
{
    printf("\n----- CÁLCULO DE PROMEDIO -----\n");

    int calificaciones[] = {85, 90, 78, 92, 88};
    int num_calificaciones = 5;

    printf("Calificaciones: ");
    for (int i = 0; i < num_calificaciones; i++)
    {
        printf("%d ", calificaciones[i]);
    }
    printf("\n");

    // FORMA INCORRECTA: Dividir dentro del bucle (error común)
    printf("\nFORMA INCORRECTA (error común):\n");
    printf("float promedio = 0;\n");
    printf("for (int i = 0; i < num_calificaciones; i++) {\n");
    printf("    promedio = promedio + calificaciones[i] / num_calificaciones; // ¡ERROR!\n");
    printf("}\n");

    float promedio_incorrecto = 0;
    for (int i = 0; i < num_calificaciones; i++)
    {
        // Este es el error: dividir dentro del bucle
        promedio_incorrecto = promedio_incorrecto + calificaciones[i] / num_calificaciones;
    }
    printf("Resultado incorrecto: %.2f\n", promedio_incorrecto);

    // FORMA CORRECTA: Sumar primero, dividir después
    printf("\nFORMA CORRECTA:\n");
    printf("int suma = 0;\n");
    printf("for (int i = 0; i < num_calificaciones; i++) {\n");
    printf("    suma += calificaciones[i];\n");
    printf("}\n");
    printf("float promedio = (float)suma / num_calificaciones;\n");

    int suma = 0;
    for (int i = 0; i < num_calificaciones; i++)
    {
        suma += calificaciones[i];
    }
    float promedio_correcto = (float)suma / num_calificaciones;
    printf("Resultado correcto: %.2f\n", promedio_correcto);

    // Explicar por qué el resultado es diferente
    printf("\nExplicación de la diferencia:\n");
    printf("- En la forma incorrecta, realizamos la división en cada iteración,\n");
    printf("  lo que lleva a resultados parciales y pérdida de precisión.\n");
    printf("- En la forma correcta, sumamos todos los valores primero y luego\n");
    printf("  realizamos una sola división al final.\n");
}
