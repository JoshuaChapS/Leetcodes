# 3. longest-substring-without-repeating-characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

- **Patrón:** sliding window con `set`; la ventana crece por la derecha y se encoge por la izquierda hasta eliminar el duplicado
- **Señal:** subarreglo/substring **contiguo** con una restricción que se puede violar al extender y reparar al encoger → ventana con dos punteros que solo avanzan (nunca retroceden)
- **Tiempo:** O(n) amortizado — el `while` anidado engaña; cada carácter entra y sale del set a lo más una vez, trabajo total ≤ 2n · **Espacio:** O(min(n, tamaño del alfabeto))
- **Intento:** el algoritmo salió a la primera. El bug fue `is not` en vez de `!=` — tercera vez en la misma familia (167 con enteros, aquí con strings). Latente: pasó 60,000 pruebas ASCII porque CPython cachea las cadenas de 1 carácter en latin-1; solo revienta con griego o CJK, y LeetCode ni lo detectaría porque sus entradas son ASCII. **Un test suite verde no es correctitud.**