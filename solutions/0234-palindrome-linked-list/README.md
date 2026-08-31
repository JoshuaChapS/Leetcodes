# 234. Palindrome Linked List

**Patrón:** Composición — punto medio con rápido/lento (876) + invertir lista (206),
luego comparar las dos mitades en paralelo.

**Señal:** "¿es palíndromo?" en una lista enlazada con O(1) espacio. No hay índices
ni acceso por atrás, así que no puedes ir con dos punteros desde los extremos:
hay que traer la segunda mitad "al derecho" invirtiéndola.

**Tiempo/Espacio:** O(n) / O(1) — el `reverse` es in-place. (La recursión usa O(n/2)
de pila; con 100k nodos son ~50k marcos, cabe en los 8 MB por defecto pero no sobra
tanto. La versión iterativa de 206 no tiene ese techo.)

**Intento:** Salió a la primera reusando 876 y 206 tal cual, sin adaptarlos. Detalle
que parece bug y no lo es: en longitud impar `middleNode` devuelve el nodo de en medio,
así que ese nodo queda en AMBAS mitades — no importa, se compara contra sí mismo.
Lo que sí es un pendiente real: la función **muta la lista del que la llama** (deja la
primera mitad cortada). En una entrevista hay que decirlo: se puede volver a invertir
la segunda mitad antes de retornar, otra pasada O(n/2), sigue O(1) espacio.
Verificado: 8/8 casos fijos, 20 000/20 000 aleatorios contra oráculo, y 100k nodos sin
desbordar la pila.

**Repaso:** 2026-09-02