#include <stdio.h>
#include <string.h>

// Definición de Constante de PI
#define PI 3.1416

// Definición de la estructura Círculo
typedef struct
{
    float radio;
} Circulo;

// Prototipos de funciones
void cargarCirculo(Circulo *c);
void mostrarCirculo(Circulo c);
float calcularArea(Circulo c);
float calcularPerimetro(Circulo c);

int main()
{
    Circulo c1;
    Circulo c2;

    printf("Cargar datos del primer círculo:\n");
    cargarCirculo(&c1);

    printf("\nCargar datos del segundo círculo:\n");
    cargarCirculo(&c2);

    printf("\nDatos del primer círculo:\n");
    mostrarCirculo(c1);
    printf("Área: %.2f\n", calcularArea(c1));
    printf("Perímetro: %.2f\n", calcularPerimetro(c1));

    printf("\nDatos del segundo círculo:\n");
    mostrarCirculo(c2);
    printf("Área: %.2f\n", calcularArea(c2));
    printf("Perímetro: %.2f\n", calcularPerimetro(c2));

    return 0;
}

// Función para cargar un círculo
void cargarCirculo(Circulo *c)
{
    // Validar radio
    do
    {
        printf("Ingrese el radio (mayor que 0): ");
        if (scanf("%f", &c->radio) != 1 || c->radio <= 0)
        {
            printf("Entrada inválida. Intente de nuevo.\n");
            while (getchar() != '\n')
                ; // limpiar buffer
        }
        else
            break;
    } while (1);
}

// Función para mostrar los datos de un círculo
void mostrarCirculo(Circulo c)
{
    printf("Radio: %.2f\n", c.radio);
}

// Función para calcular el área de un círculo
float calcularArea(Circulo c)
{
    return PI * c.radio * c.radio; // M_PI es una constante definida en math.h
}

// Función para calcular el perímetro de un círculo
float calcularPerimetro(Circulo c)
{
    return 2 * PI * c.radio; // M_PI es una constante definida en math.h
}