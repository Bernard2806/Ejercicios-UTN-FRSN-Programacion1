## 📘 Paso de parámetros en funciones en C

En C, hay **dos formas** principales de pasar valores a una función:

---

### 📦 1. Pasar por **valor** (copia de variable)

Cuando pasas una variable **por valor**, se crea una **copia** de la variable.
Cualquier cambio que se haga en la función **no afecta** a la variable original.

#### 🧪 Ejemplo:

```c
#include <stdio.h>

void cambiarValor(int x) {
    x = 100;
}

int main() {
    int a = 5;
    cambiarValor(a);
    printf("Valor de a: %d\n", a);  // Imprime 5
    return 0;
}
```

🔍 Aunque dentro de `cambiarValor` se cambia `x` a 100, eso no afecta a `a` en `main`, porque son **copias distintas**.

---

### 🔗 2. Pasar por **referencia** (usando punteros)

Si quieres **modificar** la variable original desde la función, debes pasar un **puntero** a su dirección.

#### 🧪 Ejemplo:

```c
#include <stdio.h>

void cambiarValor(int *x) {
    *x = 100;
}

int main() {
    int a = 5;
    cambiarValor(&a);
    printf("Valor de a: %d\n", a);  // Imprime 100
    return 0;
}
```

🔍 Ahora `cambiarValor` recibe la **dirección de memoria de `a`**, y al usar `*x`, cambia el contenido real.

---

### 🧠 Resumen rápido:

| Tipo de paso      | Se usa puntero | Modifica variable original | Ejemplo       |
| ----------------- | -------------- | -------------------------- | ------------- |
| Por valor (copia) | ❌ No           | ❌ No                       | `funcion(a)`  |
| Por referencia    | ✅ Sí           | ✅ Sí                       | `funcion(&a)` |

---
