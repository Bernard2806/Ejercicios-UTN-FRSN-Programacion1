#include <stdio.h>
#include <string.h>

#define TAMANIO 6

// Definición del struct
struct producto
{
    int codigo;
    char descripcion[41];
    float precio;
};

// Prototipos
void cargarProductos(struct producto vec[], int tam);
void imprimirProductos(const struct producto vec[], int tam);
void mostrarProductoMayorPrecio(const struct producto vec[], int tam);

int main()
{
    struct producto productos[TAMANIO];

    // Cargar vector
    cargarProductos(productos, TAMANIO);

    // Imprimir vector
    imprimirProductos(productos, TAMANIO);

    // Mostrar producto con mayor precio
    mostrarProductoMayorPrecio(productos, TAMANIO);

    return 0;
}

// Cargar los productos
void cargarProductos(struct producto vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Producto %d:\n", i + 1);

        printf("  Código: ");
        scanf("%d", &vec[i].codigo);

        printf("  Descripción: ");
        // Limpieza del búfer para fgets si se necesita
        getchar();
        fgets(vec[i].descripcion, sizeof(vec[i].descripcion), stdin);
        // Eliminar salto de línea al final
        vec[i].descripcion[strcspn(vec[i].descripcion, "\n")] = '\0';

        printf("  Precio: ");
        scanf("%f", &vec[i].precio);

        printf("\n");
    }
}

// Imprimir los productos
void imprimirProductos(const struct producto vec[], int tam)
{
    printf("\n--- Lista de Productos ---\n");
    for (int i = 0; i < tam; i++)
    {
        printf("Producto %d:\n", i + 1);
        printf("  Código: %d\n", vec[i].codigo);
        printf("  Descripción: %s\n", vec[i].descripcion);
        printf("  Precio: %.2f\n\n", vec[i].precio);
    }
}

// Mostrar el producto con mayor precio
void mostrarProductoMayorPrecio(const struct producto vec[], int tam)
{
    int indiceMax = 0;
    for (int i = 1; i < tam; i++)
    {
        if (vec[i].precio > vec[indiceMax].precio)
        {
            indiceMax = i;
        }
    }

    printf("--- Producto con el precio más alto ---\n");
    printf("Descripción: %s\n", vec[indiceMax].descripcion);
    printf("Precio: %.2f\n", vec[indiceMax].precio);
}