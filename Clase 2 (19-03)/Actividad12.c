#include <stdio.h> 
 
int main() { 
 int x; 
 
 // Pedir un número al usuario 
 printf("Ingrese un número entero: "); 
 scanf("%d", &x); 
 
 // Mostrar el valor original 
 printf("\nValor original de x: %d\n", x); 
 
 // Post-incremento (muestra el valor antes de sumar) 
 printf("x++  (Post-incremento): %d  -> Ahora x vale: %d\n", x++, x); 
 
 // Pre-incremento (suma antes de mostrar) 
 printf("++x  (Pre-incremento): %d  -> Ahora x vale: %d\n", ++x, x); 
 
 // Pre-decremento (resta antes de mostrar) 
 printf("--x  (Pre-decremento): %d  -> Ahora x vale: %d\n", --x, x); 
 
 // Post-decremento (muestra el valor antes de restar) 
 printf("x--  (Post-decremento): %d  -> Ahora x vale: %d\n", x--, x); 
 
 return 0; 
}