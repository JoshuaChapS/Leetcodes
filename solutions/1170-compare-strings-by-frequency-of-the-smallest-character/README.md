# 1170 · Compare Strings by Frequency of the Smallest Character

**Patrón:** precalcular un valor por palabra, ordenar, y contestar cada consulta contando cuántos
son mayores.

**Señal:** "para cada consulta, ¿cuántos elementos de otra lista cumplen X?". Si X es una
comparación con un número, se ordena la lista una vez y cada consulta es buscar dónde cae.

**Tiempo/Espacio:** O((Q + W) · L + W log W + Q · W) como lo hice, con Q = consultas, W = palabras
y L = largo de cada palabra; O(W) espacio. Con `upper_bound` la parte de las consultas baja a
O(Q log W).

**Intento:** lo difícil fue el enunciado, no el problema: el inglés está enredado. Lo entendí
haciendo el ejemplo a mano. `f(s)` recorre la palabra guardando la letra más chica vista y cuántas
veces aparece; si llega una más chica, reinicia el conteo. Luego ordeno las `f` de las palabras y
por cada consulta avanzo hasta el primer valor mayor. Salió bien a la primera, ~20 min dentro de un
simulacro de 90 min (lo hice después de atorarme con el 853). Quise hacer `f` una lambda y no me
salió la sintaxis: es `auto f = [](const string& s) { ... };`, con punto y coma al final.

**Nota:** el `while` que busca el primer valor mayor es exactamente `upper_bound`, porque el vector
está ordenado: `wf.end() - upper_bound(wf.begin(), wf.end(), fun)`. Y `sort` basta; `stable_sort`
no aporta nada con `int`.

**Repaso:** 2026-10-15