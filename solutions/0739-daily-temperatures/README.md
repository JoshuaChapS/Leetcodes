# 739 · Daily Temperatures

**Patrón:** pila monótona. La pila guarda los **índices** de los días que todavía esperan un día
más caliente; de abajo hacia arriba quedan de mayor a menor temperatura.

**Señal:** "para cada elemento, el **siguiente** mayor (o menor) a su derecha". Cuando la
respuesta de uno depende del primero que lo supere, es pila monótona.

**Tiempo/Espacio:** O(n) tiempo, O(n) espacio. Aunque hay un `while` dentro del `for`, cada índice
entra una vez y sale una vez.

**Intento:** solo se me ocurría la fuerza bruta, O(n²): por cada día buscar hacia adelante.
La idea que lo destraba: recorrer de izquierda a derecha con una "fila de espera" de días sin
respuesta. Cuando llega un día más caliente que el de hasta arriba, ese día es su respuesta y sale
de la fila. Es `while` y no `if`, porque un día caliente puede resolver a varios de un jalón.

La estructura salió bien a la primera (el `!s.empty()` antes del `top()`). Dos bugs: puse
`s.top() − i`, que da negativo, cuando el día que espera es anterior: es `i − s.top()`. Y se me
olvidó el `return ans`, igual que en el 1049; `-Wall` lo avisa.

**Repaso:** 2026-10-12