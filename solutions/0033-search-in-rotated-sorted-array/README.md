# 33 · Search in Rotated Sorted Array

**Patrón:** búsqueda binaria en arreglo rotado — **hallar primero la mitad ordenada**, luego
chequear el rango contra esa mitad.

**Señal:** arreglo ordenado y rotado, buscar un `target`, en O(log n). Rotado + buscar +
O(log n) → binary search, pero con el giro de que el arreglo no está del todo ordenado.

**Tiempo/Espacio:** O(log n) tiempo, O(1) espacio.

**Intento:** mi primer intento decidía la dirección comparando extremos (`nums[r] >= target`,
`nums[l] <= target`) **sin fijar cuál mitad estaba ordenada**. Falla cuando esa mitad cruza el
pivote: en `[1,2,3,0]` con target 3, el extremo `nums[r]=0` me mandó a la izquierda y el 3 estaba
a la derecha → -1 (22 casos mal en el oracle). El fix es el orden correcto: primero
`nums[m] >= nums[l]` me dice qué mitad está ordenada; **solo ahí** el chequeo de rango es válido,
porque dentro de una mitad ordenada los extremos sí son frontera. La lección: en rotado, no
compares contra un extremo hasta saber que ese lado está ordenado.

**Repaso:** 2026-09-09