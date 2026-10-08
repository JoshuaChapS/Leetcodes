# 482 · License Key Formatting

**Patrón:** recorrer el string de atrás hacia adelante, contando, y voltear el resultado al final.

**Señal:** "el primer grupo puede ser más corto, todos los demás miden exactamente k". Si el grupo
irregular es el primero, desde la izquierda no sabes dónde cortar sin contar todo antes; desde la
derecha todos los grupos son de tamaño k y el sobrante cae solo al principio.

**Tiempo/Espacio:** O(n) tiempo, O(n) espacio para la respuesta. El `reverse` es otra pasada O(n).

**Intento:** dos bugs, ~15 min. El primero fue `counter == 0;` en vez de `counter = 0;`: compara y
tira el resultado, así que el contador nunca se reiniciaba y metía un guion en cada vuelta.
Compila sin error; con `-Wall` avisa *statement has no effect*.

El segundo es mi patrón de siempre: el guard existe pero la operación peligrosa pasa antes. Revisaba
`counter == k` y metía el guion **antes** de saber si el carácter era alfanumérico, así que un guion
de la entrada también disparaba el guion de la salida. Falló con `"--a-a-a-a--"`, k = 2: devolvía
`"-AA-AA"` en vez de `"AA-AA"`. El arreglo fue mover el `if (counter == k)` adentro del
`if (isalnum(...))`: el guion solo entra justo antes de una letra que empieza grupo nuevo, así que
nunca queda uno al principio ni al final.

**Repaso:** 2026-10-10