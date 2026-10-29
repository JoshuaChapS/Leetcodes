# 450 · Delete Node in a BST

**Patrón:** borrado recursivo en un BST: la función regresa la nueva raíz del subárbol y el padre la conecta (`root->left = deleteNode(root->left, key)`).

**Señal:** modificar la estructura de un BST. Con recursión que regresa la raíz nueva, no hay que guardar al padre a mano.

**Tiempo/Espacio:** O(h) tiempo y O(h) espacio por la recursión, con h = altura del árbol.

**Intento:** la primera versión era iterativa, con un puntero `behind` al padre, y tenía dos errores. El `while (temp->val != key)` se salía justo cuando encontraba el nodo, así que la rama que borraba nunca se ejecutaba. Y con dos hijos movía el sucesor y le colgaba el subárbol derecho, pero el sucesor seguía conectado a su padre: borrar la raíz de `{5,3,6,2,4,7}` dejaba un ciclo 6 → 7 → 6. Me frustré y pedí la solución, pero no la leí: la escribí yo con dos ideas. Hacerlo recursivo, y con dos hijos no mover nodos sino intercambiar el valor con el sucesor (el más chico de la derecha) y borrar `key` del subárbol derecho, donde ya cae en el caso fácil porque el sucesor no tiene hijo izquierdo. Salió a la primera, en unos 15 minutos.

**Nota:** la versión más común copia el valor del sucesor y borra el sucesor (`deleteNode(root->right, sucesor->val)`); el intercambio que hice también funciona porque `key` es menor que todo el subárbol derecho. Este código no libera la memoria del nodo borrado; en C++ de producción habría que hacer `delete` o usar `unique_ptr`.

**Repaso:** 2026-11-01 (en frío, sin ver esto)