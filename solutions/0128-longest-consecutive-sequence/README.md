# 128. Longest Consecutive Sequence

**Patrón:** Hash set + caminar sólo desde las cabezas de racha.

**Señal:** "secuencia consecutiva más larga" y **no puedes ordenar** (ordenar da O(n log n)
y tira el propósito). Necesitas preguntar "¿existe x?" muchísimas veces → hash set, O(1).

**Tiempo/Espacio:** O(n) / O(n).

**Intento:** La idea la traía a medias: set + caminar hacia adelante desde cada elemento.
Eso solo es O(n²) — con `[1..100]` arrancas 100 caminatas y sumas 100+99+98+... ≈ n²/2.
Lo que faltaba: **arrancar sólo donde `x-1` NO está en el set**, o sea las cabezas de racha.
Esa pregunta la contesta el mismo set en O(1); no hace falta ordenar ni otra estructura.
Así cada elemento se recorre una sola vez en todo el algoritmo (pertenece a exactamente
una racha) → total ≈ 2n → O(n).

**La medición, que vale más que la explicación:** mismo código, n = 100 000 en una sola racha:

    con la guardia `if (!s.count(x-1))` :      12.1 ms
    sin la guardia                      :  27 692.4 ms   → 2 286x más lento

**C++ nuevo aquí:** `unordered_set` (NO `set`, que es árbol O(log n)); `s.count(x)` para
membresía (`.contains()` es C++20); `m[k]` en un map **inserta** si no existe, así que para
consultar se usa `.count()`. Y `for (int i : s)` da una **copia** — por eso `i++` es seguro;
`for (int& i : s)` ni compila, porque los elementos de un set son `const`: la llave es la
entrada del hash y mutarla corrompería su bucket.

**Repaso:** 2026-09-03