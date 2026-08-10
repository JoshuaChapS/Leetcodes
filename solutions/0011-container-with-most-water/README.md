# 11. container-with-most-water
https://leetcode.com/problems/container-with-most-water/

- **Patrón:** two pointers convergentes, moviendo siempre el limitante
- **Señal:** maximizar sobre **pares** donde una dimensión (el ancho) solo puede empeorar al moverme → mover el lado alto nunca sube el `min`, así que descartarlo es seguro; cada paso elimina un candidato sin evaluarlo
- **Tiempo:** O(n) · **Espacio:** O(1)
- **Intento:** la regla de movimiento salió mal a la primera — comparaba `height[d-1]` contra `height[d]` (el vecino) en vez de los dos punteros entre sí. Dos bugs mecánicos aparte: `__main_` con un guion bajo de menos (no corría nada, ni el print), y `n-1*min(...)` sin paréntesis, que por coincidencia daba el valor correcto en el caso de ejemplo.