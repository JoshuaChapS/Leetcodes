# 56 · Merge Intervals

**Patrón:** ordenar y recorrer una vez. Ordenas por inicio y vas fusionando con el último
intervalo del resultado mientras haya traslape.

**Señal:** "intervalos", "fusionar", "solapamiento", "salas de reuniones". Casi siempre empieza
igual — **ordenar por inicio** — y después es una pasada lineal.

**Tiempo/Espacio:** O(n log n) por el `sort` (la pasada es O(n)), O(n) de espacio para la salida.

**Detalle útil:** para `vector<vector<int>>` **no hace falta comparador**. `sort` a secas ya
ordena lexicográficamente: por `[0]` y, si empatan, por `[1]` — que es justo lo que se necesita.
Misma razón por la que `priority_queue<pair<int,int>>` ordena por `.first`.

**Intento:** la estructura salió a la primera y los dos ejemplos del enunciado pasaban. El bug
estaba en un intervalo **contenido** dentro de otro: con `[[1,10],[2,3]]` yo hacía
`last = intervals[i][1]`, que **encoge** el final de 10 a 3. Ordenar por inicio garantiza que los
**inicios** vienen en orden, pero **no dice nada de los finales** — un intervalo posterior puede
terminar antes. El arreglo fue una palabra: `last = max(last, intervals[i][1])`. Sin ese caso en
los ejemplos, pasaba limpio y fallaba 4 de cada 20 entradas aleatorias.

**Nota para la próxima:** usé `temp` y `last` como auxiliares, pero no hacen falta —
`ans.back()` devuelve referencia al último intervalo, así que se puede extender en su lugar y la
solución queda en dos ramas sin variables extra.

**Repaso:** 2026-09-08