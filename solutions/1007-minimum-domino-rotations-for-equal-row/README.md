# 1007 · Minimum Domino Rotations For Equal Row

**Patrón:** candidatos desde el primer elemento. Si un valor tiene que llenar toda la fila, tiene
que estar en la ficha 0, así que solo hay dos candidatos: `tops[0]` y `bottoms[0]`. Para cada uno
reviso si es posible y cuánto cuesta con conteos de todo el arreglo.

**Señal:** "que **todos** los elementos cumplan X". Cuando la condición es sobre todos, el primer
elemento ya reduce los candidatos a casi nada; no hace falta buscar el más frecuente.

**Tiempo/Espacio:** O(n) tiempo, O(1) espacio (los valores van de 1 a 6).

**Intento:** no lo saqué solo. Cinco intentos en ~40 min y al final vi la solución. Mi idea fue
buscar el valor **más frecuente** arriba y abajo y apostar todo a ese, pero la frecuencia no decide
nada aquí: con `tops = [3,3,6,6]`, `bottoms = [6,6,2,5]` escogía el 3 (empata en frecuencia y no
está en todas las fichas) y regresaba -1, cuando el 6 sí era posible con 2 rotaciones.

Lo que sí tenía bien desde el segundo intento: la fórmula de factibilidad,
`top[x] + bot[x] − same[x] == n` (las fichas con `x` en los dos lados se cuentan una vez), y el
costo `min(n − top[x], n − bot[x])`. Lo que me faltaba era a qué valores aplicarla.

El error de proceso fue peor que el de algoritmo: cada intento le agregaba un parche (`count`,
`else if`) a los mismos dos ciclos del "más frecuente", en vez de borrarlos. Cuando la estrategia
está mal, ninguna condición extra la arregla: borrar primero y reescribir.

También: `ignore[top[i]]++` en vez de `ignore[tops[i]]++`. `top[i]` no solo lee mal, **inserta la
llave `i`** en el mapa y le cambia los conteos.

**Repaso:** 2026-10-10 (en frío, sin ver esto)