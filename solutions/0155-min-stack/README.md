# 155 · Min Stack

**Patrón:** stack auxiliar con el "mínimo hasta aquí": junto a cada elemento guardo el mínimo de todo lo que hay debajo de él, incluyéndolo.

**Señal:** una estructura que solo cambia por un extremo (stack) y me piden una propiedad agregada (mínimo, máximo) en O(1). Como lo de abajo nunca cambia mientras el elemento siga ahí, ese valor se puede calcular al hacer `push` y ya no se vuelve a tocar.

**Tiempo/Espacio:** O(1) tiempo en `push`, `pop`, `top` y `getMin`; O(n) espacio, con n = elementos en el stack, por el segundo stack.

**Intento:** mi problema era que si hacía `pop` del mínimo tenía que volver a buscarlo, y eso es O(n). Primero pensé en tener un heap junto al stack, pero no sirve: el heap es O(log n) y no puede borrar un elemento cualquiera cuando lo saco del stack. Con dos pistas no me salió, así que me explicaron la idea: no hace falta mantener ningún orden, solo saber cuál era el mínimo cuando entró cada elemento. Con `push 5, push 3, push 7`, `s2` queda `[5, 3, 3]`; al sacar el 7 y el 3 vuelvo a `[5]` sin buscar nada. Con eso lo escribí yo y salió bien al primer intento, unos 12 minutos en total.

**Nota:** `stack<int>` usa un `deque` por dentro; con `stack<int, vector<int>>` o un `vector` directo suele ser más rápido porque la memoria es contigua. Es una mejora de constante, no de complejidad. Los nombres `vals_` / `mins_` se explican solos mejor que `s1` / `s2`, y el `this->` sobra.

**Repaso:** 2026-10-24 (en frío, sin ver esto)