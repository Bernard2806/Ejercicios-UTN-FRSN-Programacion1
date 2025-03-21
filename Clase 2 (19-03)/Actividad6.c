#include <stdio.h>

int main() {
    float baseImponible, totalFactura;
    const float IVA = 0.21;

    printf("Ingrese la base imponible (precio sin IVA): ");
    scanf("%f", &baseImponible);
    
    totalFactura = baseImponible * (1 + IVA);
    
    printf("\nBase imponible: $%.2f", baseImponible);
    printf("\nIVA (21%%): $%.2f", baseImponible * IVA);
    printf("\nTotal factura: $%.2f\n", totalFactura);
    
    return 0;
}