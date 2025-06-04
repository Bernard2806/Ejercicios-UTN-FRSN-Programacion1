## 🧠 ¿Qué es una estructura en C?

Una **estructura** (`struct`) en C permite agrupar diferentes **tipos de datos** bajo un mismo nombre.
Es útil cuando querés representar un "objeto" real con varias propiedades.

Por ejemplo, un **bombero** podría tener nombre, edad y número de legajo.

---

### 🧪 Ejemplo básico de estructura

```c
#include <stdio.h>

// Definimos la estructura
struct Bombero {
    char nombre[50];
    int edad;
    int legajo;
};

int main() {
    // Creamos una variable del tipo Bombero
    struct Bombero b1;

    // Asignamos valores
    strcpy(b1.nombre, "Juan Pérez");
    b1.edad = 35;
    b1.legajo = 1023;

    // Mostramos los datos
    printf("Nombre: %s\n", b1.nombre);
    printf("Edad: %d\n", b1.edad);
    printf("Legajo: %d\n", b1.legajo);

    return 0;
}
```

---

### 🧰 Pasar estructuras a funciones

Por **valor** (copia):

```c
void mostrarBombero(struct Bombero b) {
    printf("Nombre: %s\n", b.nombre);
}
```

Por **referencia** (puntero):

```c
void cambiarEdad(struct Bombero *b, int nuevaEdad) {
    b->edad = nuevaEdad;
}
```

---
