# 98. Validate Binary Search Tree
https://leetcode.com/problems/validate-binary-search-tree/

- **Patrón:** Recursión con rango heredado. Cada nodo debe caer dentro de un rango `(min, max)` que hereda de sus ancestros; al bajar a la izquierda se aprieta el `max` (= valor del padre), a la derecha se aprieta el `min`. No basta comparar un nodo con sus hijos inmediatos.

- **Señal:** "Validar BST" → la propiedad no es local (nodo vs hijos) sino de subárbol completo: TODO el subárbol derecho de un nodo debe ser mayor que él, no solo el hijo. Eso pide propagar cotas hacia abajo, no comparaciones locales.

- **Tiempo:** O(n) — se visita cada nodo una vez · **Espacio:** O(h) por la pila de recursión.

- **Intento:** El primer intento tenía la idea del rango pero cayó en las dos trampas clásicas del problema, las dos de C++, no de algoritmo:
  1. **`min < x < max` NO funciona en C++.** Se parsea como `(min < x) < max`: primero evalúa `min < x` → un bool (0 o 1), luego compara `0/1 < max`, que casi siempre da true. En Python encadena como uno espera; en C++ hay que escribir `min < x && x < max`. Un árbol inválido pasaba como válido por esto (lo comprobé corriéndolo).
  2. **Cotas con `int` fallan en los extremos.** Los valores de nodo pueden ser `INT_MIN`/`INT_MAX`, así que usar esos como centinelas `-∞`/`+∞` rechaza un nodo legítimo (`INT_MIN < INT_MIN` es false). Solución: cotas en `long` (`LONG_MIN`/`LONG_MAX`), 64 bits, más anchas que cualquier valor de 32 bits. (2^32 no cabe en int ni en unsigned int; necesita 64 bits.)
  También me faltaban los `return false` (solo recursaba, nunca rechazaba) y tenía un typo `node->right.val` en vez de `node->right->val` — `.` sobre un puntero, error de compilación; va `->`.
  La estructura final: si el hijo rompe el orden local o su cota, `ans = false`; si no, recurse con la cota apretada.

- **Repaso:** 2026-08-30