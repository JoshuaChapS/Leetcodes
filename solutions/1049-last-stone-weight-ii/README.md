# 1049 · Last Stone Weight II

**Patrón:** DP de subset sum (mochila 0/1). Se reduce a partir las piedras en 2 bolsas con la
mínima diferencia.

**Señal:** "chocan dos y queda la diferencia", "lo más parejo posible", "repartir en dos". Si el
resultado final es una resta de sumas, en realidad son dos grupos. Al final cada piedra quedó
sumando o restando, sin importar el orden de los choques.

**Tiempo/Espacio:** O(n · S) tiempo, O(S) espacio, con S = suma total / 2.

**Intento:** la reducción me costó. Primero leí que pedía el peso **máximo** (pide el mínimo) y
traté de pensarlo como choques, donde cada estado es un vector distinto de piedras y no hay forma
de llevarlo. Lo que lo destrabó: dividir las piedras en 2 bolsas con la mínima diferencia; la bolsa
chica no pasa de la mitad y la respuesta es `total − 2·(bolsa chica)`.

Ya con eso, el código salió a la primera: `a[s]` = "¿alguna combinación suma exactamente s?",
empiezo con `a[0] = true`, y por cada piedra recorro de la mitad hacia abajo con
`if (a[s − piedra]) a[s] = true`. De derecha a izquierda para no usar la misma piedra dos veces
(de izquierda a derecha sería como el 322, donde cada moneda se repite).

Dos correcciones después de que pasó: el vector era de `total + 1` y basta con `mitad + 1`, porque
nunca paso de la mitad; y faltaba un `return total;` al final. Nunca llega ahí porque `a[0]` siempre
es `true`, pero sin él la función no regresa nada en todos los caminos y `-Wall` avisa.

**Repaso:** 2026-10-12