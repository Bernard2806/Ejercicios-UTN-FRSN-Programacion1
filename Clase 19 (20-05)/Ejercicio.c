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
void ordenarBibliotecaPorISBN(Libro biblioteca[], int cantidadLibros);
int estaBibliotecaOrdenadaPorISBN(Libro biblioteca[], int cantidadLibros);
int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, int isbn);
void buscarLibroPorISBN(Libro biblioteca[], int cantidadLibros);

int main()
{
    Libro biblioteca[MAX_CANTIDAD_LIBROS];
    int cantidadLibros = 0;

    inicializarBiblioteca(biblioteca, &cantidadLibros);

    int continuar = 1;

    while (continuar)
    {
        int opcion = mostrarMenu();
        if (opcion == 6)
        {
            continuar = 0;
        }
        else
        {
            logicaMenu(opcion, biblioteca, &cantidadLibros);
        }
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
    printf("\n===== CREAR LIBRO ===== \n\n");
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
    scanf("%d", &nuevoLibro.isbn); // Corregido: & añadido para la variable

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

void buscarLibroPorISBN(Libro biblioteca[], int cantidadLibros)
{
    printf("\n===== BUSCAR LIBRO POR ISBN ===== \n\n");
    int isbn;
    printf("Ingrese el ISBN del libro a buscar: ");
    scanf("%d", &isbn);
    getchar(); // Limpiar el buffer

    int index = buscarLibroBinario(biblioteca, cantidadLibros, isbn);

    if (index != -1)
    {
        printf("\nInformación del libro:\n");
        printf("Título: %s\n", biblioteca[index].titulo);
        printf("ISBN: %d\n", biblioteca[index].isbn);
        printf("Autor: %s\n", biblioteca[index].autor);
        printf("Editorial: %s\n", biblioteca[index].editorial);
        printf("Estado: %s\n", biblioteca[index].prestado ? "Prestado" : "Disponible");
    }
    else
    {
        printf("No se encontró un libro con el ISBN %d.\n", isbn);
    }
}

void prestarLibro(Libro biblioteca[], int cantidadLibros)
{
    printf("\n===== PRESTAR LIBRO ===== \n\n");
    int isbn;
    printf("Ingrese el ISBN del libro a prestar: ");
    scanf("%d", &isbn); // Corregido: & añadido para la variable
    getchar();          // Limpiar el buffer

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
        printf("No se encontró un libro con el ISBN %d.\n", isbn); // Corregido: formato de impresión
    }
}

void devolverLibro(Libro biblioteca[], int cantidadLibros)
{
    printf("\n===== DEVOLVER LIBRO ===== \n\n");
    int isbn;
    printf("Ingrese el ISBN del libro a devolver: ");
    scanf("%d", &isbn);
    getchar(); // Limpiar el buffer

    int index = buscarLibroBinario(biblioteca, cantidadLibros, isbn);

    if (index != -1)
    {
        if (biblioteca[index].prestado == 1)
        {
            biblioteca[index].prestado = 0;
            printf("El libro '%s' ha sido devuelto.\n", biblioteca[index].titulo);
        }
        else
        {
            printf("El libro '%s' no estaba prestado.\n", biblioteca[index].titulo);
        }
    }
    else
    {
        printf("No se encontró un libro con el ISBN %d.\n", isbn);
    }
}

int buscarLibroBinario(Libro biblioteca[], int cantidadLibros, int isbn)
{
    if (!estaBibliotecaOrdenadaPorISBN(biblioteca, cantidadLibros)) // Corregido: lógica invertida
    {
        printf("La biblioteca no está ordenada por ISBN. Ordenando...\n");
        ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
    }
    else
    {
        printf("La biblioteca ya está ordenada por ISBN.\n");
    }

    printf("Buscando el libro con ISBN %d...\n", isbn); // Corregido: formato de impresión

    int izquierda = 0;
    int derecha = cantidadLibros - 1;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (biblioteca[medio].isbn == isbn)
            return medio;

        if (biblioteca[medio].isbn < isbn)
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
            return 0; // No está ordenado
        }
    }
    return 1; // Está ordenado
}

void listarLibros(Libro biblioteca[], int cantidadLibros)
{
    if (!estaBibliotecaOrdenadaPorISBN(biblioteca, cantidadLibros))
    {
        ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
    }

    printf("\n===== LISTADO DE LIBROS ===== \n\n");
    if (cantidadLibros == 0)
    {
        printf("No hay libros en la biblioteca.\n");
        return;
    }

    for (int i = 0; i < cantidadLibros; i++)
    {
        printf("Libro %d:\n", i + 1);
        printf("Título: %s\n", biblioteca[i].titulo);
        printf("ISBN: %d\n", biblioteca[i].isbn);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Editorial: %s\n", biblioteca[i].editorial);
        printf("Estado: %s\n\n", biblioteca[i].prestado ? "Prestado" : "Disponible");
    }
}

void modificarLibro(Libro biblioteca[], int cantidadLibros)
{
    printf("\n===== MODIFICAR LIBRO ===== \n\n");
    int isbn;
    printf("Ingrese el ISBN del libro a modificar: ");
    scanf("%d", &isbn);
    getchar(); // Limpiar el buffer

    int index = buscarLibroBinario(biblioteca, cantidadLibros, isbn);

    if (index != -1)
    {
        printf("\nLibro encontrado. Datos actuales:\n");
        printf("Título: %s\n", biblioteca[index].titulo);
        printf("ISBN: %d\n", biblioteca[index].isbn);
        printf("Autor: %s\n", biblioteca[index].autor);
        printf("Editorial: %s\n", biblioteca[index].editorial);
        printf("Estado: %s\n\n", biblioteca[index].prestado ? "Prestado" : "Disponible");

        int opcionModificar;
        printf("¿Qué desea modificar?\n");
        printf("1. Título\n");
        printf("2. ISBN\n");
        printf("3. Autor\n");
        printf("4. Editorial\n");
        printf("5. Estado de préstamo\n");
        printf("6. Cancelar\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcionModificar);
        getchar(); // Limpiar el buffer

        switch (opcionModificar)
        {
        case 1:
            printf("Ingrese el nuevo título: ");
            fgets(biblioteca[index].titulo, sizeof(biblioteca[index].titulo), stdin);
            biblioteca[index].titulo[strcspn(biblioteca[index].titulo, "\n")] = 0;
            break;
        case 2:
            printf("Ingrese el nuevo ISBN: ");
            scanf("%d", &biblioteca[index].isbn);
            getchar(); // Limpiar el buffer
            // Después de cambiar el ISBN, la biblioteca podría no estar ordenada
            ordenarBibliotecaPorISBN(biblioteca, cantidadLibros);
            break;
        case 3:
            printf("Ingrese el nuevo autor: ");
            fgets(biblioteca[index].autor, sizeof(biblioteca[index].autor), stdin);
            biblioteca[index].autor[strcspn(biblioteca[index].autor, "\n")] = 0;
            break;
        case 4:
            printf("Ingrese la nueva editorial: ");
            fgets(biblioteca[index].editorial, sizeof(biblioteca[index].editorial), stdin);
            biblioteca[index].editorial[strcspn(biblioteca[index].editorial, "\n")] = 0;
            break;
        case 5:
            if (biblioteca[index].prestado == 0)
            {
                biblioteca[index].prestado = 1;
                printf("El libro ahora está marcado como prestado.\n");
            }
            else
            {
                biblioteca[index].prestado = 0;
                printf("El libro ahora está marcado como disponible.\n");
            }
            break;
        case 6:
            printf("Operación cancelada.\n");
            return;
        default:
            printf("Opción inválida.\n");
            return;
        }

        printf("Libro modificado exitosamente.\n");
    }
    else
    {
        printf("No se encontró un libro con el ISBN %d.\n", isbn);
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

    printf("\n===== SISTEMA DE BIBLIOTECA ===== \n\n");
    printf("\t1. Crear libro \n");
    printf("\t2. Listar todos los libros \n");
    printf("\t3. Prestar un libro \n");
    printf("\t4. Modificar un libro \n");
    printf("\t5. Buscar libro por ISBN \n");
    printf("\t6. Salir \n");
    printf("\n================================== \n\n");

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
        modificarLibro(biblioteca, *cantidadLibros);
        break;
    case 5:
        buscarLibroPorISBN(biblioteca, *cantidadLibros);
        break;
    case 6:
        printf("Saliendo del sistema...\n");
        exit(0);
        break;
    default:
        printf("Error inentendible, opción no válida\n");
        break;
    }
}