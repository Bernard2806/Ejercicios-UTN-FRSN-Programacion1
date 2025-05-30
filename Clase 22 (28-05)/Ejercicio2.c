#include <stdio.h>
#include <stdlib.h>

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
int mostrarMenuIncial(); // Esta función muestra el menú inicial y devuelve la opción seleccionada por el usuario
void logicaMenuInicial(int opcion, Contacto *contactos, int numContactos); // Esta función maneja la lógica del menú inicial

// Solicitadas en el Ejercicio
void cargarContactos(Contacto *contactos, int *numContactos); // Esta función carga contactos iniciales pidiendolos al usuario en el array de contactos
void mostrarContacto(Contacto contacto);                      // Esta función muestra un contacto en la consola
void buscarPorCategoria(Contacto *contactos, int numContactos, int categoria); // Esta función busca contactos por categoría
void ordenarPorNombre(Contacto *contactos, int numContactos); // Esta función ordena los contactos por nombre
void contarPorCategoria(Contacto *contactos, int numContactos); // Esta función cuenta los contactos por categoría

int main()
{
    Contacto contactos[MAX_CONTACTOS];
    int numContactos = 0;

    // Cargar contactos iniciales
    cargarContactos(contactos, &numContactos);

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
        printf("Mostrar todos\n");
        // Aquí iría la lógica para mostrar todos los elementos
        break;
    case 2:
        printf("Buscar por categoría\n");
        // Aquí iría la lógica para buscar por categoría
        break;
    case 3:
        printf("Ordenar por nombre\n");
        // Aquí iría la lógica para ordenar por nombre
        break;
    case 4:
        printf("Contar por categoría\n");
        // Aquí iría la lógica para contar por categoría
        break;
    case 5:
        exit(0);
    default:
        printf("Opción no válida.\n");
    }
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