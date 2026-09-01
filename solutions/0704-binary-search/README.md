# 704. Binary Search
https://leetcode.com/problems/binary-search 
**Patrón:** Búsqueda binaria — descartar la mitad del rango en cada paso sobre un arreglo
ordenado. O(log n).

**Señal:** arreglo **ordenado** + "encuentra el índice de X" / "en O(log n)". Ordenado +
búsqueda = binaria, casi siempre.

**Tiempo/Espacio:** O(log n) / O(1).

**Intento:** El esqueleto salió bien (`while(left<=right)`, mover `left=mid+1` / `right=mid-1`,
`-1` si no está). El bug fue el punto medio: escribí `(right-left)/2`, que es un **ancho** (la
distancia de `left` al medio), no un índice — así que en cuanto la ventana se movía de 0, el
medio quedaba fuera del rango. Se arregla anclándolo a `left`. Lo dejé como `left + (right-left)/2`,
que da el índice correcto.

**Repaso:** 2026-09-05