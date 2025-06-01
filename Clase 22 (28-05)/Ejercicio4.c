#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 8
#define MAX_COMPRAS 4

// Prototipos de funciones
void mostrarMenu();
void mostrarProductos(char[], float[], int);
int buscarIndiceProducto(char[], int, char);
int productoYaAgregado(char[], int, char);
void mostrarTicket(char[], float[][3], int);

int main()
{
    char letrasProductos[MAX_PRODUCTOS] = {'b', 'm', 'p', 'n', 't', 'l', 'a', 'z'};
    float precios[MAX_PRODUCTOS] = {120.50, 98.30, 75.00, 85.00, 110.00, 45.50, 60.00, 50.00};

    char productos_ticket[MAX_COMPRAS]; // letras de productos comprados
    float ticket[MAX_COMPRAS][3];       // [kilos][precio por kilo][subtotal]
    int cantidadCompras = 0;

    int opcion;
    do
    {
        mostrarMenu();
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            if (cantidadCompras >= MAX_COMPRAS)
            {
                printf("⚠️ Ya se alcanzó el límite de 4 productos.\n");
                opcion = 2;
                break;
            }

            mostrarProductos(letrasProductos, precios, MAX_PRODUCTOS);
            char letra;
            printf("Ingrese la letra del producto: ");
            scanf(" %c", &letra);

            int indice = buscarIndiceProducto(letrasProductos, MAX_PRODUCTOS, letra);
            if (indice == -1)
            {
                printf("❌ Producto inválido. Intente nuevamente.\n");
                break;
            }

            if (productoYaAgregado(productos_ticket, cantidadCompras, letra))
            {
                printf("❌ Ya compró este producto. No puede repetirlo.\n");
                break;
            }

            float kilos;
            printf("Ingrese la cantidad de kilos: ");
            scanf("%f", &kilos);

            // Agregar al ticket
            productos_ticket[cantidadCompras] = letra;
            ticket[cantidadCompras][0] = kilos;
            ticket[cantidadCompras][1] = precios[indice];
            ticket[cantidadCompras][2] = kilos * precios[indice];
            cantidadCompras++;

            printf("✅ Producto agregado con éxito.\n");
            break;

        case 2:
            mostrarTicket(productos_ticket, ticket, cantidadCompras);
            break;

        default:
            printf("❌ Opción inválida. Intente nuevamente.\n");
        }

    } while (opcion != 2);

    return 0;
}

// Muestra el menú principal
void mostrarMenu()
{
    printf("\n====== VERDULERÍA MENU ======\n");
    printf("1. Agregar producto\n");
    printf("2. Terminar compra / Salir\n");
    printf("=============================\n");
}

// Muestra la lista de productos y precios
void mostrarProductos(char letras[], float precios[], int cantidad)
{
    printf("\nProductos disponibles:\n");
    printf("Letra | Producto   | Precio por kilo ($)\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < cantidad; i++)
    {
        char *nombre;
        switch (letras[i])
        {
        case 'b':
            nombre = "Banana";
            break;
        case 'm':
            nombre = "Manzana";
            break;
        case 'p':
            nombre = "Pera";
            break;
        case 'n':
            nombre = "Naranja";
            break;
        case 't':
            nombre = "Tomate";
            break;
        case 'l':
            nombre = "Lechuga";
            break;
        case 'a':
            nombre = "Papa";
            break;
        case 'z':
            nombre = "Zanahoria";
            break;
        default:
            nombre = "Desconocido";
        }
        printf("  %c    | %-9s | $%.2f\n", letras[i], nombre, precios[i]);
    }
    printf("----------------------------------------\n");
}

// Devuelve el índice del producto si existe, o -1 si no está
int buscarIndiceProducto(char letras[], int cantidad, char letra)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (letras[i] == letra)
            return i;
    }
    return -1;
}

// Verifica si un producto ya fue comprado
int productoYaAgregado(char productos[], int cantidad, char letra)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (productos[i] == letra)
            return 1;
    }
    return 0;
}

// Muestra el ticket final de compra
void mostrarTicket(char productos[], float ticket[][3], int cantidad)
{
    if (cantidad == 0)
    {
        printf("🛒 No se realizaron compras.\n");
        return;
    }

    float total = 0;

    printf("\n========== TICKET DE COMPRA ==========\n");
    printf("Producto | Kilos  | Subtotal ($)\n");
    printf("-------------------------------\n");

    for (int i = 0; i < cantidad; i++)
    {
        printf("   %c     | %.2f  | $%.2f\n", productos[i], ticket[i][0], ticket[i][2]);
        total += ticket[i][2];
    }

    printf("-------------------------------\n");
    printf("TOTAL A PAGAR: $%.2f\n", total);
    printf("=======================================\n");
}