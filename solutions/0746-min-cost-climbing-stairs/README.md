# 746 · Min Cost Climbing Stairs

**Patrón:** DP lineal, como el 70. `steps[i]` = costo mínimo para estar parado en el escalón i;
llegas desde i − 1 o desde i − 2, pagando el costo del escalón del que sales.

**Señal:** "llegar al final avanzando 1 o 2" + "mínimo costo". Es el 70 cambiando "contar formas"
por "quedarse con el mínimo".

**Tiempo/Espacio:** O(n) tiempo, O(n) espacio. Solo uso los dos anteriores, así que con dos
variables queda en O(1).

**Intento:** salió limpio a la primera, ~7 min. Lo que había que leer bien: la cima es el índice
`n` (después del último escalón), no `n − 1`, y se puede empezar en el 0 o en el 1 sin pagar, por
eso `steps[0] = steps[1] = 0`.

**Repaso:** 2026-10-12