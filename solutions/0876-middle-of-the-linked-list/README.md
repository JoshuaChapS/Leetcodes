# 876. Middle of the Linked List

**Patrón:** Dos punteros rápido/lento (Floyd). El rápido avanza 2, el lento 1;
cuando el rápido llega al final, el lento está en el medio.

**Señal:** "el nodo de en medio" de una lista enlazada, en una sola pasada y
O(1) espacio → fast/slow. (No hay índice: no puedes saltar al medio directo.)

**Tiempo/Espacio:** O(n) / O(1).

**Intento:** El algoritmo salió al toque (transfiere de 141). El bug fue de C++,
mi patrón #1: la condición del `while` era `fast != nullptr || fast->next != nullptr`.
El cuerpo hace `fast = fast->next->next`, que desreferencia DOS punteros, así que
ambos tienen que estar vivos. Con `||` el cuerpo entra teniendo sólo uno vivo →
`fast->next->next` truena (null-deref). El `||` dice "al menos uno", yo necesitaba
"los dos": `&&`. Corregido y verificado con ASan/UBSan + oráculo 20k/20k.
Para longitud par devuelve el SEGUNDO medio (fast termina en nullptr); para impar,
fast termina en el último nodo.

**Repaso:** 2026-09-02