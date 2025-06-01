#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ejercicio 2: Agenda de Contactos

// Definir constante para el número máximo de contactos
#define MAX_CONTACTOS 10

// Definir constante para la cantidad de contactos a cargar al iniciar
#define CANTIDAD_CONTACTOS_INICIAL 5

// Definición de la estructura Contacto
// Esta estructura representa un contacto con su nombre, teléfono, email y categoría.
typedef struct Contacto
{
    char nombre[50];
    char telefono[15];
    char email[50];
    int categoria; // 1=Familia, 2=Trabajo, 3=Amigos
} Contacto;

// Prototipos de Funciones

// Añadidas por mi
int mostrarMenuIncial();                                                   // Esta función muestra el menú inicial y devuelve la opción seleccionada por el usuario
void logicaMenuInicial(int opcion, Contacto *contactos, int numContactos); // Esta función maneja la lógica del menú inicial
void mostrarTodos(Contacto *contactos, int numContactos);                  // Esta función muestra todos los contactos en la consola

// Solicitadas en el Ejercicio
void cargarContactos(Contacto *contactos, int *numContactos);                  // Esta función carga contactos iniciales pidiendolos al usuario en el array de contactos
void mostrarContacto(Contacto contacto);                                       // Esta función muestra un contacto en la consola
void buscarPorCategoria(Contacto *contactos, int numContactos, int categoria); // Esta función busca contactos por categoría
void ordenarPorNombre(Contacto *contactos, int numContactos);                  // Esta función ordena los contactos por nombre
void contarPorCategoria(Contacto *contactos, int numContactos);                // Esta función cuenta los contactos por categoría

int main()
{
    Contacto contactos[MAX_CONTACTOS];
    int numContactos = 0;

    // Cargar contactos iniciales
    cargarContactos(contactos, &numContactos);

    // Bucle infinito para mostrar el menú inicial y manejar las opciones
    while (1)
    {
        int opcion = mostrarMenuIncial();
        logicaMenuInicial(opcion, contactos, numContactos);
        printf("\n");
    }

    return 0;
}

void logicaMenuInicial(int opcion, Contacto *contactos, int numContactos)
{
    switch (opcion)
    {
    case 1:
        printf("Mostrar todos los contactos:\n");
        mostrarTodos(contactos, numContactos);
        break;
    case 2:
        printf("Buscar por categoría\n");
        printf("Ingrese la categoría (1=Familia, 2=Trabajo, 3=Amigos): ");

        int categoria;
        scanf("%d", &categoria);

        while (categoria < 1 || categoria > 3)
        {
            printf("Categoría inválida. Por favor, ingrese una categoría entre 1 y 3: ");
            scanf("%d", &categoria);
        }

        buscarPorCategoria(contactos, numContactos, categoria);
        break;
    case 3:
        printf("Ordenar por nombre\n");
        ordenarPorNombre(contactos, numContactos);
        mostrarTodos(contactos, numContactos);
        break;
    case 4:
        printf("Contar por categoría\n");
        contarPorCategoria(contactos, numContactos);
        break;
    case 5:
        exit(0);
    default:
        printf("Opción no válida.\n");
    }

    printf("Presione Enter para continuar...");
    getchar(); // Consumir el salto de línea pendiente
}

int mostrarMenuIncial()
{
    int opcion;

    printf("----- Menú -----\n");
    printf("1. Mostrar todos\n");
    printf("2. Buscar por categoría\n");
    printf("3. Ordenar por nombre\n");
    printf("4. Contar por categoría\n");
    printf("5. Salir\n");

    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    while (opcion < 1 || opcion > 5)
    {
        printf("Opción inválida. Por favor, ingrese una opción entre 1 y 5: ");
        scanf("%d", &opcion);
    }

    return opcion;
}

void cargarContactos(Contacto *contactos, int *numContactos)
{
    // Cargar contactos iniciales
    for (int i = 0; i < CANTIDAD_CONTACTOS_INICIAL; i++)
    {
        printf("Ingrese el nombre del contacto %d: ", i + 1);
        scanf("%s", contactos[i].nombre);
        printf("Ingrese el telefono del contacto %d: ", i + 1);
        scanf("%s", contactos[i].telefono);
        printf("Ingrese el email del contacto %d: ", i + 1);
        scanf("%s", contactos[i].email);
        printf("Ingrese la categoria del contacto %d (1=Familia, 2=Trabajo, 3=Amigos): ", i + 1);
        scanf("%d", &contactos[i].categoria);
        (*numContactos)++;
    }
}

void mostrarContacto(Contacto contacto)
{
    printf("-------------------------\n");
    printf("Nombre: %s\n", contacto.nombre);
    printf("Teléfono: %s\n", contacto.telefono);
    printf("Email: %s\n", contacto.email);

    switch (contacto.categoria)
    {
    case 1:
        printf("Categoría: Familia\n");
        break;
    case 2:
        printf("Categoría: Trabajo\n");
        break;
    case 3:
        printf("Categoría: Amigos\n");
        break;
    default:
        printf("Categoría: Desconocida\n");
        break;
    }
    printf("-------------------------\n");
}

void mostrarTodos(Contacto *contactos, int numContactos)
{
    if (numContactos == 0)
    {
        printf("No hay contactos para mostrar.\n");
        return;
    }

    for (int i = 0; i < numContactos; i++)
    {
        mostrarContacto(contactos[i]);
    }
}

void buscarPorCategoria(Contacto *contactos, int numContactos, int categoria)
{
    int encontrado = 0;

    for (int i = 0; i < numContactos; i++)
    {
        if (contactos[i].categoria == categoria)
        {
            mostrarContacto(contactos[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron contactos en la categoría seleccionada.\n");
    }
}

void ordenarPorNombre(Contacto *contactos, int numContactos)
{
    // Implementación de la lógica de ordenamiento por nombre
    for (int i = 0; i < numContactos - 1; i++)
    {
        for (int j = i + 1; j < numContactos; j++)
        {
            if (strcmp(contactos[i].nombre, contactos[j].nombre) > 0)
            {
                Contacto temp = contactos[i];
                contactos[i] = contactos[j];
                contactos[j] = temp;
            }
        }
    }
    printf("Contactos ordenados por nombre.\n");
}

void contarPorCategoria(Contacto *contactos, int numContactos)
{
    int contadorFamilia = 0, contadorTrabajo = 0, contadorAmigos = 0;

    for (int i = 0; i < numContactos; i++)
    {
        switch (contactos[i].categoria)
        {
        case 1:
            contadorFamilia++;
            break;
        case 2:
            contadorTrabajo++;
            break;
        case 3:
            contadorAmigos++;
            break;
        default:
            break;
        }
    }

    printf("Total de contactos por categoría:\n");
    printf("Familia: %d\n", contadorFamilia);
    printf("Trabajo: %d\n", contadorTrabajo);
    printf("Amigos: %d\n", contadorAmigos);
}