#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_CANTIDAD_LIBROS = 100;

// Definicion de la estructura Libro
typedef struct
{
    char titulo[100];
    char isbn[20];
    char autor[50];
    char editorial[50];
    int prestado; // 0: disponible, 1: prestado
} Libro;

// Prototipo de funciones
void inicializarBiblioteca(Libro biblioteca[], int *cantidadLibros);
int mostrarMenu();
void logicaMenu(int opcion, Libro biblioteca[], int *cantidadLibros);
void crearLibro(Libro biblioteca[], int *cantidadLibros);
void listarLibros(Libro biblioteca[], int cantidadLibros);
void prestarLibro(Libro biblioteca[], int cantidadLibros);
void modificarLibro(Libro biblioteca[], int cantidadLibros);
void ordenarBibliotecaPorISBN(Libro biblioteca[], int cantidadLibros); // Función para ordenar antes de buscar
int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, char isbn[]);

void clearConsole();

int main()
{
    Libro biblioteca[MAX_CANTIDAD_LIBROS];
    int cantidadLibros = 0;

    inicializarBiblioteca(biblioteca, &cantidadLibros);

    while (1)
    {
        logicaMenu(mostrarMenu(), biblioteca, &cantidadLibros);
    }

    return 0;
}

void inicializarBiblioteca(Libro biblioteca[], int *cantidadLibros)
{
    strcpy(biblioteca[0].titulo, "Don Quijote de la Mancha");
    strcpy(biblioteca[0].isbn, "1234");
    strcpy(biblioteca[0].autor, "Miguel de Cervantes");
    strcpy(biblioteca[0].editorial, "Planeta");
    biblioteca[0].prestado = 0;

    strcpy(biblioteca[1].titulo, "Cien años de soledad");
    strcpy(biblioteca[1].isbn, "2345");
    strcpy(biblioteca[1].autor, "Gabriel García Márquez");
    strcpy(biblioteca[1].editorial, "Planeta");
    biblioteca[1].prestado = 0;

    strcpy(biblioteca[2].titulo, "El principito");
    strcpy(biblioteca[2].isbn, "3456");
    strcpy(biblioteca[2].autor, "Antoine de Saint-Exupéry");
    strcpy(biblioteca[2].editorial, "Salamandra");
    biblioteca[2].prestado = 0;

    *cantidadLibros = 3;
}

void crearLibro(Libro biblioteca[], int *cantidadLibros)
{
    clearConsole();
    printf("===== CREAR LIBRO ===== \n\n");
    if (*cantidadLibros >= MAX_CANTIDAD_LIBROS)
    {
        printf("No se pueden agregar más libros. Capacidad máxima alcanzada.\n");
        return;
    }

    Libro nuevoLibro;

    printf("Ingrese el título del libro: ");
    getchar(); // Limpiar el buffer
    fgets(nuevoLibro.titulo, sizeof(nuevoLibro.titulo), stdin);
    nuevoLibro.titulo[strcspn(nuevoLibro.titulo, "\n")] = 0;

    printf("Ingrese el ISBN del libro: ");
    fgets(nuevoLibro.isbn, sizeof(nuevoLibro.isbn), stdin);
    nuevoLibro.isbn[strcspn(nuevoLibro.isbn, "\n")] = 0;

    printf("Ingrese el autor del libro: ");
    fgets(nuevoLibro.autor, sizeof(nuevoLibro.autor), stdin);
    nuevoLibro.autor[strcspn(nuevoLibro.autor, "\n")] = 0;

    printf("Ingrese la editorial del libro: ");
    fgets(nuevoLibro.editorial, sizeof(nuevoLibro.editorial), stdin);
    nuevoLibro.editorial[strcspn(nuevoLibro.editorial, "\n")] = 0;

    nuevoLibro.prestado = 0; // Se establece que el libro no está prestado al crearlo

    biblioteca[*cantidadLibros] = nuevoLibro;
    (*cantidadLibros)++;

    printf("Libro creado exitosamente.\n");
}

void listarLibros(Libro biblioteca[], int cantidadLibros)
{
    for (int i = 0; i < cantidadLibros; i++)
    {
        printf("Libro %d:\n", i + 1);
        printf("Título: %s\n", biblioteca[i].titulo);
        printf("ISBN: %s\n", biblioteca[i].isbn);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Editorial: %s\n", biblioteca[i].editorial);
        printf("Estado: %s\n", biblioteca[i].prestado ? "Prestado" : "Disponible");
    }
}

int mostrarMenu()
{
    int opcion;

    clearConsole();

    printf("===== SISTEMA DE BIBLIOTECA ===== \n\n");
    printf("\t1. Crear libro\n");
    printf("\t2. Listar todos los libros\n");
    printf("\t3. Prestar un libro\n");
    printf("\t4. Modificar un libro\n");
    printf("\t5. Buscar libro por ISBN\n");
    printf("\t6. Salir\n");
    printf("\n==================================\n\n");
    printf("Ingrese una opción: ");

    scanf("%d", &opcion);

    while (opcion < 1 || opcion > 6)
    {
        printf("\nOpción inválida. Ingrese nuevamente: ");
        scanf("%d", &opcion);
    }

    return opcion;
}

void logicaMenu(int opcion, Libro biblioteca[], int *cantidadLibros)
{
    clearConsole();
    switch (opcion)
    {
    case 1:
        crearLibro(biblioteca, cantidadLibros);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        printf("Saliendo del sistema...\n");
        break;
    default:
        printf("Error intentendible, opcion no valida\n");
        break;
    }
}

// Función para limpiar la consola
void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}