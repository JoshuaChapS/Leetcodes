# 200. number-of-islands
https://leetcode.com/problems/number-of-islands/

- **Patrón:** DFS flood fill sobre matriz (grafo implícito), hundiendo la isla a `"0"` para usar la propia matriz como visitados
- **Señal:** matriz de `0`/`1` donde importan las celdas **conectadas** entre sí → grafo implícito, cada celda es nodo y sus vecinos son las 4 adyacentes; contar componentes conexas = contar cuántas veces arranco el recorrido
- **Tiempo:** O(m·n) — el doble `for` toca cada celda una vez y el flood fill acumulado también, porque cada celda se hunde una sola vez · **Espacio:** O(m·n) en el peor caso por la pila de recursión
- **Intento:** dos bugs. (1) Comparé contra `1` en vez de `"1"`: la matriz es de caracteres y Python responde `False` en silencio en vez de marcar error. (2) La cuarta rama quedó con la guardia de la segunda (`i-1>=0` en vez de `j-1>=0`) por copy-paste — y como en Python el índice `-1` cuenta desde el final, no truena: se teletransporta al otro extremo de la matriz y fusiona islas separadas. Respuesta incorrecta en silencio. La versión con `for di, dj in DIRS` escribe la guardia una sola vez y hace imposible ese error.
- **Pendiente:** el DFS recursivo revienta con `RecursionError` en una matriz de 300×300 llena de tierra (90,000 niveles contra el límite de 1,000 de Python). La versión iterativa con pila explícita lo evita.