# 560 · Subarray Sum Equals K

**Patrón:** suma acumulada (prefix sum) + hash map que cuenta cuántas veces salió cada suma acumulada.

**Señal:** piden contar subarreglos continuos con una suma exacta y **hay negativos**. Con negativos la ventana deslizante no sirve, porque agrandar la ventana puede bajar la suma. Además, la fuerza bruta es un `for` adentro de otro que busca algo, y eso se cambia por un hash map.

**Tiempo/Espacio:** O(n) tiempo, O(n) espacio, con n = tamaño de `nums`. En el peor caso el mapa guarda las n sumas acumuladas distintas.

**Intento:** primero pensé la fuerza bruta: probar cada inicio y cada final, O(n²). Luego intenté ventana deslizante, pero no funciona con negativos: en `[1, 1, -1, 2]` con k = 1, la suma sube y baja, así que no sé cuándo mover el inicio. No supe hacerlo eficiente y me explicaron la idea. La suma de `nums[a..b]` es la suma acumulada hasta b menos la suma acumulada hasta a−1. Entonces en cada índice busco cuántas veces, antes, la suma acumulada valió `suma − k`. Cada una es un inicio distinto. Por eso el mapa es `int` y no `bool`: en `[2, 0, 0, 1]` con k = 1, el 2 sale tres veces y hay tres subarreglos. Me costó entender por qué solo cuenta índices anteriores. Es por el orden: primero busco y después meto la suma actual. `esta[0] = 1` sirve para los subarreglos que empiezan en el índice 0. Lo escribí yo después de la explicación, pero no lo resolví en frío.

**Nota:** el `if (esta.count(sum - k))` no hace falta para que sea correcto, porque `esta[sum - k]` daría 0. Lo dejo porque evita llenar el mapa de claves con 0. Si las sumas pudieran ser muy grandes, usaría `long long`.

**Repaso:** 2026-11-07 (en frío, sin ver esto)