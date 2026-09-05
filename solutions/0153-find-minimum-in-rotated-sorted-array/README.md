# 153 · Find Minimum in Rotated Sorted Array

**Patrón:** búsqueda binaria en arreglo rotado — comparar `mid` contra un extremo
(`nums[right]`) para saber en qué mitad está el mínimo.

**Señal:** arreglo ordenado que fue **rotado**, pedir el mínimo en O(log n). Ordenado +
O(log n) → binary search. Pero **no hay target**: en vez de comparar `mid` con un valor
buscado, lo comparas con un **extremo** para decidir qué lado conserva la vuelta (el pivote).

**Tiempo/Espacio:** O(log n) tiempo, O(1) espacio.

**Intento:** la lógica de ramas salió a la primera — si `nums[right] > nums[mid]`, la parte
derecha está ordenada y `mid` puede ser el mínimo → `right = mid`; si `nums[right] < nums[mid]`,
el mínimo está a la derecha → `left = mid+1`. El bug fue la condición del ciclo: usé
`while (left <= right)` con `right = mid` (que **conserva** `mid`). Cuando la ventana llega a
un elemento (`left == right`), `nums[mid] == nums[right]`, ninguna rama se cumple, nada se
mueve → **ciclo infinito** (colgaba hasta con `[5]`). Es la misma trampa del 74, en espejo:
**cuando una rama conserva `mid`, la condición tiene que ser `<` estricto, no `<=`.** Cambié
`<=` por `<` y listo.

**Repaso:** 2026-09-08