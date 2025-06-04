### 🧠 ¿Qué es un puntero?

Un **puntero** es una variable que guarda la **dirección de memoria** de otra variable.

📦 Por ejemplo:

```c
int a = 5;       // Variable normal
int *p = &a;     // "p" guarda la dirección de "a"
```

* `a` guarda el valor `5`
* `&a` es "la dirección de memoria de `a`"
* `*p` es "el valor al que apunta el puntero `p`"

---

### 🔍 ¿Cómo acceder a la variable a la que apunta el puntero?

```c
#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;

    printf("Valor de a: %d\n", a);       // 10
    printf("Direccion de a: %p\n", &a);  // algo como 0x7ffeef
    printf("Valor de p: %p\n", p);       // igual a &a
    printf("Valor al que apunta p: %d\n", *p);  // 10

    *p = 20;  // cambia el valor de a
    printf("Nuevo valor de a: %d\n", a); // 20

    return 0;
}
```

---

### 🔁 ¿Cómo pasar un array por referencia con punteros y recorrerlo con un `for`?

Cuando pasas un **array a una función**, en realidad estás pasando un **puntero al primer elemento**.

```c
#include <stdio.h>

void mostrarArray(int *arr, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Elemento %d: %d\n", i, *(arr + i)); // accede con puntero
    }
}

int main() {
    int numeros[] = {5, 10, 15, 20};
    int tam = sizeof(numeros) / sizeof(numeros[0]);

    mostrarArray(numeros, tam);  // se pasa como puntero

    return 0;
}
```

---

### ➕ BONUS: Recorrer un array con puntero directamente

```c
#include <stdio.h>

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    int *ptr = numeros; // apunta al primer elemento

    for (int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, *(ptr + i));
    }

    return 0;
}
```

---

### 🧠 Resumen

| Concepto                  | Código                  | ¿Qué hace?                |
| ------------------------- | ----------------------- | ------------------------- |
| Declarar puntero          | `int *p;`               | Crea un puntero a entero  |
| Apuntar a variable        | `p = &a;`               | Guarda dirección de `a`   |
| Acceder al valor apuntado | `*p`                    | Lee o cambia valor de `a` |
| Pasar array a función     | `func(arr, tam);`       | Se pasa como puntero      |
| Acceso con puntero        | `*(arr + i)` o `arr[i]` | Son equivalentes          |

---
