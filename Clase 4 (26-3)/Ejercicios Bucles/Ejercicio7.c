#include <stdio.h>

int main() {
    int numero, suma = 0, contador = 0;
    int mayor, menor;
    int pares = 0, impares = 0;
    float promedio;

    // Solicitar el primer número
    printf("Ingrese un numero (0 para terminar): ");
    scanf("%d", &numero);

    // Verificar si el primer número no es 0 para inicializar mayor y menor
    if (numero != 0) {
        mayor = menor = numero;
        suma = numero;
        contador = 1;
        if (numero % 2 == 0)
            pares++;
        else
            impares++;
    }

    // Bucle principal
    while (numero != 0) {
        printf("Ingrese un numero (0 para terminar): ");
        scanf("%d", &numero);
        
        if (numero != 0) {
            suma += numero;
            contador++;
            
            // Actualizar mayor y menor
            if (numero > mayor)
                mayor = numero;
            if (numero < menor)
                menor = numero;
            
            // Contar pares e impares
            if (numero % 2 == 0)
                pares++;
            else
                impares++;
        }
    }

    // Mostrar resultados solo si se ingresaron números
    if (contador > 0) {
        promedio = (float)suma / contador;
        
        printf("\nResultados:\n");
        printf("Suma total: %d\n", suma);
        printf("Promedio: %.2f\n", promedio);
        printf("Numero mayor: %d\n", mayor);
        printf("Numero menor: %d\n", menor);
        printf("Cantidad de numeros pares: %d\n", pares);
        printf("Cantidad de numeros impares: %d\n", impares);
    } else {
        printf("\nNo se ingresaron numeros para analizar.\n");
    }

    return 0;
}