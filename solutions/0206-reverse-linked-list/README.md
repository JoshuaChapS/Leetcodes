# 206. Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/

- **Patrón:** Reacomodo de punteros nodo por nodo. Recorres la lista y volteas cada `next` para que apunte hacia atrás en vez de hacia adelante. Antes de sobrescribir `current->next`, hay que **guardar el siguiente** o pierdes el resto de la lista.

- **Señal:** "Invertir/reordenar una lista ligada" → tres punteros (prev, current, next) caminando juntos. No hay que copiar nodos ni valores, solo reapuntar. Cualquier problema de lista que rompe/reordena enlaces es esta misma mecánica.

- **Tiempo:** O(n) — cada nodo se toca una vez · **Espacio:** O(n) por la pila de recursión en esta versión; la versión iterativa con un `while` es O(1). Vale saber las dos: en entrevista a veces piden la iterativa por el espacio constante.

- **Intento:** Primer problema de lista ligada en C++, y salió a la primera — el test de si la fluidez de C++ ya generaliza a una estructura nueva, no solo a árboles. Usé recursión de cola con acumulador: `reverse(current, last)`, donde `last` es el `prev` que se va arrastrando. La clave fue la misma lección del `temp` de 226 (invertir árbol): guardo `next = current->next` **antes** de hacer `current->next = last`, porque en el momento que reapunto `current->next` pierdo el acceso al resto de la lista. Caso base `current == nullptr` → regreso `last`, que es la nueva cabeza. Maneja bien lista vacía y de un solo nodo. La versión recursiva es en el fondo la iterativa (prev/current/next) escrita como recursión: `last`=prev, el `next` guardado=temp.

- **Repaso:** 2026-08-30