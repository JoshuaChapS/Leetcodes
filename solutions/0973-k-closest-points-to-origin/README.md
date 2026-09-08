# 973 · K Closest Points to Origin

**Patrón:** heap de tamaño `k`. Para los `k` **más cercanos** (distancias chicas) va un
**max-heap**: `pop()` expulsa la distancia mayor, así que sobreviven las chicas.

**Señal:** "los k más cercanos / los k más chicos / top k" → heap de tamaño k. La regla que
resuelve la mitad del problema: **el heap va al revés de lo que buscas** — k más grandes →
min-heap, k más chicos → max-heap. Lo que `pop()` tira es lo que no quieres.

**Tiempo/Espacio:** O(n log k) tiempo, O(k) espacio. Ordenar todo sería O(n log n); con `k`
chico y `n` grande el heap gana.

**No hace falta `sqrt`:** la raíz es monótona, así que comparar `x²+y²` ordena igual que
comparar la distancia real — y te ahorras el `double` y su error de redondeo en una
comparación que tiene que ser exacta.

**Intento:** dos bugs. El primero fue escribir `point[0]^2` creyendo que era "al cuadrado":
en C++ **`^` es XOR bit a bit**, no potencia — `3^2` da 1, no 9. Compila y devuelve basura sin
avisar; en C++ no hay operador de potencia, se multiplica. El segundo fue la dirección del
heap: usé **min-heap** (como en el 215, donde sí tocaba) y con eso `pop()` botaba la distancia
**menor**, o sea justo los puntos cercanos que quería conservar. Aquí es al revés — **max-heap**,
y la condición de entrada es `dist < pq.top().first`, no `>`.

**Repaso:** 2026-09-08