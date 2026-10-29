# 230 · Kth Smallest Element in a BST

**Patrón:** recorrido inorder iterativo con un `stack`, contando los nodos y parando en el k-ésimo.

**Señal:** "el k-ésimo más chico" en un BST. El inorder (izquierda, nodo, derecha) visita un BST en orden creciente, así que solo hay que contar.

**Tiempo/Espacio:** O(h + k) tiempo y O(h) espacio, con h = altura del árbol y k el índice que busco. En un árbol balanceado h ≈ log n; en el peor caso, si el árbol es una línea, h = n.

**Intento:** lo primero que pensé fue meter todos los valores a un min-heap y sacar k veces, que funciona pero es O(n log n) y no aprovecha que es un BST. Con la pista de qué recorrido sale ordenado, me acordé del inorder. Lo hice iterativo: bajo por la izquierda metiendo nodos al stack, y cada vez que saco uno, si tiene hijo derecho, bajo por la izquierda de ese hijo. `now` empieza en 1 porque el tope ya es el más chico, así que saco k − 1 veces y el tope es la respuesta. Salió a la primera, en unos 13 minutos.

**Nota:** el ciclo de "bajar por la izquierda" está repetido dos veces; se puede sacar a una función `pushLeft`. Si el árbol cambia seguido y se pide el k-ésimo muchas veces, se guarda en cada nodo el tamaño de su subárbol izquierdo y se encuentra en O(h).

**Repaso:** 2026-11-01