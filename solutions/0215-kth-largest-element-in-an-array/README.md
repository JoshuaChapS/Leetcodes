# 215 · Kth Largest Element in an Array

**Patrón:** heap. Dos caminos válidos — max-heap con todo y sacar `k-1`, o min-heap de
tamaño `k` y devolver su `top()`.

**Señal:** "k-ésimo mayor", "top k", "los k más frecuentes" → heap. Y pide no ordenar:
`sort` lo resuelve en O(n log n), pero con heap se puede hacer mejor cuando `k` es chico.

**Tiempo/Espacio:** max-heap completo O(n log n) tiempo, O(n) espacio. Min-heap de tamaño
`k`: O(n log k) tiempo, O(k) espacio — el bueno cuando `k << n`.

**Intento:** tres errores antes de que saliera. Primero `return pq.pop()` — `pop()` devuelve
`void`, no el valor; se lee con `top()` y se saca con `pop()`, siempre en dos pasos. Segundo,
el de fondo: usé un **max-heap** de tamaño `k`, y ahí `pop()` quita el **más grande**, justo el
que quería conservar. Para quedarse con los `k` mayores el heap tiene que ser **min**: así va
expulsando a los chicos y `top()` termina siendo el k-ésimo mayor. Tercero, metí un
`unordered_set` para saltar repetidos sin leer la nota del enunciado — pide el k-ésimo **en
orden ordenado, no el k-ésimo distinto**, así que los duplicados cuentan y el set sobraba.
Terminé por el otro camino: max-heap con todo y `k-1` pops — `k-1`, no `k`, porque `top()`
ya es el primero.

**Repaso:** 2026-09-08