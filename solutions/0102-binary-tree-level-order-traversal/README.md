# 102. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/

- **Patrón:** BFS por niveles con una cola. El truco que lo hace "por niveles" y no un BFS plano: al inicio de cada nivel, capturar `q.size()` en una variable y procesar exactamente esa cantidad de nodos. Todo lo que se encola dentro de ese bucle pertenece al siguiente nivel.

- **Señal:** "por niveles" / "level order" en un árbol → BFS con cola, no DFS. Si pidiera profundidad o inversión sería recursión; "nivel por nivel" pide cola.

- **Tiempo:** O(n) — cada nodo entra y sale de la cola una vez · **Espacio:** O(n) — la cola llega a guardar el nivel más ancho, más el vector de resultado.

- **Intento:** Primer BFS en C++. La lógica salió sola porque ya la tenía de grafos (200, 994); lo nuevo fue puro C++:
  1. **La API de `std::queue`** — `front()` y `pop()` son dos llamadas separadas porque `pop()` devuelve `void` (no como `popleft()` de Python que saca y devuelve). Se lee con `front()`, luego se quita con `pop()`.
  2. **El bug del árbol vacío** — sin guard, `push(root)` mete un `nullptr`, y en el bucle `current->val` desreferencia un puntero nulo y truena. LeetCode prueba `[]`. Fix: `if (root == nullptr) return {};` al inicio. Es mi patrón de siempre: la operación peligrosa antes de que exista el guard.
  Además afiancé punteros: copiar un puntero copia la **dirección**, no el nodo; reasignar un puntero solo toca esa caja, no a los demás punteros que apuntaban al mismo lugar.

- **Repaso:** 2026-08-29