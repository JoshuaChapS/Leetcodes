# 207 · Course Schedule

**Patrón:** orden topológico con el algoritmo de Kahn: grado de entrada + cola. Se puede terminar
si y solo si el grafo dirigido no tiene ciclos.

**Señal:** "prerrequisitos", "dependencias", "¿se puede completar todo?". Relaciones de "A antes que
B" son un grafo dirigido, y "no se puede terminar" es un ciclo.

**Tiempo/Espacio:** O(V + E) tiempo y espacio, con V = cursos y E = prerrequisitos.

**Intento:** ~34 min. La idea salió bien desde el principio: lista de adyacencia del prerrequisito
al curso que desbloquea, `indeg` con cuántos prerrequisitos le faltan a cada curso, y una cola con
los que tienen 0. El bug: después de procesar cada curso volvía a recorrer **todos** los cursos
buscando `indeg == 0`, y metía otra vez a los que ya estaban esperando en la cola. Un curso
repetido le resta dos veces a sus vecinos y el conteo se rompe (`n = 4`, `[[1,2],[3,0],[1,3]]`
daba false). El arreglo: meter a un vecino solo en el momento en que su grado **llega** a 0, que
pasa una sola vez. Eso además lo baja a O(V + E).

**Repaso:** 2026-10-14