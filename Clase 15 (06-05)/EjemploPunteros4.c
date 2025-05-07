#include <stdio.h>

int main()
{

    char nombre[] = "Matias!";
    char *p = nombre;

    printf("ANTES DEL WHILE\n");
    printf("c | Direccion\n");

    while (*p != '\0')
    {
        printf("%c | %p \n", *p, p);
        p++;
    }

    return 0;
}