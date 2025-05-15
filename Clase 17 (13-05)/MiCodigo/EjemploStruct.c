#include <stdio.h>
#include <string.h>

// Estructura de datos que representa una persona
typedef struct {
    char nombre[255];
    char apellido[255]; 
    int edad;
    float altura;
} Persona;

// Prototipo de funciónes

void mostrarPersona(Persona p);
void cargarPersona(Persona *p);
int compararPersonas(Persona p1, Persona p2);

int main(){
    Persona p1; // Declaración de una variable de tipo Persona
    Persona p2;

    printf("Cargar Datos de la persona 1:\n");
    cargarPersona(&p1); // Llamada a la función para cargar los datos de la persona

    printf("\nDatos de la persona 1:\n");
    mostrarPersona(p1); // Llamada a la función para mostrar los datos de la persona

    printf("\nCargar Datos de la persona 2:\n");
    cargarPersona(&p2); // Llamada a la función para cargar los datos de la persona

    printf("\nDatos de la persona 2:\n");
    mostrarPersona(p2); // Llamada a la función para mostrar los datos de la persona

    printf("\nLas personas son iguales: %s\n", compararPersonas(p1, p2) ? "si" : "no");
    return 0;
}

int compararPersonas(Persona p1, Persona p2){
    return (p1.edad == p2.edad && p1.altura == p2.altura && strcmp(p1.nombre, p2.nombre) == 0 && strcmp(p1.apellido, p2.apellido) == 0);
}

void cargarPersona(Persona *p){
    printf("\tIngrese el nombre: ");
    scanf("%s", p->nombre);
    printf("\tIngrese el apellido: ");
    scanf("%s", p->apellido);
    printf("\tIngrese la edad: ");
    scanf("%d", &p->edad);
    printf("\tIngrese la altura: ");
    scanf("%f", &p->altura);
}

void mostrarPersona(Persona p){
    printf("\tNombre: %s\n", p.nombre);
    printf("\tApellido: %s\n", p.apellido);
    printf("\tEdad: %d\n", p.edad);
    printf("\tAltura: %.2f\n", p.altura);
}