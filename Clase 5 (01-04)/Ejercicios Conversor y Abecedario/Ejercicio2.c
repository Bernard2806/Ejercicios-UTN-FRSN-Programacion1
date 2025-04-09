#include <stdio.h>
#include <ctype.h> // Para convertir letras a mayúsculas con toupper

// Función que valida si un caracter es una letra mayúscula del abecedario
int esLetraValida(char letra) {
    return letra >= 'A' && letra <= 'Z';
}

// Función para obtener la siguiente letra en el abecedario (ciclando de Z a A)
char obtenerSiguienteLetra(char letraActual) {
    if (letraActual == 'Z') {
        return 'A'; // Volvemos a empezar desde A
    }
    return letraActual + 1;
}

int main() {
    int cantidadLetras;
    char letraInicial, letraEsperada, letraIngresada;

    printf("===== SECUENCIA DEL ABECEDARIO =====\n\n");

    // Pedimos la cantidad de letras
    printf("Ingrese la cantidad de letras a ingresar: ");
    scanf("%d", &cantidadLetras);

    if (cantidadLetras <= 0) {
        printf("La cantidad tiene que ser mayor a cero. Dale, no seas malo.\n");
        return 1;
    }

    // Pedimos la letra inicial
    printf("Ingrese la primera letra: ");
    scanf(" %c", &letraInicial); // Espacio antes de %c para evitar problemas con buffer

    // Convertimos a mayúscula por si puso minúscula
    letraInicial = toupper(letraInicial);

    // Validamos la letra inicial
    if (!esLetraValida(letraInicial)) {
        printf("La letra ingresada no es válida. Tiene que ser de la A a la Z.\n");
        return 1;
    }

    printf("\n- Eligió comenzar por la '%c' e ingresar %d letras\n", letraInicial, cantidadLetras);

    letraEsperada = obtenerSiguienteLetra(letraInicial); // Calculamos la próxima letra esperada

    for (int i = 1; i < cantidadLetras; i++) {
        while (1) {
            printf("- Siguiente letra: ");
            scanf(" %c", &letraIngresada);
            letraIngresada = toupper(letraIngresada);

            if (!esLetraValida(letraIngresada)) {
                printf("Eso no es una letra válida del abecedario. Probá de nuevo.\n");
                continue;
            }

            if (letraIngresada == letraEsperada) {
                break; // ¡Bien ahí! Pasamos a la siguiente
            } else {
                printf("Esa no es la letra correcta. Te toca poner la '%c'. Intentá otra vez.\n", letraEsperada);
            }
        }

        letraEsperada = obtenerSiguienteLetra(letraEsperada); // Actualizamos la siguiente letra esperada
    }

    printf("- FIN DEL PROGRAMA\n");
    return 0;
}