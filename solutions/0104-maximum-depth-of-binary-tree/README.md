# 104. Maximum Depth of Binary Tree

**Patrón:** recursión sobre árbol — la profundidad de un nodo es 1 más la mayor
profundidad de sus hijos. Caso base: nodo `None` → 0.

**Señal:** la estructura es un árbol (`TreeNode` con `left`/`right`), no una lista ni
un grafo con ciclos — no hace falta un `visited`. "Profundidad" o "altura" sobre un
árbol es casi siempre postorden implícito: primero resuelves los hijos, luego combinas.

**Tiempo/Espacio:** O(n) tiempo — cada nodo se visita una sola vez. O(h) espacio
auxiliar por la pila de recursión, donde h es la altura: O(log n) si el árbol está
balanceado, O(n) en el peor caso (árbol degenerado, una sola rama).

**Intento:** el problema en sí (`max(maxDepth(left), maxDepth(right)) + 1`) salió a
la primera. El trabajo real estuvo en construir el árbol localmente para poder probar,
ya que LeetCode recibe un `TreeNode` ya armado, no la lista plana.

Primer intento de construcción: un método `append()` que caminaba el árbol buscando
el primer espacio vacío, izquierda primero. Fallaba porque (1) trataba cada `None` de
la lista como un nodo real en vez de "aquí no hay hijo", y (2) el orden de la lista de
LeetCode es por niveles (BFS), no por profundidad — llenar por izquierda no reproduce
esa estructura.

Reescrito con una cola de `(nodo_padre, lado)`. Primer bug: encolaba el valor que
sacaba de la cola en vez de la referencia al padre — reasignar esa variable no movía
el puntero `left`/`right` real (paso por valor vs por referencia, ya visto antes).
Segundo bug: dentro del método usaba `tree` (la raíz) en vez de `node` (el nodo que
se estaba procesando) — funcionaba en el primer nivel y rompía en el segundo.

Separé `build(lista) -> TreeNode` (solo mío, para pruebas locales) de
`maxDepth(root) -> int` (lo que de verdad manda LeetCode) — no hacía falta resolver
las dos cosas en una sola pasada.