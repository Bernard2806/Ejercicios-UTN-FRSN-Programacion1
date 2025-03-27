#include <stdio.h> // Librería necesaria para usar printf y scanf

int main()
{
    int numero, suma = 0, contador = 0; // Variables para almacenar los números ingresados y estadísticas
    int mayor, menor;                   // Variables para guardar el número mayor y menor
    int pares = 0, impares = 0;         // Contadores de números pares e impares
    float promedio;                     // Variable para almacenar el promedio de los números

    // Pedimos el primer número al usuario
    printf("Ingrese un numero (0 para terminar): ");
    scanf("%d", &numero); // Leemos el número ingresado

    // Verificamos que el primer número no sea 0 para inicializar las variables mayor y menor
    if (numero != 0)
    {
        mayor = menor = numero; // Si no es 0, inicializamos mayor y menor con ese número
        suma = numero;          // La suma empieza con el primer número
        contador = 1;           // Ya tenemos un número ingresado
        if (numero % 2 == 0)    // Si el número es par
            pares++;            // Incrementamos el contador de pares
        else                    // Si el número es impar
            impares++;          // Incrementamos el contador de impares
    }

    // Bucle principal que sigue pidiendo números hasta que el usuario ingrese 0
    while (numero != 0)
    {
        printf("Ingrese un numero (0 para terminar): ");
        scanf("%d", &numero); // Leemos el siguiente número

        if (numero != 0)
        {                   // Si el número no es 0, lo procesamos
            suma += numero; // Sumamos el número a la suma total
            contador++;     // Aumentamos el contador de números ingresados

            // Actualizamos el número mayor y menor según el número ingresado
            if (numero > mayor)
                mayor = numero; // Si el número es mayor que el actual, lo actualizamos
            if (numero < menor)
                menor = numero; // Si el número es menor que el actual, lo actualizamos

            // Contamos si el número es par o impar
            if (numero % 2 == 0)
                pares++; // Si es par, incrementamos el contador de pares
            else
                impares++; // Si es impar, incrementamos el contador de impares
        }
    }

    // Verificamos si se ingresaron números (si el contador es mayor que 0)
    if (contador > 0)
    {
        promedio = (float)suma / contador; // Calculamos el promedio

        // Mostramos los resultados
        printf("\nResultados:\n");
        printf("Suma total: %d\n", suma);                     // La suma total de los números
        printf("Promedio: %.2f\n", promedio);                 // El promedio de los números
        printf("Numero mayor: %d\n", mayor);                  // El número mayor
        printf("Numero menor: %d\n", menor);                  // El número menor
        printf("Cantidad de numeros pares: %d\n", pares);     // La cantidad de números pares
        printf("Cantidad de numeros impares: %d\n", impares); // La cantidad de números impares
    }
    else
    {
        printf("\nNo se ingresaron numeros para analizar.\n"); // Mensaje si no se ingresaron números
    }

    return 0; // Fin del programa
}