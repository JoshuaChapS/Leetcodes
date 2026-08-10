# 125. valid-palindrome
https://leetcode.com/problems/valid-palindrome/

- **Patrón:** two pointers convergentes, saltando caracteres irrelevantes
- **Señal:** busco una relación entre pares de elementos y el arreglo tiene estructura explotable (ordenado o simétrico) → comparar los extremos me dice cuál mover, y descarto candidatos sin examinarlos: O(n²) → O(n)
- **Tiempo:** O(n) · **Espacio:** O(1) — v1 con lista filtrada era O(n)
- **Intento:** salió a la primera con lista + espejo `d[i]`/`d[n-1-i]`; dos bugs — filtré solo `a-z` cuando el enunciado dice alfanumérico (`"0P"`), y puse la guardia de rango después del acceso en el `and` (`" "` → IndexError). El short-circuit solo protege lo que está a su derecha.