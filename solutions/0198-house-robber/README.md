# 198 · House Robber

**Patrón:** DP lineal: `amount[i]` = lo máximo que puedo juntar si robo la casa i, contando solo las casas hasta i.

**Señal:** "lo máximo" con una restricción entre vecinos (no puedo robar dos casas seguidas). Cada casa es una decisión que depende de las anteriores, así que el estado es el índice.

**Tiempo/Espacio:** O(n) tiempo y O(n) espacio, con n = número de casas.

**Intento:** primero definí el estado: lo máximo si robo la casa i. La primera idea fue revisar todas las casas hasta i-2, que sería O(n²). Luego me di cuenta de que solo importan i-2 e i-3: como el dinero nunca es negativo, si mi último robo fuera en i-4 o antes, también podría robar i-2 y ganar lo mismo o más. Entonces `amount[i] = nums[i] + max(amount[i-2], amount[i-3])`, y la respuesta es `max(amount[n-1], amount[n-2])`, porque el mejor plan termina en la última casa o en la penúltima. Los casos de 1, 2 y 3 casas los resolví antes del ciclo para que ningún índice quede negativo. Salió a la primera, en unos 12 minutos.

**Nota:** como solo miro tres posiciones atrás, se puede hacer con tres variables en vez del arreglo: O(1) de espacio. La definición más común es "lo máximo con las primeras i casas, robe la i o no": `dp[i] = max(dp[i-1], dp[i-2] + nums[i])`, que tiene menos casos especiales.

**Repaso:** 2026-11-01