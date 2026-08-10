# 15. 3sum
https://leetcode.com/problems/3sum/

- **Patrón:** ordenar + fijar un elemento + two pointers en el resto (2Sum reducido)
- **Señal:** buscar una relación entre k elementos sin índice fijo, y el orden no importa en la salida → si ordenar no rompe el problema, ordena: te compra la estructura explotable de two pointers y deja los duplicados pegados
- **Tiempo:** O(n²) — el sort O(n log n) queda dominado · **Espacio:** O(1) sin contar la salida
- **Intento:** la estructura salió rápido; todo el trabajo fue en duplicados. Saltar mirando adelante (`nums[i+1]==nums[i]`) se come la primera aparición o deja el puntero parado en el último del bloque; hay que **pasar** el bloque, no aterrizar en él. Segundo bug: calcular `total` al final del cuerpo lo evalúa con los punteros ya fuera de rango — va al principio, donde la guardia del `while` ya aplicó.

