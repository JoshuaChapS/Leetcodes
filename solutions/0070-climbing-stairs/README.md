# 70. climbing-stairs
https://leetcode.com/problems/climbing-stairs/

- **Patrón:** DP bottom-up con dos variables (Fibonacci disfrazado)
- **Señal:** "de cuántas formas puedo llegar a n" donde cada estado depende de unos pocos estados anteriores → recurrencia + subproblemas que se traslapan = DP. Si además solo dependes de los últimos k estados, no necesitas la tabla completa.
- **Tiempo:** O(n) · **Espacio:** O(1)
- **Intento:** primero la recursión directa `f(n)=f(n-1)+f(n-2)`. La recurrencia era correcta pero el costo O(φⁿ): n=30 hace 1,664,079 llamadas para calcular 30 números, y n=45 (el límite de LeetCode) tomaría ~200s. El desperdicio es recalcular los mismos subproblemas desde ramas distintas del árbol. Bottom-up: mismo resultado en 0.000008s.
- **Modismo:** `a, b = b, a + b` — el lado derecho se evalúa completo antes de desempaquetar, así que no hace falta temporal.