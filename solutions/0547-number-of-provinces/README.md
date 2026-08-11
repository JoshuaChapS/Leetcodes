# 547. number-of-provinces
https://leetcode.com/problems/number-of-provinces/

- **Patrón:** DFS sobre matriz de adyacencia, contando cuántas veces arranco el recorrido
- **Señal:** "cuántos grupos / componentes conexas" → recorrer desde cada nodo no visitado y contar arranques. Clave: aquí el nodo es el **índice**, no la celda; `isConnected[i][j]` es una arista. Misma pregunta que 200 con representación distinta.
- **Tiempo:** O(n²) — obligado por la matriz de adyacencia, hay que leerla completa aunque el grafo sea disperso; con lista de adyacencia sería O(V+E) · **Espacio:** O(n)
- **Intento:** salió a la primera, sin bugs. Usé un conjunto `nonVisited` que se vacía en vez de un `visited` que crece: el bucle externo queda `while nonVisited` y el `pop()` da el siguiente arranque gratis.