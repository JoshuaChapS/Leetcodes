# 235. Lowest Common Ancestor of a Binary Search Tree
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

- **Patrón:** Recursión guiada por la propiedad del BST (izquierda < nodo < derecha). No hay que buscar en ambos subárboles como en un árbol general: la ordenación dice exactamente hacia dónde caminar.

- **Señal:** "BST" + "ancestro común" → usar la ordenación. Si fuera un árbol binario cualquiera (sin orden) sería el problema 236, más caro. La palabra "Search" en BST es la pista de que hay orden que explotar.

- **Tiempo:** O(h) — un solo camino hacia abajo, h = altura (O(log n) balanceado, O(n) degenerado) · **Espacio:** O(h) por la pila de recursión (O(1) si se hace iterativo con un while).

- **Intento:** El algoritmo salió a la primera: si p y q se separan (uno menor y otro mayor que el nodo), o uno ES el nodo, entonces el nodo es el LCA; si ambos son menores voy a la izquierda, si ambos mayores a la derecha. Lo que costó fue un **bug de copy-paste en dos versiones seguidas**:
  1. Primero dupliqué el **cuerpo** de la rama (las dos ramas retornaban `root->left`).
  2. Al arreglarlo cambié el cuerpo a `root->right` pero dejé la **condición** idéntica (`p<root` en las dos), así que la rama seguía siendo código muerto y el caso "ambos mayores" caía en `nullptr`.
  La lección: al arreglar una rama copiada hay que cambiar **la prueba Y el cuerpo**, es fácil actualizar solo uno. Es mi patrón recurrente #1. También sobraban los guards `root->left != nullptr` y el `else return nullptr`: como el problema garantiza que p y q existen, nunca camino a un null, y esos guards solo creaban una ruta equivocada.

- **Repaso:** 2026-08-30