#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_CANTIDAD_LIBROS = 100;

// Definicion de la estructura Libro
typedef struct
{
    char titulo[100];
    int isbn;
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
int estaBibliotecaOrdenadaPorISBN(Libro biblioteca[], int cantidadLibros);
int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, int isbn);

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
    biblioteca[0].isbn = 1234;
    strcpy(biblioteca[0].autor, "Miguel de Cervantes");
    strcpy(biblioteca[0].editorial, "Planeta");
    biblioteca[0].prestado = 0;

    strcpy(biblioteca[1].titulo, "Cien años de soledad");
    biblioteca[1].isbn = 2345;
    strcpy(biblioteca[1].autor, "Gabriel García Márquez");
    strcpy(biblioteca[1].editorial, "Planeta");
    biblioteca[1].prestado = 0;

    strcpy(biblioteca[2].titulo, "El principito");
    biblioteca[2].isbn = 3456;
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
    scanf("%s", nuevoLibro.isbn);

    getchar(); // Limpiar el buffer

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

void prestarLibro(Libro biblioteca[], int cantidadLibros)
{
    int isbn;
    printf("Ingrese el ISBN del libro a prestar: ");
    scanf("%d", isbn);
    getchar(); // Limpiar el buffer

    int index = buscarLibroBinario(biblioteca, cantidadLibros, isbn);

    if (index != -1)
    {
        if (biblioteca[index].prestado == 0)
        {
            biblioteca[index].prestado = 1;
            printf("El libro '%s' ha sido prestado.\n", biblioteca[index].titulo);
        }
        else
        {
            printf("El libro '%s' ya está prestado.\n", biblioteca[index].titulo);
        }
    }
    else
    {
        printf("No se encontró un libro con el ISBN '%s'.\n", isbn);
    }
}

int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, int isbn)
{
    if (estaBibliotecaOrdenadaPorISBN(biblioteca, cantidadLibros))
    {
        printf("La biblioteca no está ordenada por ISBN. Ordenando...\n");
        ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
    }
    else
    {
        printf("La biblioteca ya está ordenada por ISBN.\n");
    }

    printf("Buscando el libro con ISBN '%s'...\n", isbn);

    int izquierda = 0;
    int derecha = cantidadLibros - 1;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (biblioteca->isbn[medio] == isbn)
            return medio;

        if (biblioteca->isbn[medio] < isbn)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    return -1;
}

int estaBibliotecaOrdenadaPorISBN(Libro biblioteca[], int cantidadLibros)
{
    for (int i = 0; i < cantidadLibros - 1; i++)
    {
        if (biblioteca[i].isbn > biblioteca[i + 1].isbn)
        {
            return 1; // No está ordenado
        }
    }
    return 0; // Está ordenado
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

void ordenarBibliotecaPorISBN(Libro biblioteca[], int cantidadLibros)
{
    Libro temp;

    for (int i = 0; i < cantidadLibros - 1; i++)
    {
        for (int j = 0; j < cantidadLibros - i - 1; j++)
        {
            if (biblioteca[j].isbn > biblioteca[j + 1].isbn)
            {
                temp = biblioteca[j];
                biblioteca[j] = biblioteca[j + 1];
                biblioteca[j + 1] = temp;
            }
        }
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
        listarLibros(biblioteca, *cantidadLibros);
        break;
    case 3:
        prestarLibro(biblioteca, *cantidadLibros);
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