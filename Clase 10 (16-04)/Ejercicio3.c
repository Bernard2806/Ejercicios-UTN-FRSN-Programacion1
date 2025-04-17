#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones

void cargarArray(int arreglo[], int largo, int min, int max);
void mostrarArray(int arreglo[], int largo);
void mostrarNumerosPrimosArray(int arreglo[], int largo);

int esPrimo(int numero);
int esMultiplo(int numero, int multiplo);

int contarMultiplos(int arreglo[], int largo, int numero);

float promedioNoPrimosNiMultiplosDe5(int arreglo[], int largo);

int main()
{
    int numeros[10];

    cargarArray(numeros, sizeof(numeros) / sizeof(numeros[0]), 1, 1000);

    printf("Los numeros son: ");
    mostrarArray(numeros, sizeof(numeros) / sizeof(numeros[0]));

    printf("\nLos numeros primos son: ");
    mostrarNumerosPrimosArray(numeros, sizeof(numeros) / sizeof(numeros[0]));

    printf("\nLa cantidad de multiplos de 5 es: %d\n", contarMultiplos(numeros, sizeof(numeros) / sizeof(numeros[0]), 5));

    return 0;
}

// Funciones - Tipo Void

// La función cargarArray recibe un arreglo, su largo y un rango (min y max).
// Pide al usuario cargar numeros para el arreglo entre min y max.
void cargarArray(int arreglo[], int largo, int min, int max)
{
    for (int i = 0; i < largo; i++)
    {
        do
        {
            printf("Ingrese el valor [%d] entre %d y %d: ", i + 1, min, max);
            scanf("%d", &arreglo[i]);
        } while (arreglo[i] < min - 1 || arreglo[i] > max + 1);
    }
}

// La función mostrarArray recibe un arreglo y su largo.
// Muestra todos los números del arreglo en la consola.
void mostrarArray(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("%d, ", arreglo[i]);
    }
}

// La función mostrarNumerosPrimosArray recibe un arreglo y su largo.
// Muestra todos los números primos del arreglo en la consola.
// Utiliza la función esPrimo para determinar si un número es primo.
// La función esPrimo devuelve 1 si el número es primo, 0 si no lo es.
// La función mostrarNumerosPrimosArray recorre el arreglo y llama a esPrimo para cada número.
// Si es primo, lo muestra en la consola.
void mostrarNumerosPrimosArray(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        if (esPrimo(arreglo[i]))
        {
            printf("%d, ", arreglo[i]);
        }
    }
}

// Funciones con Retorno - Tipo Int (Boolean)

// La función esPrimo recibe un número y devuelve 1 si es primo, 0 si no lo es.
int esPrimo(int numero)
{
    // Si el número es menor que 2, no es primo.
    if (numero < 2)
        return 0;

    // Arrancamos a probar desde el 2 hasta la mitad del número.
    // Porque ningún número se puede dividir por algo más grande que su mitad (excepto él mismo).
    for (int i = 2; i <= numero / 2; i++)
    {
        // Si el número es divisible por i, no es primo.
        // Por ejemplo, 6 es divisible por 2 y 3.
        // Entonces, 6 no es primo.
        if (numero % i == 0)
            return 0;
    }

    // Si pasamos todo el for sin encontrar divisores, el número es primo.
    return 1;
}

// La función esMultiplo recibe un número y un múltiplo.
// Devuelve 1 si el número es múltiplo del múltiplo dado, 0 si no lo es.
int esMultiplo(int numero, int multiplo)
{
    if (numero % multiplo == 0)
        return 1;

    return 0;
}

// Funciones con Retorno - Tipo Int

// La función contarMultiplos recibe un arreglo, su largo y un número.
// Devuelve la cantidad de números en el arreglo que son múltiplos del número dado.
int contarMultiplos(int arreglo[], int largo, int numero)
{
    int contador = 0;

    for (int i = 0; i < largo; i++)
    {
        esMultiplo(arreglo[i], numero) ? contador++ : contador;

        // Si el número es múltiplo, sumamos 1 al contador.
        // Si no es múltiplo, no hacemos nada.

        // El operador ternario es una forma corta de escribir un if-else.
        // En este caso, no necesitamos hacer nada si no es múltiplo.
        // Entonces, solo dejamos el contador como está.

        // contador += esMultiplo(arreglo[i], numero) ? 1 : 0;

        // Otra forma de escribirlo sería:
        // if (esMultiplo(arreglo[i], numero))
        // {
        //     contador++;
        // }
    }

    return contador;
}

// Funciones - Tipo Float

// La función promedioNoPrimosNiMultiplosDe5 recibe un arreglo y su largo.
// Devuelve el promedio de los números que no son primos ni múltiplos de 5.
// La función suma todos los números que cumplen la condición y luego divide por el largo del arreglo.
float promedioNoPrimosNiMultiplosDe5(int arreglo[], int largo){
    int suma = 0;

    for(int i = 0; i < largo; i++){
        if(!esPrimo(arreglo[i]) && !esMultiplo(arreglo[i], 5)){
            suma += arreglo[i];
        }
    }

    return (float)suma / largo;
}