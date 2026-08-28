# 21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/

- **Patrón:** Merge de dos listas ordenadas con dos punteros + **nodo dummy (cabeza falsa)**. Se recorren ambas listas a la vez tomando siempre el nodo más chico; el dummy evita el caso especial del primer nodo. Es el mismo merge que en merge sort, pero sobre listas ligadas.

- **Señal:** "Combinar/mezclar dos listas YA ordenadas" → merge de dos punteros, O(n+m), sin reordenar nada. Si tuviera que construir una lista nueva desde cero, el dummy head es el truco por defecto.

- **Tiempo:** O(n+m) — cada nodo se toca una vez · **Espacio:** O(1) — no se crean nodos nuevos, solo se reenlazan los existentes.

- **Intento:** La lógica del merge salió a la primera: comparar `list1->val` vs `list2->val`, enganchar el menor a `tail->next`, avanzar ese lado y `tail`; al terminar el `while`, una de las dos listas puede quedar con nodos, y como ya está ordenada se engancha entera de un jalón. El único bug fue el final: puse `return tail->next` cuando debía ser **`return dummy.next`**. `tail` termina apuntando al ÚLTIMO nodo (lo fui avanzando), así que `tail->next` no es la cabeza; el dummy nunca se movió, así que `dummy.next` es la cabeza real de la lista fusionada. Ese es justo el punto del nodo dummy: `tail` camina, `dummy` sostiene la puerta.
  Detalle de C++: `dummy` es un objeto en el stack (`ListNode dummy(0)`, sintaxis de constructor, no `new`), por eso es `dummy.next` con punto y `tail = &dummy` con `&`.

- **Repaso:** 2026-08-30