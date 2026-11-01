# 763 · Partition Labels

**Patrón:** greedy con el último índice de cada letra: recorro el string extendiendo el final de la parte hasta la última aparición de cada letra que veo, y corto cuando llego a ese final.

**Señal:** "partir en el mayor número de partes donde cada letra aparezca en una sola". Una parte no puede terminar antes de la última aparición de ninguna de sus letras, así que necesito saber dónde aparece cada letra por última vez.

**Tiempo/Espacio:** O(n) tiempo (dos pasadas) y O(1) espacio, porque el arreglo `lastSeen` tiene 26 posiciones sin importar el tamaño del string, con n = largo del string.

**Intento:** mi primera idea fue contar cuántas veces sale cada letra y luego recorrer con un mapa temporal de la parte actual, borrando cada letra cuando ya vi todas sus apariciones; cuando el mapa queda vacío, termina la parte. También era correcta y O(n). Me quedé con la del último índice porque es más corta: primero guardo en `lastSeen[s[i] - 'a']` la última posición de cada letra, y luego recorro llevando `last` = el máximo de esas posiciones para las letras que he visto. Cuando `i == last`, agrego el tamaño de la parte. Salió a la primera, en unos 23 minutos contando la planeación.

**Nota:** en vez del contador `part` se puede guardar `start`, donde empezó la parte, y agregar `i - start + 1` al cortar. Es la forma más común y evita pensar en el orden de `part = 0` y `part++`.

**Repaso:** 2026-11-04