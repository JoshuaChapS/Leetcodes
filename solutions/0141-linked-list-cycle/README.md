# 141. Linked List Cycle
https://leetcode.com/problems/linked-list-cycle/

- **Patrón:** Floyd (tortuga y liebre): dos punteros, `slow` avanza 1 nodo, `fast` avanza 2. Si la lista termina (`nullptr`), no hay ciclo; si hay ciclo, `fast` alcanza a `slow` dentro del bucle y se encuentran en el mismo nodo. O(1) espacio, sin set de visitados.

- **Señal:** "¿La lista ligada tiene un ciclo?" / detectar bucle → fast/slow. La versión obvia (un `unordered_set` de nodos visitados) funciona pero es O(n) espacio; el chiste del problema es el truco de O(1).

- **Tiempo:** O(n) · **Espacio:** O(1) (dos punteros). *Nota: esta versión recursiva usa O(n) de pila; la iterativa con `while (fast && fast->next)` es la de O(1) de verdad y es la que piden en entrevista.*

- **Intento:** La estructura de Floyd salió a la primera; los bugs fueron conceptuales, dos veces el mismo:
  1. **Los tres `return` invertidos.** Llegar a `nullptr` = la lista TERMINA = NO hay ciclo = `false` (yo puse `true`); que se encuentren = SÍ hay ciclo = `true` (yo puse `false`). Tenía intercambiado "encontré el final" con "encontré un ciclo".
  2. **`slow->val == fast->val` → `slow == fast`.** Identidad vs valor: un ciclo es el MISMO nodo (misma dirección), no dos nodos distintos con el mismo número. Es mi bug recurrente de `is` vs `==` de Python, ahora en C++. Comparar punteros además evita un crash: tras mover, `fast` puede quedar `nullptr`, y `fast->val` reventaría; `slow == fast` solo compara direcciones, seguro.
  Comparar punteros con `==` da identidad porque son punteros (direcciones); en Java pasa lo mismo con referencias, y `.equals()` sería el equivalente a comparar valor.

- **Repaso:** 2026-08-30