# 322. coin-change
https://leetcode.com/problems/coin-change/

- **Patrón:** DP bottom-up con tabla completa indexada por cantidad
- **Señal:** minimizar un conteo sobre una cantidad objetivo, donde cada decisión (poner una moneda) deja un subproblema del mismo tipo más pequeño, y los subproblemas se repiten. A diferencia de 70, aquí miro hacia atrás el valor de cada moneda —que puede ser cualquiera— así que **no** se colapsa a dos variables: necesito la tabla.
- **Tiempo:** O(amount × m), con m = número de monedas. **No** es O(n²): son dos tamaños de entrada independientes. Es pseudo-polinomial porque `amount` es un valor, no un conteo de elementos · **Espacio:** O(amount)
- **Intento:** me atoré en la recurrencia. La desbloquea preguntarse *"sea cual sea la solución óptima, termina con alguna moneda — pruebo cada una y miro lo que ya resolví para `cantidad - moneda`"*. Dos decisiones que ahorran ifs: la casilla `0` vale `0`, y "imposible" es `float("inf")`, que el `min` descarta solo y que al sumarle 1 sigue siendo infinito, así que la imposibilidad se propaga sin código extra.