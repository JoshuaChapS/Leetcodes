# 74 · Search a 2D Matrix

**Patrón:** búsqueda binaria en dos etapas — primero la fila, luego la columna.

**Señal:** matriz con filas ordenadas y `primer_elemento[i] > último[i-1]`. Esa segunda
condición es la pista: la matriz es, en el fondo, un solo arreglo ordenado partido en filas.
Ordenado + "encuéntralo" → binary search, no escaneo.

**Tiempo/Espacio:** O(log m + log n) = O(log(m·n)) tiempo, O(1) espacio.

**Intento:** caí en las dos trampas clásicas de binary search, en orden.
1. **Bucle infinito.** Con `while(up<=down)` y punto medio que redondea hacia abajo, la rama
   `else up = row` no encoge la ventana cuando `up` y `down` quedan pegados → se cuelga. Fix:
   `up = row + 1`. Regla: con `up<=down`, las dos ramas saltan la fila probada (`row-1` / `row+1`).
2. **Fila equivocada.** Después del bucle usé `row` (la última sonda) en vez de la fila
   candidata. La buena es la que quedó con `primer_elemento ≤ target`. La saqué con
   `if (matrix[row][0] > target) row--`, y un guard `row == -1` para el target menor que todo
   (si no, `matrix[-1]` = lectura fuera de rango). Lección: `row` es dónde cayó la última
   sonda; no es la respuesta.

**Repaso:** 2026-09-07