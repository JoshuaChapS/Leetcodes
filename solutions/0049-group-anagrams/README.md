# 49. group-anagrams
https://leetcode.com/problems/group-anagrams/

- **Patrón:** dict de firmas, agrupar sin comparar (defaultdict(list))
- **Señal:** "agrupa los que compartan una propiedad" con n elementos
- **Tiempo:** O(n·k log k) con sorted, O(n·k) con conteo · **Espacio:** O(n·k)
- **Intento:** llegué a O(n²) comparando pares; necesité la idea de firma