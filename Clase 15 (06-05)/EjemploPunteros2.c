#include <stdio.h>

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main()
{

    int river = 2;
    int boca = 1;

    printf("Antes de swap: \n");
    printf("River: %d \n", river);
    printf("Boca: %d \n", boca);

    swap(&river, &boca);

    printf("Después de swap: \n");
    printf("River: %d \n", river);
    printf("Boca: %d \n", boca);

    return 0;
}