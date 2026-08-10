# 121. best-time-to-buy-and-sell-stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

- **Patrón:** un recorrido guardando el mínimo hasta ahora (versión con dos índices: `i` = mínimo, `d` = actual)
- **Señal:** maximizar una diferencia con **orden obligatorio** (comprar antes de vender) → no puedo ordenar ni usar dos punteros convergentes; recorro una vez acumulando el mejor candidato izquierdo visto
- **Tiempo:** O(n) · **Espacio:** O(1)
- **Intento:** salió a la primera, sin bugs. El `i < n` de la guardia es redundante porque `i < d` siempre.