#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Definición de la estructura fichaLibro
typedef struct
{
    char titulo[100];
    char autor[100];
    int anio;
    bool prestado;
} fichaLibro;

// Prototipos de funciones
void mostrarLibro(fichaLibro libro);
bool compararLibros(fichaLibro l1, fichaLibro l2);

int main()
{
    // Declarar e inicializar dos variables del tipo fichaLibro
    fichaLibro libro1 = {"Cien años de soledad", "Gabriel Garcia Marquez", 1967, false};
    fichaLibro libro2 = {"Cien años de soledad", "Gabriel Garcia Marquez", 1967, true};

    // Mostrar información
    printf("Libro 1:\n");
    mostrarLibro(libro1);
    printf("\nLibro 2:\n");
    mostrarLibro(libro2);

    // Comparar libros
    if (compararLibros(libro1, libro2))
    {
        printf("\nAmbos representan el mismo libro (aunque el estado de préstamo puede variar).\n");
    }
    else
    {
        printf("\nSon libros diferentes.\n");
    }

    return 0;
}

// Función para mostrar la información de un libro
void mostrarLibro(fichaLibro libro)
{
    printf("Título: %s\n", libro.titulo);
    printf("Autor: %s\n", libro.autor);
    printf("Año de edición: %d\n", libro.anio);
    printf("¿Prestado?: %s\n", libro.prestado ? "Sí" : "No");
}

// Función para comparar dos libros
bool compararLibros(fichaLibro l1, fichaLibro l2)
{
    return strcmp(l1.titulo, l2.titulo) == 0 &&
           strcmp(l1.autor, l2.autor) == 0 &&
           l1.anio == l2.anio;
}