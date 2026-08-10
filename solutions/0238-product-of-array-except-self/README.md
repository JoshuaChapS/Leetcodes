# 238. product-of-array-except-self
https://leetcode.com/problems/product-of-array-except-self/

- **Patrón:** prefix products — acumulados izq/der en dos pasadas
- **Señal:** "resultado por posición que depende de todo lo demás", prohibido dividir
- **Tiempo:** O(n) · **Espacio:** O(n), o O(1) con variable acumuladora
- **Intento:** sabía la de O(n²); necesité la idea de acumulados
