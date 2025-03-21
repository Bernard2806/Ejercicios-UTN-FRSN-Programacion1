#include <stdio.h>

int main(){
    // Declaración de variables para almacenar los datos del usuario
    char nombre[150];      // Array de caracteres para el nombre (150 caracteres máximo)
    char direccion[150];   // Array de caracteres para la dirección (150 caracteres máximo)
    char telefono[150];    // Array de caracteres para el teléfono (150 caracteres máximo)

    // Solicitud y lectura del nombre
    printf("Ingrese tu nombre: ");
    fflush(stdin);        // Limpia el buffer de entrada
    gets(nombre);         // Lee el nombre completo (permite espacios)

    // Solicitud y lectura de la dirección
    printf("Ingresa tu direccion: ");
    fflush(stdin);        // Limpia el buffer de entrada
    gets(direccion);      // Lee la dirección completa (permite espacios)

    // Solicitud y lectura del teléfono
    printf("Ingresa tu telefono: ");
    fflush(stdin);        // Limpia el buffer de entrada
    gets(telefono);       // Lee el número de teléfono (permite espacios)

    // Bucle que imprime los datos 3 veces
    for(int i = 0; i < 3; i++){
        printf("\n");     // Imprime una línea en blanco
        printf("Mi Nombre es %s, Mi Direccion es: %s, Mi Telefono es: %d", 
               nombre, direccion, telefono); // Muestra todos los datos
    }
    
    return 0; 
}