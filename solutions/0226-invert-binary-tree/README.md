# 226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/

- **Patrón:** Recursión sobre árbol. En cada nodo, intercambiar el hijo izquierdo con el derecho; la recursión lo propaga a todo el árbol. Mismo esqueleto que maxDepth (104): caso base en nullptr, luego actuar sobre ambos hijos.

- **Señal:** "Invertir" / "espejo" de un árbol binario. Cualquier transformación que se aplica idéntica a cada nodo → recursión. No hay ciclos (es árbol, no grafo), así que no hace falta visitados.

- **Tiempo:** O(n) — cada nodo se visita una vez · **Espacio:** O(h) — la pila de recursión, donde h es la altura (O(log n) balanceado, O(n) en el peor caso).

- **Intento:** El algoritmo salió de inmediato porque ya lo tenía de Python — el trabajo real fue el C++, primer problema en el lenguaje nuevo. Dos errores, ambos de semántica del lenguaje, no del algoritmo:
  1. **`delete temp`** — el bug importante. `temp` guardaba el subárbol izquierdo ya invertido, que acababa de asignar a `root->right`. `delete temp` libera ese subárbol → `root->right` queda apuntando a memoria liberada (use-after-free, árbol corrupto). La lección: `delete` libera el objeto en el heap al que apunta el puntero, no la variable puntero. La variable local se limpia sola. En este problema solo se **reacomodan** nodos existentes — no se crea ni destruye ninguno, así que no va ningún `delete`.
  2. **Faltaba el `return` en la rama `else`.** Una función no-void tiene que retornar en todos los caminos; caer al final es comportamiento indefinido y `-Wall` lo marca.
  Además entendí por qué el `temp` es obligatorio: la línea 2 (`root->left = invertTree(root->right)`) sobrescribe `root->left`, así que hay que guardar el valor viejo antes. Un puntero es solo una dirección (un número); `temp = root->left` copia ese número, y reasignar `root->left` después no toca la copia en `temp`. Es el mismo motivo por el que no puedes intercambiar dos variables con `a = b; b = a;`.

- **Repaso:** 2026-08-27