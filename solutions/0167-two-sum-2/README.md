# 167. two-sum-ii-input-array-is-sorted
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

- **Patrón:** two pointers convergentes sobre arreglo ordenado
- **Señal:** misma de 125 — pares de elementos + estructura explotable; aquí la propiedad es que está **ordenado**, así que la suma de los extremos me dice de qué lado sobra
- **Tiempo:** O(n) · **Espacio:** O(1) — el dict de 1 Two Sum también da O(n) tiempo, pero O(n) espacio y desperdicia el orden que el enunciado regala
- **Intento:** la lógica salió a la primera; tres bugs de ejecución — `is not` en vez de `!=` (identidad vs valor, pasó por el caché de enteros chicos de CPython), guardias sobre los bordes del arreglo en vez del invariante `izq < der`, y `if`/`elif` con la condición duplicada por copy-paste