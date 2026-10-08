# 904 · Fruit Into Baskets

**Patrón:** sliding window con conteo en `unordered_map`; en mi versión la ventana **nunca se
encoge**: si la fruta cabe crece uno, si no cabe se desliza (`l` y `r` avanzan juntos).

**Señal:** "el subarreglo contiguo más largo con a lo más K valores distintos". Contiguo + más
largo + una restricción sobre lo que hay adentro = ventana deslizante.

**Tiempo/Espacio:** O(n) tiempo, O(1) espacio (el mapa nunca pasa de 3 llaves).

**Intento:** dos intentos, ~39 min. El primero tenía tres bugs: la condición `d.size() < 2` no
dejaba entrar una fruta que ya estaba en la canasta (`[1,2,1]` daba 2), en la rama de encoger
hacía `r++` igual y me saltaba la fruta sin meterla, y `ans++` contaba frutas agregadas, no el
tamaño de la ventana.

La segunda versión funciona, pero no es la ventana de siempre: cuando la fruta no cabe, quito una
de la izquierda y meto la nueva, así que el tamaño se queda igual. Por qué está bien aunque el
mapa llegue a tener 3 tipos: `ans` solo crece cuando la ventana, ya con la fruta nueva, tiene a lo
más 2 tipos, así que cada valor de `ans` fue una ventana válida de verdad. Y una ventana inválida
nunca crece, solo se desliza con el tamaño del mejor hasta ahora, así que no se pierde nada.

**Nota:** el `d.size() == 2 &&` parece redundante pero no lo es: mientras la ventana se desliza el
mapa puede tener 3 tipos, y sin esa condición `count()` dejaría crecer una ventana inválida
(`[0,2,0,1,2]` daba 4 en vez de 3). El `> 0` del final sí sobra: se aplica al `bool` y no cambia
nada. Y `ans` siempre vale `r - l`, el mismo dato guardado dos veces.

**Repaso:** 2026-10-11