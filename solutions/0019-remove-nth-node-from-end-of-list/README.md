# 19. Remove Nth Node From End of List

**Patrón:** Dos punteros con separación fija (gap). Adelanta `right` n posiciones;
luego avanza ambos hasta que `right` llega al final y `left` queda en el PREDECESOR
del objetivo. Borrar en lista ligada = pararse en el predecesor: `pred->next = pred->next->next`.

**Señal:** "n-ésimo desde el final" + "una sola pasada" → gap de dos punteros.
Si además piden O(1) espacio, la versión iterativa (no la recursiva).

**Tiempo-Espacio:**
- Iterativa (`Solution2`): O(n) tiempo, **O(1) espacio**, una pasada. ← la de entrevista.
- Recursiva (`Solution`): O(n) tiempo, **O(n) espacio** por la pila de recursión.

**Intento:** Dos bugs, ambos de borde:
1. **Gap corto por uno.** `left` terminaba SOBRE el objetivo, no antes. Cuando el
   objetivo era el último nodo, `left` caía en el último y `left->next->next`
   desreferenciaba null → **segfault**. Arreglo: ampliar el gap (`right->next`).
2. **Borrar la cabeza.** No hay predecesor; devolvía `nullptr` y perdía la lista.
   Arreglo: `if(!right) return head->next;`.

**Repaso:**
- No mezclar `size_t` (unsigned) con `int` en comparaciones → sign-compare warning;
  un `int` negativo se envuelve a un número gigante. Usar `int i`.
- `delete trash` libera UN nodo; no sigue `trash->next`. No hace falta ponerlo en null
  antes de borrar — **salvo** que el destructor hiciera `delete next` (cascada que
  borraría el resto de la lista viva). Lo que sí importa: desconectar el nodo de la
  lista ANTES de borrarlo.
- Un nodo `dummy` (como en #21) elimina el caso especial de la cabeza.