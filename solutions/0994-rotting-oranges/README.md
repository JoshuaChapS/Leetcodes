# 994. rotting-oranges
https://leetcode.com/problems/rotting-oranges/

- **Patrón:** BFS multi-fuente por capas sobre matriz; cada capa es un minuto
- **Señal:** **"mínimo número de minutos/pasos"** sin pesos → BFS obligatorio, DFS no sirve porque llega a cada celda por el camino en el que se metió primero, no por el más corto. Y "todas se pudren al mismo tiempo" → multi-fuente: todas las podridas iniciales arrancan en la capa 0.
- **Tiempo:** O(m·n) · **Espacio:** O(m·n)
- **Intento:** primero lo escribí con DFS recursivo — herramienta equivocada. Además pasaba `minutes` como parámetro para acumularlo, y los `int` son inmutables: el `+=1` de adentro muere al regresar. Ya con BFS, dos bugs: (1) no marcaba `grid[x][y]=2` al meter la celda a la frontera, así que las capas se re-descubrían entre sí y el bucle era infinito; (2) contaba un minuto de más porque la última vuelta procesaba una capa que no pudría nada. Se resuelve metiendo `oranges>0` a la condición del `while`.
- **Casos borde:** frescas inalcanzables → `-1`, pero se sabe **al final**, no al inicio. Cero frescas desde el arranque → `0`, no `-1`.